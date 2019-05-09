
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  BasSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the Pedometer Profile.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_BLE_BAS_SUPPORT__ 

#include "DebugInitDef_Int.h"
#include "BasSrvGprot.h"
#include "BasSrv.h"
#include "Bas_def.h"
#include "Kal_trace.h"

/*UT*/
#include "BtcmSrvGprot.h"
#include "PowerOnChargerProt.h"
#include "mmi_rp_srv_bas_def.h"
#include "device.h"

#include "CharBatSrvGprot.h"

#include "MMI_conn_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "blesrvgprot.h" // srv_ble_cm_get_connected_dev_num

static BtStatus bas_disconnect_event_handler(BD_ADDR *bdaddr);
static void bas_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src);
static mmi_ret bas_recv_event_handler(mmi_event_struct *evt);

#define BAS_SEND_NOTIFICATION_TIME      (1000 * 60 * 30)

#define BAS_MULTILINK_MAX_MEM_SIZE (1024 * 10)
KAL_ADM_ID g_bas_adm_id = NULL;
kal_uint8 g_bas_mem_pool[BAS_MULTILINK_MAX_MEM_SIZE]; 

U8 g_battery_level = 0;
U8 g_send_addr[BD_ADDR_SIZE] = {0};
BasCntx  g_bas_cntx = {0};

U8       g_bas_uuid[] = {
	0x18, 0x0F, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};
gatts_callback_struct g_bas_cb = {
	bas_register_server_callback,
    bas_connection_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	bas_service_started_callback,
	NULL,
	NULL,
	bas_request_read_callback,
	bas_request_write_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

gatts_factory_callback_struct g_bas_factory_cb = {
	NULL,
	NULL,
	bas_add_services_callback,
	NULL,
};

int bas_find_uuid_by_handle(ATT_HANDLE att_handle, ATT_UUID *svc_uuid, ATT_UUID *chr_uuid , ATT_UUID *desc_uuid)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_bas_cntx.srv_list.srvlist);

	//kal_prompt_trace(MOD_BT, "[BAS] bas_find_uuid_by_handle %x!\n", att_handle);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_UUID, att_handle);
	if (mmi_IsListEmpty(&g_bas_cntx.srv_list.srvlist))
	{
		return TYPE_UNKNOW;
	}

    if (att_handle == 0)
	{
	     return TYPE_UNKNOW;
	}
    
	while ((ListEntry *)svc_list != &g_bas_cntx.srv_list.srvlist)
	{
		if (svc_list->handle == att_handle)
		{
			//kal_prompt_trace(MOD_BT, "[BAS] svc_list->type %d!\n", svc_list->type);		
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_UUID_TYPE, svc_list->type);
			switch(svc_list->type)
			{
				case TYPE_SERVICE:
					memcpy(svc_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					return TYPE_SERVICE;
					
				case TYPE_CHARACTERISTIC:
					memcpy(chr_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					bas_find_uuid_by_handle(svc_list->srvhandle, svc_uuid, chr_uuid,desc_uuid);
					return TYPE_CHARACTERISTIC;
					
				case TYPE_DESCRIPTOR:
					memcpy(desc_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					bas_find_uuid_by_handle(svc_list->charhandle, svc_uuid, chr_uuid,desc_uuid);
					return TYPE_DESCRIPTOR;
					
				default:
					return svc_list->type;
			}
		}
			
		svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
	}
	return TYPE_UNKNOW;
}

void bas_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
	BasConnCntx    *pConnNode = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	ATT_UUID         desc_uuid;
	int              type = bas_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid, &desc_uuid);
	U16              srv_id = convert_array_to_uuid16(svc_uuid);
	U16              char_id = convert_array_to_uuid16(chr_uuid);
	U16			     des_id = convert_array_to_uuid16(desc_uuid);
	ATT_VALUE        att_value;
    S32 ret_val;

	//kal_prompt_trace(MOD_BT, "[BAS] bas_request_read_callback handle:%x, type:%d, char_id %x,des_id %x, offset %d, long %d!", 
    //    attr_handle, type, char_id,des_id, offset, is_long);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_READ_CB, attr_handle, type, char_id,des_id, offset, is_long);
      
	if (type == TYPE_CHARACTERISTIC)
	{	
        if ((srv_id == BAS_SERVICE) && (char_id == BAS_LEVEL_CHAR_UUID))
        {
	        U8 battery_level = 0;
			memset(&att_value, 0, sizeof(ATT_VALUE));
		    battery_level = bas_get_battery_level();
		    memcpy(&(att_value.value[offset]), &battery_level, sizeof(battery_level));
		    att_value.len = sizeof(battery_level);
			//kal_prompt_trace(MOD_BT, "[BAS]handle:%x, type:%d, char_id %x, offset %d, battery_level %d,len %d!", 
		    //    attr_handle, type, char_id, offset, battery_level, att_value.len);
			
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_READ_RESPONSE, attr_handle, type, char_id, 
				offset, battery_level, att_value.len);
            srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);                        
        }
        else
        {
            att_value.len = 1;
            att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
            srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
        }
	}
	else if (type == TYPE_DESCRIPTOR)
	{	
        if ((char_id == BAS_LEVEL_CHAR_UUID) && (des_id == BAS_CHAR_CONFIG_UUID))
        {
    		if (pConnNode->dec.dec_value.len)
			{
			    memset(&att_value, 0, sizeof(ATT_VALUE));
				att_value.len = pConnNode->dec.dec_value.len;
				memcpy(att_value.value, pConnNode->dec.dec_value.value, sizeof(pConnNode->dec.dec_value.value)); 
			}
			else
			{
				att_value.len = BAS_MAX_VALUE_LEN;
				memcpy(att_value.value, 0, BAS_MAX_VALUE_LEN); 
			}
					
            srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);                        
        }
		else if ((char_id == BAS_LEVEL_CHAR_UUID) && (des_id == BAS_CHAR_PRE_FMT_UUID))
		{
			att_value.len = 0;
            srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value); 
		}
        else
        {
            att_value.len = 1;
            att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
            srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
        }
	}
	else
	{
		att_value.len = 1;
		att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
		srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
	}
	//kal_prompt_trace(MOD_BT, "[BAS] bas_request_read_callback -!\n");
	
}

void bas_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
	//kal_prompt_trace(MOD_BT, "[BAS] bas_register_server_callback status %x, state %d, op_flag %d!\n", 
	//	             status, g_bas_cntx.state, g_bas_cntx.op_flag);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_REGISTER_CB, status, g_bas_cntx.state, g_bas_cntx.op_flag);
	
	if (memcmp(app_uuid, &g_bas_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if (g_bas_cntx.state == BAS_STATUS_ENABLING)
		{	
			if (status == OS_STATUS_SUCCESS)
			{
				g_bas_cntx.reg_ctx = reg_ctx;
				if (g_bas_cntx.op_flag == BAS_OP_INIT)
				{
					g_bas_cntx.op_flag = BAS_OP_ADD_SERVICE;
					#ifndef BAS_UT
					srv_gatts_profile_factory_get_services(g_bas_cntx.reg_ctx, PROFILE_ID_BAS, &g_bas_cntx.srv_list);
					srv_gatts_profile_factory_add_services(g_bas_cntx.reg_ctx, &g_bas_cntx.srv_list);
					#endif
				}
			}
			else
			{
				g_bas_cntx.reg_ctx = NULL;
				//g_bas_cntx.callback = NULL;
				g_bas_cntx.op_flag = BAS_OP_DEINIT;
				g_bas_cntx.state = BAS_STATUS_DISABLED;
			}
		}
		else if (g_bas_cntx.state == BAS_STATUS_DISABLING)
		{	
			if (g_bas_cntx.op_flag == BAS_OP_INIT)
			{
				g_bas_cntx.state = BAS_STATUS_ENABLING;
				#ifndef BAS_UT
				srv_gatts_profile_factory_register(&g_bas_cntx.uid, &g_bas_cb, &g_bas_factory_cb);
				#endif
			}
			else
			{
				g_bas_cntx.reg_ctx = NULL;
				//g_bas_cntx.callback = NULL;
				g_bas_cntx.op_flag = BAS_OP_DEINIT;
				g_bas_cntx.state = BAS_STATUS_DISABLED;
			}
		}
	}
	//kal_prompt_trace(MOD_BT, "[BAS] bas_register_server_callback -!\n");
}

void bas_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	BasConnCntx    *pConnNode = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);
	BasConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[BAS] bas_connection_callback connected %d!\n", connected);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_CONNECT_CB, connected);
	
	//if (!mmi_IsListEmpty(&g_bas_cntx.conn_list))
	//{
		while ((ListEntry *)pConnNode != &g_bas_cntx.conn_list)
		{
			pConnNext = (BasConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
			if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
			{
				//kal_prompt_trace(MOD_BT, "[BAS] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_IN_LIST);
				pConnNode->conn_ctx = conn->conn_ctx;
				if (connected && (pConnNode->conn_status != BAS_STATUS_CONNECTED))
				{
					//do next step Discovery all
					#ifndef BAS_UT
					if (SRV_BAS_MAX_DEV == srv_ble_cm_get_connected_dev_num())
	                {
					    srv_gatts_listen(conn->reg_ctx, FALSE);
	                }
	                //srv_gatts_listen(conn->reg_ctx, FALSE);
					//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
					#endif
					pConnNode->conn_status = BAS_STATUS_CONNECTED;
					#if 0
/* under construction !*/
/* under construction !*/
					#endif
				}
				else if (!connected)
				{
					#ifndef BAS_UT
					srv_gatts_listen(conn->reg_ctx, TRUE);
					#endif
					mmi_RemoveEntryList(&pConnNode->conn_node);
					//free_ctrl_buffer(pConnNode);
					StopTimer(BAS_SEND_NOTIFICATION_TIMER);
					if (NULL != g_bas_adm_id)
					{
						kal_adm_free(g_bas_adm_id,pConnNode);
					}
					
					#if 0
/* under construction !*/
/* under construction !*/
					#endif
				}
				return;
			}
			pConnNode = pConnNext;
		}
	//}
	//else
	//{
		if (connected)
		{
			//kal_prompt_trace(MOD_BT, "[BAS] not find in list!\n");	
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_NOT_FIND_IN_LIST);
			//pConnNode = (BasConnCntx *)get_ctrl_buffer(sizeof(BasConnCntx));
			
			pConnNode = (BasConnCntx *)kal_adm_alloc(g_bas_adm_id, sizeof(BasConnCntx));
			
			memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
			pConnNode->conn_ctx = conn->conn_ctx;
			#ifndef BAS_UT
			if (SRV_BAS_MAX_DEV == srv_ble_cm_get_connected_dev_num())
	        {
			    srv_gatts_listen(conn->reg_ctx, FALSE);
	        }
			#endif
			pConnNode->conn_status = BAS_STATUS_CONNECTED;
			mmi_InsertTailList(&g_bas_cntx.conn_list, &pConnNode->conn_node);
			#if 0
/* under construction !*/
/* under construction !*/
			#endif
		}
	//}
}

void bas_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                     ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                     BOOL need_rsp, BOOL is_prep)
{
	BasConnCntx     *pConnNode = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	ATT_UUID         desc_uuid;
	int              type = bas_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid, &desc_uuid);
	U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
	U16              desc_uuid16 = convert_array_to_uuid16(desc_uuid);
    S32              ret_val = 0;
    ATT_VALUE        noti_value;
	int              notify_status = 0;  //0, no need , 1 notify, 2 inditcaion
       
	//kal_prompt_trace(MOD_BT, "[BAS]bas_request_write_callback attr_handle %x, svc_uuid16 %x, chr_uuid16 %x, desc_uuid16 %x!\n", 
	//	             attr_handle, svc_uuid16, chr_uuid16, desc_uuid16);  
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_WRITE_CB, attr_handle, svc_uuid16, chr_uuid16, desc_uuid16);

	if (mmi_IsListEmpty(&g_bas_cntx.conn_list))
	{
		//kal_prompt_trace(MOD_BT, "[BAS] bas_request_write_callback doesn't connected!\n");
	    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_CONNECT_FAIL);
		return;
	}
	while ((ListEntry *)pConnNode != &g_bas_cntx.conn_list)
	{
		if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[BAS] value %x %d %d %d %d", 
            //             value->value[offset], value->len, offset, need_rsp, is_prep);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_WRITE_CB_VALUE, value->value[offset], 
						value->len, offset, need_rsp, is_prep);
                  
			if ((svc_uuid16 == BAS_SERVICE) && (chr_uuid16 == BAS_LEVEL_CHAR_UUID)
				&& (desc_uuid16 == BAS_CHAR_CONFIG_UUID))
			{
			    memset(&noti_value, 0, sizeof(ATT_VALUE));
				if ((value->value[0] == 1) || (value->value[0] == 3))
				{
					if (value->len >= BAS_MAX_VALUE_LEN)
					{
						memcpy(pConnNode->dec.dec_value.value, value->value, BAS_MAX_VALUE_LEN);
						pConnNode->dec.dec_value.len = BAS_MAX_VALUE_LEN;
					}
					else
					{
						memcpy(pConnNode->dec.dec_value.value, value->value, sizeof(value->value));
						pConnNode->dec.dec_value.len = value->len;
					}
					pConnNode->dec.is_dec_write = TRUE;
					pConnNode->dec.handle = attr_handle;
					notify_status = 1;
				}

				if (need_rsp)
				{
					srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &noti_value);
				}
				switch(notify_status)
				{
					case 2:
						srv_gatts_send_indication(conn, attr_handle, TRUE, &noti_value);
						break;
					case 1:
						mmi_frm_cb_reg_event(EVT_ID_SRV_CHARBAT_NOTIFY, bas_battery_change_handler, NULL);
						StartTimer(BAS_SEND_NOTIFICATION_TIMER,BAS_SEND_NOTIFICATION_TIME,(FuncPtr)bas_send_notification);
						break;
					case 0:
					default:
						break;
				}
			}
			else
			{
			    // fail, not support read
			    value->len = 1;
	            value->value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
				//kal_prompt_trace(MOD_BT, "[BAS]write callback:value.len %d, value->value[offset]:%d!", 
			    //    value->len, value->value[offset]);			
			    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_WRITE_RESPONSE_VALUE, value->len, value->value[offset]);
			    if (need_rsp)
				{
					srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value); 
				}
			}
			return;
		}
		pConnNode = (BasConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void bas_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
	//kal_prompt_trace(MOD_BT, "[BAS] bas_service_started_callback status %d, srvc_handle %d!\n", 
	//	             status, srvc_handle);	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_SERVICE_START_CB, status, srvc_handle);
	if (status == OS_STATUS_SUCCESS)
	{
		srv_gatts_listen(reg_ctx, TRUE);
	}
}


void bas_add_services_callback(OS_STATUS status, void *reg_ctx)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_bas_cntx.srv_list.srvlist);

	//kal_prompt_trace(MOD_BT, "[BAS] bas_add_services_callback status %d, state %d, op_flag %d!\n", 
	//	             status, g_bas_cntx.state, g_bas_cntx.op_flag);	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_SERVICE_ADD_CB, status, g_bas_cntx.state, g_bas_cntx.op_flag);
	
	if (g_bas_cntx.reg_ctx == reg_ctx)
	{
		if (g_bas_cntx.state == BAS_STATUS_ENABLING)
		{	
			if (status == OS_STATUS_SUCCESS)
			{
				if (g_bas_cntx.op_flag == BAS_OP_ADD_SERVICE)
				{
					if (mmi_IsListEmpty(&g_bas_cntx.srv_list.srvlist))
					{
						//kal_prompt_trace(MOD_BT, "[BAS] is empty service list!\n");
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_LIST_EMPTY);
						return;
					}
					while ((ListEntry *)svc_list != &g_bas_cntx.srv_list.srvlist)
					{
						if (svc_list->type == TYPE_SERVICE)
						{
							#ifndef BAS_UT
							srv_gatts_start_service(reg_ctx, svc_list->handle, GATT_TRANSPORT_LE);
							#endif
						}
						svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
					}
					g_bas_cntx.state = BAS_STATUS_ENABLED;
				}
			}
			else
			{
				bas_deinit();
			}
		}	
		
	}
	//kal_prompt_trace(MOD_BT, "[BAS] bas_add_services_callback -!\n");
}

void bas_bt_event_hdlr(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case SRV_BT_CM_EVENT_BLE_ACTIVATE:
            bas_init();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            bas_deinit();
            break;

		default :
			break;
	}
}

void bas_bootup_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	

	event_mask = SRV_BT_CM_EVENT_BLE_ACTIVATE |
				 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)bas_bt_event_hdlr, event_mask, NULL);
	return; 
}
BtStatus bas_disconnect_event_handler(BD_ADDR *bdaddr)
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	BasConnCntx    *pConnCur = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);

	//kal_prompt_trace(MOD_BT, "[BAS] bas_disconnect_event_handler !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_DISCONN_EVENT);
	if ((g_bas_cntx.state == BAS_STATUS_DISABLED)
		|| (g_bas_cntx.state == BAS_STATUS_DISABLING))
		return BT_STATUS_FAILED;

    while ((ListEntry *)pConnCur != &g_bas_cntx.conn_list)
	{
		//kal_prompt_trace(MOD_BT, "[BAS] bas_disconnect_event_handler pConnCur->bdaddr %s!\n",pConnCur->bdaddr);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_DISCONN_EVENT_ADDR, pConnCur->bdaddr);

		if (memcmp(bdaddr->addr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
	    {
			//kal_prompt_trace(MOD_BT, "[BAS] find in list conn_status %d !\n", pConnCur->conn_status);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_DISCONN_EVENT_STATUS, pConnCur->conn_status);
			gatt_conn.reg_ctx = g_bas_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if ((pConnCur->conn_status == BAS_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == BAS_STATUS_CONNECTING))
			{
				pConnCur->conn_status = BAS_STATUS_DISCONNECTING;
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				srv_gatts_disconnect(&gatt_conn, &bd_addr);
				#if 0
/* under construction !*/
/* under construction !*/
				#endif
				//kal_prompt_trace(MOD_BT, "[BAS] bas_disconnect_event_handler disconnected 1!\n");
				return BT_STATUS_SUCCESS;
			}
			else if ((pConnCur->conn_status == BAS_STATUS_DISCONNECTED) 
				|| (pConnCur->conn_status == BAS_STATUS_DISCONNECTING))
			{
			    #if 0
/* under construction !*/
/* under construction !*/
				#endif
				//kal_prompt_trace(MOD_BT, "[BAS] bas_disconnect_event_handler disconnected 2!\n");
				return BT_STATUS_SUCCESS;
			}			
			break;	
		}
		pConnCur = (BasConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}
	return BT_STATUS_FAILED;
}

void bas_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((U8 *)&dst->addr[0], (U8 *)&src->lap, 3);
    dst->addr[3] = src->uap;
    memcpy((U8 *)&dst->addr[4], (U8 *)&src->nap, 2);

}

mmi_ret bas_recv_event_handler(mmi_event_struct *evt)
{
    srv_le_cm_evt_disconnect_struct *disconn_data = (srv_le_cm_evt_disconnect_struct *)evt;
	//kal_prompt_trace(MOD_BT, "[BAS] bas_recv_event_handler evt->evt_id %d!\n",evt->evt_id);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_RECV_EVENT, evt->evt_id);
	    
    if ( evt->evt_id == SRV_LE_CM_EVENT_DISCONNECT_REQ ) 
    {
        BD_ADDR remote_addr;
		bas_get_bd_addr(&remote_addr,disconn_data->dev_addr);
		bas_disconnect_event_handler(&remote_addr);
		//kal_prompt_trace(MOD_BT, "[BAS] bas_recv_event_handler remote_addr %s!\n",remote_addr.addr);
		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_RECV_EVENT_ADDR, remote_addr.addr);
    }
    return MMI_RET_OK;
}


BtStatus bas_init()
{
	BtStatus status = BT_STATUS_SUCCESS;

	//kal_prompt_trace(MOD_BT, "[BAS] bas_init state %d, op_flag %d!\n", 
	//	             g_bas_cntx.state, g_bas_cntx.op_flag);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_INIT, g_bas_cntx.state, g_bas_cntx.op_flag);
		             
	mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, bas_recv_event_handler, NULL);

	if (NULL == g_bas_adm_id)
	{
		g_bas_adm_id = kal_adm_create(g_bas_mem_pool,BAS_MULTILINK_MAX_MEM_SIZE, NULL,KAL_FALSE);
		MMI_ASSERT(g_bas_adm_id);
	}
	if (g_bas_cntx.state == BAS_STATUS_DISABLED)
	{
		g_bas_cntx.state = BAS_STATUS_ENABLING;
		g_bas_cntx.op_flag = BAS_OP_INIT;
		//g_bas_cntx.callback = cb;
		memcpy(g_bas_cntx.uid.uu, &g_bas_uuid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_bas_cntx.conn_list);
		#ifndef BAS_UT
		srv_gatts_profile_factory_register(&g_bas_cntx.uid, &g_bas_cb, &g_bas_factory_cb);
		#endif
	}
	else if (g_bas_cntx.state == BAS_STATUS_DISABLING)
	{
		if (g_bas_cntx.op_flag == BAS_OP_DEINIT)
		{
			g_bas_cntx.op_flag = BAS_OP_INIT;
		}
		//g_bas_cntx.callback = cb;
		memcpy(g_bas_cntx.uid.uu, &g_bas_uuid, sizeof(bt_uuid_struct));
	}
	//kal_prompt_trace(MOD_BT, "[BAS] bas_init -!\n");
	return status;
}

BtStatus bas_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	BasConnCntx    *pConnCur = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);
	BasConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[BAS] bas_deinit state %d, op_flag %d!\n", 
	//	             g_bas_cntx.state, g_bas_cntx.op_flag);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_DEINIT, g_bas_cntx.state, g_bas_cntx.op_flag);
	if ((g_bas_cntx.state == BAS_STATUS_DISABLED)
		|| (g_bas_cntx.state == BAS_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;
	#ifndef BAS_UT
	//srv_gatts_listen(g_bas_cntx.reg_ctx, FALSE);
	#endif
	if (g_bas_cntx.state == BAS_STATUS_ENABLED)
	{
		if (mmi_IsListEmpty(&g_bas_cntx.conn_list))
		{
			//kal_prompt_trace(MOD_BT, "[BAS] is empty connection list!\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_LIST_EMPTY);
			goto do_deinit;
		}
		
        while ((ListEntry *)pConnCur != &g_bas_cntx.conn_list)
		{
			pConnNext = (BasConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_bas_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if((pConnCur->conn_status == BAS_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == BAS_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				#ifndef BAS_UT
				//srv_gatts_disconnect(&gatt_conn, &bd_addr);
				#endif
				#if 0
/* under construction !*/
/* under construction !*/
				#endif
			}
			mmi_RemoveEntryList(&pConnCur->conn_node);
			//free_ctrl_buffer(pConnCur);
			
			if (NULL != g_bas_adm_id)
			{
				kal_adm_free(g_bas_adm_id,pConnCur);
			}
			pConnCur = pConnNext;
		}
	}
	
do_deinit:
	#ifndef BAS_UT
	srv_gatts_profile_factory_delete_services(g_bas_cntx.reg_ctx, &g_bas_cntx.srv_list);
	srv_gatts_profile_factory_clear_services(g_bas_cntx.reg_ctx, &g_bas_cntx.srv_list);
	srv_gatts_profile_factory_deregister(g_bas_cntx.reg_ctx);
	#endif
	mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, bas_recv_event_handler, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_CHARBAT_NOTIFY, bas_battery_change_handler, NULL);
	StopTimer(BAS_SEND_NOTIFICATION_TIMER);
	
	g_bas_cntx.state = BAS_STATUS_DISABLED;
	g_bas_cntx.op_flag = BAS_OP_DEINIT;

    if (g_bas_adm_id != NULL)
    {
		kal_adm_delete(g_bas_adm_id);
		g_bas_adm_id = NULL;
    }
	
	//kal_prompt_trace(MOD_BT, "[BAS] bas_deinit -!\n");
	return BT_STATUS_SUCCESS;
}

S32 bas_send_notification(void)
{
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_bas_cntx.srv_list.srvlist);
    BasConnCntx    *pConnNode = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);
    BasConnCntx    *pConnNext = NULL;
    gatt_conn_struct gatt_conn;
    ATT_VALUE *att_value = NULL;
    ATT_UUID         svc_uuid;
    ATT_UUID         chr_uuid;
    ATT_UUID         desc_uuid;
    int type;
    U16  svc_uuid16;
    U16  chr_uuid16;
    U16  desc_uuid16;
    U32 send_size = 0; 
    
          
    if (!mmi_IsListEmpty(&g_bas_cntx.conn_list))
    {
        while ((ListEntry *)pConnNode != &g_bas_cntx.conn_list)
        {
            pConnNext = (BasConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            if (pConnNode->conn_status == BAS_STATUS_CONNECTED && pConnNode->dec.is_dec_write)
            {
                //kal_prompt_trace(MOD_BT, "[BAS] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_IN_LIST);
                gatt_conn.reg_ctx = g_bas_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while ((ListEntry *)svc_list != &g_bas_cntx.srv_list.srvlist)
                {          
                    //kal_prompt_trace(MOD_BT, "[BAS] find in list!\n");  
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_IN_LIST);
                    if (svc_list->type == TYPE_DESCRIPTOR)
                    {  
                        type = bas_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid, &desc_uuid);   
                        if (type != TYPE_DESCRIPTOR)
                        {
                            break;                          
                        }
                         
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
						desc_uuid16 = convert_array_to_uuid16(desc_uuid);
                        if (svc_uuid16 == BAS_SERVICE && chr_uuid16 == BAS_LEVEL_CHAR_UUID
							&& desc_uuid16 == BAS_CHAR_CONFIG_UUID)
                        {  
                        	U8 battery_level = 0;
						    battery_level = bas_get_battery_level();
							if (battery_level != g_battery_level)
							{
								g_battery_level = battery_level;
								send_size = sizeof(battery_level);
								if (send_size > BAS_MAX_VALUE_LEN)
								{
									send_size = BAS_MAX_VALUE_LEN;
								}
								 
								att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
								memcpy(att_value->value, &battery_level, send_size);
								att_value->len = send_size;
								//kal_prompt_trace(MOD_BT, "[BAS]bas_send_notification battery_level %d,len %d!", 
								//		battery_level, att_value->len);
								
								MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_SEND_NOTI_VALUE, battery_level, att_value->len);
								srv_gatts_send_indication(&gatt_conn, pConnNode->dec.handle - 1,FALSE, att_value);
								StopTimer(BAS_SEND_NOTIFICATION_TIMER);
								StartTimer(BAS_SEND_NOTIFICATION_TIMER,BAS_SEND_NOTIFICATION_TIME,(FuncPtr)bas_send_notification);
								free_ctrl_buffer(att_value);
								att_value = NULL;
							}

                            break;
                        }
                    }
                    svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
                }
                
                return send_size;
            }
            pConnNode = pConnNext;
        }

        return 0;
    }
    else
    {
        // no connecton 
        return  0;
    }
} 
U8 bas_get_battery_level()
{
    U8 bas_level = 0;
	bas_level = mmi_gpio_get_current_battery_level();
	
	//kal_prompt_trace(MOD_BT, "[BAS] bas_get_battery_level level = %d!\n",bas_level);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_GET_VALUE, bas_level);
	if ((bas_level - BATTERY_LEVEL_0) < 0)
	{
		return 0;
	}
	if ((bas_level - BATTERY_LEVEL_0) * BATTERY_LEVEL_PERCENTAGE >= BATTERY_LEVEL_TOTAL*BATTERY_LEVEL_PERCENTAGE)
	{
		return 100;
	}
	else
	{
		return (bas_level - BATTERY_LEVEL_0) * BATTERY_LEVEL_PERCENTAGE;
	}
}


S32 bas_update_battery_level(U8 bas_update_level)
{
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_bas_cntx.srv_list.srvlist);
    BasConnCntx    *pConnNode = (BasConnCntx *)mmi_GetHeadList(&g_bas_cntx.conn_list);
    BasConnCntx    *pConnNext = NULL;
    gatt_conn_struct gatt_conn;
    ATT_VALUE *att_value = NULL;
    ATT_UUID         svc_uuid;
    ATT_UUID         chr_uuid;
    ATT_UUID         desc_uuid;
    int type;
    U16  svc_uuid16;
    U16  chr_uuid16;
    U16  desc_uuid16;
    U32 send_size = 0; 
    
          
    if (!mmi_IsListEmpty(&g_bas_cntx.conn_list))
    {
        while ((ListEntry *)pConnNode != &g_bas_cntx.conn_list)
        {
            pConnNext = (BasConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            if (pConnNode->conn_status == BAS_STATUS_CONNECTED && pConnNode->dec.is_dec_write)
            {
                //kal_prompt_trace(MOD_BT, "[BAS] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_IN_LIST);
                gatt_conn.reg_ctx = g_bas_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while ((ListEntry *)svc_list != &g_bas_cntx.srv_list.srvlist)
                {          
                    //kal_prompt_trace(MOD_BT, "[BAS] find in list!\n");  
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_FIND_IN_LIST);
                    if (svc_list->type == TYPE_DESCRIPTOR)
                    {  
                        type = bas_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid, &desc_uuid);   
                        if (type != TYPE_DESCRIPTOR)
                        {
                            break;                          
                        }
                         
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
						desc_uuid16 = convert_array_to_uuid16(desc_uuid);
                        if (svc_uuid16 == BAS_SERVICE && chr_uuid16 == BAS_LEVEL_CHAR_UUID
							&& desc_uuid16 == BAS_CHAR_CONFIG_UUID)
                        {  
                        	U8 battery_level = 0;
						    battery_level = bas_update_level;
							if (battery_level != g_battery_level)
							{
								g_battery_level = battery_level;
								send_size = sizeof(battery_level);
								if (send_size > BAS_MAX_VALUE_LEN)
								{
									send_size = BAS_MAX_VALUE_LEN;
								}
								 
								att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
								memcpy(att_value->value, &battery_level, send_size);
								att_value->len = send_size;
								//kal_prompt_trace(MOD_BT, "[BAS]bas_update_battery_level battery_level %d,len %d!", 
								//		battery_level, att_value->len);
								
								MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_UPDATE_VALUE, battery_level, att_value->len);
								srv_gatts_send_indication(&gatt_conn, pConnNode->dec.handle - 1,FALSE, att_value);
								free_ctrl_buffer(att_value);
								att_value = NULL;
							}

                            break;
                        }
                    }
                    svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
                }
                
                return send_size;
            }
            pConnNode = pConnNext;
        }

        return 0;
    }
    else
    {
        // no connecton 
        return  0;
    }
} 

mmi_ret bas_battery_change_handler(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bas_level = 0;
    srv_charbat_evt_notify_struct *info = (srv_charbat_evt_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (info->evt_id)
	{
		//kal_prompt_trace(MOD_BT, "[BAS] bas_battery_change_handler event_id = %d!\n",info->evt_id);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_CHANGE_HANDLER, info->evt_id);
		case EVT_ID_SRV_CHARBAT_NOTIFY:
		{
			if ((info->battery_level - BATTERY_LEVEL_0) < 0)
			{
				bas_level = 0;
			}
			if ((info->battery_level - BATTERY_LEVEL_0) * 33 >= 99)
			{
				bas_level = 100;
			}
			else
			{
				bas_level = (info->battery_level - BATTERY_LEVEL_0) * 33;
			}
			bas_update_battery_level(bas_level);
		}
			break;
	    default:
			break;
	}
	return MMI_RET_OK;	

}


U8 bas_ut_handle(U8 index, kal_uint8 *string)
{
    U8 bas_new_level = 0;

	if(index == 0)
	{    
		if (strcmp((const kal_char*)string, "BAS_NOTIFY10" ) == 0)
		{
			bas_new_level = 10;
		}
		else if(strcmp((const kal_char*)string, "BAS_NOTIFY33" ) == 0)
		{
			bas_new_level = 33;
		}
		else if(strcmp((const kal_char*)string, "BAS_NOTIFY50" ) == 0)
		{
			bas_new_level = 50;
		}
		else if(strcmp((const kal_char*)string, "BAS_NOTIFY66" ) == 0)
		{
			bas_new_level = 66;
		}
		else if(strcmp((const kal_char*)string, "BAS_NOTIFY80" ) == 0)
		{
			bas_new_level = 80;
		} 
	    else if(strcmp((const kal_char*)string, "BAS_NOTIFY100" ) == 0)
		{
			bas_new_level = 100;
		}        
	     
		bas_update_battery_level(bas_new_level);
		//kal_prompt_trace(MOD_BT, "[BAS] bas_ut_handle level = %d!\n", bas_new_level); 
		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_BAS_UT_HANDLER, bas_new_level);
		return 1;// means success
	}

    return 0;
}


/* more modify event MSG_ID_MMI_EQ_BATTERY_STATUS_IND, EVT_ID_SRV_CHARBAT_NOTIFY*/

#endif  /* __MMI_BLE_BAS_SUPPORT__ */
