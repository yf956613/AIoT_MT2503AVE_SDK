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
 *   mmi_rp_srv_filemanager_def.h
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


#ifndef _MMI_RP_SRV_FILEMANAGER_DEF_H
#define _MMI_RP_SRV_FILEMANAGER_DEF_H




/******************** String resource IDs - begin ********************/
typedef enum
{
    FMGR_FS_ABORTED_ERROR_TEXT = 11876 + 1, /* BASE_ID + 1 */
    FMGR_FS_PATH_OVER_LEN_ERROR_TEXT,
    FMGR_FS_ROOT_DIR_FULL_TEXT,
    FMGR_FS_MEDIA_CHANGED_TEXT,
    FMGR_FS_FAT_ALLOC_ERROR_TEXT,
    FMGR_FS_WRITE_PROTECTION_TEXT,
    FMGR_FS_DRIVE_NOT_FOUND_TEXT,
    FMGR_FS_PARAM_ERROR_TEXT,
    FMGR_FS_FILE_NOT_FOUND_TEXT,
    FMGR_FS_ACCESS_DENIED_TEXT,
    FMGR_FS_PATH_NOT_FOUND_TEXT,
    FMGR_FS_DEVICE_BUSY_TEXT,
    FMGR_FS_APP_QUOTA_FULL_TEXT,
    STR_FMGR_CARD_MOUNTING,
    MMI_RP_SRV_FILEMANAGER_STR_MAX
}mmi_rp_srv_filemanager_str_enum;
/******************** String resource IDs - finish ********************/
/******************** Template resource IDs - Begin ********************/
/******************** Template resource IDs - End ********************/


/******************** MMI Cache IDs - Begin ********************/
typedef enum
{
    NVRAM_EF_FMGR_SORT_OPTION_LID = 11876 + 1, /* BASE_ID + 1 */    /*         BYTE */ 
    MMI_RP_SRV_FILEMANAGER_MMI_CACHE_MAX
} mmi_rp_srv_filemanager_mmi_cache_enum;
/******************** MMI Cache IDs - End ********************/


#endif /* _MMI_RP_SRV_FILEMANAGER_DEF_H */
