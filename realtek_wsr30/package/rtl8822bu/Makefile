include $(TOPDIR)/rules.mk

PKG_NAME:=rtl8822bu
PKG_RELEASE:=1

include $(INCLUDE_DIR)/kernel.mk
include $(INCLUDE_DIR)/package.mk

define KernelPackage/rtl8822bu
  SUBMENU:=Wireless Drivers
  TITLE:=Realtek 8822BU USB Wifi Driver
  DEPENDS:=+kmod-usb-core +kmod-usb2 +kmod-cfg80211 +kmod-mac80211
  FILES:=$(PKG_BUILD_DIR)/88x2bu.ko
  AUTOLOAD:=$(call AutoProbe,88x2bu)
endef

define KernelPackage/rtl8822bu/description
  Realtek 8822BU USB Wi-Fi driver (custom patched).
endef

# 1. Copy our local source into the build directory
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	cp -r ./src/* $(PKG_BUILD_DIR)/
endef

# 2. Compile using the kernel's external module system
#    We force CONFIG_RTL8822BU=m to ensure your Makefile logic works
define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		ARCH="$(LINUX_KARCH)" \
		CROSS_COMPILE="$(TARGET_CROSS)" \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		M="$(PKG_BUILD_DIR)" \
		CONFIG_RTL8822BU=m \
		modules
endef

$(eval $(call KernelPackage,rtl8822bu))

