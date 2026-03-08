================================================
ZYXEL-MATRIX FIRMWARE LOADER FOR WSR30 ROUTER
================================================


Version: 2.0.0
Author: Qureshi Majad
Date: March 2026

--------------------------------------------------------------------

TABLE OF CONTENTS
-----------------
1. About
2. Requirements
3. Files Needed
4. Installation Steps
5. Router Modes
6. Default Settings
7. Security Recommendations
8. Support

--------------------------------------------------------------------

1. ABOUT
--------
Zyxel-Matrix is a custom router OS designed specifically for the 
"Zyxel Multy U AC2100 Tri-band WiFi Mesh" (technically known as WSR30). 
This user-friendly operating system provides a web-based configuration 
interface making router management simple and accessible.

The port is still under active development with more features being 
added in future releases.

--------------------------------------------------------------------

2. REQUIREMENTS
---------------
Before you begin, ensure you have:

Hardware:
• Zyxel Multy U AC2100 (WSR30) router
• Ethernet cable
• Windows PC with Ethernet port

Software:
• TFTP Client enabled in Windows
• Zyxel-Matrix Loader (included in this package)
• Firmware file (firmware.bin)

--------------------------------------------------------------------

3. FILES NEEDED
---------------
Place both files in the same folder:
• Zyxel-Matrix-Loader.exe  - The flashing tool
• firmware.bin              - The router operating system

--------------------------------------------------------------------

4. INSTALLATION STEPS
---------------------
Follow these steps carefully to install Zyxel-Matrix on your router:

STEP 1: Prepare Your PC
   • Connect your PC to the router using an Ethernet cable
   • Set your PC's Ethernet adapter to a static IP:
     - IP Address: 192.168.1.10
     - Subnet Mask: 255.255.255.0
     - Default Gateway: (leave blank)

STEP 2: Enter Recovery Mode
   • Disconnect power from the router
   • Press and hold the reset button
   • While holding reset, connect power
   • Continue holding until the LED turns GREEN
   • Release reset button

STEP 3: Flash the Firmware
   • Launch Zyxel-Matrix-Loader.exe
   • Click "Browse" or "Scan Local Folder" to select firmware.bin
   • Verify the file is loaded correctly
   • Click "Flash Firmware" button
   • Wait for the progress bar to complete
   • Do NOT power off during flashing!

STEP 4: First Boot
   • Router will automatically reboot (takes 2-3 minutes)
   • First boot takes longer than normal
   • Wait for the LED to indicate normal operation, when it is still and GREEN

--------------------------------------------------------------------

5. ROUTER MODES
---------------
The router operates in two modes after flashing:

MODE 1: AP MODE (DEFAULT)
   • Default mode immediately after flashing
   • Provides full routing capabilities
   • Connect internet cable to WAN port (RJ45 next to reset button)
   • WiFi networks broadcast automatically

MODE 2: BRIDGE/REPEATER MODE
   • No DHCP or DNS services
   • Do NOT connect internet cable directly
   • Use to extend existing wireless network
   • Ideal for mesh networking and range extension
   • Access management interface at 192.168.1.5

--------------------------------------------------------------------

6. DEFAULT SETTINGS
-------------------
AP MODE (Default):
   • Router IP: 192.168.2.1
   • WiFi SSID 2.4GHz: Zyxel_Matrix_24
   • WiFi SSID 5GHz: Zyxel_Matrix_5G
   • WiFi Password: 12345678
   • SSH Access: root / 1234
   • Luci Interface: root / 1234

BRIDGE/REPEATER MODE:
   • Management IP: 192.168.1.5
   • SSH Access: root / 1234
   • Luci Interface: root / 1234

--------------------------------------------------------------------

7. SECURITY RECOMMENDATIONS
---------------------------
IMMEDIATELY AFTER FIRST BOOT:
   • Change default WiFi password
   • Change router admin password
   • Change SSH root password
   • Update router IP if needed
   • Review WiFi security settings

--------------------------------------------------------------------

8. SUPPORT
----------
For issues, questions, or feedback:
• Check the CHANGELOG.txt for known issues
• Visit the forums for WSR30 discussions
• Report bugs with detailed description of the issue

--------------------------------------------------------------------

IMPORTANT WARNINGS:
-------------------
⚠️ Never power off the router during firmware flashing
⚠️ Do not interrupt the TFTP transfer process
⚠️ First boot takes 2-3 minutes - be patient
⚠️ Keep default passwords secure and change them immediately
⚠️ In repeater mode, never plug internet cable directly
⚠️ Always backup your current configuration before flashing

--------------------------------------------------------------------
© 2024 Majad Qureshi . All rights reserved.
This firmware is provided as-is without warranty of any kind.
