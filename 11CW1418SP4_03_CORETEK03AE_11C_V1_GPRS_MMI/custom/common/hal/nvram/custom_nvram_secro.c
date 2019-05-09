/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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

/*****************************************************************************
 *
 * Filename:
 *   custom_nvram_secro.c
 *
 * Project:
 *   MAUI
 *
 * Description:
 *   This file is intends for NVRAM auto gen statistics
 *
 * Author:
 *   nvram auto gen !
 * -------
 *
 *============================================================================
 *
 * This file is automatically generated by the nvram gen procedure
 *
 ****************************************************************************/
#if !defined(NVRAM_NOT_PRESENT)
#include "kal_general_types.h"
#ifdef __SECURE_RO_ENABLE__
#include "custom_nvram_sec.h"
#pragma arm section rodata = "SECURE_RO"
const SEC_RO_ST g_SEC_RO =
{
    /* SEC_RO ver */
    SEC_RO_STRUCT_VER,
    /* custom secret key */
    {
        0x31, 0x32, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66
    },
    /* custom secret key len */
    NVRAM_SECRET_KEY_SIZE,
    /* NVRAM Secure Parameters */
    {
        0x01
    },
    /* NVRAM SecuPack data */
    {
        0xBC, 0x00, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 
        0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 
        0x01, 0x21, 0x43, 0x65, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x65, 0x87, 0x21, 0x43, 0xFF, 0xFF, 
        0xFF, 0xFF, 0x01, 0x11, 0x11, 0x22, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x33, 0x33, 0x44, 0x44, 
        0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x55, 0x55, 0x66, 0x66, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x77, 0x77, 
        0x88, 0x88, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x99, 0x99, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xC1, 
        0xC1, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC2, 0xC2, 
        0xC2, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xC4, 0xC4, 
        0xC4, 0xC4, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xFF, 0xFF, 0xFF, 
        0xFF, 0xFF, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x88, 0x80, 0x59, 0x26,
        /* check sum */
        0x35, 0x87
    },
    {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    }
};
#pragma arm section rodata
#else  /* __SECURE_RO_ENABLE__ */
const kal_uint8 NVRAM_CUSTOM_KEY[] = 
    {
        0x31, 0x32, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66
    };
const kal_uint8 NVRAM_SECUPACK_DEFAULT[] = 
    {
        0xBC, 0x00, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 
        0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 
        0x01, 0x21, 0x43, 0x65, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x65, 0x87, 0x21, 0x43, 0xFF, 0xFF, 
        0xFF, 0xFF, 0x01, 0x11, 0x11, 0x22, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x33, 0x33, 0x44, 0x44, 
        0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x55, 0x55, 0x66, 0x66, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x77, 0x77, 
        0x88, 0x88, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x99, 0x99, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xC1, 
        0xC1, 0xC1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC2, 0xC2, 
        0xC2, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xC4, 0xC4, 
        0xC4, 0xC4, 0xC4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 0xC5, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xFF, 0xFF, 0xFF, 
        0xFF, 0xFF, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x88, 0x80, 0x59, 0x26,
        /* check sum */
        0x35, 0x87
    };
#endif /* __SECURE_RO_ENABLE__ */
kal_uint32 secupack_total_to_verify = 1;
#endif /* NVRAM_NOT_PRESENT */