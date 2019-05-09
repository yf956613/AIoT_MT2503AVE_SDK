/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#ifndef __VSM_SENSOR_SUBSYS_ADAPTOR_H_
#define __VSM_SENSOR_SUBSYS_ADAPTOR_H_
 
#include <stdint.h>
#include "vsm_driver.h"

#ifdef __cplusplus
extern "C" {
#endif
 
int32_t vsm_ppg1_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_ppg2_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_bisi_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_ekg_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_eeg_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_emg_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_gsr_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

int32_t vsm_ppg1_512hz_operate(void *self, uint32_t command, void *buff_out, int32_t size_out, int32_t *actualout,
                    void *buff_in, int32_t size_in);

void vsm_eint_set(uint32_t eint_num);

void vsm_eint_handler(void *parameter);
                    
vsm_status_t vsm_driver_sensor_subsys_init(void);

int32_t vsm_check_trigger_signal(uint32_t *signal, uint32_t *intr_ctrl);
int32_t vsm_reenable_irq(uint32_t intr_ctrl);

#ifdef __cplusplus
}
#endif

#endif /* __VSM_SENSOR_SUBSYS_ADAPTOR_H_ */

