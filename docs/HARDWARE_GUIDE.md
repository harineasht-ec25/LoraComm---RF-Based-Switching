# HARDWARE_GUIDE.md - LoraComm Hardware Design Guide

## PCB Design Overview

This document provides detailed information about the custom-designed PCB for the LoraComm system.

---

## Schematic Design

### Main Sections

1. **Power Distribution**
   - Input: 5V USB or Battery
   - 3.3V LDO Regulator (AMS1117)
   - Filtering capacitors (100µF, 10µF)
   - Current: 500mA typical

2. **ESP32 Microcontroller**
   - Direct 3.3V connection
   - Reset circuit with 10kΩ pull-up
   - Boot mode configuration
   - Status LED on GPIO 2

3. **LoRa Module Interface**
   - SPI bus connection (CLK, MOSI, MISO)
   - Chip Select (GPIO 5)
   - Reset pin (GPIO 14)
   - Interrupt pins (GPIO 26, 33)
   - Impedance-matched antenna connector

4. **Antenna Circuit**
   - 50Ω impedance matching
   - SMA connector for external antenna
   - RF shielding recommended

---

## PCB Layout Considerations

### Design Rules

**Trace Width**:
- Power traces: ≥ 16 mil (0.4 mm)
- Signal traces: ≥ 8 mil (0.2 mm)
- LoRa RF traces: ≥ 10 mil (0.25 mm)

**Via Size**:
- Via diameter: 16 mil (0.4 mm)
- Via hole: 12 mil (0.3 mm)
- Via spacing: > 30 mil

**Clearance**:
- Trace-to-trace: ≥ 8 mil (0.2 mm)
- Trace-to-pad: ≥ 8 mil (0.2 mm)
- Pad-to-pad: ≥ 12 mil

---

## Manufacturing Specifications

### PCB Specifications

| Parameter | Value |
|-----------|-------|
| Thickness | 1.6 mm |
| Copper Weight | 1 oz (35 µm) |
| Dielectric | FR-4 |
| Surface Finish | HASL or ENIG |
| Solder Mask | Green |
| Silkscreen | White |

---

## Bill of Materials Summary

See [hardware/BOM.md](../hardware/BOM.md) for complete component list and sourcing information.

For more details on firmware and API, see [API_REFERENCE.md](API_REFERENCE.md).
