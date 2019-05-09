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
 *   mmi_rp_app_dataaccount_def.h
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


#ifndef _MMI_RP_APP_DATAACCOUNT_DEF_H
#define _MMI_RP_APP_DATAACCOUNT_DEF_H




/******************** Menu resource IDs - begin ********************/
typedef enum
{
    MENU_ID_DTCNT_SIM_1 = 34334 + 1, /* BASE_ID + 1 */
    MENU_ID_DATA_CONNECTION_SIM,
    SERVICES_DATA_CONNECT_MAIN_MENU_ID,
    MENU_ID_DTCNT_OPT_ADD_GPRS,
    MENU_ID_DTCNT_ACCOUNT_OPTION,
    MENU_ID_DTCNT_OPT_EDIT,
    MENU_ID_DTCNT_OPT_DELETE,
    MENU_ID_DTCNT_OPT_CHANGE_DEFAULT,
    MENU_ID_DTCNT_OPT2_ADD_GPRS,
    MENU_ID_DTCNT_ACCOUNT_OPTION2,
    MENU_ID_DTCNT_OPT3_ADD_GPRS,
    MENU_ID_DTCNT_ACCOUNT_OPTION3,
    MENU_ID_DTCNT_OPT3_VIEW,
    MENU_ID_DTCNT_OPT3_CHANGE_DEFAULT,
    MMI_RP_APP_DATAACCOUNT_MENU_MAX
}mmi_rp_app_dataaccount_menu_enum;
/******************** Menu resource IDs - finish ********************/


/******************** String resource IDs - begin ********************/
typedef enum
{
    STR_ID_DTCNT_RENAME = 34334 + 1, /* BASE_ID + 1 */
    STR_ID_DTCNT_ADVANCED_SETTING,
    STR_ID_DTCNT_HOME_PAGE,
    STR_ID_DTCNT_CONNECTION_TYPE,
    STR_ID_DTCNT_USE_PROXY,
    STR_ID_DTCNT_PROXY_ADDRESS,
    STR_ID_DTCNT_PROXY_PORT,
    STR_ID_DTCNT_PROXY_USER_NAME,
    STR_ID_DTCNT_PROXY_PASS_WORD,
    STR_ID_DTCNT_DNS_ADDRESS1,
    STR_ID_DTCNT_DNS_ADDRESS2,
    STR_ID_DTCNT_IP_ADDRESS,
    STR_ID_DTCNT_SUBNET_MASK,
    STR_ID_DTCNT_ADD_GPRS,
    STR_ID_DTCNT_MAX_CSD_ACCOUNT_REACHED,
    STR_ID_DTCNT_NOT_ALLOW_DELETE,
    STR_ID_DTCNT_NOT_ALLOW_EDIT,
    STR_ID_DTCNT_GPRS_CHAP_AUTH,
    STR_ID_DTCNT_GPRS_APN,
    STR_ID_DTCNT_GPRS_AUTH_TYP,
    STR_ID_DTCNT_GPRS_INPUT_LACK,
    STR_ID_DTCNT_NAME_INVALID,
    STR_ID_DTCNT_CHANGE_DEFAULT,
    STR_ID_DTCNT_DELETE_ASK,
    STR_ID_DTCNT_ERR_MSG_INVALID_PORT,
    STR_ID_DTCNT_ERR_MSG_EMPTY_PORT_NUMBER,
    STR_ID_DTCNT_NOT_READY,
    STR_ID_DATA_CONNECTION_SIM,
    STR_ID_DATA_CONNECTION_SIM_NOT_ALLOW_CHANGED,
    STR_ID_DTCNT_NO_AVAILABLE_ACCOUNT,
    MMI_RP_APP_DATAACCOUNT_STR_MAX
}mmi_rp_app_dataaccount_str_enum;
/******************** String resource IDs - finish ********************/


/******************** Screen resource IDs - begin ********************/
typedef enum
{
    GRP_ID_DTCNT = 34334 + 1, /* BASE_ID + 1 */
    GRP_ID_DTCNT_PROV,
    GRP_ID_DATA_CONNECTION_SIM,
    SCR_ID_DTCNT_LIST,
    SCR_ID_DTCNT_LIST_OPTION,
    SCR_ID_DTCNT_CSD_COMMON,
    SCR_ID_DTCNT_GPRS_COMMON,
    SCR_ID_DTCNT_ADVANCED,
    SCR_ID_DTCNT_OTA_LIST,
    SCR_ID_DTCNT_EDIT,
    SCR_ID_DTCNT_NOTIFICATION,
    SCR_ID_DTCNT_MAIN,
    SCR_ID_DTCNT_GPRS_LIST,
    SCR_ID_DTCNT_OTA_GPRS_LIST,
    SCR_ID_DTCNT_LIST_ALWAYS_ASK,
    SCR_ID_DTCNT_LIST_ACCOUNT_SELECTION,
    SCR_ID_DTCNT_CUI_NORMAL_LIST,
    SCR_ID_DTCNT_CUI_SIM_LIST,
    SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST,
    SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH,
    SCR_ID_DTCNT_CUI_CBM_LIST,
    SCR_ID_DTCNT_CUI_WLAN_LIST,
    SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS,
    SCR_ID_DTCNT_CUI_PASSPHRASE_INPUT,
    SCR_ID_DTCNT_CUI_WAPI_PSK_INPUT,
    SCR_ID_DTCNT_CUI_WAPI_CERT_INPUT,
    SCR_ID_DTCNT_CUI_CSD_COMMON_VIEW,
    SCR_ID_DTCNT_CUI_GPRS_COMMON_VIEW,
    SCR_ID_DTCNT_CUI_ADVANCED_VIEW,
    SCR_ID_DTCNT_PROGRESSING,
    MMI_RP_APP_DATAACCOUNT_SCR_MAX
}mmi_rp_app_dataaccount_scr_enum;
/******************** Screen resource IDs - finish ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


/******************** Image resource IDs - begin ********************/
typedef enum
{
    IMG_ID_DTCNT_CHECKMARK = 34334 + 1, /* BASE_ID + 1 */
    SERVICES_DATA_CONNECT_IMAGE_ID,
    MMI_RP_APP_DATAACCOUNT_IMG_MAX
}mmi_rp_app_dataaccount_img_enum;
/******************** Image resource IDs - finish ********************/


#endif /* _MMI_RP_APP_DATAACCOUNT_DEF_H */
