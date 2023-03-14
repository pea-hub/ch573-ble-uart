/********************************** (C) COPYRIGHT *******************************
 * File Name          : peripheral.h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2018/12/11
 * Description        :
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef PARMETER_H
#define PARMETER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * INCLUDES
 */
#include "app_drv_fifo.h"


//***********************************************************
//任务调度定义
//***********************************************************
extern uint8_t userDevTaskId;
#define BTSTOR_EVT   0x0001     //储存蓝牙参数    **未使用
#define BTRXOK_EVT   0x0002     //蓝牙接收
#define BTSTART_EVT  0x0004     //蓝牙配置
#define U0UPLOAD_EVT  0x0008    //串口上传发送
#define BT2U0_EVT   0x0010      //蓝牙透传数据发送任务
#define LEDTASK_EVT   0x0020      //LED运行任务
#define BTDISCONNCTED 0x0022     // 关闭当前蓝牙连接



//***********************************************************
//IO口定义
//***********************************************************
//#define LED_PORT    B
#define LED0_PIN    (1<<12)
#define LED0_ON     GPIOB_SetBits(LED0_PIN)
#define LED0_OFF    GPIOB_ResetBits(LED0_PIN)
#define LED0_TOG    GPIOB_InverseBits(LED0_PIN)
#define LED0_INIT   GPIOB_ModeCfg(LED0_PIN,GPIO_ModeOut_PP_20mA)
#define IS_LED0_ON() (GPIOB_ReadPortPin(LED0_PIN)? 1: 0)

//#define LED_PORT    B
#define BTSTAOUT_PIN    (1<<11)
#define BTSTAOUT_LINK     GPIOB_ResetBits(BTSTAOUT_PIN)
#define BTSTAOUT_UNLINK   GPIOB_SetBits(BTSTAOUT_PIN)
#define BTSTAOUT_TOG    GPIOB_InverseBits(BTSTAOUT_PIN)
#define BTSTAOUT_INIT   GPIOB_ModeCfg(BTSTAOUT_PIN,GPIO_ModeOut_PP_5mA)
//#define IS_BTSTAOUT_ON() (GPIOB_ReadPortPin(LED0_PIN)? 0: 1)

//***********************************************************
//内部flash地址定义
//***********************************************************
#define BLE_STOR_ADDR 0x77C00-FLASH_ROM_MAX_SIZE

#define BLE_NAME_SIZE 32        //设备名称最大长度
#define DEVICE_NAME_DEF "AC PILE DEF"
#define DEVICE_TYPE_NAME "AC PILE"


//***********************************************************
//数据缓存定义
//***********************************************************
//The buffer length should be a power of 2
#define APP_UART_TX_BUFFER_LENGTH    512U
#define APP_UART_RX_BUFFER_LENGTH    512U

#define DATA_BUFF_SIZE    512U

typedef struct {
    uint16_t Long;                                  //数据长度
    uint8_t Data[DATA_BUFF_SIZE];   //数据缓冲区
}DATA_BUFF;
extern DATA_BUFF Uart_Rx_Data;


extern app_drv_fifo_t app_ble_rx_fifo;
extern DATA_BUFF Ble_Rx_Data;


//***********************************************************
//HID设备数据长度定义
//***********************************************************
// HID consumer input report length
#define HID_CONSUMER_IN_RPT_LEN              2


/*********************************************************************
 * CONSTANTS
 */
// Param update delay
#define START_PARAM_UPDATE_EVT_DELAY         12800

// HID idle timeout in msec; set to zero to disable timeout
#define DEFAULT_HID_IDLE_TIMEOUT             60000

// Minimum connection interval (units of 1.25ms)
#define DEFAULT_DESIRED_MIN_CONN_INTERVAL    8

// Maximum connection interval (units of 1.25ms)
#define DEFAULT_DESIRED_MAX_CONN_INTERVAL    8

// Slave latency to use if parameter update request
#define DEFAULT_DESIRED_SLAVE_LATENCY        0

// Supervision timeout value (units of 10ms)
#define DEFAULT_DESIRED_CONN_TIMEOUT         500

// Default passcode
#define DEFAULT_PASSCODE                     0

// Default GAP pairing mode
#define DEFAULT_PAIRING_MODE                 GAPBOND_PAIRING_MODE_WAIT_FOR_REQ

// Default MITM mode (TRUE to require passcode or OOB when pairing)
#define DEFAULT_MITM_MODE                    FALSE

// Default bonding mode, TRUE to bond
#define DEFAULT_BONDING_MODE                 TRUE

// Default GAP bonding I/O capabilities
#define DEFAULT_IO_CAPABILITIES              GAPBOND_IO_CAP_NO_INPUT_NO_OUTPUT

// Battery level is critical when it is less than this %
#define DEFAULT_BATT_CRITICAL_LEVEL          6

/*********************************************************************
 * CONSTANTS
 */
//*************************************************************************
extern uint16_t hidEmuConnHandle;
extern uint8 scanRspData_len;
extern uint8_t scanRspData[];
//*************************************************************************

//*************************************************************************
extern uint8_t peer_addr[6];
extern uint8_t peer_addr_type;
//*************************************************************************

//*************************************************************************
extern void GetScanRspData(char *name);
//*************************************************************************

//*************************************************************************
//运行状态数据结构体
//*************************************************************************
#pragma pack (1) // 指定结构体按照1字节对齐
typedef struct {
    uint8_t Link_Sta;
    uint8_t Link_Type;
#pragma pack (1) // 指定结构体按照1字节对齐
    union {
        uint16_t Data;                 //数据帧长度uint16_t     数据帧长度uint16_t   数据帧长度
        struct {
            uint16_t Name_ConfigSta  :1;         //设置名称状态：0：未设置名称    1：已设置名称
            uint16_t Mac_ConfigSta   :1;         //设置MAC状态：0：未设置MAC   1：已设置MAC
            uint16_t Ble_Link_Sta    :1;         //Ble连接状态
            uint16_t Ble_LinkMac_Sta :1;         //MAC解析状态 ]:0:Mac未解析 1:Mac已经解析
        }Bit;
    }Ble_Sta;
#pragma pack () // 指定结构体按照1字节对齐
    char Ble_Name[BLE_NAME_SIZE];        //已经设置的名称
    uint8_t Ble_SelfMac[6];              //已经设置的MAC
    uint8_t Ble_LinkMac[6];              //已经连接的MAC

    uint8_t Led_Mode;
#define LED_MODE_INIT 0x00  //初始化
#define LED_MODE_LINK 0x01  //已连接
#define LED_MODE_BOND 0x02  //已连接绑定

}BT_PAR;
#pragma pack () // 指定结构体按照1字节对齐

//*************************************************************************
extern BT_PAR Bt_Par_Act;
//*************************************************************************

//*************************************************************************
#pragma pack (1) // 指定结构体按照1字节对齐
typedef struct {
    char Ble_Name[BLE_NAME_SIZE];        //已经设置的名称
    uint8_t mac[6];                      //已经设置的Mac地址
    uint16_t    Crc16;                   //数据校验  数据校验
}BT_STOR;
#pragma pack (0) // 指定结构体按照1字节对齐
extern BT_STOR Bt_Stor_Act;
//*************************************************************************
//串口通讯相关结构体
//*************************************************************************

//*************************************************************************
//通讯相关结构体
//*************************************************************************
//************************************************************
//蓝牙数据发送结构体
//************************************************************
#pragma pack (1) // 指定结构体按照1字节对齐
typedef struct {
    uint8_t     HeaderCode[2]   ;       //帧头(0x5A,0xA5)uint8_t[2]   帧头(0x6A,0xA6)uint8_t[2] 帧头(0x6A,0xA6)
#pragma pack (1) // 指定结构体按照1字节对齐
    union {
        uint16_t Data;                 //数据帧长度uint16_t     数据帧长度uint16_t   数据帧长度
        struct {
            uint16_t Name_ConfigSta  :1;         //设置名称状态：0：未设置名称    1：已设置名称
            uint16_t Mac_ConfigSta   :1;         //设置MAC状态：0：未设置MAC   1：已设置MAC
            uint16_t Ble_Link_Sta    :1;         //Ble连接状态
            uint16_t Ble_LinkMac_Sta :1;         //MAC解析状态 ]:0:Mac未解析 1:Mac已经解析
        }Bit;
    }Ble_Sta;
#pragma pack () // 指定结构体按照1字节对齐
    char Ble_Name[BLE_NAME_SIZE];        //已经设置的名称
    uint8_t Ble_SelfMac[6];              //已经设置的MAC
    uint8_t Ble_LinkMac[6];              //已经连接的MAC
    uint16_t      Crc16;                      //数据校验  数据校验
}UART_SEND_STR;
#pragma pack () // 指定结构体按照1字节对齐

#define BT_SEND_STR_SIZE sizeof(UART_SEND_STR)
extern UART_SEND_STR Uart_Send_Str;
//************************************************************


//************************************************************
//蓝牙数据接收结构体
//************************************************************
#pragma pack (1) // 指定结构体按照1字节对齐
typedef struct {
    uint8_t     HeaderCode[2]   ;       //帧头(0xBA,0xAB)uint8_t[2]   帧头(0x6A,0xA6)uint8_t[2] 帧头(0x6A,0xA6)
#pragma pack (1) // 指定结构体按照1字节对齐
    union {
        uint16_t Data;                 //
        struct {
            uint16_t Name_ConfigSta  :1;         //设置状态：0：不设置名称    1：要设置名称
            uint16_t BleLink_ConfigSta:1;        //0:不允许设置连接状态 1:允许设置连接状态
            uint16_t BleLink_En       :1;        //0:设置开始连接 1:设置关闭连接
            uint16_t Mac_ConfigSta   :1;         //设置MAC状态：0：不设置MAC   1：要设置MAC
        }Bit;
    }Ble_Sta;
#pragma pack () // 指定结构体按照1字节对齐
    char Ble_Name[BLE_NAME_SIZE];        //已经设置的名称
    uint8_t Ble_SelfMac[6];              //已经设置的MAC
//    uint8_t Ble_LinkMac[6];              //已经连接的MAC
    uint16_t      Crc16;                      //数据校验  数据校验
}UART_RECE_STR;
#pragma pack () // 指定结构体按照1字节对齐

#define UART_RECE_STR_SIZE sizeof(UART_RECE_STR)
extern UART_RECE_STR Uart_Rece_Str;
//************************************************************
//*************************************************************************



//**********************************************//
//uint16_t Get_Crc16(uint8_t *addr,uint16_t num)
//计算CRC16校验值
//*addr待校验的数据
//num待校验的数据长度
//return CRC16值
//**********************************************//
static __inline uint16_t Get_Crc16(uint8_t *addr,uint16_t num)
{
    uint16_t i,j,temp;
    uint16_t crc=0xFFFF;
    for(i=0;i<num;i++)
    {
        crc=crc^(*addr);
        for(j=0;j<8;j++)
        {
            temp=crc&0x0001;
            crc=crc>>1;
            if(temp)
            {
                crc=crc^0xA001;
            }
        }
        addr++;
    }
    return crc;
}

#ifdef __cplusplus
}
#endif

#endif
