/********************************** (C) COPYRIGHT *******************************
 * File Name          : peripheral.C
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2018/12/10
 * Description        : ����ӻ�������Ӧ�ó��򣬳�ʼ���㲥���Ӳ�����Ȼ��㲥������������
 *                      ����������Ӳ�����ͨ���Զ������������
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

#include "app_drv_fifo.h"

/*********************************************************************
 * MACROS
 */


/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */
//uint8_t Peripheral_TaskID = 0x5A;// Task ID for internal task/event processing

// GAP - SCAN RSP data (max size = 31 bytes)

// GAP GATT Attributes
// Connection item list
//static peripheralConnItem_t peripheralConnList;

//static uint8_t peripheralMTU = ATT_MTU_SIZE;
/*********************************************************************
 * LOCAL FUNCTIONS
 */
//static void Peripheral_ProcessTMOSMsg(tmos_event_hdr_t *pMsg);
//static void peripheralStateNotificationCB(gapRole_States_t newState, gapRoleEvent_t *pEvent);
static void performPeriodicTask(void);
static void simpleProfileChangeCB(uint8_t paramID, uint8_t *pValue, uint16_t len);
//static void peripheralParamUpdateCB(uint16_t connHandle, uint16_t connInterval,
//                                    uint16_t connSlaveLatency, uint16_t connTimeout);
static void peripheralInitConnItem(peripheralConnItem_t *peripheralConnList);
//static void peripheralRssiCB(uint16_t connHandle, int8_t rssi);

void peripheralChar4Notify(uint8_t *pValue, uint16_t len);

/*********************************************************************
 * PROFILE CALLBACKS
 */

// GAP Role Callbacks
//static gapRolesCBs_t Peripheral_PeripheralCBs = {
//    peripheralStateNotificationCB, // Profile State Change Callbacks
//    peripheralRssiCB,              // When a valid RSSI is read from controller (not used by application)
//    peripheralParamUpdateCB
//};

// Broadcast Callbacks
static gapRolesBroadcasterCBs_t Broadcaster_BroadcasterCBs = {
    NULL, // Not used in peripheral role
    NULL  // Receive scan request callback
};

// GAP Bond Manager Callbacks
static gapBondCBs_t Peripheral_BondMgrCBs = {
    NULL, // Passcode callback (not used by application)
    NULL  // Pairing / Bonding state Callback (not used by application)
};

// Simple GATT Profile Callbacks
static simpleProfileCBs_t Peripheral_SimpleProfileCBs = {
    simpleProfileChangeCB // Characteristic value change callback
};
/*********************************************************************
 * PUBLIC FUNCTIONS
 */

/*********************************************************************
 * @fn      Peripheral_Init
 *
 * @brief   Initialization function for the Peripheral App Task.
 *          This is called during initialization and should contain
 *          any application specific initialization (ie. hardware
 *          initialization/setup, table initialization, power up
 *          notificaiton ... ).
 *
 * @param   task_id - the ID assigned by TMOS.  This ID should be
 *                    used to send messages and set timers.
 *
 * @return  none
 */
void Peripheral_Init()
{
//    Peripheral_TaskID = TMOS_ProcessEventRegister(Peripheral_ProcessEvent);

//    // Setup the GAP Peripheral Role Profile
//    {
//        uint8_t  initial_advertising_enable = TRUE;
//        uint16_t desired_min_interval = DEFAULT_DESIRED_MIN_CONN_INTERVAL;
//        uint16_t desired_max_interval = DEFAULT_DESIRED_MAX_CONN_INTERVAL;
//
//        // Set the GAP Role Parameters
//        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t), &initial_advertising_enable);
//        GAPRole_SetParameter(GAPROLE_SCAN_RSP_DATA, sizeof(scanRspData), scanRspData);
//        GAPRole_SetParameter(GAPROLE_ADVERT_DATA, sizeof(advertData), advertData);
//        GAPRole_SetParameter(GAPROLE_MIN_CONN_INTERVAL, sizeof(uint16_t), &desired_min_interval);
//        GAPRole_SetParameter(GAPROLE_MAX_CONN_INTERVAL, sizeof(uint16_t), &desired_max_interval);
//    }

    // Set the GAP Characteristics
//    GGS_SetParameter(GGS_DEVICE_NAME_ATT, GAP_DEVICE_NAME_LEN, attDeviceName);

    // Set advertising interval
//    {
//        uint16_t advInt = DEFAULT_ADVERTISING_INTERVAL;
//
//        GAP_SetParamValue(TGAP_DISC_ADV_INT_MIN, advInt);
//        GAP_SetParamValue(TGAP_DISC_ADV_INT_MAX, advInt);
//    }

//    // Setup the GAP Bond Manager
//    {
//        uint32_t passkey = 0; // passkey "000000"
//        uint8_t  pairMode = GAPBOND_PAIRING_MODE_WAIT_FOR_REQ;
//        uint8_t  mitm = TRUE;
//        uint8_t  bonding = TRUE;
//        uint8_t  ioCap = GAPBOND_IO_CAP_DISPLAY_ONLY;
//        GAPBondMgr_SetParameter(GAPBOND_PERI_DEFAULT_PASSCODE, sizeof(uint32_t), &passkey);
//        GAPBondMgr_SetParameter(GAPBOND_PERI_PAIRING_MODE, sizeof(uint8_t), &pairMode);
//        GAPBondMgr_SetParameter(GAPBOND_PERI_MITM_PROTECTION, sizeof(uint8_t), &mitm);
//        GAPBondMgr_SetParameter(GAPBOND_PERI_IO_CAPABILITIES, sizeof(uint8_t), &ioCap);
//        GAPBondMgr_SetParameter(GAPBOND_PERI_BONDING_ENABLED, sizeof(uint8_t), &bonding);
//    }

    // Initialize GATT attributes
//    GGS_AddService(GATT_ALL_SERVICES);           // GAP
//    GATTServApp_AddService(GATT_ALL_SERVICES);   // GATT attributes
//    DevInfo_AddService();                        // Device Information Service
    SimpleProfile_AddService(GATT_ALL_SERVICES); // Simple GATT Profile

    // Setup the SimpleProfile Characteristic Values
    {
        uint8_t charValue1[SIMPLEPROFILE_CHAR1_LEN] = {1};
        uint8_t charValue2[SIMPLEPROFILE_CHAR2_LEN] = {2};
        uint8_t charValue3[SIMPLEPROFILE_CHAR3_LEN] = {3};
        uint8_t charValue4[SIMPLEPROFILE_CHAR4_LEN] = {4};
        uint8_t charValue5[SIMPLEPROFILE_CHAR5_LEN] = {1, 2, 3, 4, 5};

        SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR1, SIMPLEPROFILE_CHAR1_LEN, charValue1);
        SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR2, SIMPLEPROFILE_CHAR2_LEN, charValue2);
        SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR3, SIMPLEPROFILE_CHAR3_LEN, charValue3);
        SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR4, SIMPLEPROFILE_CHAR4_LEN, charValue4);
        SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR5, SIMPLEPROFILE_CHAR5_LEN, charValue5);
    }

    // Init Connection Item
//    peripheralInitConnItem(&peripheralConnList);

    // Register callback with SimpleGATTprofile
    SimpleProfile_RegisterAppCBs(&Peripheral_SimpleProfileCBs);

    // Register receive scan request callback
//    GAPRole_BroadcasterSetCB(&Broadcaster_BroadcasterCBs);

    // Setup a delayed profile startup
//    tmos_set_event(Peripheral_TaskID, SBP_PERIODIC_EVT);
}

/*********************************************************************
 * @fn      peripheralInitConnItem
 *
 * @brief   Init Connection Item
 *
 * @param   peripheralConnList -
 *
 * @return  NULL
 */
//static void peripheralInitConnItem(peripheralConnItem_t *peripheralConnList)
//{
//    peripheralConnList->connHandle = GAP_CONNHANDLE_INIT;
//    peripheralConnList->connInterval = 0;
//    peripheralConnList->connSlaveLatency = 0;
//    peripheralConnList->connTimeout = 0;
//}

/*********************************************************************
 * @fn      Peripheral_ProcessEvent
 *
 * @brief   Peripheral Application Task event processor.  This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id - The TMOS assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  events not processed
 */
//uint16_t Peripheral_ProcessEvent(uint8_t task_id, uint16_t events)
//{
    //  VOID task_id; // TMOS required parameter that isn't used in this function

//    if(events & SYS_EVENT_MSG)
//    {
//        uint8_t *pMsg;
//
//        if((pMsg = tmos_msg_receive(Peripheral_TaskID)) != NULL)
//        {
//            Peripheral_ProcessTMOSMsg((tmos_event_hdr_t *)pMsg);
//            // Release the TMOS message
//            tmos_msg_deallocate(pMsg);
//        }
//        // return unprocessed events
//        return (events ^ SYS_EVENT_MSG);
//    }

//    if(events & BTSTOR_EVT)
//    {
//        // Start the Device
//
//        printf("\r\n*****************************\r\n");
//        printf("ERASE DATA\r\n");
//        FLASH_ROM_ERASE(BLE_STOR_ADDR,EEPROM_MIN_ER_SIZE);
//
//        tmos_memcpy(Bt_Stor_Act.Ble_Name, Bt_Par_Act.Ble_Name, BLE_NAME_SIZE);
//        Bt_Stor_Act.Crc16 = Get_Crc16((uint8_t*)&Bt_Stor_Act, sizeof(Bt_Stor_Act) - 2);
//
//        printf("WRITE DATA Bt_Stor %d byte:",sizeof(Bt_Stor_Act));
//        printf("Ble_Name:%32s\r\n",Bt_Stor_Act.Ble_Name);
//        printf("Crc16:%d\r\n",Bt_Stor_Act.Crc16);
//        EEPROM_WRITE(BLE_STOR_ADDR, &Bt_Stor_Act, sizeof(Bt_Stor_Act));
//
//        printf("READ DATA Bt_Stor %d byte:",sizeof(Bt_Stor_Act));
//        EEPROM_READ(BLE_STOR_ADDR, &Bt_Stor_Act, sizeof(Bt_Stor_Act));
//        printf("Ble_Name:%32s\r\n",Bt_Stor_Act.Ble_Name);
//        printf("Crc16:%d\r\n",Bt_Stor_Act.Crc16);
//        printf("\r\n*****************************\r\n");
//        return (events ^ BTSTOR_EVT);
//    }

//    if(events & SBP_PERIODIC_EVT)
//    {
//        // Restart timer
////        if(SBP_PERIODIC_EVT_PERIOD)
////        {
////            tmos_start_task(Peripheral_TaskID, SBP_PERIODIC_EVT, SBP_PERIODIC_EVT_PERIOD);
////        }
//        // Perform periodic application task
//        performPeriodicTask();
//
//        return (events ^ SBP_PERIODIC_EVT);
//    }

//    if(events & SBP_PARAM_UPDATE_EVT)
//    {
//        // Send connect param update request
//        GAPRole_PeripheralConnParamUpdateReq(peripheralConnList.connHandle,
//                                             DEFAULT_DESIRED_MIN_CONN_INTERVAL,
//                                             DEFAULT_DESIRED_MAX_CONN_INTERVAL,
//                                             DEFAULT_DESIRED_SLAVE_LATENCY,
//                                             DEFAULT_DESIRED_CONN_TIMEOUT,
//                                             Peripheral_TaskID);
//
//        return (events ^ SBP_PARAM_UPDATE_EVT);
//    }

//    if(events & SBP_READ_RSSI_EVT)
//    {
//        GAPRole_ReadRssiCmd(peripheralConnList.connHandle);
//        tmos_start_task(Peripheral_TaskID, SBP_READ_RSSI_EVT, SBP_READ_RSSI_EVT_PERIOD);
//        return (events ^ SBP_READ_RSSI_EVT);
//    }

    // Discard unknown events
//    return 0;
//}

/*********************************************************************
 * @fn      Peripheral_ProcessTMOSMsg
 *
 * @brief   Process an incoming task message.
 *
 * @param   pMsg - message to process
 *
 * @return  none
 */
//static void Peripheral_ProcessTMOSMsg(tmos_event_hdr_t *pMsg)
//{
//    switch(pMsg->event)
//    {
//        case GAP_MSG_EVENT:
//        {
//            break;
//        }
//
//        case GATT_MSG_EVENT:
//        {
//            gattMsgEvent_t *pMsgEvent;
//
//            pMsgEvent = (gattMsgEvent_t *)pMsg;
//            if(pMsgEvent->method == ATT_MTU_UPDATED_EVENT)
//            {
//                peripheralMTU = pMsgEvent->msg.exchangeMTUReq.clientRxMTU;
//                PRINT("mtu exchange: %d\n", pMsgEvent->msg.exchangeMTUReq.clientRxMTU);
//            }
//            break;
//        }
//
//        default:
//            break;
//    }
//}
/*********************************************************************
 * @fn      performPeriodicTask
 *
 * @brief   Perform a periodic application task. This function gets
 *          called every five seconds as a result of the SBP_PERIODIC_EVT
 *          TMOS event. In this example, the value of the third
 *          characteristic in the SimpleGATTProfile service is retrieved
 *          from the profile, and then copied into the value of the
 *          the fourth characteristic.
 *
 * @param   none
 *
 * @return  none
 */
//static void performPeriodicTask(void)
//{
//    uint8_t notiData[SIMPLEPROFILE_CHAR4_LEN];
////    extern void tmos_memcpy( void *dst, const void *src, uint32_t len );
//    tmos_memcpy((void*)notiData,(const void*)&Uart_Send_Str,sizeof(Uart_Send_Str));
//    peripheralChar4Notify(notiData, sizeof(Uart_Send_Str));
////    UART0_SendString(notiData,sizeof(Uart_Send_Str));
//}

/*********************************************************************
 * @fn      peripheralChar4Notify
 *
 * @brief   Prepare and send simpleProfileChar4 notification
 *
 * @param   pValue - data to notify
 *          len - length of data
 *
 * @return  none
 */
extern uint16_t gapConnHandle;
extern gapRole_States_t hidDevGapState;
void peripheralChar4Notify(uint8_t *pValue, uint16_t len)
{
    attHandleValueNoti_t noti;
    uint16_t data_addr = 0;
    uint16_t data_less_len = len;
//    if(len > (peripheralMTU - 3))
//    {
//        PRINT("Too large noti %d/%d\n",len,peripheralMTU - 3);
//        return;
//    }
    data_addr = 0;
    data_less_len = len;
    if(hidDevGapState == GAPROLE_CONNECTED)
    {
        while(data_less_len > 0)
        {
            if(data_less_len > 20)
            {
                noti.len = 20;
            }
            else
            {
                noti.len = data_less_len;
            }
            noti.pValue = GATT_bm_alloc(gapConnHandle, ATT_HANDLE_VALUE_NOTI, noti.len, NULL, 0);
            if(noti.pValue)
            {
                tmos_memcpy(noti.pValue, pValue, noti.len);
                if(simpleProfile_Notify(gapConnHandle, &noti) != SUCCESS)
                {
                    GATT_bm_free((gattMsg_t *)&noti, ATT_HANDLE_VALUE_NOTI);
                }
                data_less_len -=noti.len;
                data_addr += noti.len;
            }
        }
    }
}

/*********************************************************************
 * @fn      simpleProfileChangeCB
 *
 * @brief   Callback from SimpleBLEProfile indicating a value change
 *
 * @param   paramID - parameter ID of the value that was changed.
 *          pValue - pointer to data that was changed
 *          len - length of data
 *
 * @return  none
 */
static void simpleProfileChangeCB(uint8_t paramID, uint8_t *pValue, uint16_t len)
{
    switch(paramID)
    {
        case SIMPLEPROFILE_CHAR1:
        {
            uint8_t newValue[SIMPLEPROFILE_CHAR1_LEN];
            tmos_stop_task( userDevTaskId, BTRXOK_EVT );

            tmos_memcpy(newValue, pValue, len);
            PRINT("profile ChangeCB CHAR1 %d byte\r\n",len);
            app_drv_fifo_write(&app_ble_rx_fifo,pValue,&len);

            tmos_start_task(userDevTaskId, BTRXOK_EVT,50);

            tmos_start_task(userDevTaskId,BTDISCONNCTED,100);

            break;
        }

        case SIMPLEPROFILE_CHAR3:
        {
            uint8_t newValue[SIMPLEPROFILE_CHAR3_LEN];
            tmos_memcpy(newValue, pValue, len);
            PRINT("profile ChangeCB CHAR3..\n");
            break;
        }

        default:
            // should not reach here!
            break;
    }
}

/*********************************************************************
*********************************************************************/
