# Zyxel-Matrix Openwrt based firmware for WSR30 (Zyxel Multy U AC2100)

[![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](LICENSE)
[![Release](https://github.com/majad00/zyxel-matrix/releases/tag/v4.0.0)
[![Downloads](https://github.com/majad00/zyxel-matrix/releases/tag/v4.0.0)

A custom OpenWrt-based operating system for the Zyxel Multy U AC2100 Tri-band WiFi Mesh router (WSR30).

## ✨ Features

- **Easy Installation** - No UART or disassembly required! Installation using LAN port
- **Dual Mode Operation** - AP Mode (default) and Bridge/Repeater Mode
- **Full Luci Web Interface** - Manage your router through any browser
- **Advanced WiFi Control** - Expert settings for all three bands (Wlan0, Wlan1, Wlan2)
- **SSH Access** - In both operating modes
- **Active Development** - Regular updates and new features

## 📥 Quick Download

👉 **[Download Latest Release](https://github.com/majad00/zyxel-matrix/releases/tag/v4.0.0)**

The download includes:
- `Zyxel-Matrix-Loader.exe` - Windows / Linux flashing tool
- `README.txt` - Complete instructions
- `CHANGELOG.txt` - Version history

## 🚀 Flashing in 30 Seconds

1. **Connect** Ethernet cable from PC to router
2. **Set IP** on PC to `192.168.1.10`
3. **Enter Recovery Mode**: Hold reset + power on → wait for **GREEN** light
4. **Run Loader**: Select firmware → click Flash
5. **Wait** 2-3 minutes for first boot
6. **Connect WiFi**: `Zyxel_Matrix_24` / `12345678`
7. **Configure**: http://192.168.2.1 (root/1234) AP MODE ( Default after installation)
8. **Configure**: http://192.168.1.5 (root/1234) Repeater MODE

> ⚠️ **IMPORTANT**: Change default passwords immediately after first boot!

## 📋 Detailed Documentation

- [Flashing Guide](docs/flashing-guide.md)
- [Building from Source](docs/building-from-source.md)
- [Changelog](CHANGELOG.md)

## 🔧 Default Settings

| Mode | IP Address | WiFi SSID | WiFi Password | Login |
|------|------------|-----------|---------------|-------|
| **AP Mode** | 192.168.2.1 | Zyxel_Matrix_24 / Zyxel_Matrix_5G | 12345678 | root/1234 |
| **Repeater Mode** | 192.168.1.5 | (extends existing network) | N/A | root/1234 |

## 🛠️ Development

This project contains Buzybox which is based on OpenWrt. 
