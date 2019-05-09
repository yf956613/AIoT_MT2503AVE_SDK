/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

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
 *
 * Filename:
 * ---------
 * Bt_hf_message.h
 *
 * Project:
 * --------
 *   BT Project
 *
 * Description:
 * ------------
 *   This file is used to
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __BT_HF_MESSAGE_H__
#define __BT_HF_MESSAGE_H__

#ifdef SOURCE_INSIGHT_TRACE
typedef enum
{
#endif
    /* APP --> HF */
    MSG_ID_BT_HF_ACTIVATE_REQ,
    MSG_ID_BT_HF_GROUP_START = MSG_ID_BT_HF_ACTIVATE_REQ,
    MSG_ID_BT_HF_DEACTIVATE_REQ,
    MSG_ID_BT_HF_CONNECT_REQ,
    MSG_ID_BT_HF_CONNECT_IND_RES,
    MSG_ID_BT_HF_DISCONNECT_REQ,
    MSG_ID_BT_HF_SCO_CONNECT_REQ,
    MSG_ID_BT_HF_SCO_DISCONNECT_REQ,
    MSG_ID_BT_HF_AT_COMMAND_REQ,
    MSG_ID_BT_HF_RESULT_CODE_CNF,
    MSG_ID_BT_HF_ATA_REQ,
    MSG_ID_BT_HF_ATD_NUM_REQ,
    MSG_ID_BT_HF_ATD_MEM_REQ,
    MSG_ID_BT_HF_BLDN_REQ,
    MSG_ID_BT_HF_CHUP_REQ,
    MSG_ID_BT_HF_CMEE_REQ,
    MSG_ID_BT_HF_NREC_REQ,
    MSG_ID_BT_HF_VTS_REQ,
    MSG_ID_BT_HF_VGS_REQ,
    MSG_ID_BT_HF_VGM_REQ,
    MSG_ID_BT_HF_CHLD_REQ,
    MSG_ID_BT_HF_CLIP_REQ,
    MSG_ID_BT_HF_CCWA_REQ,
    MSG_ID_BT_HF_COPS_SET_REQ,
    MSG_ID_BT_HF_COPS_REQ,
    MSG_ID_BT_HF_CNUM_REQ,
    MSG_ID_BT_HF_BVRA_REQ,
    MSG_ID_BT_HF_BINP_REQ,
    MSG_ID_BT_HF_BTRH_READ_REQ,
    MSG_ID_BT_HF_BTRH_SET_REQ,
    MSG_ID_BT_HF_CLCC_REQ,
    MSG_ID_BT_HF_XAPL_REQ,
    MSG_ID_BT_HF_ACCEV_REQ,
    MSG_ID_BT_HF_VGS_IND_RES,

    /*APP <-- HF*/
    MSG_ID_BT_HF_ACTIVATE_CNF,
    MSG_ID_BT_HF_DEACTIVATE_CNF,
    MSG_ID_BT_HF_CONNECT_CNF,
    MSG_ID_BT_HF_CONNECT_IND_REQ,
    MSG_ID_BT_HF_DISCONNECT_CNF,
    MSG_ID_BT_HF_DISCONNECT_IND,
    MSG_ID_BT_HF_SCO_CONNECT_CNF,
    MSG_ID_BT_HF_SCO_CONNECT_IND,
    MSG_ID_BT_HF_SCO_DISCONNECT_CNF,
    MSG_ID_BT_HF_SCO_DISCONNECT_IND,
    MSG_ID_BT_HF_AT_COMMAND_CNF,
    MSG_ID_BT_HF_RESULT_CODE_IND,
    MSG_ID_BT_HF_ATA_CNF,
    MSG_ID_BT_HF_ATD_NUM_CNF,
    MSG_ID_BT_HF_ATD_MEM_CNF,
    MSG_ID_BT_HF_BLDN_CNF,
    MSG_ID_BT_HF_CHUP_CNF,
    MSG_ID_BT_HF_CMEE_CNF,
    MSG_ID_BT_HF_NREC_CNF,
    MSG_ID_BT_HF_VTS_CNF,
    MSG_ID_BT_HF_VGS_CNF,
    MSG_ID_BT_HF_VGM_CNF,
    MSG_ID_BT_HF_CHLD_CNF,
    MSG_ID_BT_HF_CLIP_CNF,
    MSG_ID_BT_HF_CCWA_CNF,
    MSG_ID_BT_HF_COPS_SET_CNF,
    MSG_ID_BT_HF_COPS_CNF,
    MSG_ID_BT_HF_CNUM_CNF,
    MSG_ID_BT_HF_BVRA_CNF,
    MSG_ID_BT_HF_BINP_CNF,
    MSG_ID_BT_HF_BTRH_READ_CNF,
    MSG_ID_BT_HF_BTRH_SET_CNF,
    MSG_ID_BT_HF_CLCC_CNF,
    MSG_ID_BT_HF_XAPL_CNF,
    MSG_ID_BT_HF_ACCEV_CNF,
    MSG_ID_BT_HF_VGS_IND,
    MSG_ID_BT_HF_VGM_IND,
    MSG_ID_BT_HF_BSIR_IND,
    MSG_ID_BT_HF_CIEV_SERVICE_IND,
    MSG_ID_BT_HF_CIEV_CALL_IND,
    MSG_ID_BT_HF_CIEV_CALLSETUP_IND,
    MSG_ID_BT_HF_CIEV_CALLHELD_IND,
    MSG_ID_BT_HF_CIEV_SIGNAL_IND,
    MSG_ID_BT_HF_CIEV_ROAM_IND,
    MSG_ID_BT_HF_CIEV_BATTCHG_IND,
    MSG_ID_BT_HF_RING_IND,
    MSG_ID_BT_HF_CLIP_IND,
    MSG_ID_BT_HF_CCWA_IND,
    MSG_ID_BT_HF_BVRA_IND,
    MSG_ID_BT_HF_BTRH_IND,

    MSG_ID_BT_HF_GROUP_END = MSG_ID_BT_HF_BTRH_IND,

#ifdef SOURCE_INSIGHT_TRACE
} HF_MSG_TYPE;
#endif

#endif

