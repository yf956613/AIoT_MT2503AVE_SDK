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
 *   mmi_rp_app_netset_def.h
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


#ifndef _MMI_RP_APP_NETSET_DEF_H
#define _MMI_RP_APP_NETSET_DEF_H




/******************** Menu resource IDs - begin ********************/
typedef enum
{
    MENU_ID_NETSET_MAIN = 37428 + 1, /* BASE_ID + 1 */
    MENU_ID_NETSET_NETWORK_SELECTION,
    MENU_ID_NETSET_NETSEL_AUTO,
    MENU_ID_NETSET_NETSEL_MANUAL,
    MENU_ID_NETSET_NETSEL_SELECT_MODE,
    MENU_ID_NETSET_GPRS_CONNECTION,
    MENU_ID_NETSET_PCH_MODE,
    MMI_RP_APP_NETSET_MENU_MAX
}mmi_rp_app_netset_menu_enum;
/******************** Menu resource IDs - finish ********************/


/******************** String resource IDs - begin ********************/
typedef enum
{
    STR_ID_NETSET_NETWORK_SELECTION = 37428 + 1, /* BASE_ID + 1 */
    STR_ID_NETSET_NETSEL_NEW_SEARCH,
    STR_ID_NETSET_NETSEL_SELECT_NETWORK,
    STR_ID_NETSET_NETSEL_SELECTION_MODE,
    STR_ID_NETSET_NETSEL_NETWORK_LIST,
    STR_ID_NETSET_NW_LIST_FAIL,
    STD_ID_NETSET_NW_SELECT_FAIL,
    STR_ID_NETSET_REGISTERING_NW,
    STR_ID_NETSET_GPRS_CONNECTION,
    STR_ID_NETSET_GPRS_CONNECTION_ALWAYS,
    STR_ID_NETSET_GPRS_CONNECTION_WHENNEEDED,
    STR_ID_NETSET_PCH,
    STR_ID_NETSET_PCH_DATA_PREFER,
    STR_ID_NETSET_PCH_CALL_PREFER,
    STR_ID_NETSET_PCH_QUERY,
    MMI_RP_APP_NETSET_STR_MAX
}mmi_rp_app_netset_str_enum;
/******************** String resource IDs - finish ********************/


/******************** Screen resource IDs - begin ********************/
typedef enum
{
    GRP_ID_NETSET_MAIN = 37428 + 1, /* BASE_ID + 1 */
    GRP_ID_NETSET_NW_SELECT,
    GRP_ID_NETSET_PREF_MODE,
    GRP_ID_NETSET_PREF_LIST,
    GRP_ID_NETSET_SERVICE_SELECTION,
    SCR_ID_NETSET_MAIN,
    SCR_ID_NETSET_SIM,
    SCR_ID_NETSET_NETWORK_SELECTION,
    SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS,
    SCR_ID_NETSEL_AUTO_REGISTER_PROGRESS,
    SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS,
    SCR_ID_NETSEL_MANUAL_REGISTER_PROGRESS,
    SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN,
    SCR_ID_NETSEL_SELECT_MODE,
    SCR_ID_NETSEL_ADDTIONAL_INFORMATION,
    SCR_ID_NETSEL_ADDTIONAL_INFORMATION_PROGRESS,
    SCR_ID_NETSET_PREF_MODE,
    SCR_ID_NETSET_PREF_MODE_PROGRESS,
    SCR_ID_NETSET_SERVICE_SELECTION,
    SCR_ID_NETSET_SET_RAT_PROGRESS,
    SCR_ID_NETSET_RAT_QUERY,
    SCR_ID_NETSET_NETWORK_INFO,
    SCR_ID_NETSET_GPRS_CONNECTION,
    SCR_ID_NETSET_SET_GPRS_PROGRESS,
    SCR_ID_NETSET_SET_PCH_PROGRESS,
    SCR_ID_NETSET_SET_PCH_CONFIRM,
    SCR_ID_NETSET_HSPA,
    SCR_ID_NETSET_HSPA_PROGRESS,
    SCR_ID_NETSET_HSPA_LIST,
    MMI_RP_APP_NETSET_SCR_MAX
}mmi_rp_app_netset_scr_enum;
/******************** Screen resource IDs - finish ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


/******************** Image resource IDs - begin ********************/
typedef enum
{
    IMG_SETTING_NETWORK = 37428 + 1, /* BASE_ID + 1 */
    IMG_ID_NETSET_HOME_PLMN,
    IMG_ID_NETSET_UNKNOWN_PLMN,
    IMG_ID_NETSET_FORBIDDEN_PLMN,
    MMI_RP_APP_NETSET_IMG_MAX
}mmi_rp_app_netset_img_enum;
/******************** Image resource IDs - finish ********************/


#endif /* _MMI_RP_APP_NETSET_DEF_H */
