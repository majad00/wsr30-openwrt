Manual Compilation Guide Note: All these commands assume the SDK root is: /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek/

Manually Compiling WiFi Drivers


cd /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/drivers/net/wireless/rtl8822bu/
cd /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek
make -C build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49 \
ARCH="mips" \
CROSS_COMPILE="mips-openwrt-linux-uclibc-" \
M="drivers/net/wireless/rtl8822bu" \
CONFIG_RTL8822BU=m