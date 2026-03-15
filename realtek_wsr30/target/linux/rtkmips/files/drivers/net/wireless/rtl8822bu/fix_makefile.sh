#!/bin/bash

# 1. List of all undefined symbols from your error log
SYMBOLS=(
    "phydm_get_condi_num_8822b" "odm_read_and_config_mp_8822b_agc_tab" 
    "odm_read_and_config_mp_8822b_phy_reg" "rtw_led_set_iface_en" 
    "phydm_clm_dbg" "ex_halbtc8822b2ant_halt_notify" "rtl8822bu_set_hw_type" 
    "phydm_rf_init" "config_phydm_switch_band_8822b" "rtw_roch_stay_in_cur_chan" 
    "phydm_rx_phy_status_init" "phydm_rate_type_2_num_ss" "odm_c2h_ra_para_report_handler" 
    "phydm_get_pa_bias_offset" "rm_post_event_hdl" "rtl8822bu_set_hal_ops" 
    "phydm_env_mntr_dbg" "rtw_init_roch_info" "phydm_show_sta_info" 
    "phydm_rrsr_set_register" "ex_halbtc8822b1ant_periodical" "PHY_GetTxPowerFinalAbsoluteValue" 
    "phydm_get_thermal_offset" "phy_set_rf_path_switch_8822b" "rtw_pci_aspm_config" 
    "rtw_regd_apply_flags" "config_phydm_read_rf_reg_8822b" "odm_phy_status_query" 
    "set_current_tx_agc" "phydm_bf_debug" "EFUSE_GetMaskArray_MP_8822B_MUSB" 
    "rtw_led_set_ctl_en_mask_primary" "phydm_la_cmd" "phydm_la_init" 
    "phy_get_iqk_cfir_8822b" "phydm_gen_bitmask" "mgmt_xmitframe_enqueue_for_sleeping_sta" 
    "phydm_env_mntr_set_watchdog" "phydm_ra_info_watchdog" "rtw_regd_init" 
    "phydm_ra_debug" "phydm_noisy_detection" "phydm_ra_info_init" 
    "rtw_led_rx_control" "ex_halbtc8822b2ant_display_coex_info" "odm_set_tx_ant_by_tx_info" 
    "rtw_dump_mac_rx_counters" "config_phydm_switch_channel_8822b" "phydm_config_kfree" 
    "phydm_nhm_dbg" "rtw_roch_wk_cmd" "beamforming_get_vht_ndp_tx_rate" 
    "halrf_rf_lna_setting_8822b" "Efuse_OneByteRead" "phy_lc_calibrate_8822b" 
    "halrf_init_debug_setting" "phydm_fahm_dbg" "do_imr_test_8822b" 
    "rtw_led_control" "phy_iq_calibrate_8822b" "halrf_psd_init" 
    "halrf_set_pwr_track" "phydm_physts_dbg" "rtw_roch_wk_hdl" 
    "config_phydm_write_rf_reg_8822b" "phydm_rf_watchdog" "phydm_rfe_8822b_init" 
    "phydm_lna_sat_check_init" "rtw_led_tx_control" "phy_iqk_dbg_cfir_backup_update_8822b" 
    "phydm_get_cck_rssi_table_from_reg" "config_phydm_write_txagc_8822b" 
    "phydm_8822btxbf_rfmode" "phydm_ra_registed" "phydm_env_monitor_init" 
    "init_adapter_param_88xx" "phydm_rrsr_en" "mount_api_88xx" 
    "config_phydm_trx_mode_8822b" "phydm_8822b_sutxbfer_workaroud" 
    "config_phydm_parameter_init_8822b" "config_phydm_read_txagc_8822b" 
    "phydm_cnvrt_2_sign" "halrf_psd_query" "phydm_rssi_monitor_init" 
    "phydm_modify_RA_PCR_threshold" "configure_txpower_track" "odm_update_rx_idle_ant" 
    "halrf_cmd_parser" "odm_clear_txpowertracking_state" "UpdateInterruptMask8822BE"
)

echo "Searching for missing files..."
FOUND_FILES=()

for sym in "${SYMBOLS[@]}"; do
    # Search for the function definition (ends with a brace or space) in .c files
    FILE=$(grep -rE "^\w+.*$sym\s*\(" . | grep "\.c:" | head -n 1 | cut -d: -f1 | sed 's|^\./||')
    
    if [ -n "$FILE" ]; then
        # Convert .c to .o
        OBJ_FILE="${FILE%.c}.o"
        FOUND_FILES+=("$OBJ_FILE")
    fi
done

# Sort and remove duplicates
UNIQUE_FILES=$(echo "${FOUND_FILES[@]}" | tr ' ' '\n' | sort -u)

echo "------------------------------------------------"
echo "ADD THESE TO YOUR rtl8822bu-y LIST IN MAKEFILE:"
echo "------------------------------------------------"
echo "$UNIQUE_FILES" | sed 's/$/ \\/'
echo "------------------------------------------------"

