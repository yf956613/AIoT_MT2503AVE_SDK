/* EasyCASE V6.5 27/01/2011 11:09:29 */
/* EasyCASE O
If=vertical
LevelNumbers=no
LineNumbers=no
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,12632256,255,65280,255,255,16711935
ScreenFont=Courier New,Regular,90,4,-12,0,400,0,0,0,0,0,0,3,2,1,49,96,96
PrinterFont=Courier New,,80,4,-66,0,400,0,0,0,0,0,0,3,2,1,49,600,600
LastLevelId=100688 */
/* EasyCASE ( 1
   bma250.c */
/*
 ***************************************************************************************************
 *
 * (C) All rights reserved by ROBERT BOSCH GMBH
 *
 **************************************************************************************************/
/*  $Date: 2010/03/30
 *  $Revision: 1.01 $  
 *
 */

/**************************************************************************************************
* Copyright (C) 2007 Bosch Sensortec GmbH
*
* bma250.c
*
* Usage:        Sensor Driver for BMA250 Triaxial acceleration sensor
*
* Author:       yogananth.k@in.bosch.com
**************************************************************************************************/
/* EasyCASE ( 5
   Disclaimer */
/*************************************************************************************************/
/*  Disclaimer
*
* Common:
* Bosch Sensortec products are developed for the consumer goods industry. They may only be used
* within the parameters of the respective valid product data sheet.  Bosch Sensortec products are
* provided with the express understanding that there is no warranty of fitness for a particular purpose.
* They are not fit for use in life-sustaining, safety or security sensitive systems or any system or device
* that may lead to bodily harm or property damage if the system or device malfunctions. In addition,
* Bosch Sensortec products are not fit for use in products which interact with motor vehicle systems.
* The resale and/or use of products are at the purchaser�s own risk and his own responsibility. The
* examination of fitness for the intended use is the sole responsibility of the Purchaser.
*
* The purchaser shall indemnify Bosch Sensortec from all third party claims, including any claims for
* incidental, or consequential damages, arising from any product use not covered by the parameters of
* the respective valid product data sheet or not approved by Bosch Sensortec and reimburse Bosch
* Sensortec for all costs in connection with such claims.
*
* The purchaser must monitor the market for the purchased products, particularly with regard to
* product safety and inform Bosch Sensortec without delay of all security relevant incidents.
*
* Engineering Samples are marked with an asterisk (*) or (e). Samples may vary from the valid
* technical specifications of the product series. They are therefore not intended or fit for resale to third
* parties or for use in end products. Their sole purpose is internal client testing. The testing of an
* engineering sample may in no way replace the testing of a product series. Bosch Sensortec
* assumes no liability for the use of engineering samples. By accepting the engineering samples, the
* Purchaser agrees to indemnify Bosch Sensortec from all claims arising from the use of engineering
* samples.
*
* Special:
* This software module (hereinafter called "Software") and any information on application-sheets
* (hereinafter called "Information") is provided free of charge for the sole purpose to support your
* application work. The Software and Information is subject to the following terms and conditions:
*
* The Software is specifically designed for the exclusive use for Bosch Sensortec products by
* personnel who have special experience and training. Do not use this Software if you do not have the
* proper experience or training.
*
* This Software package is provided `` as is `` and without any expressed or implied warranties,
* including without limitation, the implied warranties of merchantability and fitness for a particular
* purpose.
*
* Bosch Sensortec and their representatives and agents deny any liability for the functional impairment
* of this Software in terms of fitness, performance and safety. Bosch Sensortec and their
* representatives and agents shall not be liable for any direct or indirect damages or injury, except as
* otherwise stipulated in mandatory applicable law.
*
* The Information provided is believed to be accurate and reliable. Bosch Sensortec assumes no
* responsibility for the consequences of use of such Information nor for any infringement of patents or
* other rights of third parties which may result from its use. No license is granted by implication or
* otherwise under any patent or patent rights of Bosch. Specifications mentioned in the Information are
* subject to change without notice.
*
* It is not allowed to deliver the source code of the Software to any third party without permission of
* Bosch Sensortec.
*/
/*************************************************************************************************/
/* EasyCASE ) */
/* EasyCASE ( 100012
   File Name For Doxy */
/*! \file bma250.c
    \brief Sensor Driver for BMA250 Triaxial acceleration sensor */
/* EasyCASE ) */
/* EasyCASE ( 247
   Includes */
/* EasyCASE ( 912
   Standard includes */
/* EasyCASE ) */
/* EasyCASE ( 100013
   Module includes */
#include "bma250.h"
#include "motion_sensor_custom.h"
#include "kal_release.h"


/* EasyCASE ) */
/* EasyCASE ) */
/* EasyCASE ( 63
   Local Declarations and Definitions */
/* EasyCASE ( 322
   Protected Data Interfaces (PDIs) */
/* EasyCASE ) */
/* EasyCASE ( 251
   #Define Constants */
/* user defined code to be added here ... */

//Example....
//#define YOUR_H_DEFINE         /**< <Description for YOUR_H_DEFINE> */
/* EasyCASE ) */
/* EasyCASE ( 222
   ENUM Definitions */
/* EasyCASE < */
/* user defined code to be added here ... */

//Example...
//typedef enum {
//E_YOURDATA1, /**< <DOXY Comment for E_YOURDATA1> */
//E_YOURDATA2  /**< <DOXY Comment for E_YOURDATA2> */
//}te_YourData;
/* EasyCASE > */
/* EasyCASE ) */
/* EasyCASE ( 217
   Variable Definitions */
/* user defined code to be added here ... */

//Example.....
//char v_Variable_u8r /**\brief <Description for v_Variable_u8r>*/

// const value
#define         C_Null_U8X                              (unsigned char)0
#define         C_Zero_U8X                              (unsigned char)0
#define         C_One_U8X                               (unsigned char)1
#define         C_Two_U8X                               (unsigned char)2
#define         C_Three_U8X                             (unsigned char)3
#define         C_Four_U8X                              (unsigned char)4
#define         C_Five_U8X                              (unsigned char)5
#define         C_Six_U8X                               (unsigned char)6
#define         C_Seven_U8X                             (unsigned char)7
#define         C_Eight_U8X                             (unsigned char)8
#define         C_Nine_U8X                              (unsigned char)9
#define         C_Ten_U8X                               (unsigned char)10
#define         C_Eleven_U8X                            (unsigned char)11
#define         C_Twelve_U8X                            (unsigned char)12
#define         C_Sixteen_U8X                           (unsigned char)16
#define         C_TwentyFour_U8X                        (unsigned char)24
#define         C_ThirtyTwo_U8X                         (unsigned char)32
#define         C_Hundred_U8X                           (unsigned char)100
#define         C_OneTwentySeven_U8X                    (unsigned char)127
#define         C_TwoFiftyFive_U8X                      (unsigned char)255
#define         C_TwoFiftySix_U16X                      (unsigned short)256

bma250_t * p_bma250;
/* EasyCASE ) */
/* EasyCASE ( 223
   Constant- and Table-Definitions in ROM/EEPROM */
/* user defined code to be added here ... */

//Example....
//char const C_ConstData /**\brief <Description for C_ConstData> */
/* EasyCASE ) */
/* EasyCASE ( 252
   Functions Prototype Declaration */
/* user defined code to be added here ... */
//Example...
//void Local_1(void);       /**\brief <Description for Local_1 function> */
/* EasyCASE ) */
/* EasyCASE ) */
/* EasyCASE ( 70
   API-Interface functions */
/* EasyCASE ( 100017
   bma250_init */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief API Initialization routine
 *
 *
 *
 *
 *  \param *bma250 pointer to bma250 structured type
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_init(bma250_t *bma250)
{
	int comres= C_Zero_U8X ;
	unsigned char data;

	p_bma250 = bma250;                                                                                                                                                      /* assign bma250 ptr */
	p_bma250->dev_addr = BMA250_I2C_ADDR;           /* preset bma250 I2C_addr */
	p_bma250->bus_write = acc_sensor_write_bytes;
	p_bma250->bus_read = acc_sensor_read_bytes;  
	comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_CHIP_ID__REG, &data, 1);     /* read Chip Id */

	p_bma250->chip_id = data ;                 /* get bitslice */
	//kal_prompt_trace(MOD_MMI, "%s: chip_id %x",__FUNCTION__, data); 
	comres += p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ML_VERSION__REG, &data, 1); /* read Version reg */
	p_bma250->ml_version = bma250_GET_BITSLICE(data, bma250_ML_VERSION);                            /* get ML Version */
	p_bma250->al_version = bma250_GET_BITSLICE(data, bma250_AL_VERSION);                            /* get AL Version */
	//kal_prompt_trace(MOD_MMI, "%s: enter bma250 line 234 ",__FUNCTION__); 
	return comres;
}

/** Get chip ID
	\param *chip_id
	\return result of communication routines 
*/
int bma250_get_chip_id(unsigned char *chip_id) 
{
	int comres;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
	comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_CHIP_ID__REG, chip_id, 1 ); 
	return comres;
}

/* EasyCASE ) */
/* EasyCASE ( 100018
   bma250_soft_reset */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  Perform soft reset of bma250 via bus command 
 *
 *
 *
 *
 *  \param None
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_soft_reset(void)
   {
   int comres = C_Zero_U8X ;
   unsigned char data = bma250_EN_SOFT_RESET_VALUE ;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SOFT_RESET__REG,&data ,C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100019
   bma250_write_reg */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API writes given data to the register
 *
 *
 *
 *
 *  \param       unsigned char addr  --> Address of the register to be written
 *               unsigned char *data --> Data to be written
 *               unsigned char len   --> Length of the data    
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_write_reg(unsigned char addr, unsigned char *data, unsigned char len)
   {
   int comres = C_Zero_U8X ;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, addr, data, len);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100020
   bma250_read_reg */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API reads data from the given register
 *
 *
 *
 *
 *  \param       unsigned char addr  --> Address of the register to be read
 *               unsigned char *data --> Read data will be placed in the pointer to variable. 
 *               unsigned char len   --> Length of the data    
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_read_reg(unsigned char addr, unsigned char *data, unsigned char len)
   {
   int comres = C_Zero_U8X ;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, addr, data, len);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100688
   bma250_get_temp */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API reads data from the given register
 *
 *
 *
 *
 *  \param       
 *               unsigned char *temp --> Read data will be placed in the pointer to variable. 
 *               
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_temp(unsigned char *temp)
   {
   int comres = C_Zero_U8X ;
   unsigned char data ;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TEMP_RD_REG, &data, C_One_U8X);
      *temp = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100021
   bma250_set_mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API sets the function mode of the sensor
 *
 *
 *
 *
 *  \param       unsigned char mode  --> value to be set in mode register.
 *                        mode --> 0 --> Normal mode
 *                        mode --> 1 --> Low Power  
 *                        mode --> 2 --> Suspend 
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_mode(unsigned char Mode)
   {
   int comres=C_Zero_U8X ;
   unsigned char data1;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      if (Mode < C_Three_U8X)
         {
         comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_LOW_POWER__REG, &data1, C_One_U8X );
         switch (Mode)
            {
            case bma250_MODE_NORMAL:
               data1  = bma250_SET_BITSLICE(data1, bma250_EN_LOW_POWER, C_Zero_U8X);
               data1  = bma250_SET_BITSLICE(data1, bma250_EN_SUSPEND, C_Zero_U8X);
               break;
            case bma250_MODE_LOWPOWER:
               data1  = bma250_SET_BITSLICE(data1, bma250_EN_LOW_POWER, C_One_U8X);
               data1  = bma250_SET_BITSLICE(data1, bma250_EN_SUSPEND, C_Zero_U8X);
               break;
            case bma250_MODE_SUSPEND:
               data1  = bma250_SET_BITSLICE(data1, bma250_EN_LOW_POWER, C_Zero_U8X);
               data1  = bma250_SET_BITSLICE(data1, bma250_EN_SUSPEND, C_One_U8X);
               break;
            default:
               break;
            }
         comres += p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_LOW_POWER__REG, &data1, C_One_U8X);
         p_bma250->mode = Mode;
         }
      else
         {
         comres = E_OUT_OF_RANGE ;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100022
   bma250_get_mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the function mode of the sensor
 *
 *
 *
 *
 *  \param       unsigned char *mode  --> value read from the mode register.
 *                        mode --> 00 --> Normal mode
 *                        mode --> 01 --> Low Power  
 *                        mode --> 10 --> Suspend 
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_mode(unsigned char * Mode )
   {
   int comres= C_Zero_U8X;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_LOW_POWER__REG, Mode, C_One_U8X );
      *Mode  = (*Mode) >> C_Six_U8X;
      /* EasyCASE - */
      p_bma250->mode = *Mode;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100044
   bma250_set_range */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the g-range 
 *
 *
 *
 *
 *  \param Possible Values :
 *               unsigned char Range
 *                              0           +/-2 g
 *                              1           +/-4 g
 *                              2           +/-8 g
 *                              3           +/-16 g
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
unsigned char bma250_set_range(unsigned char Range)
   {
   int comres=C_Zero_U8X ;
   unsigned char data1;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      if (Range < C_Four_U8X)
         {
         comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_RANGE_SEL_REG, &data1, C_One_U8X );
         switch (Range)
            {
            case C_Zero_U8X:
               data1  = bma250_SET_BITSLICE(data1, bma250_RANGE_SEL, C_Three_U8X);
               break;
            case C_One_U8X:
               data1  = bma250_SET_BITSLICE(data1, bma250_RANGE_SEL, C_Five_U8X);
               break;
            case C_Two_U8X:
               data1  = bma250_SET_BITSLICE(data1, bma250_RANGE_SEL, C_Eight_U8X);
               break;
            case C_Three_U8X:
               data1  = bma250_SET_BITSLICE(data1, bma250_RANGE_SEL, C_Twelve_U8X);
               break;
            default:
               break;
            }
         comres += p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_RANGE_SEL_REG, &data1, C_One_U8X);
         }
      else
         {
         comres = E_OUT_OF_RANGE ;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100024
   bma250_get_range */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the g-range currently set
 *
 *
 *
 *
 *  \param Possible Values :
 *               unsigned char *Range
 *                              0101           +/-4 g
 *                              1000           +/-8 g
 *                              1100           +/-16 g
 *                              others         +/-2 g
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_range(unsigned char * Range )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_RANGE_SEL__REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_RANGE_SEL);
      *Range = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100025
   bma250_set_bandwidth */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the bandwidth
 *
 *
 *
 *
 *  \param Possible Values :
 *               unsigned char BW
 *
 *               bw       Selected Bandwidth[Hz]       Tupdate [us]
 *              =================================================
 *               8            7.81                       64000
 *               9            15.63                      32000
 *               10           31.25                      16000
 *               11           62.50                      8000
 *               12           125                        4000
 *               13           250                        2000
 *               14           500                        1000
 *               15           1000                       500
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_bandwidth(unsigned char BW)
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   int Bandwidth ;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      if (BW > C_Seven_U8X)
         {
         switch (BW)
            {
            case bma250_BW_7_81HZ:
               Bandwidth = bma250_BW_7_81HZ;
               
               /*  7.81 Hz      64000 uS   */
               break;
            case bma250_BW_15_63HZ:
               Bandwidth = bma250_BW_15_63HZ;
               
               /*  15.63 Hz     32000 uS   */
               break;
            case bma250_BW_31_25HZ:
               Bandwidth = bma250_BW_31_25HZ;
               
               /*  31.25 Hz     16000 uS   */
               break;
            case bma250_BW_62_50HZ:
               Bandwidth = bma250_BW_62_50HZ;
               
               /*  62.50 Hz     8000 uS   */
               break;
            case bma250_BW_125HZ:
               Bandwidth = bma250_BW_125HZ;
               
               /*  125 Hz       4000 uS   */
               break;
            case bma250_BW_250HZ:
               Bandwidth = bma250_BW_250HZ;
               
               /*  250 Hz       2000 uS   */
               break;
            case bma250_BW_500HZ:
               Bandwidth = bma250_BW_500HZ;
               
               /*  500 Hz       1000 uS   */
               break;
            case bma250_BW_1000HZ:
               Bandwidth = bma250_BW_1000HZ;
               
               /*  1000 Hz      500 uS   */
               break;
            default:
               break;
            }
         comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_BANDWIDTH__REG, &data, C_One_U8X );
         data = bma250_SET_BITSLICE(data, bma250_BANDWIDTH, Bandwidth );
         comres += p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_BANDWIDTH__REG, &data, C_One_U8X );
         }
      else
         {
         comres = E_OUT_OF_RANGE ;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100026
   bma250_get_bandwidth */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the bandwidth
 *
 *
 *
 *
 *  \param Possible Values :
 *               unsigned char BW
 *
 *               bw       Selected Bandwidth[Hz]       Tupdate [us]
 *              =================================================
 *               8            7.81                       64000
 *               9            15.63                      32000
 *               10           31.25                      16000
 *               11           62.50                      8000
 *               12           125                        4000
 *               13           250                        2000
 *               14           500                        1000
 *               15           1000                       500
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_bandwidth(unsigned char *BW)
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_BANDWIDTH__REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_BANDWIDTH);
      *BW = data ;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100027
   bma250_read_accel_xyz */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the X,Y and Z-axis acceleration data readout 
 *
 *
 *
 *
 *  \param    *acc pointer to \ref bma250acc_t structure for x,y,z data readout
 *          \note data will be read by multi-byte protocol into a 6 byte structure
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_read_accel_xyz(bma250acc_t * acc)
   {
   int comres;
   unsigned char data[6];
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ACC_X_LSB__REG, data,6);
      
      acc->x = bma250_GET_BITSLICE(data[0],bma250_ACC_X_LSB) | (bma250_GET_BITSLICE(data[1],bma250_ACC_X_MSB)<<bma250_ACC_X_LSB__LEN);
      acc->x = acc->x << (sizeof(short)*8-(bma250_ACC_X_LSB__LEN + bma250_ACC_X_MSB__LEN));
      acc->x = acc->x >> (sizeof(short)*8-(bma250_ACC_X_LSB__LEN + bma250_ACC_X_MSB__LEN));
      
      acc->y = bma250_GET_BITSLICE(data[2],bma250_ACC_Y_LSB) | (bma250_GET_BITSLICE(data[3],bma250_ACC_Y_MSB)<<bma250_ACC_Y_LSB__LEN);
      acc->y = acc->y << (sizeof(short)*8-(bma250_ACC_Y_LSB__LEN + bma250_ACC_Y_MSB__LEN));
      acc->y = acc->y >> (sizeof(short)*8-(bma250_ACC_Y_LSB__LEN + bma250_ACC_Y_MSB__LEN));
      
      acc->z = bma250_GET_BITSLICE(data[4],bma250_ACC_Z_LSB) | (bma250_GET_BITSLICE(data[5],bma250_ACC_Z_MSB)<<bma250_ACC_Z_LSB__LEN);
      acc->z = acc->z << (sizeof(short)*8-(bma250_ACC_Z_LSB__LEN + bma250_ACC_Z_MSB__LEN));
      acc->z = acc->z >> (sizeof(short)*8-(bma250_ACC_Z_LSB__LEN + bma250_ACC_Z_MSB__LEN));
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100028
   bma250_read_accel_x */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the X axis acceleration data  
 *
 *
 *
 *
 *  \param  *a_x pointer for 16 bit 2's compliment data output (LSB aligned)
 *         
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_read_accel_x(short *a_x)
   {
   int comres;
   unsigned char data[2];
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ACC_X_LSB__REG, data, 2);
      *a_x = bma250_GET_BITSLICE(data[0],bma250_ACC_X_LSB) | (bma250_GET_BITSLICE(data[1],bma250_ACC_X_MSB)<<bma250_ACC_X_LSB__LEN);
      *a_x = *a_x << (sizeof(short)*8-(bma250_ACC_X_LSB__LEN+bma250_ACC_X_MSB__LEN));
      *a_x = *a_x >> (sizeof(short)*8-(bma250_ACC_X_LSB__LEN+bma250_ACC_X_MSB__LEN));
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100029
   bma250_read_accel_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the Y axis acceleration data  
 *
 *
 *
 *
 *  \param  *a_y pointer for 16 bit 2's compliment data output (LSB aligned)
 *         
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_read_accel_y(short *a_y)
   {
   int comres;
   unsigned char data[2];
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ACC_Y_LSB__REG, data, 2);
      *a_y = bma250_GET_BITSLICE(data[0],bma250_ACC_Y_LSB) | (bma250_GET_BITSLICE(data[1],bma250_ACC_Y_MSB)<<bma250_ACC_Y_LSB__LEN);
      *a_y = *a_y << (sizeof(short)*8-(bma250_ACC_Y_LSB__LEN+bma250_ACC_Y_MSB__LEN));
      *a_y = *a_y >> (sizeof(short)*8-(bma250_ACC_Y_LSB__LEN+bma250_ACC_Y_MSB__LEN));
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100030
   bma250_read_accel_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the Z axis acceleration data  
 *
 *
 *
 *
 *  \param  *a_z pointer for 16 bit 2's compliment data output (LSB aligned)
 *         
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_read_accel_z(short *a_z)
   {
   int comres;
   unsigned char data[2];
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ACC_Z_LSB__REG, data, 2);
      *a_z = bma250_GET_BITSLICE(data[0],bma250_ACC_Z_LSB) | bma250_GET_BITSLICE(data[1],bma250_ACC_Z_MSB)<<bma250_ACC_Z_LSB__LEN;
      *a_z = *a_z << (sizeof(short)*8-(bma250_ACC_Z_LSB__LEN+bma250_ACC_Z_MSB__LEN));
      *a_z = *a_z >> (sizeof(short)*8-(bma250_ACC_Z_LSB__LEN+bma250_ACC_Z_MSB__LEN));
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100032
   bma250_reset_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API resets the interrupt  
 *
 *
 *
 *
 *  \param  none
 *         
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_reset_interrupt(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_RESET_LATCHED__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_INT_RESET_LATCHED, C_One_U8X );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT_RESET_LATCHED__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100684
   bma250_get_interruptstatus */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the interrupt status register 
 *                    interrupt status register 0x09 to 0xC (4 bytes)
 *
 *
 *
 *  \param unsigned char *intstatus 
 *                       Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_interruptstatus(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, intstatus, C_Four_U8X );
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100053
   bma250_get_interruptstatus1 */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the interrupt status1 register
 *
 *
 *
 *
 *  \param unsigned char *intstatus 
 *                       Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_interruptstatus1(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100061
   bma250_get_interruptstatus2 */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the interrupt status2 register
 *
 *
 *
 *
 *  \param      unsigned char *intstatus 
 *                       Interrupt status will be stored to pointer to a variable  
 *
 *
 *
 *  \return     result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_interruptstatus2(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS2_REG, &data, C_One_U8X );
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100065
   bma250_get_Low_G_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the Low G interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_Low_G_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_LOWG_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100067
   bma250_get_High_G_Interrupt */
/* Compiler Switch if applicable
#ifdef

#endif
*/
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the High G interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_High_G_Interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_HIGHG_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100069
   bma250_get_slope_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the slope interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_slope_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SLOPE_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100071
   bma250_get_double_tap_interrupt */
/* Compiler Switch if applicable
#ifdef

#endif
*/
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the double tap interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_double_tap_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_DOUBLE_TAP_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100073
   bma250_get_single_tap_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the single tap interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_single_tap_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SINGLE_TAP_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100075
   bma250_get_orient_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the orient interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_ORIENT_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100079
   bma250_get_flat_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the flat interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_flat_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS1_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_FLAT_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100083
   bma250_get_data_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the data interrupt
 *
 *
 *
 *
 *  \param unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_data_interrupt(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS2_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_DATA_INT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100087
   bma250_get_slope_first */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the slope first
 *
 *
 *
 *
 *  \param 
 *            unsigned char param   
 *                        0 -- > Slope First X
 *                        1 -- > Slope First Y
 *                        2 -- > Slope First Z
 *
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_slope_first(unsigned char param,unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_SLOPE_FIRST_X);
            *intstatus = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_SLOPE_FIRST_Y);
            *intstatus = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_SLOPE_FIRST_Z);
            *intstatus = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100096
   bma250_get_slope_sign */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the slope sign
 *
 *
 *
 *
 *  \param 
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_slope_sign(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SLOPE_SIGN_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100097
   bma250_get_tap_first */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the tap first
 *
 *
 *
 *
 *  \param 
 *            unsigned char param   
 *                        0 -- > Tap First X
 *                        1 -- > Tap First Y
 *                        2 -- > Tap First Z
 *
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_first(unsigned char param,unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_TAP_FIRST_X);
            *intstatus = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_TAP_FIRST_Y);
            *intstatus = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_TAP_FIRST_Z);
            *intstatus = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100101
   bma250_get_tap_sign */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the tap sign
 *
 *
 *
 *
 *  \param 
 *            unsigned char *intstatus          
 *              Interrupt status will be stored to pointer to a variable            
 *          
 *          
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_sign(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_TAP_SLOPE_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_TAP_SIGN_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100102
   bma250_get_HIGH_first */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the HIGH first
 *
 *
 *
 *
 *  \param 
 *            unsigned char param   
 *                        0 -- > High g First X
 *                        1 -- > High g First Y
 *                        2 -- > High g First Z
 *
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_HIGH_first(unsigned char param,unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_ORIENT_HIGH_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_HIGHG_FIRST_X);
            *intstatus = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_ORIENT_HIGH_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_HIGHG_FIRST_Y);
            *intstatus = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_ORIENT_HIGH_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_HIGHG_FIRST_Z);
            *intstatus = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100106
   bma250_get_HIGH_sign */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the HIGH sign
 *
 *
 *
 *
 *  \param 
 *         
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_HIGH_sign(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_ORIENT_HIGH_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_HIGHG_SIGN_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100107
   bma250_get_orient_status */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the orient status
 *
 *
 *
 *
 *  \param 
 *         
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_status(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_ORIENT_HIGH_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_ORIENT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100108
   bma250_get_orient_flat_status */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the orient flat status
 *
 *
 *
 *
 *  \param 
 *         
 *            unsigned char *intstatus
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_flat_status(unsigned char *intstatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_ORIENT_HIGH_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_FLAT_S);
      *intstatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100113
   bma250_get_sleep_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the sleep duration
 *
 *
 *
 *
 *  \param 
 *         
 *            unsigned char *sleep
 *              Interrupt status will be stored to pointer to a variable  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_sleep_duration(unsigned char *sleep )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_MODE_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SLEEP_DUR);
      *sleep = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100122
   bma250_set_sleep_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the sleep duration
 *
 *
 *
 *
 *  \param              unsigned char sleepdur
 *
 *
 *                     sleepdur 
 *                      0000 --> 0.5ms
 *                      0001 --> 0.5ms
 *                      0010 --> 0.5ms
 *                      0011 --> 0.5ms
 *                      0100 --> 0.5ms
 *                      0101 --> 0.5ms
 *                      0110 --> 1ms
 *                      0111 --> 2ms
 *                      1000 --> 4ms
 *                      1001 --> 6ms
 *                      1010 --> 10ms
 *                      1011 --> 25ms
 *                      1100 --> 50ms
 *                      1101 --> 100ms
 *                      1110 --> 500ms
 *                      1111 --> 1s
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_sleep_duration(unsigned char sleepdur )
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SLEEP_DUR__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_SLEEP_DUR, sleepdur );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_SLEEP_DUR__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100130
   bma250_set_suspend */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets/Resets the Suspend mode
 *
 *
 *
 *
 *  \param
 *                 unsigned char State:
 *                             0 -- > Disable suspend mode
 *                             1 -- > Enable suspend mode
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return     result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_suspend(unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SUSPEND__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_SUSPEND, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SUSPEND__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100428
   bma250_get_suspend */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the suspend mode register bit
 *
 *
 *
 *
 *  \param unsigned char *status
 *                  Read status will be placed in pointer to a variable
 *
 *
 *  \return  result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_suspend(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_MODE_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_SUSPEND);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100126
   bma250_set_lowpower */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets/resets the Lowpower register bit
 *
 *
 *
 *
 *  \param
 *
 *             unsigned char state:         
 *                     State:
 *                             0 -- > Resets the Low power register bit
 *                             1 -- > Sets the Low power regsiter bit
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_lowpower(unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_LOW_POWER__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_LOW_POWER, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_LOW_POWER__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100432
   bma250_get_lowpower_en */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the lowpower register bit status
 *
 *
 *
 *
 *  \param unsigned char *status
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_lowpower_en(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_MODE_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_LOW_POWER);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100134
   bma250_set_low_noise_ctrl */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief   This API sets the Low noise ctrl bit
 *
 *
 *
 *
 *  \param
 *              unsigned char state
 *                          State:
 *                             0 -- > Disable
 *                             1 -- > Enable
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_low_noise_ctrl(unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_LOW_NOISE__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_LOW_NOISE, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_LOW_NOISE__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100436
   bma250_get_low_noise_ctrl */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API gets the low noise ctrl register bit              
 *
 *
 *
 *
 *  \param unsigned char *status
 *                      0 -- > Disabled
 *                      1 -- > Enabled
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_low_noise_ctrl(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOW_NOISE_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_LOW_NOISE);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100138
   bma250_set_shadow_disable */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API disables the shadow procedure
 *
 *
 *
 *
 *  \param    None
 *                     
 *                     
 *                     
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_shadow_disable(unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_DIS_SHADOW_PROC__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_DIS_SHADOW_PROC, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_DIS_SHADOW_PROC__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100440
   bma250_get_shadow_disable */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the Shadow disable bit status
 *
 *
 *
 *
 *  \param unsigned char *status
 *                    1 --> Shadow procedure disabled
 *                    0 --> Shadow procedure Not disabled
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_shadow_disable(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_DATA_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_DIS_SHADOW_PROC);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100142
   bma250_set_unfilt_acc */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the unfitl_acc 
 *                      Unfiltered accelatration data are stored in Data register  
 *
 *
 *
 *  \param    None
 *                     
 *                     
 *                     
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_unfilt_acc(unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_UNFILT_ACC__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_UNFILT_ACC, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_UNFILT_ACC__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100442
   bma250_get_unfilt_acc */
/* Compiler Switch if applicable
#ifdef

#endif
*/
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the Unfilt_acc register bit status.           
 *
 *
 *
 *
 *  \param              unsigned char *status
 *                              0 --> Filtered accel data are stored in the data register
 *                              1 --> UnFiltered accel data are stored in the data register
 *
 *  \return     result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_unfilt_acc(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_DATA_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_UNFILT_ACC);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100146
   bma250_set_enable_slope_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API Enables the slope interrupt
 *
 *
 *
 *
 *  \param
 *                     State:
 *                             0 -- > enable slope x
 *                             1 -- > enable slope y
 *                             2 -- > enable slope z 
 *                             3 -- > enable slope XYZ
 *
 *
 *
 *
 *
 *
 *  \return             result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_enable_slope_interrupt(unsigned char slope)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (slope)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_X_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOPE_X_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_X_INT__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_Y_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOPE_Y_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_Y_INT__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_Z_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOPE_Z_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_Z_INT__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            state = 0x07;
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_XYZ_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOPE_XYZ_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOPE_XYZ_INT__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100446
   bma250_get_enable_slope_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of the slope interrupt
 *
 *
 *
 *
 *  \param
 *              unsigned char param
 *                                      0 -- > EN_SLOPE_X  
 *                                      1 -- > EN_SLOPE_Y   
 *                                      2 -- > EN_SLOPE_Z        
 *
 *              unsigned char *staus
 *                                      status of the slope interrupt
 *                                     
 *
 *
 *
 *  \return       result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_enable_slope_interrupt(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SLOPE_X_INT);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SLOPE_Y_INT);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SLOPE_Z_INT);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100165
   bma250_set_enable_tap_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API enables the double tap, single tap , orient and flat interrupt
 *
 *
 *
 *
 *  \param
 *                     State:
 *                             0 -- > enable double tap interrupt
 *                             1 -- > enable single tap interrupt
 *                             2 -- > enable orient interrupt 
 *                             3 -- > enable flat interrupt
 *                             
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_enable_tap_interrupt(unsigned char tapinterrupt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = C_One_U8X;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (tapinterrupt)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_DOUBLE_TAP_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_DOUBLE_TAP_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_DOUBLE_TAP_INT__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SINGLE_TAP_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SINGLE_TAP_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SINGLE_TAP_INT__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_ORIENT_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_ORIENT_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_ORIENT_INT__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_FLAT_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_FLAT_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_FLAT_INT__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100454
   bma250_get_enable_tap_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of the tap double tap , single tap,orient and flat interrupt  
 *
 *
 *
 *
 *  \param unsigned char param 
 *                       0 --> Double Tap
 *                       1 --> Single Tap
 *                       2 --> Orient Interrupt
 *                       3 --> Flat interrupt  
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_enable_tap_interrupt(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_DOUBLE_TAP_INT);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SINGLE_TAP_INT);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_ORIENT_INT);
            *status = data;
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_FLAT_INT);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100169
   bma250_set_enable_high_g_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the HIGH G interrupt enable bit
 *
 *
 *
 *
 *  \param
 *                     State:
 *                             0 -- > enable high x
 *                             1 -- > enable high y
 *                             2 -- > enable high z 
 *                             3 -- > enable high XYZ
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_enable_high_g_interrupt(unsigned char highinterrupt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (highinterrupt)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_X_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_HIGHG_X_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_X_INT__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_Y_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_HIGHG_Y_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_Y_INT__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_Z_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_HIGHG_Z_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_Z_INT__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            state = 0x07;
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_XYZ_INT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_HIGHG_XYZ_INT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_HIGHG_XYZ_INT__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100461
   bma250_get_enable_high_g_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the High G interrupt status bit
 *
 *
 *
 *
 *  \param
 *                     State:
 *                             0 -- > enable high x
 *                             1 -- > enable high y
 *                             2 -- > enable high z 
 *                             3 -- > enable high XYZ
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_enable_high_g_interrupt(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_HIGHG_X_INT);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_HIGHG_Y_INT);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_HIGHG_Z_INT);
            *status = data;
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_HIGHG_XYZ_INT);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100173
   bma250_set_enable_low_g_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API enables the low g interrupt
 *
 *
 *
 *
 *  \param              None                                    
 *                     
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return     result of communication reoutines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_enable_low_g_interrupt(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state= 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_LOWG_INT__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_LOWG_INT, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_LOWG_INT__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100465
   bma250_get_enable_low_g_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API get the status of low g interrupt          
 *
 *
 *
 *
 *  \param unsigned char *status
 *      
 *
 *
 *  \return     Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_enable_low_g_interrupt(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_LOWG_INT);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100179
   bma250_set_enable_data_interrupt */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API enables the data interrupt         
 *
 *
 *
 *
 *  \param None         
 *                     
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_enable_data_interrupt(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state= 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_NEW_DATA_INT__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_NEW_DATA_INT, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_NEW_DATA_INT__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100469
   bma250_get_enable_data_interrupt */
/* Compiler Switch if applicable
#ifdef

#endif
*/
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the enable status of the data interrupt
 *
 *
 *
 *
 *  \param unsigned char *status
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_enable_data_interrupt(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_NEW_DATA_INT);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100175
   bma250_set_int1_pad_sel */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the  INTL pad select register
 *
 *
 *
 *
 *  \param
 *               unsigned char intlsel
 *
 *                             0 -- > int1_low
 *                             1 -- > int1_High
 *                             2 -- > int1_slope         
 *                             3 -- > int1_d_tap
 *                             4 -- > int1_s_tap
 *                             5 -- > int1_orient
 *                             6 -- > int1_flat
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_int1_pad_sel(unsigned char int1sel)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (int1sel)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_LOWG__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_LOWG, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_LOWG__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_HIGHG__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_HIGHG, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_HIGHG__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_SLOPE__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_SLOPE, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_SLOPE__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_DB_TAP__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_DB_TAP, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_DB_TAP__REG, &data, C_One_U8X);
            break;
         case C_Four_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_SNG_TAP__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_SNG_TAP, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_SNG_TAP__REG, &data, C_One_U8X);
            break;
         case C_Five_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_ORIENT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_ORIENT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_ORIENT__REG, &data, C_One_U8X);
            break;
         case C_Six_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_FLAT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_FLAT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_FLAT__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100473
   bma250_get_int1_pad_sel */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the INTL pad sel register status
 *
 *
 *
 *
 *  \param
 *                   unsigned char intlsel
 *
 *                             0 -- > int1_low
 *                             1 -- > int1_High
 *                             2 -- > int1_slope         
 *                             3 -- > int1_d_tap
 *                             4 -- > int1_s_tap
 *                             5 -- > int1_orient
 *                             6 -- > int1_flat
 *
 *              unsigned char *status
 *                             0 --> Disabled 
 *                             1 --> Enabled
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_int1_pad_sel(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_LOWG);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_HIGHG);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_SLOPE);
            *status = data;
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_DB_TAP);
            *status = data;
            break;
         case C_Four_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_SNG_TAP);
            *status = data;
            break;
         case C_Five_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_ORIENT);
            *status = data;
            break;
         case C_Six_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_FLAT);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100199
   bma250_set_int_data_sel */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the int1 & int2 register
 *
 *
 *
 *
 *  \param
 *                     intsel
 *                             0 -- > int1_data
 *                             1 -- > int2_data
 *                           
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_int_data_sel(unsigned char intsel)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = C_One_U8X;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (intsel)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_NEWDATA__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT1_PAD_NEWDATA, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT1_PAD_NEWDATA__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_NEWDATA__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_NEWDATA, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_NEWDATA__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100484
   bma250_get_int_data_sel */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of int data sel
 *
 *
 *
 *
 *  \param unsigned char param
 *                      0 -- > INT1_PAD_DATA
 *                      1 -- > INT2_PAD_DATA
 *         unsigned char *status
 *                      0 -- > Disbled
 *                      1 -- > Enabled
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_int_data_sel(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_DATA_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT1_PAD_NEWDATA);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_DATA_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_NEWDATA);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100203
   bma250_set_int2_pad_sel */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API enables the int2_pad sel
 *
 *
 *
 *
 *  \param
 *              unsigned char int2sel
 *                    int2sel:
 *                             0 -- > int2_low
 *                             1 -- > int2_High
 *                             2 -- > int2_slope         
 *                             3 -- > int2_d_tap
 *                             4 -- > int2_s_tap
 *                             5 -- > int2_orient
 *                             6 -- > int2_flat
 *
 *
 *
 *  \return Result of communication routine
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_int2_pad_sel(unsigned char int2sel)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = C_One_U8X;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (int2sel)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_LOWG__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_LOWG, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_LOWG__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_HIGHG__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_HIGHG, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_HIGHG__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_SLOPE__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_SLOPE, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_SLOPE__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_DB_TAP__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_DB_TAP, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_DB_TAP__REG, &data, C_One_U8X);
            break;
         case C_Four_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_SNG_TAP__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_SNG_TAP, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_SNG_TAP__REG, &data, C_One_U8X);
            break;
         case C_Five_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_ORIENT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_ORIENT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_ORIENT__REG, &data, C_One_U8X);
            break;
         case C_Six_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_FLAT__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_INT2_PAD_FLAT, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_INT2_PAD_FLAT__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100488
   bma250_get_int2_pad_sel */
/* Compiler Switch if applicable
#ifdef

#endif
*/
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of int2 pad sel            
 *
 *
 *
 *
 *  \param
 *               unsigned char int2sel
 *                    int2sel:
 *                             0 -- > int2_low
 *                             1 -- > int2_High
 *                             2 -- > int2_slope         
 *                             3 -- > int2_d_tap
 *                             4 -- > int2_s_tap
 *                             5 -- > int2_orient
 *                             6 -- > int2_flat
 *
 *             unsigned char *status
 *                             0 -- > Disabled
 *                             1 -- > Enabled
 *
 *  \return
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_int2_pad_sel(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_LOWG);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_HIGHG);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_SLOPE);
            *status = data;
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_DB_TAP);
            *status = data;
            break;
         case C_Four_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_SNG_TAP);
            *status = data;
            break;
         case C_Five_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_ORIENT);
            *status = data;
            break;
         case C_Six_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_SEL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_INT2_PAD_FLAT);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100207
   bma250_set_int_src */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API enables the int src register
 *
 *
 *
 *
 *  \param
 *                    unsigned char intsrc
 *                     State:
 *                             0 -- > int_src_low
 *                             1 -- > int_src_High
 *                             2 -- > int_src_slope         
 *                             3 -- > int_src_tap
 *                             4 -- > int_src_data
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_int_src(unsigned char intsrc)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char state;
   state = C_One_U8X;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (intsrc)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_LOWG__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_UNFILT_INT_SRC_LOWG, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_LOWG__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_HIGHG__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_UNFILT_INT_SRC_HIGHG, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_HIGHG__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_SLOPE__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_UNFILT_INT_SRC_SLOPE, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_SLOPE__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_TAP__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_UNFILT_INT_SRC_TAP, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_TAP__REG, &data, C_One_U8X);
            break;
         case C_Four_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_DATA__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_UNFILT_INT_SRC_DATA, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UNFILT_INT_SRC_DATA__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100492
   bma250_get_int_src */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of int src register
 *
 *
 *
 *
 *  \param
 *                    unsigned char intsrc
 *                     State:
 *                             0 -- > int_src_low
 *                             1 -- > int_src_High
 *                             2 -- > int_src_slope         
 *                             3 -- > int_src_tap
 *                             4 -- > int_src_data
 *
 *                   unsigned char *status
 *                               0 -- > Disbaled
 *                               1 -- > Enabled
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_int_src(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SRC_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_UNFILT_INT_SRC_LOWG);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SRC_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_UNFILT_INT_SRC_HIGHG);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SRC_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_UNFILT_INT_SRC_SLOPE);
            *status = data;
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SRC_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_UNFILT_INT_SRC_TAP);
            *status = data;
            break;
         case C_Four_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SRC_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_UNFILT_INT_SRC_DATA);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100211
   bma250_set_int_set */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the int set
 *
 *
 *
 *
 *  \param
 *                     intset:
 *                             0 -- > int1_lvl
 *                             1 -- > int1_od
 *                             2 -- > int2_lvl         
 *                             3 -- > int2_od
 *
 *
 *
 *
 *                   state: 
 *                            Reset --> 0 -- > Writes zero
 *                             set -- > 1 -- > Writes one 
 *                                                      Reset value
 *             int1_lvl INT1 active level selection           1
 *             int2_lvl INT2 active level selection           1
 *             int1_od  INT1 output type selection            0 
 *             int2_od  INT2 output type selection            0
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_int_set(unsigned char intset,unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (intset)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_ACTIVE_LEVEL__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_INT1_PAD_ACTIVE_LEVEL, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_ACTIVE_LEVEL__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_OUTPUT_TYPE__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_INT1_PAD_OUTPUT_TYPE, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT1_PAD_OUTPUT_TYPE__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_ACTIVE_LEVEL__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_INT2_PAD_ACTIVE_LEVEL, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_ACTIVE_LEVEL__REG, &data, C_One_U8X);
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_OUTPUT_TYPE__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_INT2_PAD_OUTPUT_TYPE, state );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT2_PAD_OUTPUT_TYPE__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100496
   bma250_get_int_set */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the int set status of the register
 *
 *
 *
 *
 *  \param
 *                     intset:
 *                             0 -- > int1_lvl
 *                             1 -- > int1_od
 *                             2 -- > int2_lvl         
 *                             3 -- > int2_od
 *
 *
 *
 *
 *                   state: 
 *                            Reset --> 0 -- > Writes zero
 *                             set -- > 1 -- > Writes one 
 *                                                      Reset value
 *             int1_lvl INT1 active level selection           1
 *             int2_lvl INT2 active level selection           1
 *             int1_od  INT1 output type selection            0 
 *             int2_od  INT2 output type selection            0
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_int_set(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SET_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_INT1_PAD_ACTIVE_LEVEL);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SET_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_INT1_PAD_OUTPUT_TYPE);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SET_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_INT2_PAD_ACTIVE_LEVEL);
            *status = data;
            break;
         case C_Three_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_SET_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_INT2_PAD_OUTPUT_TYPE);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100117
   bma250_get_mode_ctrl */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of mode control register
 *
 *
 *
 *
 *  \param           unsigned char *mode        
 *
 *
 *
 *  \return     result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_mode_ctrl(unsigned char *mode)
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_MODE_CTRL_REG, &data, C_One_U8X );
      *mode = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100219
   bma250_set_low_g_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the Low g duration in ms
 *
 *
 *
 *
 *  \param
 *                     duration:
 *                             0000 0000 -- > 0 ms
 *                             0000 0001 -- > 2 ms ( one LSB = 2 ms)
 *                             0000 0010 -- > 4 ms                              
 *                             0000 0011 -- > 6 ms
 *                             0000 0101 -- > 8 ms
 *                             0000 0110 -- > 10 ms
 *                             0000 0111 -- > 12 ms  
 *                                
 *
 *                             1111 1111 ---> 512 ms  
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_low_g_duration(unsigned char duration)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOWG_DUR__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_LOWG_DUR, duration );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_LOWG_DUR__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100500
   bma250_get_low_g_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the low g duration register value
 *
 *
 *
 *
 *  \param
 *              unsigned char *status 
 *                     status:
 *                             0000 0000 -- > 0 ms
 *                             0000 0001 -- > 2 ms ( one LSB = 2 ms)
 *                             0000 0010 -- > 4 ms                              
 *                             0000 0011 -- > 6 ms
 *                             0000 0101 -- > 8 ms
 *                             0000 0110 -- > 10 ms
 *                             0000 0111 -- > 12 ms  
 *                                
 *
 *                             1111 1111 ---> 512 ms  
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_low_g_duration(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOW_DURN_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_LOWG_DUR);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100223
   bma250_set_low_g_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the low g threshold
 *
 *
 *
 *
 *  \param
 *           unsigned char threshold
 *                     threshold: "00110000" --> Reset Value
 *                             
 *                             
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_low_g_threshold(unsigned char threshold)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOWG_THRES__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_LOWG_THRES, threshold );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_LOWG_THRES__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100504
   bma250_get_low_g_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the low g threshold value
 *
 *
 *
 *
 *  \param unsigned char *status
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_low_g_threshold(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOW_THRES_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_LOWG_THRES);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100227
   bma250_set_high_g_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the high g duration
 *
 *
 *
 *
 *  \param
 *                     duration:
 *                             0000 0000 -- > 0 ms
 *                             0000 0001 -- > 2 ms ( one LSB = 2 ms)
 *                             0000 0010 -- > 4 ms                              
 *                             0000 0011 -- > 6 ms
 *                             0000 0101 -- > 8 ms
 *                             0000 0110 -- > 10 ms
 *                             0000 0111 -- > 12 ms  
 *                                
 *
 *                             1111 1111 ---> 512 ms 
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_high_g_duration(unsigned char duration)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_HIGHG_DUR__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_HIGHG_DUR, duration );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_HIGHG_DUR__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100508
   bma250_get_high_g_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the high g duration register value
 *
 *
 *
 *
 *  \param
 *              unsigned char *status 
 *                     status:
 *                             0000 0000 -- > 0 ms
 *                             0000 0001 -- > 2 ms ( one LSB = 2 ms)
 *                             0000 0010 -- > 4 ms                              
 *                             0000 0011 -- > 6 ms
 *                             0000 0101 -- > 8 ms
 *                             0000 0110 -- > 10 ms
 *                             0000 0111 -- > 12 ms  
 *                                
 *
 *                             1111 1111 ---> 512 ms  
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_high_g_duration(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_HIGH_DURN_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_HIGHG_DUR);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100228
   bma250_set_high_g_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the high g threshold
 *
 *
 *
 *
 *  \param
  *           unsigned char threshold
 *                     threshold: "11000000" --> Reset Value
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_high_g_threshold(unsigned char threshold)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_HIGHG_THRES__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_HIGHG_THRES, threshold );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_HIGHG_THRES__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100512
   bma250_get_high_g_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the high g threshold value
 *
 *
 *
 *
 *  \param unsigned char *status
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_high_g_threshold(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_HIGH_THRES_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_HIGHG_THRES);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100232
   bma250_set_slope_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the slope duration
 *
 *
 *
 *
 *  \param 
 *                    unsigned char duration  
 *
 *                     duration: "00010100" --> reset value
 *                            
 *                            
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 * 
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_slope_duration(unsigned char duration)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SLOPE_DUR__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_SLOPE_DUR, duration );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_SLOPE_DUR__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100516
   bma250_get_slope_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the slope duration    
 *
 *
 *
 *
 *  \param      unsigned char *status
 *                      
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_slope_duration(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SLOPE_DURN_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SLOPE_DUR);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100233
   bma250_set_slope_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the slope threshold
 *
 *
 *
 *
 *  \param
 *                      unsigned char threshold
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_slope_threshold(unsigned char threshold)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SLOPE_THRES__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_SLOPE_THRES, threshold );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_SLOPE_THRES__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100520
   bma250_get_slope_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the slope threshold
 *
 *
 *
 *
 *  \param              unsigned char *status
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_slope_threshold(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SLOPE_THRES_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SLOPE_THRES);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100245
   bma250_set_tap_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the tap duration
 *
 *
 *
 *
 *  \param
 *          unsigned chat duration
 *     
 *     
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_tap_duration(unsigned char duration)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_DUR__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_TAP_DUR, duration );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_TAP_DUR__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100524
   bma250_get_tap_duration */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the Tap durations
 *
 *
 *
 *
 *  \param  unsigned chat *status
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_duration(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_PARAM_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_TAP_DUR);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100251
   bma250_set_tap_shock */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the tap shock duration
 *
 *
 *
 *
 *  \param
 *                  unsigned char setval
 *                             0 -- > 50 ms
 *                             1 -- > 75 ms
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_tap_shock(unsigned char setval)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_SHOCK_DURN__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_TAP_SHOCK_DURN, setval );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_TAP_SHOCK_DURN__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100528
   bma250_get_tap_shock */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the tap shock duration
 *
 *
 *
 *
 *  \param       unsigned char *status
 *                      0 -- > 50 ms
 *                      1 -- > 75 ms
 *
 *
 *  \return     result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_shock(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_PARAM_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_TAP_SHOCK_DURN);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100253
   bma250_set_tap_quiet */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the tap quiet duration
 *
 *
 *
 *
 *  \param
 *             unsigned char duration:
 *                             0 -- > 30 ms
 *                             1 -- > 20 ms
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_tap_quiet_duration(unsigned char duration)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_QUIET_DURN__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_TAP_QUIET_DURN, duration );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_TAP_QUIET_DURN__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100532
   bma250_get_tap_quiet */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the tap quiet duration
 *
 *
 *
 *
 *  \param
 *             unsigned char *status
 *                             0 -- > 30 ms
 *                             1 -- > 20 ms
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_quiet(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_PARAM_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_TAP_QUIET_DURN);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100257
   bma250_set_tap_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the tap threshold
 *
 *
 *
 *
 *  \param
 *             unsigned char threshold:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_tap_threshold(unsigned char threshold)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_THRES__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_TAP_THRES, threshold );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_TAP_THRES__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100536
   bma250_get_tap_threshold */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the tap threshold
 *
 *
 *
 *
 *  \param
 *              unsigned char threshold
 *                             "00000"
 *                             
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_threshold(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_THRES_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_TAP_THRES);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100261
   bma250_set_tap_samp */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the tap sample period
 *
 *
 *
 *
 *  \param unsigned char samp
 *                     samp:
 *         tap_samp             Samples
 *              00                2
 *              01                4
 *              10                8
 *              11                16
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_tap_samp(unsigned char samp)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_SAMPLES__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_TAP_SAMPLES, samp );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_TAP_SAMPLES__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100540
   bma250_get_tap_samp */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the tap sample period
 *
 *
 *
 *
 *  \param unsigned char samp
 *                     samp:
 *         tap_samp             Samples
 *              00                2
 *              01                4
 *              10                8
 *              11                16
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_tap_samp(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_TAP_THRES_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_TAP_SAMPLES);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100265
   bma250_set_orient_mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the orient mode
 *
 *
 *
 *
 *  \param
 *              unsigned char mode       
 *               Orient mode  Orientation mode
 *                     00       Symmetrical
 *                     01       High asymmetrical
 *                     10       Low asymmetrical
 *                     11       Symmetrical
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_orient_mode(unsigned char mode)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_MODE__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_ORIENT_MODE, mode );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_ORIENT_MODE__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100544
   bma250_get_orient_mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the orient mode
 *
 *
 *
 *
 *  \param
 *              unsigned char mode       
 *               Orient mode  Orientation mode
 *                     00       Symmetrical
 *                     01       High asymmetrical
 *                     10       Low asymmetrical
 *                     11       Symmetrical
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_mode(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_PARAM_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_ORIENT_MODE);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100267
   bma250_set_orient_blocking */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the orient blocking
 *
 *
 *
 *
 *  \param
 *             unsigned char orientblk
 *                            
 *                            
 *
 *      orient_blocking                       Conditions
 *              00                              No blocking
 *              01                              Theta blocking
 *              10                              Theta blocking
 *                                                      OR
 *                                      slope of an acceleration in any axis is > 0.2g
 *              
 *              11                     The orient value is not stable for at least 100 ms
 *                                                      OR
 *                                              Theta blocking
 *                                                      OR
 *                                        slope of an acceleration in any axis is > 0.4g
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_orient_blocking(unsigned char orientblk)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_BLOCK__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_ORIENT_BLOCK, orientblk );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_ORIENT_BLOCK__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100548
   bma250_get_orient_blocking */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the orient blocking
 *
 *
 *
 *
 *  \param
 *             unsigned char orientblk
 *                            
 *                            
 *
 *      orient_blocking                       Conditions
 *              00                              No blocking
 *              01                              Theta blocking
 *              10                              Theta blocking
 *                                                      OR
 *                                      slope of an acceleration in any axis is > 0.2g
 *              
 *              11                     The orient value is not stable for at least 100 ms
 *                                                      OR
 *                                              Theta blocking
 *                                                      OR
 *                                        slope of an acceleration in any axis is > 0.4g
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_blocking(unsigned char *orientblk )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_PARAM_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_ORIENT_BLOCK);
      *orientblk = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100269
   bma250_set_orient_hyst */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the orient hysteresis
 *
 *
 *
 *
 *  \param           unsigned char orienthyst
 *                     orienthyst:
 *                            Orientation hysteresis
 *                                     Reset value -- > "001"
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_orient_hyst(unsigned char orienthyst)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_HYST__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_ORIENT_HYST, orienthyst );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_ORIENT_HYST__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100552
   bma250_get_orient_hyst */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the orient hysteresis
 *
 *
 *
 *
 *  \param           unsigned char *status 
 *                     orienthyst:
 *                            Orientation hysteresis
 *                                     Reset value -- > "001"
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_hyst(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_PARAM_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_ORIENT_HYST);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100273
   bma250_set_theta_blocking */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the theta blocking 
 *
 *
 *
 *
 *  \param
 *               unsigned char thetablk                 
 *                      theatblk:
 *                             "001000" -- > Reset Value
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_theta_blocking(unsigned char thetablk)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_THETA_BLOCK__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_THETA_BLOCK, thetablk );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_THETA_BLOCK__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100556
   bma250_get_theta_blocking */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the theta blocking 
 *
 *
 *
 *
 *  \param
 *               unsigned char *status                 
 *                      theatblk:
 *                             "001000" -- > Reset Value
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_theta_blocking(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_THETA_BLOCK_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_THETA_BLOCK);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100281
   bma250_set_orient_ex */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the orient ex
 *
 *
 *
 *
 *  \param      unsigned char orientex
 *                     orientex:
 *                             If the register orient_ex is set to ,1., 
 *      the axes X and Z are swapped and axis Y is inverted in all orientation calculations.
 *
 *                             Reset value will be       "0"
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_orient_ex(unsigned char orientex)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_ORIENT_AXIS__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_ORIENT_AXIS, orientex );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_ORIENT_AXIS__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100560
   bma250_get_orient_ex */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the orient ex
 *
 *
 *
 *
 *  \param      unsigned char *status 
 *                     orientex:
 *                             If the register orient_ex is set to ,1., 
 *      the axes X and Z are swapped and axis Y is inverted in all orientation calculations.
 *
 *                             Reset value will be       "0"
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_orient_ex(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_THETA_BLOCK_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_ORIENT_AXIS);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100277
   bma250_set_theta_flat */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the theta flat
 *
 *
 *
 *
 *  \param
 *                      unsigned char thetaflat
 *                     "001000" Reset value
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_theta_flat(unsigned char thetaflat)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_THETA_FLAT__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_THETA_FLAT, thetaflat );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_THETA_FLAT__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100564
   bma250_get_theta_flat */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the theta flat
 *
 *
 *
 *
 *  \param
 *                      unsigned char *status
 *                     "001000" Reset value
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_theta_flat(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_THETA_FLAT_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_THETA_FLAT);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100418
   bma250_set_flat_hold_time */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets flat hold time
 *
 *
 *
 *
 *  \param
 *             unsigned char holdtime
 *                      flat holdtime   time(s)  
 *                        00             0
 *                        01             0.512
 *                        10             1.024
 *                        11             2.048
 *                      
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_flat_hold_time(unsigned char holdtime)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_FLAT_HOLD_TIME__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_FLAT_HOLD_TIME, holdtime );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_FLAT_HOLD_TIME__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100422
   bma250_get_flat_hold_time */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets flat hold time
 *
 *
 *
 *
 *  \param
 *             unsigned char *holdtime
 *                      flat holdtime   time(s)  
 *                        00             0
 *                        01             0.512
 *                        10             1.024
 *                        11             2.048
 *                      
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_flat_hold_time(unsigned char *holdtime )
   {
   int comres= C_Zero_U8X;
   unsigned char data1;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_FLAT_HOLD_TIME_REG, &data1, C_One_U8X );
      data1  = bma250_GET_BITSLICE(data1, bma250_FLAT_HOLD_TIME);
      *holdtime = data1 ;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100285
   bma250_get_low_power_state */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the lowpower state 
 *
 *
 *
 *
 *  \param unsigned char *Lowpower
 *                      
 *              state : 
 *                      0 -- >  sleep period
 *                      1 -- >  otherwise  
 *                              After reset it will be set to "0"
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_low_power_state(unsigned char *Lowpower )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_STATUS_LOW_POWER_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_LOW_POWER_MODE_S);
      *Lowpower = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100289
   bma250_set_selftest_st */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the selftest st
 *
 *
 *
 *
 *  \param 
 *              unsigned char selftest
 * 
 *                             00       No self-test active
 *                             01       Self-test active for X axis
 *                             10       Self-test active for Y axis
 *                             11       Self-test active for Z axis                       
 *                             
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_selftest_st(unsigned char selftest)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SELF_TEST__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_SELF_TEST, selftest );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SELF_TEST__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100568
   bma250_get_selftest_st */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the selftest st
 *
 *
 *
 *
 *  \param 
 *              unsigned char selftest
 *
 *                             00       No self-test active
 *                             01       Self-test active for X axis
 *                             10       Self-test active for Y axis
 *                             11       Self-test active for Z axis                                                                           
 *                             
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_selftest_st(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SELF_TEST_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_SELF_TEST);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100293
   bma250_set_selftest_stn */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief
 *
 *
 *
 *
 *  \param
 *             unsigned char stn        
 *                         
 *                         If stn is at ,0., a positive self-test deviation is performed
 *                         If stn is at ,1., a negative self-test deviation is performed
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_selftest_stn(unsigned char stn)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_NEG_SELF_TEST__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_NEG_SELF_TEST, stn );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_NEG_SELF_TEST__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100572
   bma250_get_selftest_stn */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief
 *
 *
 *
 *
 *  \param
 *
 *                         If stn is at ,0., a positive self-test deviation is performed
 *                         If stn is at ,1., a negative self-test deviation is performed 
 *
 *
 *
 *  \return
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_selftest_stn(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SELF_TEST_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_NEG_SELF_TEST);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100297
   bma250_set_selftest_st_amp */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the selftest st amp
 *
 *
 *
 *
 *  \param
 *              unsigned char stamp
 *       
 *           Self-test amplitude is control through st_amp state;
 *
 *              st_amp<2:0>                     vst_amp amplitude
 *                                                  (ratio of vreg)
 *              000                                      3/10
 *              001                                      4/10
 *              010                                      5/10
 *              011                                      6/10
 *              100                                      7/10
 *              101                                      8/10
 *              110                                      9/10
 *              111                                      1
 *
 *
 *
 *
 *
 *
 *
 *  \return
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_selftest_st_amp(unsigned char stamp)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SELF_TEST_AMP__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_SELF_TEST_AMP, stamp );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_SELF_TEST_AMP__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100576
   bma250_get_selftest_st_amp */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the selftest st amp
 *
 *
 *
 *
 *  \param
 *              unsigned char *status
 *       
 *           Self-test amplitude is control through st_amp state;
 *
 *              st_amp<2:0>                     vst_amp amplitude
 *                                                  (ratio of vreg)
 *              000                                      3/10
 *              001                                      4/10
 *              010                                      5/10
 *              011                                      6/10
 *              100                                      7/10
 *              101                                      8/10
 *              110                                      9/10
 *              111                                      1
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_selftest_st_amp(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SELF_TEST_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_SELF_TEST_AMP);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100038
   bma250_set_ee_w */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the ee_w bit
 *
 *
 *
 *
 *  \param 
 *              unsigned char selftest
 * 
 *                      eew 0 = lock EEPROM 
 *                      eew 1 = unlock Setting part of EEPROM
 *                             
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_ee_w(unsigned char eew)
   {
   unsigned char data;
         int comres;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR ;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNLOCK_EE_WRITE_SETTING__REG,&data, C_One_U8X);
      data = bma250_SET_BITSLICE(data, bma250_UNLOCK_EE_WRITE_SETTING, eew);
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UNLOCK_EE_WRITE_SETTING__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100039
   bma250_get_ee_w */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the status of the ee_w bit
 *
 *
 *
 *
 *  \param 
 *              unsigned char selftest
 * 
 *                      eew 0 = lock EEPROM 
 *                      eew 1 = unlock Setting part of EEPROM
 *                             
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_ee_w(unsigned char *eew)
   {
   int comres;
   if (p_bma250==C_Zero_U8X)
      {
      comres =E_SMB_NULL_PTR ;
      }
   else
      {
  	  comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UNLOCK_EE_WRITE_SETTING__REG,eew, C_One_U8X);
      *eew = bma250_GET_BITSLICE(*eew, bma250_UNLOCK_EE_WRITE_SETTING);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100305
   bma250_set_ee_prog_trig */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the ee_prog_trig bit
 *
 *
 *
 *
 *  \param none
 *        
 *        
 *        
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_ee_prog_trig(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char eeprog;
   eeprog = 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_START_EE_WRITE_SETTING__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_START_EE_WRITE_SETTING, eeprog );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_START_EE_WRITE_SETTING__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100309
   bma250_get_eeprom_writing_status */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the EEPROM writing status
 *
 *
 *
 *
 *  \param unsigned char *eewrite 
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_eeprom_writing_status(unsigned char *eewrite )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EEPROM_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EE_WRITE_SETTING_S);
      *eewrite = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100313
   bma250_set_update_image */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the Update image in EEPROM control
 *
 *
 *
 *
 *  \param
 *     
 *     
 *     
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_update_image(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char update;
   update = C_One_U8X;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_UPDATE_IMAGE__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_UPDATE_IMAGE, update );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_UPDATE_IMAGE__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100321
   bma250_set_3wire_spi */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the 3wite SPI 
 *
 *
 *
 *
 *  \param      None
 *                    
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \   return result of communication routines       
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_3wire_spi(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char update;
   update = 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SPI_MODE_3__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_SPI_MODE_3, update );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SPI_MODE_3__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100580
   bma250_get_3wire_spi */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the 3wire SPI
 *
 *
 *
 *
 *  \param  unsigned char *status
 *
 *
 *
 *  \return  result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_3wire_spi(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SERIAL_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_SPI_MODE_3);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100677
   bma250_set_i2c_wdt_en */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the i2c watchdog enable 
 *
 *
 *
 *
 *  \param      None
 *                    
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \   return result of communication routines       
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_i2c_wdt_en(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char update;
   update = 0x01;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_I2C_WATCHDOG__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_I2C_WATCHDOG, update );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_I2C_WATCHDOG__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100678
   bma250_get_i2c_wdt_en_status */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the i2c watch dog enable status
 *
 *
 *
 *
 *  \param  unsigned char *status
 *
 *
 *
 *  \return  result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_i2c_wdt_en_status(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SERIAL_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_EN_I2C_WATCHDOG);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100325
   bma250_set_i2c_wdt_timer */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the i2c Watch dog timer
 *
 *
 *
 *
 *  \param
 *                     duration:
 *                             0 -- > 1 ms
 *                             1 -- > 50 ms
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_i2c_wdt_timer(unsigned char timedly)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_I2C_WATCHDOG_PERIOD__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_I2C_WATCHDOG_PERIOD, timedly );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_I2C_WATCHDOG_PERIOD__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100584
   bma250_get_i2c_wdt_timer */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the i2c Watch dog timer
 *
 *
 *
 *
 *  \param              unsigned char *status 
 *                     
 *                             0 -- > 1 ms
 *                             1 -- > 50 ms
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_i2c_wdt_timer(unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_SERIAL_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_I2C_WATCHDOG_PERIOD);
      *status = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100339
   bma250_set_hp_en */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the hp_en bit
 *
 *
 *
 *
 *  \param
 *                   unsigned char param
 *                             0 -- >  hp_x_en
 *                             1 -- >  hp_y_en
 *                             2 -- >  hp_z_en
 *                   unsigned char hpval
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_hp_en(unsigned char param,unsigned char hpval)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOW_COMP_X__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOW_COMP_X, hpval );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOW_COMP_X__REG, &data, C_One_U8X);
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOW_COMP_Y__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOW_COMP_Y, hpval );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOW_COMP_Y__REG, &data, C_One_U8X);
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_SLOW_COMP_Z__REG, &data, C_One_U8X );
            data = bma250_SET_BITSLICE(data, bma250_EN_SLOW_COMP_Z, hpval );
            comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_SLOW_COMP_Z__REG, &data, C_One_U8X);
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100597
   bma250_get_hp_en */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the hp_en bit
 *
 *
 *
 *
 *  \param
 *                   unsigned char param
 *                             0 -- >  hp_x_en
 *                             1 -- >  hp_y_en
 *                             2 -- >  hp_z_en
 *                   unsigned char *status
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_hp_en(unsigned char param,unsigned char *status )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      switch (param)
         {
         case C_Zero_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_CTRL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SLOW_COMP_X);
            *status = data;
            break;
         case C_One_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_CTRL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SLOW_COMP_Y);
            *status = data;
            break;
         case C_Two_U8X:
            comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_CTRL_REG, &data, C_One_U8X );
            data = bma250_GET_BITSLICE(data, bma250_EN_SLOW_COMP_Z);
            *status = data;
            break;
         default:
            break;
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100343
   bma250_get_cal_ready */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API get the status of the cal_rdy bit
 *
 *
 *
 *
 *  \param              unsigned char *calrdy
 *                           calredy reset value "0"
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_cal_ready(unsigned char *calrdy )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_FAST_COMP_RDY_S);
      *calrdy = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100347
   bma250_set_cal_trigger */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief  This API sets the cal trigger
 *
 *
 *
 *
 *  \param
 *                     duration:
 *                             00 -- > None
 *                             01 -- > X
 *                             10 -- > Y      
 *                             11 -- > Z
 *
 *
 *
 *
 *
 *
 *  \return     Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_cal_trigger(unsigned char caltrigger)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EN_FAST_COMP__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_EN_FAST_COMP, caltrigger );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_EN_FAST_COMP__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100351
   bma250_set_offset_reset */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset reset bit
 *
 *
 *
 *
 *  \param              None
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return     Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_reset(void)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   unsigned char offsetreset;
   offsetreset = C_One_U8X;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_RESET_OFFSET_REGS__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_RESET_OFFSET_REGS, offsetreset );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_RESET_OFFSET_REGS__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100355
   bma250_set_offset_cutoff */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset cutoff
 *
 *
 *
 *
 *  \param      unsigned char offsetcutoff
 *                    
 *
 *                           cut_off              OffsetPer   
 *                             0        -- >           8
 *                             1        -- >           16
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_cutoff(unsigned char offsetcutoff)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_COMP_CUTOFF__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_COMP_CUTOFF, offsetcutoff );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_COMP_CUTOFF__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100359
   bma250_get_offset_cutoff */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset cutoff
 *
 *
 *
 *
 *  \param      unsigned char offsetcutoff
 *                    
 *
 *                           cut_off              OffsetPer   
 *                             0        -- >           8
 *                             1        -- >           16
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_cutoff(unsigned char *cutoff )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_PARAMS_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_COMP_CUTOFF);
      *cutoff = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100363
   bma250_set_offset_target_x */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset target_x
 *
 *
 *
 *
 *  \param unsigned char offsettarget
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_target_x(unsigned char offsettarget)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_COMP_TARGET_OFFSET_X__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_COMP_TARGET_OFFSET_X, offsettarget );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_COMP_TARGET_OFFSET_X__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100369
   bma250_get_offset_target_x */
/* Compiler Switch if applicable
#ifdef

#endif
*/
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_target_x
 *
 *
 *
 *
 *  \param unsigned char *offsettarget
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_target_x(unsigned char *offsettarget )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_PARAMS_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_COMP_TARGET_OFFSET_X);
      *offsettarget = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100368
   bma250_set_offset_target_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_target_y
 *
 *
 *
 *
 *  \param unsigned char offsettarget
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_target_y(unsigned char offsettarget)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_COMP_TARGET_OFFSET_Y__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_COMP_TARGET_OFFSET_Y, offsettarget );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_COMP_TARGET_OFFSET_Y__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100364
   bma250_get_offset_target_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_target_y
 *
 *
 *
 *
 *  \param unsigned char *offsettarget
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_target_y(unsigned char *offsettarget )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_PARAMS_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_COMP_TARGET_OFFSET_Y);
      *offsettarget = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100371
   bma250_set_offset_target_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_target_z
 *
 *
 *
 *
 *  \param unsigned char offsettarget
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_target_z(unsigned char offsettarget)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_COMP_TARGET_OFFSET_Z__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_COMP_TARGET_OFFSET_Z, offsettarget );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_COMP_TARGET_OFFSET_Z__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100372
   bma250_get_offset_target_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_target_z
 *
 *
 *
 *
 *  \param unsigned char *offsettarget
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_target_z(unsigned char *offsettarget )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_PARAMS_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_COMP_TARGET_OFFSET_Z);
      *offsettarget = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100376
   bma250_set_offset_filt_x */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_filt_x 
 *
 *
 *
 *
 *  \param
 *                    unsigned char offsetfilt
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_filt_x(unsigned char offsetfilt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      data =  offsetfilt;
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_OFFSET_FILT_X_REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100377
   bma250_get_offset_filt_x */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_filt_x 
 *
 *
 *
 *
 *  \param
 *                    unsigned char *offsetfilt
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_filt_x(unsigned char *offsetfilt )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_FILT_X_REG, &data, C_One_U8X );
      *offsetfilt = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100381
   bma250_set_offset_filt_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_filt_y
 *
 *
 *
 *
 *  \param
 *                    unsigned char offsetfilt
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_filt_y(unsigned char offsetfilt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      data =  offsetfilt;
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_OFFSET_FILT_Y_REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100382
   bma250_get_offset_filt_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_filt_x 
 *
 *
 *
 *
 *  \param
 *                    unsigned char *offsetfilt
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_filt_y(unsigned char *offsetfilt )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_FILT_Y_REG, &data, C_One_U8X );
      *offsetfilt = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100384
   bma250_set_offset_filt_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_filt_z 
 *
 *
 *
 *
 *  \param
 *                    unsigned char offsetfilt
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_filt_z(unsigned char offsetfilt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      data =  offsetfilt;
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_OFFSET_FILT_Z_REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100385
   bma250_get_offset_filt_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_filt_z 
 *
 *
 *
 *
 *  \param
 *                    unsigned char *offsetfilt
 *                    
 *                    
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_filt_z(unsigned char *offsetfilt )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_FILT_Z_REG, &data, C_One_U8X );
      *offsetfilt = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100389
   bma250_set_offset_unfilt_x */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_unfilt_x 
 *
 *
 *
 *
 *  \param              unsigned char offsetfilt
 *               
 *               
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_unfilt_x(unsigned char offsetfilt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      data =  offsetfilt;
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_OFFSET_UNFILT_X_REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100390
   bma250_get_offset_unfilt_x */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_unfilt_x 
 *
 *
 *
 *
 *  \param              unsigned char *offsetfilt
 *               
 *               
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_unfilt_x(unsigned char *offsetfilt )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_UNFILT_X_REG, &data, C_One_U8X );
      *offsetfilt = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100391
   bma250_set_offset_unfilt_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_unfilt_y 
 *
 *
 *
 *
 *  \param              unsigned char offsetfilt
 *               
 *               
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_unfilt_y(unsigned char offsetfilt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      data =  offsetfilt;
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_OFFSET_UNFILT_Y_REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100392
   bma250_get_offset_unfilt_y */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_unfilt_y 
 *
 *
 *
 *
 *  \param              unsigned char offsetfilt
 *               
 *               
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_unfilt_y(unsigned char *offsetfilt )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_UNFILT_Y_REG, &data, C_One_U8X );
      *offsetfilt = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100393
   bma250_set_offset_unfilt_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_unfilt_z 
 *
 *
 *
 *
 *  \param              unsigned char offsetfilt
 *               
 *               
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_offset_unfilt_z(unsigned char offsetfilt)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      data =  offsetfilt;
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_OFFSET_UNFILT_Z_REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100394
   bma250_get_offset_unfilt_z */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the offset_unfilt_z 
 *
 *
 *
 *
 *  \param              unsigned char offsetfilt
 *               
 *               
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_offset_unfilt_z(unsigned char *offsetfilt )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_OFFSET_UNFILT_Z_REG, &data, C_One_U8X );
      *offsetfilt = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100034
   bma250_set_Int_Mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the set_Int_Mode
 *
 *
 *
 *
 *  \param              unsigned char Mode
 *               
 *               0000            non-latched
 *               0001            temporary, 250 ms
 *               0010            temporary, 500 ms
 *               0011            temporary, 1 s
 *               0100            temporary, 2 s
 *               0101            temporary, 4 s
 *               0110            temporary, 8 s
 *               0111            latched
 *               1000            non-latched
 *               1001            temporary, 500 �s
 *               1010            temporary, 500 �s
 *               1011            temporary, 1 ms
 *               1100            temporary, 12.5 ms
 *               1101            temporary, 25 ms
 *               1110            temporary, 50 ms
 *               1111            latched
 *
 *
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_Int_Mode(unsigned char Mode )
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_MODE_SEL__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_INT_MODE_SEL, Mode );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT_MODE_SEL__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100035
   bma250_get_Int_Mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets the set_Int_Mode
 *
 *
 *
 *
 *  \param              unsigned char *Mode
 *               
 *               0000            non-latched
 *               0001            temporary, 250 ms
 *               0010            temporary, 500 ms
 *               0011            temporary, 1 s
 *               0100            temporary, 2 s
 *               0101            temporary, 4 s
 *               0110            temporary, 8 s
 *               0111            latched
 *               1000            non-latched
 *               1001            temporary, 500 �s
 *               1010            temporary, 500 �s
 *               1011            temporary, 1 ms
 *               1100            temporary, 12.5 ms
 *               1101            temporary, 25 ms
 *               1110            temporary, 50 ms
 *               1111            latched
 *
 *
 *               
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_Int_Mode(unsigned char * Mode )
   {
   int comres= C_Zero_U8X;
   unsigned char data1;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_MODE_SEL__REG, &data1, C_One_U8X );
      data1  = bma250_GET_BITSLICE(data1, bma250_INT_MODE_SEL);
      *Mode = data1 ;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100036
   bma250_set_Int_Enable */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the offset_filt_z 
 *
 *
 *
 *
 *  \param
 *                   unsigned char InterruptType  
 *                        
 *                      0      Low G Interrupt Enable
 *                      1      High G X Interrupt Enable
 *                      2      High G Y Interrupt Enable
 *                      3      High G Z Interrupt Enable
 *                      4      New Data Interrupt Enable
 *                      5      Slope X Interrupt Enable
 *                      6      Slope Y Interrupt Enable
 *                      7      Slope Z Interrupt Enable
 *                      8      Single Tap Interrupt Enable
 *                      9      Double tap Interrupt Enable
 *                      10     Orient Interrupt Enable
 *                      11     Flat Interrupt Enableunsigned char offsetfilt
 *                    
 *                    unsigned char value
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_Int_Enable(unsigned char InterruptType , unsigned char value )
   {
   int comres=C_Zero_U8X;
   unsigned char data1,data2;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data1, C_One_U8X );
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data2, C_One_U8X );
      
      value = value & C_One_U8X;
      switch (InterruptType)
         {
         case C_Zero_U8X:
            /* Low G Interrupt  */
            data2 = bma250_SET_BITSLICE(data2, bma250_EN_LOWG_INT, value );
            break;
         case C_One_U8X:
            /* High G X Interrupt */
            /* EasyCASE - */
            data2 = bma250_SET_BITSLICE(data2, bma250_EN_HIGHG_X_INT, value );
            break;
         case C_Two_U8X:
            /* High G Y Interrupt */
            /* EasyCASE - */
            data2 = bma250_SET_BITSLICE(data2, bma250_EN_HIGHG_Y_INT, value );
            break;
         case C_Three_U8X:
            /* High G Z Interrupt */
            /* EasyCASE - */
            data2 = bma250_SET_BITSLICE(data2, bma250_EN_HIGHG_Z_INT, value );
            break;
         case C_Four_U8X:
            /* New Data Interrupt  */
            /* EasyCASE - */
            data2 = bma250_SET_BITSLICE(data2, bma250_EN_NEW_DATA_INT, value );
            break;
         case C_Five_U8X:
            /* Slope X Interrupt */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_SLOPE_X_INT, value );
            break;
         case C_Six_U8X:
            /* Slope Y Interrupt */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_SLOPE_Y_INT, value );
            break;
         case C_Seven_U8X:
            /* Slope Z Interrupt */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_SLOPE_Z_INT, value );
            break;
         case C_Eight_U8X:
            /* Single Tap Interrupt */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_SINGLE_TAP_INT, value );
            break;
         case C_Nine_U8X:
            /* Double Tap Interrupt */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_DOUBLE_TAP_INT, value );
            break;
         case C_Ten_U8X:
            /* Orient Interrupt  */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_ORIENT_INT, value );
            break;
         case C_Eleven_U8X:
            /* Flat Interrupt */
            /* EasyCASE - */
            data1 = bma250_SET_BITSLICE(data1, bma250_EN_FLAT_INT, value );
            break;
         default:
            break;
         }
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE1_REG, &data1, C_One_U8X );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_INT_ENABLE2_REG, &data2, C_One_U8X );
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100037
   bma250_write_ee */
/* EasyCASE F */
/** write byte to bma250 EEPROM
   \param addr address to write to (image addresses are automatically extended to EEPROM space)
   \param data byte content to write
   \return result of bus communication function
   \note this function will first write to the image and then trigger the copy of this byte from image
    to the EEPROM by writting to the EEPROM byte
*/
int bma250_write_ee(unsigned char addr, unsigned char data)
   {
   int comres;
   unsigned char ee_busy;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      if (p_bma250->delay_msec == C_Zero_U8X)
         {
         comres = E_SMB_NULL_PTR;
         }
      else
         {
         comres = bma250_get_ee_w( & ee_busy );
         if (ee_busy)
            {
            comres = E_EEPROM_BUSY;
            }
         else
            {
            comres += p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, addr, &data, C_One_U8X );
                addr += bma250_EEP_OFFSET;
                comres += p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, addr, &data, C_One_U8X );
                p_bma250->delay_msec( bma250_EE_W_DELAY );
            }
         }
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100237
   bma250_set_low_hy */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the Low hysteresis
 *
 *
 *
 *
 *  \param
 *              unsigned char hysval:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_low_hy(unsigned char hysval)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOWG_HYST__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_LOWG_HYST, hysval );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_LOWG_HYST__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100239
   bma250_set_high_hy */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the high hysteresis
 *
 *
 *
 *
 *  \param
 *              unsigned char hysval:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_high_hy(unsigned char hysval)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_HIGHG_HYST__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_HIGHG_HYST, hysval );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_HIGHG_HYST__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100241
   bma250_set_low_mode */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API sets the Low mode
 *
 *
 *
 *
 *  \param
 *              unsigned char state:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *  \return result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_set_low_mode(unsigned char state)
   {
   int comres=C_Zero_U8X;
   unsigned char data;
   if (p_bma250==C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_LOWG_INT_MODE__REG, &data, C_One_U8X );
      data = bma250_SET_BITSLICE(data, bma250_LOWG_INT_MODE, state );
      comres = p_bma250->bma250_BUS_WRITE_FUNC(p_bma250->dev_addr, bma250_LOWG_INT_MODE__REG, &data, C_One_U8X);
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ( 100317
   bma250_get_update_image_status */
/* EasyCASE F */
/*******************************************************************************
 * Description: *//**\brief This API gets image update status
 *
 *
 *
 *
 *  \param unsigned char *imagestatus
 *
 *
 *
 *  \return Result of communication routines
 *
 *
 ******************************************************************************/
/* Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 ******************************************************************************/
int bma250_get_update_image_status(unsigned char *imagestatus )
   {
   int comres = C_Zero_U8X ;
   unsigned char data;
   if (p_bma250 == C_Zero_U8X)
      {
      comres = E_SMB_NULL_PTR;
      }
   else
      {
      comres = p_bma250->bma250_BUS_READ_FUNC(p_bma250->dev_addr, bma250_EEPROM_CTRL_REG, &data, C_One_U8X );
      data = bma250_GET_BITSLICE(data, bma250_UPDATE_IMAGE);
      *imagestatus = data;
      }
   return comres;
   }
/* EasyCASE ) */
/* EasyCASE ) */
/* EasyCASE ( 253
   Local functions */
/* EasyCASE ) */
/* EasyCASE ) */
