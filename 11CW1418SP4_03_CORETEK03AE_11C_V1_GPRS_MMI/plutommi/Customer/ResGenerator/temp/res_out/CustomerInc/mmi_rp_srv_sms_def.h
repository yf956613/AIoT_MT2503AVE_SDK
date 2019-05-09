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
 *   mmi_rp_srv_sms_def.h
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


#ifndef _MMI_RP_SRV_SMS_DEF_H
#define _MMI_RP_SRV_SMS_DEF_H




/******************** Timer resource IDs - begin ********************/
typedef enum
{
    MESSAGES_SMS_BOOTUP_TIMER_ID = 9466 + 1, /* BASE_ID + 1 */
    MESSAGES_CONTINUE_SEND_SMS_PROCESS_TIMER_ID,
    SRV_SMS_LMS_RECV_TIMER_ID,
    MMI_RP_SRV_SMS_TIMER_MAX
}mmi_rp_srv_sms_timer_enum;
/******************** Timer resource IDs - finish ********************/


/******************** Events resource IDs - begin ********************/
typedef enum
{
    EVT_ID_SRV_SMS_BEGIN = 9466 + 1, /* BASE_ID + 1 */
    EVT_ID_SRV_SMS_READY,
    EVT_ID_SRV_SMS_NEW_MSG,
    EVT_ID_SRV_SMS_NEW_MSG_WAITING,
    EVT_ID_SRV_SMS_STATUS_REPORT,
    EVT_ID_SRV_SMS_SIM_REFRESH,
    EVT_ID_SRV_SMS_AT_CMD_IND,
    EVT_ID_SRV_SMS_MEM_EXCEED,
    EVT_ID_SRV_SMS_MEM_FULL,
    EVT_ID_SRV_SMS_MEM_AVAILABLE,
    EVT_ID_SRV_SMS_ADD_MSG,
    EVT_ID_SRV_SMS_DEL_MSG,
    EVT_ID_SRV_SMS_UPDATE_MSG,
    EVT_ID_SRV_SMS_UPDATE_SENDING_ICON,
    EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS,
    EVT_ID_SRV_SMS_API_SEND_MSG,
    EVT_ID_SRV_SMS_UPDATE_COUNTER,
    EVT_ID_SRV_SMS_REFRESH_MSG,
    EVT_ID_SRV_SMS_CLEAR_FOLDER,
    EVT_ID_SRV_SMS_HIDE_LIST,
    EVT_ID_SRV_SMS_ADD_REPORT,
    EVT_ID_SRV_SMS_DEL_REPORT,
    EVT_ID_SRV_SMS_UPDATE_REPORT,
    EVT_ID_SRV_SMS_PS_NORMAL_IND,
    EVT_ID_SRV_SMS_PS_STORAGE_IND,
    EVT_ID_SRV_SMS_PS_RECEIVER_IND,
    EVT_ID_SRV_SMS_PS_AT_IND,
    EVT_ID_SRV_SMS_PS_CB_MSG_IND,
    EVT_ID_SRV_SMS_PS_CB_GS_CHANGE_IND,
    EVT_ID_SRV_SMS_ASYNC_CALLBACK,
    EVT_ID_SRV_SMS_STARTUP_READ_ME_SMS,
    MMI_RP_SRV_SMS_EVENT_MAX
}mmi_rp_srv_sms_event_enum;
/******************** Events resource IDs - begin ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


/******************** MMI Cache IDs - Begin ********************/
typedef enum
{
    NVRAM_SMS_ACTIVE_PROFILE_INDEX = 9466 + 1, /* BASE_ID + 1 */     /*         BYTE */ 
    NVRAM_SMS_MISCELL_SETTING,                                  /*         BYTE */ 
    NVRAM_SMS_CONCAT_MSG_REF_VALUE,                             /*        SHORT */ 
    MMI_RP_SRV_SMS_MMI_CACHE_MAX
} mmi_rp_srv_sms_mmi_cache_enum;
/******************** MMI Cache IDs - End ********************/


#endif /* _MMI_RP_SRV_SMS_DEF_H */
