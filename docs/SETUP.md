# LoraComm Setup Guide

## Prerequisites

Before you begin, ensure you have the following installed:

- **Arduino IDE** (v1.8.13 or later) - [Download](https://www.arduino.cc/en/software)
- **ESP32 Board Package** for Arduino IDE
- **LoRa Library**: `RadioHead` or `LoRaMesher`
- **USB Driver** for ESP32 (CH340 or CP2102)

---

## Hardware Assembly

### Components Required

| Component | Quantity | Notes |
|-----------|----------|-------|
| ESP32 Development Board | 2 | 1 for Transmitter, 1 for Receiver |
| LoRa Module (SX1278/SX1276) | 2 | One per board |
| Antenna (LoRa) | 2 | 433MHz or 915MHz matching module |
| Voltage Regulator (3.3V) | 2 | For stable power |
| USB Cable (Micro-B) | 2 | For programming |
| Capacitors (100µF, 10µF) | 4 | Decoupling |
| Resistors (10kΩ, 1kΩ) | 4 | Pull-ups and current limiting |
| LEDs | 2 | Status indicators |
| Breadboard/PCB | 2 | For prototyping or final design |

### Connection Diagram

#### ESP32 to LoRa Module (SX1278)

| ESP32 Pin | LoRa Pin | Function |
|-----------|----------|----------|
| GPIO 18 | CLK | SPI Clock |
| GPIO 23 | MOSI | SPI Data Out |
| GPIO 19 | MISO | SPI Data In |
| GPIO 5 | CS | Chip Select |
| GPIO 14 | RST | Reset |
| GPIO 26 | DIO0 | Interrupt 0 |
| GPIO 33 | DIO1 | Interrupt 1 (Optional) |
| GND | GND | Ground |
| 3V3 | VCC | Power |

### Wiring Steps

1. **Power Section**
   - Connect 3.3V regulator to ESP32 5V input
   - Connect LoRa VCC to 3.3V output
   - Add 100µF capacitor across power and GND

2. **SPI Communication**
   - Connect CLK, MOSI, MISO to specified GPIO pins
   - Add 1kΩ current limiting resistor on CS line

3. **Interrupt Pins**
   - Connect DIO0 to GPIO 26 with pull-up resistor
   - Connect RST to GPIO 14 with pull-up resistor

4. **Status Indicator**
   - Connect LED anode to GPIO 2 (through 220Ω resistor)
   - Connect LED cathode to GND

---

## Software Installation

### Step 1: Install ESP32 Board Package

1. Open **Arduino IDE**
2. Go to **File → Preferences**
3. Add to "Additional Boards Manager URLs":
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to **Tools → Board → Boards Manager**
5. Search for "ESP32" and install **esp32** by Espressif Systems

### Step 2: Install Required Libraries

1. Go to **Sketch → Include Library → Manage Libraries**
2. Search and install:
   - **RadioHead Packet Radio library** (by Mike McCauley)
   - **Adafruit GFX Library** (optional, for display)

### Step 3: Configure Board Settings

1. **Tools → Board**: Select "ESP32 Dev Module"
2. **Tools → Upload Speed**: Set to 115200
3. **Tools → Port**: Select the COM port of your ESP32

---

## Firmware Flashing

### Transmitter Setup

1. Navigate to `firmware/transmitter/transmitter.ino`
2. Open in Arduino IDE
3. Configure parameters:
   ```cpp
   #define LORA_FREQ 433.0      // Frequency in MHz
   #define TX_POWER 20          // Power in dBm (max 20)
   #define BANDWIDTH 125000     // Bandwidth in Hz
   ```
4. Click **Sketch → Upload**
5. Wait for upload completion message

### Receiver Setup

1. Navigate to `firmware/receiver/receiver.ino`
2. Open in Arduino IDE
3. Ensure **same frequency as transmitter**:
   ```cpp
   #define LORA_FREQ 433.0      // Must match transmitter!
   ```
4. Click **Sketch → Upload**
5. Wait for upload completion message

---

## Testing & Verification

### LED Test

1. Upload `firmware/utilities/led_test.ino` to test LED functionality
2. Both LEDs should blink every 1 second
3. If no blink, check GPIO pin connections

### Channel Configuration

1. Upload `firmware/utilities/channel_config.ino`
2. Open **Serial Monitor** (Ctrl+Shift+M)
3. Set baud rate to **115200**
4. Verify channel information displayed

### First Communication Test

1. Power on both Transmitter and Receiver boards
2. Open **Serial Monitor** on Receiver (115200 baud)
3. Transmitter will send test message every 2 seconds
4. Receiver should display incoming messages in Serial Monitor

Expected output on Receiver:
```
[LORA] Waiting for message...
[LORA] Message received!
[DATA] Length: 13
[DATA] RSSI: -45 dBm
[DATA] SNR: 9.5 dB
Message: Hello World!
```

---

## Troubleshooting

### No Upload to ESP32

- **Check USB Cable**: Ensure it's a data cable, not power-only
- **Install CH340 Driver**: If using CH340 chip [Download](https://sparks.gogo.co.nz/ch340.html)
- **Reset ESP32**: Hold BOOT button while uploading

### LoRa Module Not Detected

- **Check SPI Connections**: Verify CLK, MOSI, MISO pins
- **Verify CS Pin**: Ensure GPIO 5 is not used elsewhere
- **Reset Module**: Cycle power to LoRa module

### No Message Reception

- **Check Frequency**: Both boards must use same frequency
- **Check Antenna**: Ensure antenna is properly seated
- **Check Power Supply**: Ensure stable 3.3V to LoRa module
- **Verify DIO0**: Check interrupt pin connection

---

## Next Steps

- Review [HARDWARE_GUIDE.md](HARDWARE_GUIDE.md) for detailed PCB design
- Check [API_REFERENCE.md](API_REFERENCE.md) for available functions
- Explore [examples/](../examples/) for advanced usage

---

## Support

For issues or questions, please:
1. Check existing [GitHub Issues](https://github.com/harineasht-ec25/LoraComm---RF-Based-Switching/issues)
2. Create a new issue with detailed error description
3. Include hardware configuration and code snippet
