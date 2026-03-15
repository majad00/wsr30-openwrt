/******************************************************************************
 *
 * Port for WSR30 by majad qureshi at lut.fi
 *****************************************************************************/
 
 #ifndef __PHYDM_FEATURES_IOT_H__
#define __PHYDM_FEATURES_IOT_H__

/* 1. DISABLE problematic Logic Analyzer (This fixes your current crash) */
#define PHYDM_LA_MODE_SUPPORT            0

/* 2. Basic Signal Quality Features (Keep these for stability) */
#define NHM_SUPPORT
#define CLM_SUPPORT
#define PHYDM_SUPPORT_CCKPD
#define PHYDM_SUPPORT_ADAPTIVITY
#define PHYDM_SUPPORT_RSSI_MONITOR
#define CFG_DIG_DAMPING_CHK

/* 3. RTL8822B Specific Hardware Fixes */
#if (RTL8822B_SUPPORT)
    #define PHYDM_TXA_CALIBRATION
    #define PHYDM_POWER_TRAINING_SUPPORT
    #define CONFIG_ADAPTIVE_SOML
    #define PHYDM_DC_CANCELLATION
#endif

/* 4. Antenna Diversity (Essential for 2x2 MIMO) */
#ifdef CONFIG_ANTENNA_DIVERSITY
    #define CONFIG_PHYDM_ANTENNA_DIVERSITY
    /* Note: We keep this simple. S0S1 is usually for single-antenna chips. */
#endif

/* 5. Disable non-existent SoC headers */
#undef CONFIG_HL_SMART_ANTENNA_TYPE2
#undef CONFIG_PSD_TOOL

/* 6. Beamforming (Optional: If your Makefile enables it) */
#ifdef PHYDM_BEAMFORMING_SUPPORT
    #if (RTL8822B_SUPPORT)
        #define DRIVER_BEAMFORMING_VERSION2
        #define CONFIG_BB_TXBF_API
    #endif
#endif

#ifdef CONFIG_BT_COEXIST
    #define ODM_CONFIG_BT_COEXIST
#endif

#endif