# LoraComm System Architecture

## Overview

The LoraComm system is a bi-directional long-range wireless communication platform built on ESP32 microcontrollers and LoRa technology. This document provides detailed insights into the system architecture.

---

## System Architecture Diagram

```
┌─────────────────────────────────────────────────────────────┐
│                    LoRaComm System                           │
└─────────────────────────────────────────────────────────────┘

┌──────────────────────┐              ┌──────────────────────┐
│  TRANSMITTER UNIT    │              │  RECEIVER UNIT       │
├──────────────────────┤              ├──────────────────────┤
│ ┌────────────────┐   │              │ ┌────────────────┐   │
│ │  ESP32 MCU     │   │              │ │  ESP32 MCU     │   │
│ │  (40 MHz)      │   │              │ │  (40 MHz)      │   │
│ └────────────────┘   │              │ └────────────────┘   │
│        │             │              │        │             │
│        ├─ SPI Bus    │              │        ├─ SPI Bus    │
│        │             │              │        │             │
│ ┌────────────────┐   │              │ ┌────────────────┐   │
│ │ LoRa Module    │   │              │ │ LoRa Module    │   │
│ │ (E220-900T22D)     │   │              │ │ (E220-900T22D) │   │
│ └────────────────┘   │              │ └────────────────┘   │
│        │             │              │        │             │
│        └─ RF Out ────────────────────── RF In             │
│                      │              │                      │
└──────────────────────┘              └──────────────────────┘
         433 MHz / 915 MHz LoRa Wireless Link
       (up to 10+ km in open space)
```

---

## Component Architecture

### 1. ESP32 Microcontroller

**Role**: Main processing unit and communication controller

**Specifications**:
- Dual-core processor @ 240 MHz
- 4 MB Flash memory
- 520 KB RAM
- Wi-Fi & Bluetooth capable
- 34 GPIO pins
- Built-in SPI controllers

**Key Functions**:
- SPI communication with LoRa module
- Data encoding/decoding
- Message scheduling
- Status monitoring via LEDs
- Serial debugging output

### 2. LoRa Module (SX1278)

**Role**: RF transceiver for wireless communication

**Specifications**:
- Frequency range: 433 MHz or 915 MHz
- Transmission power: up to 20 dBm
- Bandwidth: 125 kHz - 500 kHz
- Spreading factor: SF7 - SF12
- Max data rate: ~50 kbps

**Key Functions**:
- Modulation/Demodulation (LoRa)
- Frequency synthesis
- Automatic gain control (AGC)
- CRC error detection
- Interrupt generation on message reception

### 3. Power Management

**Input**: 5V USB or battery supply

**Voltage Regulation**:
- 5V for ESP32 and LoRa module
- Current capacity: min 500mA

**Power Consumption**:
- Idle: ~30 mA
- Transmitting: ~150-200 mA
- Receiving: ~50-100 mA

---

## Performance Metrics

### Transmission Range
- **Open space**: 10+ km (optimal conditions)
- **Urban area**: 2-5 km (with obstacles)
- **Indoor**: 50-200 meters

### Power Consumption
- Transmit: ~180 mA @ 20 dBm
- Receive: ~75 mA
- Sleep: ~1 µA
