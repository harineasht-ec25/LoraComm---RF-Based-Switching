# 📡 LoRaComm Setup Guide

## Requirements

Before starting, install the following:

* Arduino IDE 2.x or later
* ESP32 Board Package
* LoRa_E220 Library by Renzo Mischianti
* USB Driver (CP2102 / CH340 depending on ESP32 board)

---

# 🔧 Hardware Configuration

## 📤 Transmitter Unit

### ESP32 ↔ E220-900T22D Connections

| ESP32 Pin | E220 Pin | Function     |
| --------- | -------- | ------------ |
| GPIO16    | RXD      | UART RX      |
| GPIO17    | TXD      | UART TX      |
| GPIO18    | M0       | Mode Control |
| GPIO5     | M1       | Mode Control |
| GPIO4     | AUX      | Status Pin   |
| 3.3V      | VCC      | Power        |
| GND       | GND      | Ground       |

### User Interface

| Component  | ESP32 Pin |
| ---------- | --------- |
| Button 1   | GPIO13    |
| Button 2   | GPIO12    |
| Button 3   | GPIO14    |
| Button 4   | GPIO27    |
| Status LED | GPIO15    |
| LCD SDA    | GPIO21    |
| LCD SCL    | GPIO22    |

---

## 📥 Receiver Unit

### ESP32 ↔ E220-900T22D Connections

| ESP32 Pin | E220 Pin | Function     |
| --------- | -------- | ------------ |
| GPIO16    | RXD      | UART RX      |
| GPIO17    | TXD      | UART TX      |
| GPIO18    | M0       | Mode Control |
| GPIO5     | M1       | Mode Control |
| GPIO4     | AUX      | Status Pin   |
| 3.3V      | VCC      | Power        |
| GND       | GND      | Ground       |

### Output Devices

| Device     | ESP32 Pin |
| ---------- | --------- |
| Relay 1    | GPIO27    |
| Relay 2    | GPIO14    |
| Relay 3    | GPIO12    |
| Relay 4    | GPIO13    |
| Status LED | GPIO15    |

---

# 📺 LCD Connections

### 16x2 I2C LCD

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO21    |
| SCL     | GPIO22    |

### I2C Address

```cpp
0x27
```

---

# 💻 Software Installation

## Step 1: Install ESP32 Board Package

1. Open Arduino IDE
2. Go to File → Preferences
3. Add:

```text
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

4. Open Boards Manager
5. Search ESP32
6. Install Espressif ESP32 Package

---

## Step 2: Install Required Libraries

Open:

```text
Sketch → Include Library → Manage Libraries
```

Install:

```text
LoRa_E220
LiquidCrystal_I2C
Wire
```

---

# ⚙️ LoRa Configuration

Current project configuration:

| Parameter            | Value         |
| -------------------- | ------------- |
| Module               | E220-900T22D  |
| UART Baud Rate       | 9600          |
| ESP32 Serial Monitor | 115200        |
| LoRa Channel         | 18            |
| Operating Mode       | MODE_0_NORMAL |
| Address              | 0x0000        |

---

# 🚀 Uploading Firmware

## Transmitter

1. Connect ESP32 through USB.
2. Open transmitter firmware.
3. Select:

```text
Board : ESP32 Dev Module
Upload Speed : 115200
```

4. Upload code.

Expected Serial Output:

```text
================================
4 CHANNEL LORA TRANSMITTER
================================
```

---

## Receiver

1. Connect second ESP32.
2. Open receiver firmware.
3. Upload code.

Expected Serial Output:

```text
================================
4 CHANNEL LORA RECEIVER
================================
Receiver Ready!
```

---

# 🧪 System Test

## Relay Test

### Button Mapping

| Button   | Command | Relay   |
| -------- | ------- | ------- |
| Button 1 | R1      | Relay 1 |
| Button 2 | R2      | Relay 2 |
| Button 3 | R3      | Relay 3 |
| Button 4 | R4      | Relay 4 |

### Operation

* First press → Relay ON
* Second press → Relay OFF
* Third press → Relay ON
* Fourth press → Relay OFF

This toggle cycle repeats indefinitely.

---

# 📡 Communication Test

Power ON:

* Transmitter
* Receiver

Press Button 1.

Receiver Output:

```text
Received: R1
Relay 1 : ON
```

Press Button 1 again.

```text
Received: R1
Relay 1 : OFF
```

Status LED on GPIO15 blinks whenever a valid LoRa packet is received.

---

# 🔍 Troubleshooting

## No LoRa Communication

Verify:

* Both modules use Channel 18
* Both modules use 9600 UART baud rate
* Antennas are connected
* M0 = GPIO18
* M1 = GPIO5
* AUX = GPIO4

---

## LCD Not Working

Run I2C Scanner.

Expected result:

```text
I2C Device Found at 0x27
```

If blank:

* Adjust contrast potentiometer
* Verify SDA = GPIO21
* Verify SCL = GPIO22

---

## ESP32 Not Uploading

* Use a data USB cable
* Check COM Port
* Hold BOOT button during upload if required

---

# 📈 Future Expansion

* GPS Tracking
* Solar Power Integration
* Mobile Application
* Cloud Monitoring
* LoRa Mesh Networking
* Secure Encrypted Communication

---

### Built using ESP32, EBYTE E220-900T22D, Custom PCB Design and Long-Range LoRa Communication.
