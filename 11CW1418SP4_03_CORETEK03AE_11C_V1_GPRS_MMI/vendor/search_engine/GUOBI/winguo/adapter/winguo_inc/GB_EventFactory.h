#ifndef GBEVENTFACTORY_DEFINE_FOR_PLATFORM_KNIGHTNIU_2008_03_03_H
#define GBEVENTFACTORY_DEFINE_FOR_PLATFORM_KNIGHTNIU_2008_03_03_H

#include "GB_DataTypeDef.h"
#include "GB_HWPlat.h"


// 需要用GB_WG_SysKeyTransform将系统KEY转换 [3/7/2011 lzp]
typedef enum _GBKEYVALUE{
	GB_WG_KEY_0 = 0,
	GB_WG_KEY_1,
	GB_WG_KEY_2,
	GB_WG_KEY_3,
	GB_WG_KEY_4,
	GB_WG_KEY_5,
	GB_WG_KEY_6,
	GB_WG_KEY_7,
	GB_WG_KEY_8,
	GB_WG_KEY_9,
	GB_WG_KEY_STAR,
	GB_WG_KEY_POUND,
	GB_WG_KEY_LSK,
	GB_WG_KEY_RSK,
	GB_WG_KEY_CSK,
	GB_WG_KEY_UP_ARROW,	
	GB_WG_KEY_DOWN_ARROW,
	GB_WG_KEY_LEFT_ARROW,
	GB_WG_KEY_RIGHT_ARROW,
	GB_WG_KEY_SEND,
	GB_WG_KEY_END,	
	GB_WG_KEY_CLEAR,
	GB_WG_KEY_VOL_UP,
	GB_WG_KEY_VOL_DOWN,
	GB_WG_KEY_QUICK_ACS,
	GB_WG_KEY_ENTER,
	GB_WG_KEY_ESC,
	GB_WG_KEY_BACK,
	GB_WG_KEY_POWER,
	GB_WG_KEY_SEND1,
    GB_WG_KEY_SEND2,
//QWERTY Begin
	GB_WG_KEY_A,
	GB_WG_KEY_B,
	GB_WG_KEY_C,
	GB_WG_KEY_D,
	GB_WG_KEY_E,
	GB_WG_KEY_F,
	GB_WG_KEY_G,
	GB_WG_KEY_H,
	GB_WG_KEY_I,
	GB_WG_KEY_J,
	GB_WG_KEY_K,
	GB_WG_KEY_L,
	GB_WG_KEY_M,
	GB_WG_KEY_N,
	GB_WG_KEY_O,
	GB_WG_KEY_P,
	GB_WG_KEY_Q,
	GB_WG_KEY_R,
	GB_WG_KEY_S,
	GB_WG_KEY_T,
	GB_WG_KEY_U,
	GB_WG_KEY_V,
	GB_WG_KEY_W,
	GB_WG_KEY_X,
	GB_WG_KEY_Y,
	GB_WG_KEY_Z,
	GB_WG_KEY_SPACE,
	GB_WG_KEY_TAB,
	GB_WG_KEY_DEL,
	GB_WG_KEY_ALT,
	GB_WG_KEY_CTRL,
	GB_WG_KEY_WIN,
	GB_WG_KEY_SHIFT,
	GB_WG_KEY_QUESTION,
	GB_WG_KEY_PERIOD,
	GB_WG_KEY_COMMA,
	GB_WG_KEY_EXCLAMATION,
	GB_WG_KEY_APOSTROPHE,
	GB_WG_KEY_AT,
	GB_WG_KEY_BACKSPACE,
	GB_WG_KEY_FN,
	GB_WG_KEY_SYMBOL,
	GB_WG_KEY_NUM_LOCK,
	GB_WG_KEY_QWERTY_MENU,
	GB_WG_KEY_OK,
//QWERTY End
	GB_WG_MAX_KEYS,	
	GB_WG_KEY_INVALID
}GBKeyValue;

typedef enum _GBKEYEVENT{
	GBKEY_PRESS = 0,
	GBKEY_RELEASE,
	GBKEY_LONG_PRESS,
	GBKEY_REPEAT,
//	GBEVENT_INPUTBOX_CALLBACK,
	GBEVENT_HANDWRITEND,
	GBEVENT_HWCONFIRM,
	GBEVENT_INVALID
}GBKeyEvent;

typedef enum _GBPENEVENT{
	GBPEN_DOWN = 0,
	GBPEN_UP,
	GBPEN_MOVE, 
	GBPEN_LONGTAP,
	GBPEN_INVALID
}GBPenEvent;

GBKeyValue  GetKeyValueFromPlat(GB_INT platKeyValue);
GBKeyEvent  GetKeyEventFromPlat(GB_INT platKeyEvent);
GBPenEvent  GetPenEventFromPlat(GB_INT platPenEvent);


#endif
