#include <linux/types.h>

/* LED Stubs - Disabling LED functionality */
void rtw_led_control(void *p, int c) {}
void rtw_led_tx_control(void *p, int c) {}
void rtw_led_rx_control(void *p, int c) {}
void rtl8822bu_initswleds(void *p) {}
void rtl8822bu_deinitswleds(void *p) {}
void dump_led_config(void *p, void *q) {}
void rtw_led_set_strategy(void *p, int s) {}
void rtw_led_set_iface_en_mask(void *p, int m) {}
void rtw_led_set_ctl_en_mask_primary(void *p, int m) {}
void rtw_led_set_iface_en(void *p, int e) {}

/* PHYDM & Power Tracking Stubs - Resolving AP/Client conflicts */
void odm_txpowertracking_init(void *p) {}
void phydm_get_thermal_trim_offset(void *p) {}
void phydm_get_power_trim_offset(void *p) {}
void phydm_get_pa_bias_offset(void *p) {}
void set_current_tx_agc(void *p) {}
void phydm_config_new_kfree(void *p) {}
void watchdog_stop(void *p) {}
void phydm_la_cmd(void *p) {}
void phydm_la_init(void *p) {}

/* Beamforming Stubs */
u32 beamforming_get_vht_ndp_tx_rate(void *p) { return 0; }
u32 beamforming_get_htndp_tx_rate(void *p) { return 0; }

/* Hardware & Interface Stubs */
void UpdateInterruptMask8822BE(void *p) {}
void mdio_write_88xx(void *p) {}
void dbi_w8_88xx(void *p) {}
void EFUSE_GetMaskArray_MP_8822B_USB(void *p) {}

/* IO Wrapper Stubs */
/* These usually map to macros. If the linker asks for them, 
   the header definitions might be missing or mismatched. */
u8 RTL_R8(void *p, u32 addr) { return 0; }
u32 RTL_R32(void *p, u32 addr) { return 0; }
void RTL_W8(void *p, u32 addr, u8 val) {}
void RTL_W32(void *p, u32 addr, u32 val) {}
void Efuse_OneByteRead(void *p, u16 addr, u8 *data, bool b) {}
u32 RTL_MILISECONDS_TO_JIFFIES(u32 ms) { return ms; }

/* Debug Stubs */
void panic_printk(const char *fmt, ...) {}

