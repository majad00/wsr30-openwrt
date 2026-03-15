# Force the include path to the actual directory on your disk
EXTRA_CFLAGS += -I$(PWD)/include

# --- FIXED INCLUDE PATHS ---
EXTRA_CFLAGS += -I$(src)/include
EXTRA_CFLAGS += -I$(src)/core
EXTRA_CFLAGS += -I$(src)/os_dep/include
EXTRA_CFLAGS += -I$(src)/os_dep/linux
EXTRA_CFLAGS += -I$(src)/hal
EXTRA_CFLAGS += -I$(src)/hal/rtl8822b
EXTRA_CFLAGS += -I$(src)/hal/rtl8822b/usb
EXTRA_CFLAGS += -I$(src)/hal/halmac
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/halmac_8822b
EXTRA_CFLAGS += -I$(src)/hal/phydm
EXTRA_CFLAGS += -I$(src)/hal/phydm/halrf
EXTRA_CFLAGS += -I$(src)/hal/phydm/rtl8822b
EXTRA_CFLAGS += -I$(src)/platform
EXTRA_CFLAGS += -I$(src)/hal/btc
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/pcie
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/sdio
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/usb

# --- RELAX COMPILER STRICTNESS ---
EXTRA_CFLAGS += -Wno-error
EXTRA_CFLAGS += -Wno-implicit-function-declaration
EXTRA_CFLAGS += -Wno-unused-variable
EXTRA_CFLAGS += -Wno-unused-function
EXTRA_CFLAGS += -Wno-unused-label
EXTRA_CFLAGS += -Wno-unused-value
EXTRA_CFLAGS += -Wno-return-type

# --- CONFIG FLAGS ---
EXTRA_CFLAGS += -DCONFIG_RTL8822B -DCONFIG_USB_HCI
EXTRA_CFLAGS += -DCONFIG_IOCTL_CFG80211 -DRTW_USE_CFG80211_STA_EVENT
EXTRA_CFLAGS += -DCONFIG_BIG_ENDIAN
EXTRA_CFLAGS += -DCONFIG_AP_MODE -DCONFIG_XMIT_THREAD_MODE

# --- ADDED: Fix for rtw_cmd.c undeclared variables ---
EXTRA_CFLAGS += -DCONFIG_CONCURRENT_MODE
EXTRA_CFLAGS += -DCONFIG_LAYER2_ROAMING
EXTRA_CFLAGS += -DCONFIG_SCAN_BACKOP
EXTRA_CFLAGS += -DCONFIG_ROAMING_FLAG=0x01
EXTRA_CFLAGS += -Wno-macro-redefined

#============NA
# Add these to your existing FIXED INCLUDE PATHS section
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/pcie
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/sdio
EXTRA_CFLAGS += -I$(src)/hal/halmac/halmac_88xx/usb