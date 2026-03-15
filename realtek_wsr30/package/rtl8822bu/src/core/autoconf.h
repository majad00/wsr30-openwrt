/******************************************************************************
 *
 * Copyright(c) 2015 - 2017 Realtek Corporation.
 *
 * [Repaired for Minimal In-Tree Build: No LED, No Debug, No P2P]
 *
 *****************************************************************************/
#define CONFIG_SINGLE_IMG

/*
 * Public General Config
 */
#define AUTOCONF_INCLUDED
#define RTL871X_MODULE_NAME "88x2BU"
#define DRV_NAME "rtl88x2bu"

/* Set CONFIG_RTL8822B from Makefile */
#ifndef CONFIG_RTL8822B
#define CONFIG_RTL8822B
#endif
#define CONFIG_USB_HCI	1
#define PLATFORM_LINUX	1

/*
 * Wi-Fi Functions Config
 */
#define CONFIG_80211N_HT
#define CONFIG_80211AC_VHT
#ifdef CONFIG_80211AC_VHT
	#ifndef CONFIG_80211N_HT
		#define CONFIG_80211N_HT
	#endif
	#define CONFIG_BEAMFORMING
#endif

/* set CONFIG_IOCTL_CFG80211 from Makefile */
#ifdef CONFIG_IOCTL_CFG80211
	#define CONFIG_CFG80211_FORCE_COMPATIBLE_2_6_37_UNDER
	#define CONFIG_SET_SCAN_DENY_TIMER
#endif

/*
 * Internal General Config
 */
#define RTW_HALMAC		/* Use HALMAC architecture, necessary for 8822B */
#define CONFIG_EMBEDDED_FWIMG	1
#if (CONFIG_EMBEDDED_FWIMG==1)
	#define	LOAD_FW_HEADER_FROM_DRIVER
#endif

#define CONFIG_XMIT_ACK
#ifdef CONFIG_XMIT_ACK
	#define CONFIG_ACTIVE_KEEP_ALIVE_CHECK
#endif

#define CONFIG_RECV_REORDERING_CTRL	1

/* Power Saving */
#ifdef CONFIG_POWER_SAVING
	#define CONFIG_IPS	1
	#ifdef CONFIG_IPS
	#define CONFIG_IPS_CHECK_IN_WD 
	#endif

	#define CONFIG_LPS	1
	#if defined(CONFIG_LPS)
		#define CONFIG_LPS_LCLK	1
	#endif

	#ifdef CONFIG_LPS
		#define CONFIG_WMMPS_STA 1
	#endif 
#endif 

#ifdef CONFIG_ANTENNA_DIVERSITY
	#define CONFIG_HW_ANTENNA_DIVERSITY
#endif

/* AP Mode */
#ifdef CONFIG_AP_MODE
	#if defined(CONFIG_CONCURRENT_MODE) && defined(CONFIG_INTERRUPT_BASED_TXBCN)
		#undef CONFIG_INTERRUPT_BASED_TXBCN
	#endif
	#ifdef CONFIG_INTERRUPT_BASED_TXBCN
		#define CONFIG_INTERRUPT_BASED_TXBCN_BCN_OK_ERR
	#endif

	#define CONFIG_NATIVEAP_MLME
	#ifndef CONFIG_NATIVEAP_MLME
		#define CONFIG_HOSTAPD_MLME	1
	#endif
	#define CONFIG_FIND_BEST_CHANNEL	1
#endif

/* * [MINIMAL] Features Disabled 
 */
#undef CONFIG_P2P
#undef CONFIG_WFD
#undef CONFIG_TDLS
#undef CONFIG_RTW_LED
#undef CONFIG_RTW_SW_LED
#undef CONFIG_WOWLAN 
#undef CONFIG_GPIO_WAKEUP
#undef CONFIG_AP_WOWLAN
#undef CONFIG_MP_INCLUDED
#define MP_DRIVER 0

/* * Interface Config
 */
#define CONFIG_USB_TX_AGGREGATION	1
#define CONFIG_USB_RX_AGGREGATION	1
#define CONFIG_USB_VENDOR_REQ_BUFFER_PREALLOC
#define CONFIG_USB_VENDOR_REQ_MUTEX
#define CONFIG_VENDOR_REQ_RETRY

/*
 * HAL Config
 */
#define RTL8812A_RX_PACKET_INCLUDE_CRC	0
#define CONFIG_RX_PACKET_APPEND_FCS
#define CONFIG_OUT_EP_WIFI_MODE	0
#define ENABLE_USB_DROP_INCORRECT_OUT
#define CONFIG_ADHOC_WORKAROUND_SETTING	1
#define ENABLE_NEW_RFE_TYPE	0
#define DISABLE_BB_RF	0
#define RTL8188E_EARLY_MODE_PKT_NUM_10	0

/*
 * [CRITICAL FIXES] Minimal Build Compatibility Layer
 * These definitions satisfy the compiler when features are disabled.
 */

/* 1. Debugging Disabled (Must be 0, not undefined) */
#ifdef DBG
#undef DBG
#endif
#define DBG 0

#ifdef CONFIG_PROC_DEBUG
#undef CONFIG_PROC_DEBUG
#endif

/* 2. Missing Makefile Variables (Hardcoded for manual build) */
#ifndef CONFIG_RTW_ADAPTIVITY_EN
#define CONFIG_RTW_ADAPTIVITY_EN 0
#endif

#ifndef CONFIG_RTW_ADAPTIVITY_MODE
#define CONFIG_RTW_ADAPTIVITY_MODE 0
#endif

#define RTW_NOTCH_FILTER 0

/* 3. Dummy LED Definitions */
#ifndef LED_CTL_MODE
#define LED_CTL_SITE_SURVEY 0
#define LED_CTL_START_TO_LINK 0
#define LED_CTL_LINK 0
#define LED_CTL_POWER_ON 0
#define LED_CTL_POWER_OFF 0
#define LED_CTL_TX 0
#define LED_CTL_RX 0
#define LED_CTL_NO_LINK 0
#define LED_CTL_LINK_5G 0
#define LED_CTL_LINK_2G 0
#define LED_CTL_START_WPS 0
#define LED_CTL_STOP_WPS 0
#define LED_CTL_STOP_WPS_FAIL 0
#define LED_CTL_STOP_WPS_FAIL_OVERLAP 0
#define LED_CTL_WPS_WORKING 0
#define LED_CTL_START_WPS_BOTTON 0
#endif

/* 4. Neutralize the LED Function Call */
#define rtw_led_control(adapter, ctl) do {} while(0)