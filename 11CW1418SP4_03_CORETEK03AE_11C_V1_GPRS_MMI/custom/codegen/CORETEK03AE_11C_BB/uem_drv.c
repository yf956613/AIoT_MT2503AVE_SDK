/*
 * Generated by MTK DrvGen Version 10.01.0 for MT6261NP. Copyright MediaTek Inc. (C) 2012.
 * Wed May 08 10:40:43 2019
 * Do Not Modify the File.
 */

/*****************************************************************************
*
* Filename:
* ---------
*    ***.*
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*  
*
* Author:
* -------
*  dongming.li       Generated By DRV TOOL
*
*============================================================================
****************************************************************************/
#ifdef __CUST_NEW__
#include "kal_release.h"
#include "gpio_drv.h"
#include "custom_em.h"
#include "custom_equipment.h"


const kal_uint8 GPIO_LABELID_MAX = 1;
kal_uint8 EmGpioIdxMenu2Tbl[1];
const unsigned char netname[][MAX_NETNAME_TEXT] = {
"KEYPAD",
};
GPIO_MAP_ENTRY gpio_map_tbl[] = {
{GPIO_VALID, GPIO_PORT_21, netname[0], NULL},
};


const kal_uint8 EINT_LABELID_MAX = 2;
const unsigned char eintname[][MAX_NETNAME_TEXT] = {
"KEYPAD_WAKEUP_EINT_NO",
"POWER_KEY_EINT_NO",
};
GPIO_MAP_ENTRY eint_map_tbl[] = {
{GPIO_VALID, 25, eintname[0], NULL},
{GPIO_VALID, 33, eintname[1], NULL},
};


const kal_uint8 ADC_LABELID_MAX = 4;
const unsigned char adcname[][MAX_NETNAME_TEXT] = {
"ADC_VBAT",
"ADC_VISENSE",
"ADC_VCHARGER",
"ADC_VBATTMP",
};
GPIO_MAP_ENTRY adc_map_tbl[] = {
{GPIO_VALID, 0, adcname[0], NULL},
{GPIO_VALID, 1, adcname[1], NULL},
{GPIO_VALID, 2, adcname[2], NULL},
{GPIO_VALID, 3, adcname[3], NULL},
};


#endif /* __CUST_NEW__ */


