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

Open the router and locate the TX, RX, and ground wires. Connect them accordingly. One wire should be connected to Realtek prompt (by pressing ESC during the boot process)

Set up the Ethernet connection with the following command:

plaintext
ipconfig 192.168.1.6
Execute the command autoburn 0. For example, using TFTP on Windows:

cmd
tftp -i 192.168.1.6 put firmware.bin
Once TFTP is complete, burn using the following commands, selecting Bank 1 or Bank 2.

Bank 1
plaintext
nandbe 40 27F
NANDW 800000 A0500000 SIZE
db 1
Bank 2
plaintext
nandbe 2C0 4FF
NANDW 5800000 A0500000
db 1


Troubleshooting
If the kernel refuses to load or you encounter a compression error, ensure the following specific settings in the Makefile. Change mtdblock3 to mtdblock6 for bank 2 installation:

makefile
LZMA_TEXT_START=0x80c00000 \
LOADADDR=0x80000000 \
BOARD="AP" \
KERNEL_CMDLINE=console=ttyS0,38400 root=/dev/mtdblock3 rootfstype=squashfs init=/sbin/init
