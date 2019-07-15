/*
 * Nanjing NWOW Technology Co.,Ltd.(C) 2019
 * www.nwowtec.com
 * dequan.wang@nwowtec.com
 * Create the AIOT ECU Software on March 27, 2019.
 * Software is eating up the world...
 * Across the Great Wall, we can reach every corner in the world. 
 *
 * */

/*
 * Filename:
 * ----------
 * aiot_ecu.c
 *
 * Project:
 * ----------
 * AIOT ECU
 *
 * Description:
 * ------------
 * AIOT ECU (Electronic Control Unit) Main Task.
 *
 * Author:
 * --------
 * WDQ
 *
 * */

/*****************************************************************************
 * Include                                                                     
 ****************************************************************************/
#include "aiot_ecu.h"
#include "kal_trace.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "common_nvram_editor_data_item.h"

/*****************************************************************************
 * Define                                                                      
 ****************************************************************************/

/*****************************************************************************
 * Typedef                                                                     
 ****************************************************************************/

/*****************************************************************************
 * Local Variable                                                              
 ****************************************************************************/

/*****************************************************************************
 * Extern Global Variable                                                      
 ****************************************************************************/

/*****************************************************************************
 * Local Function                                                              
 ****************************************************************************/

/*****************************************************************************
 * Extern Global Function                                                      
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  UT_timer
 * DESCRIPTION
 *  Unit testing Case  
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/

void UT_Case1_timer(void)
{
	static kal_uint16 UT_Case1_timer_count = 0;
	
	ecu_debug_print(MOD_MMI, "UT_case1_timer %d: ECU_UT_TIMER, 10s", ++UT_Case1_timer_count);
	StartTimer(ECU_UT_TIMER, 10*1000, UT_Case1_timer);
}


/*****************************************************************************
 * FUNCTION
 *  AIOT_ECU_Init
 * DESCRIPTION
 *  The main fuction of AIOT ECU 
 * PARAMETERS
 * 
 * RETURNS
 *
 ****************************************************************************/
void AIOT_ECU_Init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
 	/*----------------------------------------------------------------*/
	StartTimer(ECU_UT_TIMER, 10*1000, UT_Case1_timer);
}

