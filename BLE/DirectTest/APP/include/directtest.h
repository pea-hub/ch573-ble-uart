/********************************** (C) COPYRIGHT *******************************
 * File Name          : directtest..h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2018/12/11
 * Description        :
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef TEST_H
#define TEST_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * FUNCTIONS
 */
#define TEST_EVENT    1

extern void TEST_Init(void);

extern tmosEvents TEST_ProcessEvent(tmosTaskID task_id, tmosEvents events);

/*******************************************************************************
 * @fn          API_LE_ReceiverTestCmd API
 *
 * @brief       used to start a test where the DUT generates test reference packets at a fixed interval
 *
 * input parameters
 *
 * @param       tx_channel - RF channel(0-39)
 *              len        - 测试数据包长度(1-255)
 *              payload    - 测试的数据类型(0-7),8种数据类型。
 *                           0：PRBS9       1：全部为0xF0  2：全部为0xAA  3：PRBS15
 *                           4：全部为0xFF  5：全部为0x00  6：全部为0x0F  7：全部为0x55
 *              tx_power   - bit0~5: 测试的发送功率（1-31）对应（-20dBM至5dBm）
 *                           bit7: 1-关白化(接入地址0x71764129);0-开白化(接入地址0x8E86BED9)
 *
 * output parameters
 *
 * @param       None
 *
 * @return      Command Status.
 *
 * Command Complete event
 */
extern uint8_t API_LE_TransmitterTestCmd(uint8_t tx_channel, uint8_t len, uint8_t payload, uint8_t tx_power);

/*******************************************************************************
 * @fn          API_LE_TestEndCmd API
 *
 * @brief       used to stop any test which is in progress
 *
 * input parameters
 *
 * @param       None
 *
 * output parameters
 *
 * @param       None
 *
 * @return      Command Status.
 *
 * Command Complete event
 */
extern uint8_t API_LE_TestEndCmd(void);

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif
