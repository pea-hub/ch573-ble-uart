/********************************** (C) COPYRIGHT *******************************
 * File Name          : peripheral.C
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2018/12/10
 * Description        : 外设从机多连接应用程序，初始化广播连接参数，然后广播，连接主机后，
 *                      请求更新连接参数，通过自定义服务传输数据
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "CONFIG.h"
#include "devinfoservice.h"
#include "gattprofile.h"
#include "peripheral.h"
#include "UserCode.h"

#include "hiddev.h"
#include "hidconsumer.h"

#include "Parmeter.h"
#include "app_drv_fifo.h"

#include "CH57x_uart.h"
#include "CH57xBLE_LIB.h"
#include "HAL.h"
#include "UserCode.h"


/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */
//********************************************************************
//************************************************************
//蓝牙储存的数据
//************************************************************
BT_STOR Bt_Stor_Act;

//************************************************************
//蓝牙运行状态
//************************************************************
BT_PAR Bt_Par_Act=
{
  .Ble_Sta.Data = 0,
  .Ble_Name=DEVICE_NAME_DEF,
  .Ble_SelfMac = {0},
  .Ble_LinkMac = {0}
};
//********************************************************************

//********************************************************************
//************************************************************
//蓝牙数据发送结构体
//#define BT_SEND_STR_SIZE sizeof(BT_SEND_STR)
//************************************************************
UART_SEND_STR Uart_Send_Str = {
        .HeaderCode = {0xBA,0xAB},
        .Ble_Sta.Data = 0,                  //回复初始化状态
        .Ble_Name = DEVICE_NAME_DEF,        //加载默认的名称
        .Ble_SelfMac = {0},                 //加载默认的MAC地址
        .Ble_LinkMac = {0},                 //清除连接的MAC地址
        .Crc16 = 0
};
//************************************************************

//************************************************************
//蓝牙数据接收结构体
//************************************************************
//#define UART_RECE_STR_SIZE sizeof(UART_RECE_STR)
UART_RECE_STR Uart_Rece_Str = {0};
//************************************************************
//********************************************************************

//********************************************************************
//MAC解析用中间变量
uint8_t peer_addr[6];
uint8_t peer_addr_type;

//********************************************************************
//扫描回复数据
uint8 scanRspData_len = 0;

uint8_t scanRspData[32] = {
        0x0B,  
        GAP_ADTYPE_LOCAL_NAME_COMPLETE,  //ADV TYPE Complete local name
        'S','O','L','P','V','I','L','_', 'G','B',
		0x07,
		GAP_ADTYPE_MANUFACTURER_SPECIFIC,
        0,0,0,0,0,0
};


extern uint8_t advertData[32];
extern uint8_t advertData_len;
//************************************************************
//开机刷新ID数据
//************************************************************
void GetScanRspData(char *name)
{
    uint8 tempAddr=0;
    scanRspData[0] = strlen((const char*)name)+1;
    scanRspData[1] = GAP_ADTYPE_LOCAL_NAME_COMPLETE;
    sprintf((char *)&scanRspData[2],"%s",(char *)name);
      // connection interval range
    tempAddr = scanRspData[0];
    tempAddr++;

    // connection interval range
    scanRspData[tempAddr++] = 0x05; // length of this data
    scanRspData[tempAddr++] = GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE;
    scanRspData[tempAddr++] = LO_UINT16(DEFAULT_DESIRED_MIN_CONN_INTERVAL); // 100ms
    scanRspData[tempAddr++] = HI_UINT16(DEFAULT_DESIRED_MIN_CONN_INTERVAL);
    scanRspData[tempAddr++] = LO_UINT16(DEFAULT_DESIRED_MAX_CONN_INTERVAL); // 1s
    scanRspData[tempAddr++] = HI_UINT16(DEFAULT_DESIRED_MAX_CONN_INTERVAL);

    // service UUIDs
    scanRspData[tempAddr++] = 0x05; // length of this data
    scanRspData[tempAddr++] = GAP_ADTYPE_16BIT_MORE;
    scanRspData[tempAddr++] = LO_UINT16(HID_SERV_UUID);
    scanRspData[tempAddr++] = HI_UINT16(HID_SERV_UUID);
    scanRspData[tempAddr++] = LO_UINT16(BATT_SERV_UUID);
    scanRspData[tempAddr++] = HI_UINT16(BATT_SERV_UUID);

    // Tx power level
    scanRspData[tempAddr++] = 0x02; // length of this data
    scanRspData[tempAddr++] = GAP_ADTYPE_POWER_LEVEL;
    scanRspData[tempAddr++] = 0; // 0dBm

    scanRspData_len = tempAddr;
}
//************************************************************



//********************************************************************
//串口通讯数据缓存
//********************************************************************
////The buffer length should be a power of 2
//#define APP_UART_TX_BUFFER_LENGTH    512U
//#define APP_UART_RX_BUFFER_LENGTH    512U

//The tx buffer and rx buffer for app_drv_fifo
//length should be a power of 2
static uint8_t app_uart_tx_buffer[APP_UART_TX_BUFFER_LENGTH] = {0};
static uint8_t app_uart_rx_buffer[APP_UART_RX_BUFFER_LENGTH] = {0};

static app_drv_fifo_t app_uart_tx_fifo;
static app_drv_fifo_t app_uart_rx_fifo;

uint8_t app_ble_rx_buffer[APP_UART_RX_BUFFER_LENGTH] = {0};

app_drv_fifo_t app_ble_rx_fifo;
DATA_BUFF Ble_Rx_Data = {0};

DATA_BUFF Uart_Rx_Data = {0};

//interupt uart rx flag ,clear at main loop
bool uart_rx_flag = false;

//for interrupt rx blcak hole ,when uart rx fifo full
uint8_t for_uart_rx_black_hole = 0;

//fifo length less that MTU-3, retry times
uint32_t uart_to_ble_send_evt_cnt = 0;

uint8_t advData[32] = {0};

/********************宏定义：通信有限状态机状态宏定义******************/
#define STATUS_RCV_HEAD             0//状态0-接收数据包帧头1
#define STATUS_RCV_LEN              1//状态1-接收数据包数据长度
#define STATUS_RCV_SUCC             10  //接收成功
//***********************************************************************//
//int16_t Deal_Mqtt_RcCmd(const MQTT_CMD_BUFF *Rx_Buff)
//处理接受到的数据
//***********************************************************************//
int16_t Deal_UART_RcCmd(DATA_BUFF* Rx_Buff)
{
    uint8_t ret = 0; 
    if(!(Rx_Buff->Data[0]==0xBA)&&(Rx_Buff->Data[1]==0xAB)) /* 数据过滤 */
    {
        return 1;
    }

    tmos_memcpy(&Uart_Rece_Str,&Rx_Buff->Data,UART_RECE_STR_SIZE); /* 内存拷贝至接收处理结构体 */

    uint16_t crc16check = 0;
    crc16check = Get_Crc16(&Rx_Buff->Data[2],UART_RECE_STR_SIZE-4);
  
    PRINT("crc:%04X,%04X\r\n",crc16check,Uart_Rece_Str.Crc16);

    if(crc16check!=Uart_Rece_Str.Crc16)
    {
        return 0;
    }

    if(Uart_Rece_Str.Ble_Sta.Bit.Name_ConfigSta == 1) /* 蓝牙配置设置判断  */
    {
        printf("设置蓝牙名称:\r\n",Uart_Rece_Str.Ble_Name);
        for(uint8_t i = 0; i<BLE_NAME_SIZE; i++)
        {
            printf("%c",Uart_Rece_Str.Ble_Name[i]);
        }
        printf("\r\n");
        printf("设置MAC:");
        for(uint8_t i = 0; i<6; i++)
        {
            printf("%02X",Uart_Rece_Str.Ble_SelfMac[i]);
        }
        printf("\r\n");
        tmos_memcpy(Bt_Par_Act.Ble_Name,Uart_Rece_Str.Ble_Name,BLE_NAME_SIZE);
        tmos_memcpy(Bt_Par_Act.Ble_SelfMac,Uart_Rece_Str.Ble_SelfMac,6);

        uint8_t index = 0;
        
        advData[index+1] = GAP_ADTYPE_LOCAL_NAME_COMPLETE;
        tmos_memcpy(&advData[index+2],Uart_Rece_Str.Ble_Name,strlen(Uart_Rece_Str.Ble_Name));    
        advData[index] = strlen(Uart_Rece_Str.Ble_Name)+1;
        index = strlen(Uart_Rece_Str.Ble_Name)+2;
        
        advData[index+1] = GAP_ADTYPE_MANUFACTURER_SPECIFIC;
        for(int j = 0;j < 6;j++)
        {
            advData[index+2+j] = Uart_Rece_Str.Ble_SelfMac[5-j];
        } 
        advData[index] = 7;
        index += 8;
        
        advData[index] = 0x02;  // length of this data
        advData[index+1] = GAP_ADTYPE_FLAGS;
        advData[index+2] = GAP_ADTYPE_FLAGS_LIMITED | GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED;
        index +=3;

        tmos_memcpy(advertData,advData,index);
        tmos_memcpy(scanRspData,advData,index);
        
        advertData_len = index;
        scanRspData_len = index;

        if(Bt_Par_Act.Ble_Sta.Bit.Name_ConfigSta != 1)
        {
            tmos_set_event(userDevTaskId, BTSTART_EVT);
        }
        Bt_Par_Act.Ble_Sta.Bit.Name_ConfigSta = 1;
        Bt_Par_Act.Ble_Sta.Bit.Mac_ConfigSta = 1;
    }

    if(Uart_Rece_Str.Ble_Sta.Bit.BleLink_ConfigSta)
    {
        PRINT("设置蓝牙连接状态：%s\r\n",(Uart_Rece_Str.Ble_Sta.Bit.BleLink_En)?("开始连接"):("断开连接"));
        if(Uart_Rece_Str.Ble_Sta.Bit.BleLink_En != 1 )
        {
            GAPRole_TerminateLink(hidEmuConnHandle);
        }
    }
    else
    {
        PRINT("不配置蓝牙连接状态\r\n");
    }
    tmos_set_event(userDevTaskId, U0UPLOAD_EVT);
    printf("U0UPLOAD_EVT set\r\n");
    return 1;
}


//************************************************************
//串口发送进程
//************************************************************
void app_uart_process(void)
{
    UINT32 irq_status;
    SYS_DisableAllIrq(&irq_status);
    if(uart_rx_flag)
    {
        uart_rx_flag = false;

        PRINT("收到串口数据 共%d字节 %d :\r\n",Uart_Rx_Data.Long,app_uart_rx_fifo.end);
        for(uint16_t i=0;i<Uart_Rx_Data.Long ;i++)
        {
            if( i%8 == 0) PRINT("\r\n");
            PRINT("%02X ",Uart_Rx_Data.Data[i]);
        }
        PRINT("\r\n开始解析\r\n");

        if(0 == Deal_UART_RcCmd(&Uart_Rx_Data))
        {
            PRINT("不包含命令数据，转发至BLE\r\n");
            peripheralChar4Notify(Uart_Rx_Data.Data,Uart_Rx_Data.Long);
        }

        PRINT("\r\n解析结束\r\n");
    }
    SYS_RecoverIrq(irq_status);

    //tx process
    if(R8_UART0_TFC < UART_FIFO_SIZE)
    {
        app_drv_fifo_read_to_same_addr(&app_uart_tx_fifo, (uint8_t *)&R8_UART0_THR, UART_FIFO_SIZE - R8_UART0_TFC);
    }
}


//************************************************************
//串口初始化
//************************************************************
void app_uart_init()
{
    //tx fifo and tx fifo
    //The buffer length should be a power of 2
    app_drv_fifo_init(&app_uart_tx_fifo, app_uart_tx_buffer, APP_UART_TX_BUFFER_LENGTH);
    app_drv_fifo_init(&app_uart_rx_fifo, app_uart_rx_buffer, APP_UART_RX_BUFFER_LENGTH);

    app_drv_fifo_init(&app_ble_rx_fifo, app_ble_rx_buffer, APP_UART_RX_BUFFER_LENGTH);

    //uart tx io
    GPIOB_SetBits(bTXD0);
    GPIOB_ModeCfg(bTXD0, GPIO_ModeOut_PP_5mA);

    //uart rx io
    GPIOB_SetBits(bRXD0);
    GPIOB_ModeCfg(bRXD0, GPIO_ModeIN_PU);

    //uart3 init
    UART0_DefInit();

    //enable interupt
    UART0_INTCfg(ENABLE, RB_IER_RECV_RDY | RB_IER_LINE_STAT);
    PFIC_EnableIRQ(UART0_IRQn);
}

//************************************************************
//

//************************************************************
//串口发送函数
//发送fifo加载程序
//************************************************************
void app_uart_tx_data(uint8_t *data, uint16_t length)
{
    uint16_t write_length = length;
    uint8_t buf[APP_UART_RX_BUFFER_LENGTH] = {0};
    tmos_memcpy(buf,data,length);
    UART0_SendString(buf,length);
    //app_drv_fifo_write(&app_uart_tx_fifo, data, &write_length);
}
//************************************************************

//Not every uart reception will end with a UART_II_RECV_TOUT
//UART_II_RECV_TOUT can only be triggered when R8_UARTx_RFC is not 0
//Here we cannot rely UART_II_RECV_TOUT as the end of a uart reception

__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode")))
void UART0_IRQHandler(void)
{
    uint16_t error;
    uint8_t itflag = 0;
    static uint16_t p_write_length= 0;
    uint8_t index = 0;
    static uint8_t buf[100] = {0};
    itflag = UART0_GetITFlag();
    switch(itflag)
    {
        case UART_II_LINE_STAT:
            UART0_GetLinSTA();
            break;

        case UART_II_RECV_RDY:
        {
            index =  UART0_RecvString(&buf[p_write_length]);
            p_write_length += index;
            if(p_write_length==sizeof(UART_RECE_STR))
            {
                tmos_memcpy(Uart_Rx_Data.Data,buf,p_write_length);
                Uart_Rx_Data.Long = p_write_length;
                uart_rx_flag = true;
                p_write_length = 0;
                memset(buf,0,sizeof(buf));
            }
            break;
        }
        case UART_II_RECV_TOUT:
            printf("itflag:%02X\r\n",UART_II_RECV_TOUT);
            break;
        case UART_II_THR_EMPTY:
            break;
        case UART_II_MODEM_CHG:
            break;
        default:
            break;
    }
}




uint8_t userDevTaskId;

void UserDev_Init()
{
    userDevTaskId = TMOS_ProcessEventRegister(User_ProcessEvent);
}

uint16_t User_ProcessEvent(uint8_t task_id, uint16_t events)
{
//      VOID task_id; // TMOS required parameter that isn't used in this function

    if(events & SYS_EVENT_MSG)
    {
        uint8_t *pMsg;

        if((pMsg = tmos_msg_receive(userDevTaskId)) != NULL)
        {
//            Peripheral_ProcessTMOSMsg((tmos_event_hdr_t *)pMsg);
            // Release the TMOS message
            tmos_msg_deallocate(pMsg);
        }
        // return unprocessed events
        return (events ^ SYS_EVENT_MSG);
    }

    if(events & BTSTART_EVT)
    {
//        HAL_Init();
        GAPRole_PeripheralInit();
        HidDev_Init();
        Peripheral_Init();
        HidEmu_Init();
        return (events ^ BTSTART_EVT);
    }
    if(events & BTRXOK_EVT)
    {
        app_drv_fifo_read_all_new(&app_ble_rx_fifo,Ble_Rx_Data.Data,&Ble_Rx_Data.Long);
        if(Ble_Rx_Data.Long > 0)
        {
            app_uart_tx_data(Ble_Rx_Data.Data,Ble_Rx_Data.Long);
            Ble_Rx_Data.Long = 0;
        }
        tmos_stop_task(userDevTaskId,BTRXOK_EVT);
        
        return (events ^ BTRXOK_EVT);
    }
     if(events & BTDISCONNCTED)
     {
        GAPRole_TerminateLink(hidEmuConnHandle);
        tmos_stop_task(userDevTaskId,BTDISCONNCTED);
        return (events ^ BTDISCONNCTED);
     }
    if(events & U0UPLOAD_EVT)
    {
        Uart_Send_Str.Ble_Sta.Data = Bt_Par_Act.Ble_Sta.Data;
        tmos_memcpy(Uart_Send_Str.Ble_Name, Bt_Par_Act.Ble_Name, BLE_NAME_SIZE);
        tmos_memcpy(Uart_Send_Str.Ble_SelfMac, Bt_Par_Act.Ble_SelfMac, 6);
        tmos_memcpy(Uart_Send_Str.Ble_LinkMac, Bt_Par_Act.Ble_LinkMac, 6);
        Uart_Send_Str.Crc16 = Get_Crc16((uint8_t*)(&Uart_Send_Str) + 2, BT_SEND_STR_SIZE - 4);

        app_uart_tx_data((uint8_t*)&Uart_Send_Str,BT_SEND_STR_SIZE);

        tmos_stop_task(userDevTaskId,U0UPLOAD_EVT);
        return (events ^ U0UPLOAD_EVT);
    }

    if(events & LEDTASK_EVT)
    {
//        PRINT("LED TEST\r\n");
        if(Bt_Par_Act.Ble_Sta.Bit.Ble_Link_Sta == 1)
        {
            if(Bt_Par_Act.Ble_Sta.Bit.Ble_LinkMac_Sta == 1)
            {
                Bt_Par_Act.Led_Mode = LED_MODE_BOND;
            }
            else
            {
                Bt_Par_Act.Led_Mode = LED_MODE_LINK;
            }
        }
        else
        {
            Bt_Par_Act.Led_Mode = LED_MODE_INIT;
        }
        switch(Bt_Par_Act.Led_Mode)
        {
            default : Bt_Par_Act.Led_Mode = LED_MODE_INIT;
            break;
            case LED_MODE_INIT:
            {
                if(IS_LED0_ON())
                {
                    LED0_OFF;
                    tmos_start_task(userDevTaskId,LEDTASK_EVT,1600);
                }
                else
                {
                    LED0_ON;
                    tmos_start_task(userDevTaskId,LEDTASK_EVT,160);
                }
            }
            break;
            case LED_MODE_LINK:
            {
                if(IS_LED0_ON())
                {
                    LED0_OFF;
                    tmos_start_task(userDevTaskId,LEDTASK_EVT,800);
                }
                else
                {
                    LED0_ON;
                    tmos_start_task(userDevTaskId,LEDTASK_EVT,160);
                }
            }
            break;
            case LED_MODE_BOND:
            {
                if(IS_LED0_ON())
                {
                    LED0_OFF;
                    tmos_start_task(userDevTaskId,LEDTASK_EVT,320);
                }
                else
                {
                    LED0_ON;
                    tmos_start_task(userDevTaskId,LEDTASK_EVT,160);
                }
            }
            break;
        }
        return (events ^ LEDTASK_EVT);
    }
    if(events & BTSTOR_EVT)
    {
//        // Start the Device
//        PRINT("\r\n*****************************\r\n");
//        PRINT("ERASE DATA\r\n");
//        FLASH_ROM_ERASE(BLE_STOR_ADDR,EEPROM_MIN_ER_SIZE);
//
//        tmos_memcpy(Bt_Stor_Act.Ble_Name, Bt_Par_Act.Ble_Name, BLE_NAME_SIZE);
//        Bt_Stor_Act.Crc16 = Get_Crc16((uint8_t*)&Bt_Stor_Act, sizeof(Bt_Stor_Act) - 2);
//
//        PRINT("WRITE DATA Bt_Stor %d byte:",sizeof(Bt_Stor_Act));
//        PRINT("Ble_Name:%32s\r\n",Bt_Par_Act.Ble_Name);
//        PRINT("Crc16:%d\r\n",Bt_Stor_Act.Crc16);
//        EEPROM_WRITE(BLE_STOR_ADDR, &Bt_Stor_Act, sizeof(Bt_Stor_Act));
//
//        PRINT("READ DATA Bt_Stor %d byte:",sizeof(Bt_Stor_Act));
//        EEPROM_READ(BLE_STOR_ADDR, &Bt_Stor_Act, sizeof(Bt_Stor_Act));
//        PRINT("Ble_Name:%32s\r\n",Bt_Stor_Act.Ble_Name);
//        PRINT("Crc16:%d\r\n",Bt_Stor_Act.Crc16);
//        PRINT("\r\n*****************************\r\n");
//        tmos_stop_task(userDevTaskId,BTSTOR_EVT);
        return (events ^ BTSTOR_EVT);
    }
    // Discard unknown events
    return 0;
}

void Init_GPIO(void)
{
    LED0_ON;
    LED0_INIT;
    tmos_set_event(userDevTaskId,LEDTASK_EVT);

    BTSTAOUT_UNLINK;
    BTSTAOUT_INIT;

}


/* 等待串口配置蓝牙模块mac地址和名称 */
void ble_module_cfg(void)
{
    Uart_Send_Str.Ble_Sta.Data = Bt_Par_Act.Ble_Sta.Data;
    tmos_memcpy(Uart_Send_Str.Ble_Name, Bt_Par_Act.Ble_Name, BLE_NAME_SIZE);
    tmos_memcpy(Uart_Send_Str.Ble_SelfMac, Bt_Par_Act.Ble_SelfMac, 6);
    tmos_memcpy(Uart_Send_Str.Ble_LinkMac, Bt_Par_Act.Ble_LinkMac, 6);
    Uart_Send_Str.Crc16 = Get_Crc16((uint8_t*)(&Uart_Send_Str) + 2, BT_SEND_STR_SIZE - 4);

    app_uart_tx_data((uint8_t*)&Uart_Send_Str,BT_SEND_STR_SIZE);
    while(1)
    {
        app_uart_process();
        if(Bt_Par_Act.Ble_Sta.Bit.Name_ConfigSta == 1&&Bt_Par_Act.Ble_Sta.Bit.Mac_ConfigSta == 1)
        {
            break;
        }
    }
}
/*********************************************************************
*********************************************************************/
