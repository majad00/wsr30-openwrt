# Building from Source: Router Hardware Specs

## Hardware Specifications
- **CPU:** MIPS 1074Kc (Realtek RTL8198C)
- **SoC:** Realtek RTL8198C @ 800MHz
- **RAM:** 256MB DDR3
- **Flash:** 512MB NAND (F59L4G81A)
- **Partitions:** 9 MTD partitions, including dual firmware (linux/rootfs and linux2/rootfs2)
- **WiFi:** Realtek 8822B (USB-connected)
- **Bootloader:** Zyxel Multiboot (proprietary)

## Compilation Instructions

The source code must be compiled separately, and the master copy requires some modifications. Follow these steps:

1. Compile the driver first
2. Run `make menuconfig` to adjust the features you want to add or remove

### Files to Modify

The following files need to be modified to support the WSR30, partition layout, and bootloader address:

- `target/linux/rtkmips/image/Makefile`
- `target/linux/rtkmips/image/lzma-loader/src/loader.c`
- `target/linux/rtkmips/files/arch/mips/realtek/Platform`
- `target/linux/rtkmips/files/arch/rlx/soc-rtl819xd/prom.c`
- `target/linux/rtkmips/files/arch/rlx/kernel/vmlinux.lds.S`
- `target/linux/rtkmips/rtl8198c/config-3.10`
- `target/linux/rtkmips/files/drivers/mtd/nand/rtk_nand_sd.c`
- `target/linux/rtkmips/files/drivers/mtd/nand/rtknflash/ops_rtknand.c`
- `target/linux/rtkmips/files/drivers/mtd/nand/rtkn_nand/rtknflash_openwrt.c`
- `target/linux/rtkmips/files/drivers/mtd/nand/rtknflash/rtknflash.h` (BBT)
- `target/linux/rtkmips/files/drivers/mtd/nand/Kconfig`

### Partition Layout

To match the required NAND driver partition layout in `rtk_nand_sd.c`, change the default layout to the following 9 MTD partitions:

| Partition | Address Range | Name |
|-----------|--------------|------|
| 1 | `0x000000000000-0x000000500000` | boot |
| 2 | `0x000000500000-0x000000800000` | setting |
| 3 | `0x000000800000-0x000000e00000` | linux |
| 4 | `0x000000e00000-0x000005000000` | rootfs |
| 5 | `0x000005000000-0x000005800000` | config |
| 6 | `0x000005800000-0x000005e00000` | linux2 |
| 7 | `0x000005e00000-0x00000a000000` | rootfs2 |
| 8 | `0x00000a000000-0x00000d000000` | app |
| 9 | `0x00000d000000-0x000015000000` | wsr |

Make sure to use the exact console command after partition modifications:

console=ttyS0,38400 mtdparts=rtk_nand:5M(boot),3M(setting),4M(kernel),68M(rootfs) root=/dev/mtdblock3 rootfstype=squashfs ro init=/sbin/init


Flashing the Binary
Use the following NANDW commands to burn the resulting binary:

Open the router and locate the TX, RX, and ground wires. Connect them accordingly. Once connected you should be able to see Realtek prompt (by pressing ESC during the boot process)

UART CONNECTION GUIDE

<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/2532cdbc-8d5e-44e5-8b76-afa5dc57ae2a" />

After you access the Realtek prompt, Set up the Ethernet connection with the following command:
ETH
ipconfig 192.168.1.6
autoburn 0
Now go to Windows or Linux and send firmware (Windows: tftp -i 192.168.1.6 put firmware.bin)
choose one of Bank to flash firmware, recommended is Bank 2.
Flashing Bank 1
nandbe 40 27F
NANDW 800000 A0500000 SIZE
db 1
Flashing Bank 2
nandbe 2C0 4FF
NANDW 5800000 A0500000 SIZE
db 1

**Troubleshooting**
If the kernel refuses to load or you encounter a compression error, ensure the following specific settings in the Makefile. Change mtdblock3 to mtdblock6 for bank 2 installation:

LZMA_TEXT_START=0x80c00000 \
LOADADDR=0x80000000 \
BOARD="AP" \
KERNEL_CMDLINE=console=ttyS0,38400 root=/dev/mtdblock3 rootfstype=squashfs init=/sbin/init

**Manual Compilation Guide**
Note: All these commands assume the SDK root is:
/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek/

Manually Compiling WiFi Drivers
cd /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/drivers/net/wireless/rtl8822bu/

cd /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek

make -C build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49 \
ARCH="mips" \
CROSS_COMPILE="mips-openwrt-linux-uclibc-" \
M="drivers/net/wireless/rtl8822bu" \
CONFIG_RTL8822BU=m

Manually Compiling Loader.bin (LZMA Loader)
cd /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/target/linux/rtkmips/image/lzma-loader
export STAGING_DIR=/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/staging_dir
make clean
make loader.bin \
CROSS_COMPILE=/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/staging_dir/toolchain-mips_24kec_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc- \
LZMA_TEXT_START=0x80c00000 \
LOADADDR=0x80000000 \
BOARD="AP" \
KERNEL_CMDLINE="console=ttyS0,38400 root=/dev/mtdblock3 rootfstype=squashfs init=/sbin/init" \
LOADER_DATA=/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/vmlinux.lzma

Manually Compiling SquashFS
# Define the paths
ROOT_DIR="/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/build_dir/target-mips_24kec_uClibc-0.9.33.2/root-rtkmips"
KDIR="/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c"
MKSQUASHFS="/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/squashfs-new/squashfs-tools/mksquashfs_mips_be"
# Generate the rootfs directly into KDIR
rm $KDIR/root.squashfs
# Use mksquashfs4 to create the squashfs image
/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/realtek/staging_dir/host/bin/mksquashfs4 $ROOT_DIR $KDIR/root.squashfs \
-nopad -noappend -root-owned -comp xz \
-p '/dev d 755 0 0' \
-p '/dev/console c 600 0 0 5 1' \
-p '/dev/ttyS0 c 666 0 0 4 64' \
-p '/dev/null c 666 0 0 1 3'

Manually Compiling Kernel
cd /home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49
export PATH=$PATH:/home/majad/OpenWrt/wsr30/openwrt_rtk/rtk_openwrt_sdk/staging_dir/toolchain-mips_24kec_gcc-4.8-linaro_uClibc-0.9.33.2/bin
export ARCH=mips
export CROSS_COMPILE=mips-openwrt-linux-
# Edit linker script if needed: nano arch/mips/kernel/vmlinux.lds
make vmlinux LDFLAGS_vmlinux="-e 0x80003c10"

Version 1 - Create LZMA compressed kernel
xz --format=lzma --lzma1=lc=3,lp=0,pb=2,dict=512KiB -c vmlinux > vmlinux.lzma

Version 2 - Alternative method using objcopy and lzma
mips-openwrt-linux-objcopy -O binary vmlinux vmlinux.bin
lzma e vmlinux.bin vmlinux.lzma -d512k -lc3 -lp0 -pb2

**Important** Notes
For Bank 2 installation, change mtdblock3 to mtdblock6 in all kernel command lines
The SIZE parameter in NANDW commands must be the exact hex size of the TFTP upload
Make sure to use the correct toolchain paths for your environment











