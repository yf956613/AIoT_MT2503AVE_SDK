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
 *   mmi_rp_app_ucm_def.h
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


#ifndef _MMI_RP_APP_UCM_DEF_H
#define _MMI_RP_APP_UCM_DEF_H




/******************** Menu resource IDs - begin ********************/
typedef enum
{
    MENU_ID_UCM_INCALL_OPTION = 41092 + 1, /* BASE_ID + 1 */
    MENU_ID_UCM_INCALL_OPTION_HOLD,
    MENU_ID_UCM_INCALL_OPTION_RETRIEVE,
    MENU_ID_UCM_INCALL_OPTION_SWAP,
    MENU_ID_UCM_INCALL_OPTION_CONF,
    MENU_ID_UCM_INCALL_OPTION_SPLIT,
    MENU_ID_UCM_INCALL_OPTION_END_SINGLE,
    MENU_ID_UCM_INCALL_OPTION_END_CONF,
    MENU_ID_UCM_INCALL_OPTION_END_ALL,
    MENU_ID_UCM_INCALL_OPTION_PHONEBOOK,
    MENU_ID_UCM_INCALL_OPTION_CALLLOG,
    MENU_ID_UCM_INCALL_OPTION_SMS,
    MENU_ID_UCM_INCALL_OPTION_MUTE,
    MENU_ID_UCM_INCALL_OPTION_UNMUTE,
    MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH,
    MENU_ID_UCM_INCALL_OPTION_SPEAKER_VOLUME,
    MENU_ID_UCM_IN_CALL_DIALER_OPTION,
    MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL,
    MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE,
    MENU_ID_UCM_CALL_TYPE,
    MENU_ID_UCM_CALL_TYPE_VOICE,
    MMI_RP_APP_UCM_MENU_MAX
}mmi_rp_app_ucm_menu_enum;
/******************** Menu resource IDs - finish ********************/


/******************** String resource IDs - begin ********************/
typedef enum
{
    STR_ID_UCM_CALLING = 41092 + 1, /* BASE_ID + 1 */
    STR_ID_UCM_VOICE_ACTIVE,
    STR_ID_UCM_VOICE_HOLD,
    STR_ID_UCM_REJECT,
    STR_ID_UCM_ANSWER,
    STR_ID_UCM_HAND_HELD,
    STR_ID_UCM_HAND_FREE,
    STR_ID_UCM_PROCESSING,
    STR_ID_UCM_NOT_ALLOW_TO_HOLD,
    STR_ID_UCM_NOT_ALLOW_TO_SWAP,
    STR_ID_UCM_HOLD,
    STR_ID_UCM_RETRIEVE,
    STR_ID_UCM_SWAP,
    STR_ID_UCM_CONFERENCE,
    STR_ID_UCM_SPLIT,
    STR_ID_UCM_END_SINGLE,
    STR_ID_UCM_END_CONFERENCE,
    STR_ID_UCM_END_ALL,
    STR_ID_UCM_END_CALL,
    STR_ID_UCM_PHONEBOOK,
    STR_ID_UCM_UNMUTE,
    STR_ID_UCM_VOICE_CALL,
    STR_ID_UCM_SWITCH_AUDIO_PATH,
    STR_ID_UCM_ACTIVE,
    STR_ID_UCM_END_ALL_ACTIVE,
    STR_ID_UCM_END_ALL_HELD,
    MMI_RP_APP_UCM_STR_MAX
}mmi_rp_app_ucm_str_enum;
/******************** String resource IDs - finish ********************/


/******************** Screen resource IDs - begin ********************/
typedef enum
{
    GRP_ID_UCM_PRE_MO = 41092 + 1, /* BASE_ID + 1 */
    GRP_ID_UCM_MO,
    GRP_ID_UCM_MT,
    GRP_ID_UCM_INCALL,
    GRP_ID_UCM_VT,
    GRP_ID_UCM_INT_MARKER,
    GRP_ID_UCM_MARKER,
    GRP_ID_UCM_CALL_END,
    GRP_ID_UCM_AUTO_REDIAL,
    GRP_ID_UCM_CONFIRM,
    GRP_ID_UCM_MO_FAIL_POST_ACTION,
    GRP_ID_UCM_UHA,
    SCR_ID_UCM_OUTGOING,
    SCR_ID_UCM_INCOMING,
    SCR_ID_UCM_IN_CALL,
    SCR_ID_UCM_DTMF_EDITOR,
    SCR_ID_UCM_MULTI_HELD_CALL,
    SCR_ID_UCM_CALL_END,
    SCR_ID_UCM_VOIP_DIALER,
    SCR_ID_UCM_VOICE_DIALER,
    SCR_ID_UCM_TRANSFER,
    SCR_ID_UCM_DEFLECT,
    SCR_ID_UCM_CONFIRM,
    SCR_ID_UCM_PROCESSING,
    SCR_ID_UCM_AUTO_REDIAL,
    SCR_ID_UCM_DIAL_CALL_TYPE_MENU,
    SCR_ID_UCM_BGS_EFFECT_SELECT,
    SCR_ID_UCM_URIAGENT_CONFIRM,
    SCR_ID_UCM_SEND_DTMF,
    SCR_ID_UCM_DUMMY,
    SCR_ID_UCM_ECT_CONFIRM,
    SCR_ID_UCM_REJ_BY_SMS_CONFIRM,
    SCR_ID_UCM_DISCONNECT_SCREEN,
    SCR_ID_UCM_GRAY_SCREEN,
    SCR_ID_UCM_MO_FAIL_POST_ACTION,
    SCR_ID_UCM_VT_INCALL,
    SCR_ID_UCM_VT_DIALER,
    SCR_ID_UCM_VT_MO_FAIL_POST_ACTION,
    SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY,
    SCR_ID_UCM_VT_VIDEO_QUALITY,
    SCR_ID_UCM_VT_PIC_VIEWER,
    MMI_RP_APP_UCM_SCR_MAX
}mmi_rp_app_ucm_scr_enum;
/******************** Screen resource IDs - finish ********************/


/******************** Timer resource IDs - begin ********************/
typedef enum
{
    UCM_NOTIFY_DURATION_TIMER = 41092 + 1, /* BASE_ID + 1 */
    UCM_FTE_AUTO_LOCK_TIMER_ID,
    UCM_VT_FALL_TO_VOICE_NOTIFY_TIMER_ID,
    VT_START_CAMERA_QUERY_TIMER,
    CM_UPDATE_NCENTER_TIMER,
    TIMER_ID_UCM_DELAY_RING,
    MMI_RP_APP_UCM_TIMER_MAX
}mmi_rp_app_ucm_timer_enum;
/******************** Timer resource IDs - finish ********************/


/******************** Audio resource IDs - begin ********************/
typedef enum
{
    AUD_ID_UCM_AUTO_ANSWER = 41092 + 1, /* BASE_ID + 1 */
    MMI_RP_APP_UCM_AUD_MAX
}mmi_rp_app_ucm_aud_enum;
/******************** Audio resource IDs - finish ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


/******************** Image resource IDs - begin ********************/
typedef enum
{
    IMG_ID_UCM_CALL_STATE_ACTIVE = 41092 + 1, /* BASE_ID + 1 */
    IMG_ID_UCM_CALL_STATE_HOLD,
    MMI_RP_APP_UCM_IMG_MAX
}mmi_rp_app_ucm_img_enum;
/******************** Image resource IDs - finish ********************/


#endif /* _MMI_RP_APP_UCM_DEF_H */
