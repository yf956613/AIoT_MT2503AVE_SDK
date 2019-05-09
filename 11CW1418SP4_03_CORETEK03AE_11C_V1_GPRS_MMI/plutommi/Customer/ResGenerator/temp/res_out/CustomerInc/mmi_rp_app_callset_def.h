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
 *   mmi_rp_app_callset_def.h
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


#ifndef _MMI_RP_APP_CALLSET_DEF_H
#define _MMI_RP_APP_CALLSET_DEF_H




/******************** Menu resource IDs - begin ********************/
typedef enum
{
    MENU_ID_CALLSET_CALL_CENTER = 33808 + 1, /* BASE_ID + 1 */
    MENU_ID_CALLSET_CALL_LOG,
    MENU_ID_CALLSET_CALL_WAIT,
    MENU_ID_CALLSET_CALL_SETTING,
    MENU_ID_CALLSET_CFU_VOICE,
    MENU_ID_CALLSET_CFNRC_VOICE,
    MENU_ID_CALLSET_CFNRY_VOICE,
    MENU_ID_CALLSET_CFB_VOICE,
    MENU_ID_CALLSET_CFU_DATA,
    MENU_ID_CALLSET_CALLFWD_CANCELALL,
    MENU_ID_CALLSET_CALL_FWD,
    MENU_ID_CALLSET_MORE,
    MENU_ID_CALLSET_ANS_MODE,
    MENU_ID_CALLSET_ACTIVATE,
    MENU_ID_CALLSET_DEACTIVATE,
    MENU_ID_CALLSET_QUERY,
    MENU_ID_CALLSET_CF_NUM_EDIT_FROM_PHB,
    MENU_ID_CALLSET_CALL_WAIT_OPT,
    MENU_ID_CALLSET_ACTIVATE_CF,
    MENU_ID_CALLSET_CF_TO_NEW,
    MENU_ID_CALLSET_CF_TO_VM,
    MENU_ID_CALLSET_CFU_VOICE_OPT,
    MENU_ID_CALLSET_CFNRC_VOICE_OPT,
    MENU_ID_CALLSET_CFNRY_VOICE_OPT,
    MENU_ID_CALLSET_CFB_VOICE_OPT,
    MENU_ID_CALLSET_CFU_DATA_OPT,
    MENU_ID_CALLSET_CFNRY_TIME_OPT,
    MENU_ID_CALLSET_CFNRY_5_SEC,
    MENU_ID_CALLSET_CFNRY_10_SEC,
    MENU_ID_CALLSET_CFNRY_15_SEC,
    MENU_ID_CALLSET_CFNRY_20_SEC,
    MENU_ID_CALLSET_CFNRY_25_SEC,
    MENU_ID_CALLSET_CFNRY_30_SEC,
    MENU_ID_CALLSET_OFF,
    MENU_ID_CALLSET_ON,
    MENU_ID_CALLSET_ANS_MODE_OPT,
    MENU_ID_CALLSET_ANS_MODE_ANYKEY,
    MENU_ID_CALLSET_ANS_MODE_AUTO,
    MMI_RP_APP_CALLSET_MENU_MAX
}mmi_rp_app_callset_menu_enum;
/******************** Menu resource IDs - finish ********************/


/******************** String resource IDs - begin ********************/
typedef enum
{
    STR_ID_CALLSET_CALL_CENTER = 33808 + 1, /* BASE_ID + 1 */
    STR_ID_CALLSET_CALL_SETTING,
    STR_ID_CALLSET_MORE,
    STR_ID_CALLSET_CALLFWD,
    STR_ID_CALLSET_CFU_VOICE,
    STR_ID_CALLSET_CFNRC,
    STR_ID_CALLSET_CFNRY,
    STR_ID_CALLSET_CFB,
    STR_ID_CALLSET_CFU_DATA,
    STR_ID_CALLSET_CALLFWD_CANCELALL,
    STR_ID_CALLSET_CALLFWD_OPT,
    STR_ID_CALLSET_CF_TO_NEW,
    STR_ID_CALLSET_CF_TO_VM,
    STR_ID_CALLSET_CALLFWD_TO_NUM,
    STR_ID_CALLSET_CF_NUM_EDIT_FROM_PHB,
    STR_ID_CALLSET_CFNRY_WAIT_TIME,
    STR_ID_CALLSET_CFNRY_5_SEC,
    STR_ID_CALLSET_CFNRY_10_SEC,
    STR_ID_CALLSET_CFNRY_15_SEC,
    STR_ID_CALLSET_CFNRY_20_SEC,
    STR_ID_CALLSET_CFNRY_25_SEC,
    STR_ID_CALLSET_CFNRY_30_SEC,
    STR_ID_CALLSET_CALLWAIT,
    STR_ID_CALLSET_NUMBER_TOO_LONG,
    STR_ID_CALLSET_QUERY,
    STR_ID_CALLSET_ANS_MODE_ANYKEY,
    STR_ID_CALLSET_ANS_MODE,
    STR_ID_CALLSET_ANS_MODE_AUTO,
    MMI_RP_APP_CALLSET_STR_MAX
}mmi_rp_app_callset_str_enum;
/******************** String resource IDs - finish ********************/


/******************** Screen resource IDs - begin ********************/
typedef enum
{
    GRP_ID_CALLSET_COMMON = 33808 + 1, /* BASE_ID + 1 */
    GRP_ID_CALLSET_CF,
    MMI_RP_APP_CALLSET_SCR_MAX
}mmi_rp_app_callset_scr_enum;
/******************** Screen resource IDs - finish ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


/******************** Image resource IDs - begin ********************/
typedef enum
{
    IMG_ID_CALLSET_CALL_SETTING = 33808 + 1, /* BASE_ID + 1 */
    MMI_RP_APP_CALLSET_IMG_MAX
}mmi_rp_app_callset_img_enum;
/******************** Image resource IDs - finish ********************/


#endif /* _MMI_RP_APP_CALLSET_DEF_H */
