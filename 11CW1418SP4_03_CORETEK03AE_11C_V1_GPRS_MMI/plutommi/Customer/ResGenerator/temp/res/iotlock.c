
#include "mmi_features.h"

#ifdef __IOT_LOCK__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_IOT_LOCK">

	<RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="iot_lock_sr_nw_availability_changed_notify"/>
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED" proc="iot_lock_sim_imsi_changed_notify"/>
	<TIMER id="BOOTUP_LED_BEEP_TIMER"/>
	<TIMER id="LOCK_KICK_DOG_TIMER"/>
#ifdef __IOT_BLE_BKSS_SUPPORT__
	<TIMER id="BLE_BKSS_CONNECTED_TIMER"/>
	<TIMER id="BLE_BKSS_TIMER"/>
	<TIMER id="BLE_BKSS_VIB_TIMER"/>
	<TIMER id="BLE_BKSS_OPEN_TIMER"/>
	<TIMER id="BLE_BKSS_OPEN_TIMER2"/>
	<TIMER id="BLE_BKSS_CLOSE_TIMER"/>
#endif

	<TIMER id="LOCK_REG_TIMER"/>
	<TIMER id="LOCK_AUTH_TIMER"/>
	<TIMER id="LOCK_HEART_BEAT_TIMER"/>
	<TIMER id="LOCK_HEART_TIMEOUT_TIMER"/>
	<TIMER id="LOCK_GPS_ON_TIMER"/>
	<TIMER id="LOCK_GPS_UPDATE_TIMER"/>
	<TIMER id="LOCK_GPS_CTL_TIMER"/>
	<TIMER id="LOCK_GPS_STOP_TIMER"/>
	<TIMER id="LOCK_GPS_QUERY_TIMER"/>
	<TIMER id="LOCK_VIB_REPORT_TIMER"/>
	<TIMER id="LOCK_RESETLOCK_TIMER"/>
	<TIMER id="LOCK_OPEN_LOCK_TIMER"/>
	<TIMER id="LOCK_LOCK_TIMER"/>
	<TIMER id="LOCK_OPEN_HISR_TIMER"/>
	<TIMER id="LOCK_CLOSE_HISR_TIMER"/>
	<TIMER id="LOCK_SHARK_TIMER"/>
	<TIMER id="LOCK_OPEN_G_SENEOR_TIMER"/>
	<TIMER id="LOCK_LED1_TIMER"/>
	<TIMER id="LOCK_LED2_TIMER"/>
	<TIMER id="LOCK_LED3_TIMER"/>
	<TIMER id="LOCK_LED4_TIMER"/>
	<TIMER id="LOCK_BEEP_TIMER1"/>
	<TIMER id="LOCK_BEEP_TIMER2"/>
	<TIMER id="LOCK_MOTOR_TIMER1"/>
	<TIMER id="LOCK_MOTOR_TIMER2"/>
	<TIMER id="LOCK_ATA_AT_TIMER1"/>
	<TIMER id="LOCK_ATA_AT_TIMER2"/>
	<TIMER id="LOCK_ATA_AT_TIMER3"/>
	<TIMER id="LOCK_ATA_AT_TIMER4"/>
	<TIMER id="LOCK_ACC_VIB_TIMER1"/>
	<TIMER id="LOCK_ACC_VIB_TIMER2"/>
	<TIMER id="LOCK_ACC_VIB_TIMER3"/>
	<TIMER id="LOCK_ACC_VIB_TIMER4"/>
	<TIMER id="LOCK_ACC_VIB_TIMER5"/>
	<TIMER id="LOCK_ACC_VIB_TIMER6"/>
	<TIMER id="LOCK_TRANS_TIMER"/>
	<TIMER id="LOCK_STOP_USER_TIMER"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER0"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER1"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER2"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER3"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER4"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER5"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER6"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER7"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER8"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER9"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER10"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER11"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER12"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER13"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER14"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER15"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER16"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER17"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER18"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER19"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER20"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER21"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER22"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER23"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER24"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER25"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER26"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER27"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER28"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER29"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER30"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER31"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER32"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER33"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER34"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER35"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER36"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER37"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER38"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER39"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER40"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER41"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER42"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER43"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER44"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER45"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER46"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER47"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER48"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER49"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER50"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER51"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER52"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER53"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER54"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER55"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER56"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER57"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER58"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER59"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER60"/>
	<TIMER id="LOCK_RESEND_TIMEOUT_TIMER_MAXNUM"/>
	<TIMER id="LOCK_MOVE_TIMER"/>
	<TIMER id="LOCK_MOVE_STOP_TIMER"/>
	<TIMER id="LOCK_SHARK_GAP_TIMER"/>
	<TIMER id="LOCK_SLOPE_TIMER"/>
	<TIMER id="LOCK_FOTA_START_TIMER"/>
	<TIMER id="LOCK_LOCK_AMEND_TIMER"/>
	<TIMER id="LOCK_DELAY_REPORT_TIMER"/>
	<TIMER id="LOCK_LOC_REPORT_TIMER"/>
	
	<TIMER id="LOCK_ECG_TIMER1"/>
	<TIMER id="LOCK_ECG_TIMER2"/>
	<TIMER id="LOCK_UPLOAD_ECG_TIMER"/>
	<TIMER id="LOCK_UPLOAD_ECG_BEGIN_TIMER"/>
	<TIMER id="LOCK_LOW_POWER_GPS_REPORT_TIMER"/>

	<TIMER id="LOCK_CONN_TIMER"/>
	<TIMER id="LOCK_REG_TIMEOUT_TIMER"/>
	<TIMER id="LOCK_AUTH_TIMEOUT_TIMER"/>
	<TIMER id="LOCK_RECONNECT_TIMER"/>
	<TIMER id="LOCK_SMS_RESET_TIMER"/>
	<TIMER id="LOCK_SMS_CHANGE_TIMER"/>
	<TIMER id="FIND_BIKE_LED_TIMER"/>
	<TIMER id="FIND_BIKE_SPEAKER_LED_TIMER"/>
	<TIMER id="NWOW_GSM_STATE_LED_TIMER"/>
</APP>

#endif /* __IOT_LOCK__ */
