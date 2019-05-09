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
 *	 gdi_image_sequence.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  virtual file image
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_IMAGE_VIRTUALFILE_H_
#define _GDI_IMAGE_VIRTUALFILE_H_

#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"

extern S32 gdi_image_get_virtual_filename(S8* image_buffer, S8* virtual_fname);
extern GDI_RESULT gdi_image_virtualfile_draw_handler(U32 flag,U32 frame_pos,S32 x,S32 y,S32 w,S32 h,U8* data_ptr,U32 img_size);
extern GDI_RESULT gdi_image_virtualfile_get_dimension_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *width,S32 *height);
extern GDI_RESULT gdi_image_virtualfile_get_frame_count_handler(U32 flag,U8* data_ptr,U32 img_size,S32 *frame_count);
extern GDI_RESULT gdi_image_virtualfile_get_pos_info_handler(U32 flag,U8* data_ptr,U32 img_size,BOOL quick_mode, S32 *total_pos,gdi_anim_pos_type_enum *pos_type);

extern GDI_RESULT gdi_image_virtualfile_sequence_draw_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8* data_ptr,
            U32 img_size);
extern GDI_RESULT gdi_image_virtualfile_sequence_get_dimension_handler(
            U32 flag,
            U8* data_ptr,
            U32 img_size,
            S32 *width,
            S32 *height);
extern GDI_RESULT gdi_image_virtualfile_sequence_get_pos_info_handler(
            U32 flag,
            U8* data_ptr,
            U32 img_size,
            BOOL quick_mode, 
            S32 *total_pos,
            gdi_anim_pos_type_enum *pos_type);
GDI_RESULT gdi_image_virtualfile_sequence_get_image_size(
            U8 *data_ptr,
            U32 *image_file_size);



#endif /* _GDI_IMAGE_VIRTUALFILE_H_ */



