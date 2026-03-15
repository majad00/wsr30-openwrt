# Zyxel-Matrix for WSR30 (Zyxel Multy U AC2100)

[![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](LICENSE)
[![Release](https://img.shields.io/github/v/release/yourusername/zyxel-matrix-wsr30)](https://github.com/majad00/zyxel-matrix/releases/tag/v4.0.0)
[![Downloads](https://img.shields.io/github/downloads/yourusername/zyxel-matrix-wsr30/total)](https://github.com/majad00/wsr30-openwrt/releases/download/v4.0.0/Zyxel-Matrix-WSR30-v4.1.zip)

A custom OpenWrt-based operating system for the Zyxel Multy U AC2100 Tri-band WiFi Mesh router (WSR30).

## ✨ Features

- **Easy Installation** - No UART or disassembly required! upgrade over LAN
- **Dual Mode Operation** - AP Mode (default) and Bridge/Repeater Mode
- **Full Luci Web Interface** - Manage your router through any browser
- **Advanced WiFi Control** - Expert settings for all three Radios (Wlan0, Wlan1, Wlan2)
- **SSH Access** - In both operating modes
- **Root access with full previliges 
- **Tri band radio** - Backhauld 5GH radio plus regular 2.4 and 5GH radios
- **Source and pre cross-compiled binary ready to install

## 📥 Quick Download

👉 **[Download Latest Release](https://github.com/majad00/wsr30-openwrt/releases/download/v4.0.0/Zyxel-Matrix-WSR30-v4.1.zip)**

The download includes:
- `Zyxel-Matrix-Loader.exe` - Windows flashing tool
- `README.txt` - Complete instructions
- `CHANGELOG.txt` - Version history

## 🚀 Flashing in 30 Seconds

1. **Connect** Ethernet cable from PC to router
2. **Set IP** on PC to `192.168.1.10`
3. **Enter Recovery Mode**: Hold reset + power on → wait for **GREEN** light
4. **Run Loader**: Select firmware → click Flash
5. **Wait** 2-3 minutes for first boot
6. **Connect WiFi**: `Zyxel_Matrix_24` / `12345678`
7. **Configure**: http://192.168.2.1 (root/1234)

> ⚠️ **IMPORTANT**: Change default passwords immediately after first boot!

## 📋 Detailed Documentation

- [Building from Source](docs/build_guide.md)
- [Changelog](CHANGELOG.txt)

## 🔧 Default Settings

| Mode | IP Address | WiFi SSID | WiFi Password | Login |
|------|------------|-----------|---------------|-------|
| **AP Mode** | 192.168.2.1 | Zyxel_Matrix_24 / Zyxel_Matrix_5G | 12345678 | root/1234 |
| **Repeater Mode** | 192.168.1.5 | Same SSID (extends existing network) | 12345678| root/1234 |

## 🛠️ Development

This project include busybox based on OpenWrt. To build from source:
See Source, for installing precompiled firmware see Release, for firmware loader see Windows or Linux
