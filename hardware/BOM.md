# 📡 LoRaComm – Bill of Materials (BOM)

## Project

**LoRaComm – Long-Range Wireless Control & Emergency Alert System**

---

# 📤 Transmitter Unit

## Core Electronics

| Reference | Component                | Quantity | Specification      | Approx. Cost (₹) |
| --------- | ------------------------ | -------- | ------------------ | ---------------- |
| U1        | ESP32 Development Module | 1        | ESP32 DevKit V1    | ₹450             |
| U2        | LoRa Module              | 1        | EBYTE E220-900T22D | ₹650             |
| LCD1      | LCD Display              | 1        | 16x2 I2C LCD       | ₹150             |

---

## User Interface

| Reference | Component                 | Quantity | Specification         | Approx. Cost (₹) |
| --------- | ------------------------- | -------- | --------------------- | ---------------- |
| SW1-SW4   | Push Buttons              | 4        | Momentary Push Button | ₹40              |
| LED1      | Status LED                | 1        | 5mm Red LED           | ₹5               |
| R1        | Current Limiting Resistor | 1        | 220Ω                  | ₹2               |

---

## Power Section

| Reference | Component          | Quantity | Specification | Approx. Cost (₹) |
| --------- | ------------------ | -------- | ------------- | ---------------- |
| U3        | Voltage Regulator  | 1        | AMS1117-3.3V  | ₹15              |
| C1-C4     | Capacitors         | 4        | 10µF / 100µF  | ₹20              |
| J1        | DC Power Connector | 1        | 5V Input      | ₹15              |

---

# 📥 Receiver Unit

## Core Electronics

| Reference | Component                | Quantity | Specification      | Approx. Cost (₹) |
| --------- | ------------------------ | -------- | ------------------ | ---------------- |
| U4        | ESP32 Development Module | 1        | ESP32 DevKit V1    | ₹450             |
| U5        | LoRa Module              | 1        | EBYTE E220-900T22D | ₹650             |

---

## Relay & Alert Section

| Reference | Component                 | Quantity | Specification           | Approx. Cost (₹) |
| --------- | ------------------------- | -------- | ----------------------- | ---------------- |
| RL1-RL4   | Relay Modules             | 4        | 5V Relay                | ₹320             |
| LED2      | Status LED                | 1        | 5mm Green LED           | ₹5               |
| R2        | Current Limiting Resistor | 1        | 220Ω                    | ₹2               |
| BZ1       | Siren/Buzzer              | 1        | 12V Alarm Siren         | ₹250             |
| WL1-WL2   | Warning Lamps             | 2        | High Intensity LED Lamp | ₹300             |

---

## RF Components

| Reference | Component     | Quantity | Specification        | Approx. Cost (₹) |
| --------- | ------------- | -------- | -------------------- | ---------------- |
| ANT1      | LoRa Antenna  | 1        | 900 MHz Antenna      | ₹150             |
| ANT2      | LoRa Antenna  | 1        | 900 MHz Antenna      | ₹150             |
| SMA1-SMA2 | SMA Connector | 2        | Female SMA Connector | ₹100             |

---

# 🔧 PCB & Assembly

| Component               | Quantity | Approx. Cost (₹) |
| ----------------------- | -------- | ---------------- |
| Transmitter PCB         | 1        | ₹250             |
| Receiver PCB            | 1        | ₹250             |
| PCB Fabrication         | 2 Boards | ₹500             |
| Connectors & Headers    | Assorted | ₹100             |
| Wiring & Hardware       | Assorted | ₹150             |
| Enclosure (Transmitter) | 1        | ₹250             |
| Enclosure (Receiver)    | 1        | ₹300             |

---

# 💰 Cost Summary

## Prototype Cost

| Item                   | Cost   |
| ---------------------- | ------ |
| Electronics            | ₹3,400 |
| PCB Fabrication        | ₹500   |
| Enclosures             | ₹550   |
| Miscellaneous Hardware | ₹250   |

### Estimated Total Prototype Cost

# ₹4,500 – ₹5,000

---

# 🏭 Small Batch Production (10 Units)

| Item               | Estimated Cost |
| ------------------ | -------------- |
| Components         | ₹32,000        |
| PCB Manufacturing  | ₹4,000         |
| Enclosures         | ₹5,000         |
| Assembly & Testing | ₹4,000         |

### Estimated Production Cost

# ₹45,000 – ₹50,000

### Cost Per Unit

# ₹4,500 – ₹5,000

---

# 🛒 Indian Suppliers

### Components

* Robu.in
* ElectronicsComp.com
* FabToLab.com
* Thingbits Electronics
* Amazon India

### PCB Manufacturing

* JLCPCB
* PCBPower India
* LionCircuits
* PCBWay

---

## Revision

**Version:** 1.0

**Project:** LoRaComm – Long-Range Wireless Control & Emergency Alert System

**LoRa Module:** EBYTE E220-900T22D

**Microcontroller:** ESP32 DevKit V1

**Updated:** June 2026
