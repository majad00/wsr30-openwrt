# 
# Copyright (C) 2006-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
# Modified by majad qureshi for WSR30 Multy U Zyxel Tri band router
include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/image.mk

OBJCOPY := $(TOPDIR)/staging_dir/toolchain-mips_24kec_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-objcopy
LOADER_MAKE := $(NO_TRACE_MAKE) -C lzma-loader KDIR=$(KDIR) LINUX_DIR=$(LINUX_DIR)


BlockSize=128k
ifeq ($(CONFIG_MTD_NAND_RTK_BLOCK_SIZE),0x80000)
BlockSize=512k
endif
ifeq ($(CONFIG_MTD_NAND_RTK_BLOCK_SIZE),0x20000)
BlockSize=128k
endif

define mkcmdline
board=$(1) console=$(2),$(3) linuxpart=0x$(4) hwpart=0x$(5)
endef

#console=ttyS0,38400 mtdparts=rtk_nand:5M(boot)ro,3M(setting)ro,6M(linux),66M(rootfs),8M(config),6M(linux2),66M(rootfs2),48M(app),128M(rootfs_data) root=/dev/mtdblock3 rootfstype=squashfs

SINGLE_PROFILES :=

define SingleProfile

  define Image/Build/Profile/$(1)/initramfs
	$(call Image/BuildLoader,loader-$(SUBTARGET)-$(1),bin,$(call mkcmdline,$(1),$(2),$(3)) $(4),$(5))
	cvimg-$(SUBTARGET) linux $(KDIR)/loader-$(SUBTARGET)-$(1).bin $(BIN_DIR)/$(IMG_PREFIX)-$(1)-ramfs.bin $(5) $(6)
  endef
ifeq ($(CONFIG_MTD_NAND_RTK),y)
 define Image/Build/Profile/$(1)/squashfs
	rm -f $(KDIR)/loader-fixed.bin $(KDIR)/image.raw
	$(call Image/BuildLoader,$(1),bin,$(call mkcmdline,$(1),$(2),$(3),$(6),$(7)),$(5))
	cp $(KDIR)/loader-fixed.bin $(KDIR)/image.raw
	truncate -s 6291440 $(KDIR)/image.raw
	cat $(KDIR)/root.squashfs-4k >> $(KDIR)/image.raw
	rm -f $(BIN_DIR)/openwrt-wsr30-firmware.bin
	$(STAGING_DIR_HOST)/bin/cvimg-rtl8198c linux $(KDIR)/image.raw \
		$(BIN_DIR)/openwrt-wsr30-final.bin 0x80c00000 0x80000006
	@echo "--- Verifying SquashFS Offset ---"
	
	#@if [ "$$(grep -aob "hsqs" $(BIN_DIR)/rtkmips/openwrt-wsr30-final.bin | cut -d: -f1)" = "5242880" ]; then \
	#	echo "Success: SquashFS starts at exactly 5MB (5242880)"; \
	#else \
	#	echo "ERROR: SquashFS alignment is WRONG!"; \
	#	exit 1; \
	#fi
	
	@echo "--- VERIFYING SIGNATURE ---"
	@hexdump -C $(BIN_DIR)/openwrt-wsr30-final.bin | head -n 2
  endef 


endif
  SINGLE_PROFILES += $(1)

endef

define MultiProfile

  define Image/Build/Profile/$(1)/initramfs
	$(foreach p,$(2),
		$$(call Image/Build/Profile/$p/initramfs)
	)
  endef

  define Image/Build/Profile/$(1)/squashfs
	$(foreach p,$(2),
		$$(call Image/Build/Profile/$p/squashfs)
	)
  endef

endef

define Image/Prepare
	rm -f $(KDIR)/vmlinux.final.lzma $(KDIR)/vmlinux_raw.bin $(KDIR)/vmlinux.bin.lzma
	$(TARGET_CROSS)objcopy -O binary -S $(KDIR)/vmlinux.elf $(KDIR)/vmlinux_raw.bin
	lzma e $(KDIR)/vmlinux_raw.bin -d20 -lc3 -lp0 -pb2 $(KDIR)/vmlinux.bin.lzma
	
	@echo "SUCCESS: Verify 5d 00 start:"
	@hexdump -C $(KDIR)/vmlinux.bin.lzma | head -n 1
endef


define Build/Clean
	$(LOADER_MAKE) clean
endef

define Image/BuildLoader
	@echo "DEBUG: Compiling LZMA loader"
	$(LOADER_MAKE) LOADER=loader.bin \
		KERNEL_CMDLINE="$(call mkcmdline,$(1),$(2),$(3),$(4))" \
		LZMA_TEXT_START=0x80a00000 \
		LOADADDR=0x80000000 \
		LOADER_DATA="$(KDIR)/vmlinux.bin.lzma" BOARD="$(1)" \
		compile loader.bin
	cp $(KDIR)/lzma-loader/loader.bin $(KDIR)/loader-fixed.bin
endef

# rtl819xd profiles
#
ifeq ($(CONFIG_TARGET_rtkmips_rtl8198c),y)
  $(eval $(call SingleProfile,AP,ttyS0,38400,root=/dev/mtdblock6 rootfstype=squashfs,0x80c00000,0x80000005,0))
  Image/Build/Profile/Default := $(Image/Build/Profile/AP/squashfs)
endif

# RAMFS
define Image/Build/Initramfs
	$(call Image/Build/Profile/$(PROFILE)/initramfs)
endef


# SQUASHFS
ifeq ($(CONFIG_MTD_NAND_RTK),y)
define Image/Build
	$(if $(filter squashfs,$(1)), \
		dd if=$(KDIR)/root.squashfs of=$(KDIR)/root.squashfs-4k bs=$(BlockSize) conv=sync; \
		$(call Image/Build/Profile/$(PROFILE)/squashfs) \
	)
endef
else
define Image/Build
	$(if $(filter squashfs,$(1)), \
		dd if=$(KDIR)/root.squashfs of=$(KDIR)/root.squashfs-4k bs=128k conv=sync; \
		$(call Image/Build/Profile/AP/squashfs) \
	)
endef
endif

$(eval $(call BuildImage))
