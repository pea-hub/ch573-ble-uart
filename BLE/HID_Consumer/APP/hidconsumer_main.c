/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : ����������Ӧ��������������ϵͳ��ʼ��
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

/******************************************************************************/
/* ͷ�ļ����� */
#include "CONFIG.h"
#include "HAL.h"
#include "hiddev.h"
#include "hidconsumer.h"

#include "gattprofile.h"
#include "peripheral.h"

#include "UserCode.h"
#include "Parmeter.h"

#include "UserCode.h"

#include "ISP573.h"

#include "Parmeter.h"

/*********************************************************************
 * GLOBAL TYPEDEFS
 */
__attribute__((aligned(4))) uint32_t MEM_BUF[BLE_MEMHEAP_SIZE / 4];

#if(defined(BLE_MAC)) && (BLE_MAC == TRUE)
const uint8_t MacAddr[6] = {0x84, 0xC2, 0xE4, 0x03, 0x02, 0x02};
#endif

/*********************************************************************
 * @fn      Main_Circulation
 *
 * @brief   ��ѭ��
 *
 * @return  none
 */
__attribute__((section(".highcode")))
void Main_Circulation()
{
    while(1)
    {
        TMOS_SystemProcess();
        app_uart_process();
    }
}

/*********************************************************************
 * @fn      main
 *
 * @brief   ������
 *
 * @return  none
 */
int main(void)
{
#if(defined(DCDC_ENABLE)) && (DCDC_ENABLE == TRUE)
    PWR_DCDCCfg(ENABLE);
#endif
    SetSysClock(CLK_SOURCE_PLL_60MHz);
#if(defined(HAL_SLEEP)) && (HAL_SLEEP == TRUE)
    GPIOA_ModeCfg(GPIO_Pin_All, GPIO_ModeIN_PU);
    GPIOB_ModeCfg(GPIO_Pin_All, GPIO_ModeIN_PU);
#endif
#ifdef DEBUG
    GPIOA_SetBits(bTXD1);
    GPIOA_ModeCfg(bTXD1, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
#endif
    app_uart_init();

//    GetScanRspData(Bt_Par_Act.Ble_Name);
      ble_module_cfg();
      CH57X_BLEInit();
//    GetMACAddress(Bt_Par_Act.Ble_SelfMac);

//    EEPROM_READ(BLE_STOR_ADDR, &Bt_Stor_Act, sizeof(Bt_Stor_Act));

      HAL_Init();
//    GAPRole_PeripheralInit();
//    HidDev_Init();
//    Peripheral_Init();
//    HidEmu_Init();

    UserDev_Init();
    printf("BTSTART_EVT set\r\n");
    tmos_set_event(userDevTaskId, BTSTART_EVT);
    tmos_set_event(userDevTaskId, U0UPLOAD_EVT);
    printf("U0UPLOAD_EVT set\r\n");
//    app_uart_tx_data("BLE POWER ON\r\n",14);
    Init_GPIO();
    
    Main_Circulation();
}

/******************************** endfile @ main ******************************/
