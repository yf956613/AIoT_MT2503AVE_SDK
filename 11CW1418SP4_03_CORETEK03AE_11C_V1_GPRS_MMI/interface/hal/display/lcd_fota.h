/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 * ---------
 *
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the header of LCD driver for FOTA/Card download/BLT/MLT.
 *    This file is only for target.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 08 02 2011 bin.han
 * removed!
 * .
 *
 * 08 02 2011 bin.han
 * removed!
 * .
 *
 * 03 30 2011 chelun.tsai
 * removed!
 * lcd_if_hw.h move to HAL.
 *
 * 02 16 2011 sophie.chen
 * removed!
 * .
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __LCD_FOTA_H__
#define __LCD_FOTA_H__

#if defined(__MTK_TARGET__)

#include "drv_comm.h"
#include "kal_release.h"
//#include "lcd_if_hw.h"
#include "lcd_if.h"
//#include "lcd_sw.h"		///Bin: removed for unnecessary inclusion
//#include "lcd_if_manager\inc\lcd_if_manager.h"


#ifdef __cplusplus
extern "C" {
#endif

/*typedef enum
{    
   LCD_DRIVING_2MA = 0,
   LCD_DRIVING_4MA = 1,
   LCD_DRIVING_6MA = 2,
   LCD_DRIVING_8MA = 3,
   LCD_DRIVING_10MA = 4,
   LCD_DRIVING_12MA = 5,
   LCD_DRIVING_14MA = 6,
   LCD_DRIVING_16MA = 7   
}  LCD_DRIVING_CURRENT_ENUM;  
*/


typedef enum
{
 LCD_UPDATE_BLT = 0,
 LCD_UPDATE_FLT,
 LCD_UPDATE_BLT_AND_FLT,
 LCD_UPDATE_NONE = 0xF 
}LCD_UPDATE_ACT_ENUM;


typedef struct
{
   kal_bool    layer_update_queue;     /* lcd layer parameter queue is full or not */
   kal_bool    source_key_enable;      /* enable/disable source key for specified layer */
   kal_bool    color_palette_enable;   /* enable/disable color palette for specified layer */
   kal_bool    opacity_enable;         /* enable/disable opacity for specified layer */
  
   kal_uint8   source_color_format;    /* color format of the specified layer*/ //LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM
   kal_uint8   color_palette_select;   /* selection of color palette table */
   kal_uint8   opacity_value;          /* opacity value for specified layer */   
   kal_uint8   rotate_value;           /* rotate select for specified layer */ //LCD_LAYER_ROTATE_ENUM
   kal_uint16  x_offset;               /* x axis offset from main window for specified layer */
   kal_uint16  y_offset;               /* y axis offset from main widnow for specified layer */
   kal_uint16  row_number;             /* layer buffer height of specified layer */
   kal_uint16  column_number;          /* layer buffer width of specified layer */
   kal_uint32  source_key;             /* source key color in RGB565 format for specified layer */
   kal_uint32  frame_buffer_address;   /* frame buffer start address of specified layer */

   // For MT6236
   kal_bool    dst_key_enable;         /* enable/disable source key for specified layer */
   kal_bool    swap_enable;          /* enable/disable source key for specified layer */
   kal_bool    lgamma_enable;          /* enable/disable source key for specified layer */
   kal_bool    dither_enable;          /* enable/disable source key for specified layer */
   kal_uint16  mem_x_offset;           /* x axis offset from mem space window for specified layer */
   kal_uint16  mem_y_offset;           /* y axis offset from mem space window for specified layer */
   kal_uint16  mem_pitch;              /* pitch of mem space window for specified layer */
} ddv2_lcd_layer_para_struct;


typedef struct
{ 
   kal_uint8   lcd_id; /// which lcd will be updated (MAIN_LCD or SUB_LCD)
   LCD_UPDATE_ACT_ENUM update; 
   kal_bool    block_mode_flag; /// block caller or not   
   void        (*lcd_block_mode_cb)(void); /// callback when lcd update is done
   
   kal_uint16  tgt_start_x; /// the starting x coordinate of LCM to be updated    
   kal_uint16  tgt_start_y; /// the starting y coordinate of LCM to be updated   
   kal_uint16  tgt_end_x;   /// the ending x coordinate of LCM to be updated   
   kal_uint16  tgt_end_y;   /// the ending y coordinate of LCM to be updated               
   kal_uint16  roi_offset_x; /// the ROI window offset x from main window   
   kal_uint16  roi_offset_y; /// the ROI window offset y from main window   

   kal_uint32  update_layer; /// the layers to be updated   
   kal_uint32  roi_background_color; /// background color of ROI

   //flatten parameters
   kal_uint8   block_mode;
   kal_uint8   memory_data_format;
   kal_uint8   memory_out_alpha;
   kal_uint16  memory_block_width;
   kal_uint16  dest_offset_x;
   kal_uint16  dest_offset_y;
   kal_uint32  memory_output_buffer_address;
   kal_uint32  memory_output_buffer_size;
   kal_uint32  dest_temp_address;

   //kal_uint32  landsp_ui_blt;
}  ddv2_lcd_roi_para_struct;

/******************************************************************
* Export APIs
*******************************************************************/
void lcd_init(LCD_TYPE_ENUM lcd_id, kal_uint16 background_color);
void lcd_config_layer(kal_uint32 layer_index, ddv2_lcd_layer_para_struct *layer_data);
void lcd_config_roi(ddv2_lcd_roi_para_struct *roi_para);
void lcd_start(
 LCD_UPDATE_ACT_ENUM mode,
 kal_bool block_req,
 kal_uint32 start_x, 
 kal_uint32 start_y, 
 kal_uint32 end_x, 
 kal_uint32 end_y);


#ifdef __cplusplus
}
#endif


#endif //defined(__MTK_TARGET__)


#endif //__LCD_FOTA_H__

