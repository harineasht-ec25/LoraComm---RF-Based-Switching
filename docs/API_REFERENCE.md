# LoraComm API Reference

## Overview

Quick reference guide for LoraComm firmware API functions.

---

## Core Configuration

### LoRa Parameters

```cpp
#define LORA_FREQ 433.0          // Frequency in MHz (433 or 915)
#define TX_POWER 20              // Transmission power in dBm (2-20)
#define BANDWIDTH 125000         // Bandwidth in Hz
#define SPREADING_FACTOR 7       // SF7-SF12
#define CODING_RATE 5            // 4/5, 4/6, 4/7, 4/8
```

---

## Transmitter API

### Setup Transmitter
```cpp
void setupTransmitter()
```
Initializes the transmitter with default LoRa settings.

### Send Message
```cpp
bool sendMessage(const char* message, uint8_t destination = 0xFF)
```
Sends a message. Returns `true` if successful.

### Set Transmission Power
```cpp
void setTxPower(int8_t power)  // Power in dBm (2-20)
```

### Set Frequency
```cpp
void setFrequency(float frequency)  // 433.0 or 915.0 MHz
```

---

## Receiver API

### Setup Receiver
```cpp
void setupReceiver()
```
Initializes the receiver and enters RX mode.

### Check for Message
```cpp
bool hasMessage()  // Returns true if message available
```

### Receive Message
```cpp
struct ReceivedMessage {
  uint8_t sender;
  uint8_t destination;
  int16_t rssi;        // Signal strength (-200 to 0 dBm)
  float snr;           // Signal-to-Noise ratio (dB)
  uint8_t length;
  uint8_t data[256];
};

ReceivedMessage receiveMessage()
```

---

## GPIO Control API

### LED Functions
```cpp
void initLED(uint8_t pin)
void ledOn()
void ledOff()
void ledBlink(uint16_t duration = 100)  // duration in ms
```

---

## LoRa Configuration

### Spreading Factor
```cpp
void setSpreadingFactor(uint8_t sf)  // 7-12
```

### Bandwidth
```cpp
void setBandwidth(uint32_t bandwidth)  // 125000, 250000, or 500000
```

### Coding Rate
```cpp
void setCodingRate(uint8_t numerator, uint8_t denominator)
```

---

## Transmitter Example

```cpp
#include "LoraComm.h"

#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  initLED(LED_PIN);
  setupTransmitter();
  setFrequency(433.0);
  setTxPower(20);
}

void loop() {
  static unsigned long lastSend = 0;
  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    if (sendMessage("Hello!")) {
      Serial.println("Sent");
      ledBlink(100);
    }
  }
}
```

---

## Receiver Example

```cpp
#include "LoraComm.h"

#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  initLED(LED_PIN);
  setupReceiver();
  setFrequency(433.0);
}

void loop() {
  if (hasMessage()) {
    ReceivedMessage msg = receiveMessage();
    Serial.print("RSSI: ");
    Serial.println(msg.rssi);
    ledBlink(200);
  }
}
```

---

For detailed documentation, see:
- [SETUP.md](SETUP.md) - Hardware setup
- [ARCHITECTURE.md](ARCHITECTURE.md) - System design
- [HARDWARE_GUIDE.md](HARDWARE_GUIDE.md) - PCB design
