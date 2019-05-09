/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   mmi_rp_srv_iot_lock_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource populate function generated by XML resgen
 *
 * Author:
 * -------
 *   MTK resgenerator XML parser
 *
 *******************************************************************************/


#ifndef _MMI_RP_SRV_IOT_LOCK_DEF_H
#define _MMI_RP_SRV_IOT_LOCK_DEF_H




/******************** Timer resource IDs - begin ********************/
typedef enum
{
    BOOTUP_LED_BEEP_TIMER = 30285 + 1, /* BASE_ID + 1 */
    LOCK_KICK_DOG_TIMER,
    BLE_BKSS_CONNECTED_TIMER,
    BLE_BKSS_TIMER,
    BLE_BKSS_VIB_TIMER,
    BLE_BKSS_OPEN_TIMER,
    BLE_BKSS_OPEN_TIMER2,
    BLE_BKSS_CLOSE_TIMER,
    LOCK_REG_TIMER,
    LOCK_AUTH_TIMER,
    LOCK_HEART_BEAT_TIMER,
    LOCK_HEART_TIMEOUT_TIMER,
    LOCK_GPS_ON_TIMER,
    LOCK_GPS_UPDATE_TIMER,
    LOCK_GPS_CTL_TIMER,
    LOCK_GPS_STOP_TIMER,
    LOCK_GPS_QUERY_TIMER,
    LOCK_VIB_REPORT_TIMER,
    LOCK_RESETLOCK_TIMER,
    LOCK_OPEN_LOCK_TIMER,
    LOCK_LOCK_TIMER,
    LOCK_OPEN_HISR_TIMER,
    LOCK_CLOSE_HISR_TIMER,
    LOCK_SHARK_TIMER,
    LOCK_OPEN_G_SENEOR_TIMER,
    LOCK_LED1_TIMER,
    LOCK_LED2_TIMER,
    LOCK_LED3_TIMER,
    LOCK_LED4_TIMER,
    LOCK_BEEP_TIMER1,
    LOCK_BEEP_TIMER2,
    LOCK_MOTOR_TIMER1,
    LOCK_MOTOR_TIMER2,
    LOCK_ATA_AT_TIMER1,
    LOCK_ATA_AT_TIMER2,
    LOCK_ATA_AT_TIMER3,
    LOCK_ATA_AT_TIMER4,
    LOCK_ACC_VIB_TIMER1,
    LOCK_ACC_VIB_TIMER2,
    LOCK_ACC_VIB_TIMER3,
    LOCK_ACC_VIB_TIMER4,
    LOCK_ACC_VIB_TIMER5,
    LOCK_ACC_VIB_TIMER6,
    LOCK_TRANS_TIMER,
    LOCK_STOP_USER_TIMER,
    LOCK_RESEND_TIMEOUT_TIMER0,
    LOCK_RESEND_TIMEOUT_TIMER1,
    LOCK_RESEND_TIMEOUT_TIMER2,
    LOCK_RESEND_TIMEOUT_TIMER3,
    LOCK_RESEND_TIMEOUT_TIMER4,
    LOCK_RESEND_TIMEOUT_TIMER5,
    LOCK_RESEND_TIMEOUT_TIMER6,
    LOCK_RESEND_TIMEOUT_TIMER7,
    LOCK_RESEND_TIMEOUT_TIMER8,
    LOCK_RESEND_TIMEOUT_TIMER9,
    LOCK_RESEND_TIMEOUT_TIMER10,
    LOCK_RESEND_TIMEOUT_TIMER11,
    LOCK_RESEND_TIMEOUT_TIMER12,
    LOCK_RESEND_TIMEOUT_TIMER13,
    LOCK_RESEND_TIMEOUT_TIMER14,
    LOCK_RESEND_TIMEOUT_TIMER15,
    LOCK_RESEND_TIMEOUT_TIMER16,
    LOCK_RESEND_TIMEOUT_TIMER17,
    LOCK_RESEND_TIMEOUT_TIMER18,
    LOCK_RESEND_TIMEOUT_TIMER19,
    LOCK_RESEND_TIMEOUT_TIMER20,
    LOCK_RESEND_TIMEOUT_TIMER21,
    LOCK_RESEND_TIMEOUT_TIMER22,
    LOCK_RESEND_TIMEOUT_TIMER23,
    LOCK_RESEND_TIMEOUT_TIMER24,
    LOCK_RESEND_TIMEOUT_TIMER25,
    LOCK_RESEND_TIMEOUT_TIMER26,
    LOCK_RESEND_TIMEOUT_TIMER27,
    LOCK_RESEND_TIMEOUT_TIMER28,
    LOCK_RESEND_TIMEOUT_TIMER29,
    LOCK_RESEND_TIMEOUT_TIMER30,
    LOCK_RESEND_TIMEOUT_TIMER31,
    LOCK_RESEND_TIMEOUT_TIMER32,
    LOCK_RESEND_TIMEOUT_TIMER33,
    LOCK_RESEND_TIMEOUT_TIMER34,
    LOCK_RESEND_TIMEOUT_TIMER35,
    LOCK_RESEND_TIMEOUT_TIMER36,
    LOCK_RESEND_TIMEOUT_TIMER37,
    LOCK_RESEND_TIMEOUT_TIMER38,
    LOCK_RESEND_TIMEOUT_TIMER39,
    LOCK_RESEND_TIMEOUT_TIMER40,
    LOCK_RESEND_TIMEOUT_TIMER41,
    LOCK_RESEND_TIMEOUT_TIMER42,
    LOCK_RESEND_TIMEOUT_TIMER43,
    LOCK_RESEND_TIMEOUT_TIMER44,
    LOCK_RESEND_TIMEOUT_TIMER45,
    LOCK_RESEND_TIMEOUT_TIMER46,
    LOCK_RESEND_TIMEOUT_TIMER47,
    LOCK_RESEND_TIMEOUT_TIMER48,
    LOCK_RESEND_TIMEOUT_TIMER49,
    LOCK_RESEND_TIMEOUT_TIMER50,
    LOCK_RESEND_TIMEOUT_TIMER51,
    LOCK_RESEND_TIMEOUT_TIMER52,
    LOCK_RESEND_TIMEOUT_TIMER53,
    LOCK_RESEND_TIMEOUT_TIMER54,
    LOCK_RESEND_TIMEOUT_TIMER55,
    LOCK_RESEND_TIMEOUT_TIMER56,
    LOCK_RESEND_TIMEOUT_TIMER57,
    LOCK_RESEND_TIMEOUT_TIMER58,
    LOCK_RESEND_TIMEOUT_TIMER59,
    LOCK_RESEND_TIMEOUT_TIMER60,
    LOCK_RESEND_TIMEOUT_TIMER_MAXNUM,
    LOCK_MOVE_TIMER,
    LOCK_MOVE_STOP_TIMER,
    LOCK_SHARK_GAP_TIMER,
    LOCK_SLOPE_TIMER,
    LOCK_FOTA_START_TIMER,
    LOCK_LOCK_AMEND_TIMER,
    LOCK_DELAY_REPORT_TIMER,
    LOCK_LOC_REPORT_TIMER,
    LOCK_ECG_TIMER1,
    LOCK_ECG_TIMER2,
    LOCK_UPLOAD_ECG_TIMER,
    LOCK_UPLOAD_ECG_BEGIN_TIMER,
    LOCK_LOW_POWER_GPS_REPORT_TIMER,
    LOCK_CONN_TIMER,
    LOCK_REG_TIMEOUT_TIMER,
    LOCK_AUTH_TIMEOUT_TIMER,
    LOCK_RECONNECT_TIMER,
    LOCK_SMS_RESET_TIMER,
    LOCK_SMS_CHANGE_TIMER,
    FIND_BIKE_LED_TIMER,
    FIND_BIKE_SPEAKER_LED_TIMER,
    NWOW_GSM_STATE_LED_TIMER,
    MMI_RP_SRV_IOT_LOCK_TIMER_MAX
}mmi_rp_srv_iot_lock_timer_enum;
/******************** Timer resource IDs - finish ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


#endif /* _MMI_RP_SRV_IOT_LOCK_DEF_H */
