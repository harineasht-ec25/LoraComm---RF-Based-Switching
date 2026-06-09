# LoraComm - RF Based Switching Codebase Structure

## Overview
Organized codebase for ESP32-based LoRa wireless relay control system using E220 LoRa modules for long-range RF communication in remote regions.

## Directory Structure

```
LoraComm---RF-Based-Switching/
├── src/
│   ├── Transmitter/
│   │   └── Transmitter_v1_4.ino       # 4-channel transmitter (button controller)
│   ├── Receiver/
│   │   └── Receiver_v1_4_1.ino        # 4-channel receiver (relay controller)
│   ├── Configuration/
│   │   └── ChannelConfig.ino          # LoRa module configuration utility
│   └── Tests/
│       └── LED_Test.ino               # Basic LED functionality test
├── hardware/
│   └── (PCB layouts and schematics)
├── docs/
│   └── (Documentation files)
├── PCB_Layouts/
│   └── (PCB design files)
├── README.md                          # Project overview and setup guide
├── LICENSE                            # MIT License
├── CONTRIBUTING.md                    # Contributing guidelines
├── CODEBASE_STRUCTURE.md              # This file
└── .gitignore                         # Git ignore patterns
```

## Hardware Specifications

### Transmitter Unit
- **MCU**: ESP32
- **LoRa Module**: E220-400T30D
- **Buttons**: 4 push buttons (GPIO13, GPIO12, GPIO14, GPIO27)
- **Feedback**: Status LED (GPIO15)
- **Communication**: 4-channel wireless relay control

### Receiver Unit
- **MCU**: ESP32
- **LoRa Module**: E220-400T30D
- **Relays**: 4-channel relay module
  - Relay 1: GPIO13
  - Relay 2: GPIO12
  - Relay 3: GPIO14
  - Relay 4: GPIO27
- **Feedback**: Status LED (GPIO15)
- **Protection**: Duplicate packet filtering

### LoRa Module Pins (Both Units)
- RX: GPIO16
- TX: GPIO17
- M0: GPIO18
- M1: GPIO5
- AUX: GPIO4
- Baud Rate: 9600
- Module Model: E220-400T30D

## File Descriptions

### Transmitter_v1_4.ino
**Main transmitter firmware** - Control system
- Features:
  - 4-channel wireless command transmission
  - Button press detection with hardware debouncing
  - Status LED feedback on transmission
  - 1000ms command interval protection (prevents rapid repeated commands)
  - Serial debug output at 115200 baud
  - Commands sent: R1, R2, R3, R4

### Receiver_v1_4_1.ino
**Main receiver firmware** - Control system
- Features:
  - 4-channel relay control via wireless commands
  - Duplicate packet filtering (500ms lockout)
  - Individual relay state tracking
  - Status LED blink on valid reception
  - Serial debug output with relay status
  - Enhanced error handling

### ChannelConfig.ino
**Configuration utility for LoRa module setup**
- Capabilities:
  - Frequency configuration
  - Address settings (ADDH, ADDM, ADDL)
  - Module parameters display
  - Configuration verification
  - Must be run on freshly powered module

### LED_Test.ino
**Basic diagnostic sketch**
- Purpose:
  - Verify LED connectivity
  - Test GPIO15 functionality
  - Debug hardware issues before main firmware
  - Simple 500ms blink interval

## Compilation Instructions

### Requirements
- Arduino IDE 1.8.19 or higher
- ESP32 Board Package 2.0+
- LoRa_E220 Library (install from Library Manager)

### Setup Steps
1. **Install ESP32 Support**
   - Open Arduino IDE → Preferences
   - Add to Additional Boards Manager URLs: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Boards Manager → Search "ESP32" → Install latest version

2. **Install LoRa Library**
   - Sketch → Include Library → Manage Libraries
   - Search for "LoRa_E220" → Install by Renzo Mischianti

3. **Board Configuration**
   - Select: Tools → Board → ESP32 → ESP32 Dev Module
   - Port: Select appropriate COM port
   - Upload Speed: 921600

### Uploading Firmware
1. **Transmitter Unit**
   ```
   - Open: src/Transmitter/Transmitter_v1_4.ino
   - Verify compilation
   - Upload to transmitter ESP32
   ```

2. **Receiver Unit**
   ```
   - Open: src/Receiver/Receiver_v1_4_1.ino
   - Verify compilation
   - Upload to receiver ESP32
   ```

3. **Testing**
   ```
   - Open: src/Tests/LED_Test.ino
   - Upload for hardware verification
   - Expected: LED blinks every 500ms
   ```

## Communication Protocol

### Command Format
- **Message Type**: Single character commands
- **Valid Commands**: 
  - `R1` → Toggle Relay 1
  - `R2` → Toggle Relay 2
  - `R3` → Toggle Relay 3
  - `R4` → Toggle Relay 4
- **Response**: Status LED blink on successful reception

### Safety Features
- **Receive Lockout**: 500ms prevents duplicate relay triggering
- **Command Interval**: 1000ms limits transmission frequency
- **Serial Monitoring**: All operations logged to serial console
- **Relay State Tracking**: Persistent state monitoring

## Troubleshooting Guide

### No Communication Between Units
1. Verify LoRa module wiring (RX, TX, M0, M1, AUX pins)
2. Confirm baud rate is 9600 on both units
3. Check module addresses match (ADDH, ADDM, ADDL)
4. Use ChannelConfig.ino to verify module settings
5. Test with LED_Test.ino first to confirm hardware

### Relay Not Toggling
1. Verify relay module connections
2. Check GPIO assignments (13, 12, 14, 27)
3. Test relay control with simple GPIO test
4. Check relay power supply
5. Verify relay coil voltage requirements

### Status LED Not Blinking
1. Verify LED pin connection (GPIO15)
2. Check LED polarity (long leg to GPIO, short to GND)
3. Test with LED_Test.ino independently
4. Verify GPIO15 is not being used by module

### LoRa Module Not Responding
1. Check serial connection (TX/RX pins correct)
2. Verify AUX pin is floating or pulled high
3. Power cycle the module
4. Confirm 3.3V power supply (not 5V)
5. Check for loose connections

## Performance Specifications

- **Communication Range**: Up to 5km (line of sight)
- **Command Latency**: ~100ms typical
- **Relay Switching Time**: <10ms
- **Serial Baud Rate**: 115200 bps
- **LoRa Baud Rate**: 9600 bps
- **LED Blink Duration**: 100ms

## Version History
- **v1.4.1**: Final receiver firmware with enhanced packet filtering
- **v1.4**: Final transmitter firmware with improved button debouncing
- **v1.0-v1.3**: Development iterations

## Future Improvements
- [ ] Add remote configuration over LoRa
- [ ] Implement acknowledgment protocol
- [ ] Add relay timer functionality
- [ ] Battery monitoring and reporting
- [ ] Web dashboard for monitoring
- [ ] Multiple receiver coordination

## License
MIT License - See LICENSE file for details

## Contributing
Please see CONTRIBUTING.md for guidelines on how to contribute to this project.

## Support
For issues and questions:
1. Check README.md for basic setup
2. Review CONTRIBUTING.md for contribution guidelines
3. Open an issue on GitHub with detailed description
4. Include serial monitor output and hardware setup details
