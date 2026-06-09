/************************************************
 *            LORA TRANSMITTER v1.4
 * ----------------------------------------------
 * BTN1 (GPIO13) -> Relay 1 Toggle
 * BTN2 (GPIO12) -> Relay 2 Toggle
 * BTN3 (GPIO14) -> Relay 3 Toggle
 * BTN4 (GPIO27) -> Relay 4 Toggle
 *
 * LED (GPIO15) -> Blink when message sent
 ************************************************/

#include <LoRa_E220.h>

/************ LORA PINS ************/
#define LORA_RX    16
#define LORA_TX    17
#define PIN_M0     18
#define PIN_M1     5
#define PIN_AUX    4

/************ BUTTON PINS ************/
#define BUTTON_1   13
#define BUTTON_2   12
#define BUTTON_3   14
#define BUTTON_4   27

/************ STATUS LED ************/
#define STATUS_LED 15

/************ TIMING ************/
const unsigned long COMMAND_INTERVAL = 1000; // ms-can change if needed

unsigned long lastCommandTime = 0;

/************ LORA OBJECT ************/
HardwareSerial LoRaSerial(2);
LoRa_E220 e220(&LoRaSerial, PIN_M0, PIN_M1, PIN_AUX);

/************************************************
 * SEND COMMAND FUNCTION
 ************************************************/
void sendCommand(String command)
{
  if (millis() - lastCommandTime < COMMAND_INTERVAL)
    return;

  lastCommandTime = millis();

  ResponseStatus rs = e220.sendMessage(command);

  Serial.print("Sent: ");
  Serial.print(command);
  Serial.print(" | Status: ");
  Serial.println(rs.getResponseDescription());

  digitalWrite(STATUS_LED, HIGH);
  delay(100);
  digitalWrite(STATUS_LED, LOW);
}

/************************************************
 * SETUP
 ************************************************/
void setup()
{
  Serial.begin(115200);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);

  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, LOW);

  LoRaSerial.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

  e220.begin();
  e220.setMode(MODE_0_NORMAL);

  Serial.println("================================");
  Serial.println("4 CHANNEL LORA TRANSMITTER");
  Serial.println("================================");
}

/************************************************
 * LOOP
 ************************************************/
void loop()
{
  /******** BUTTON 1 ********/
  if (digitalRead(BUTTON_1) == LOW)
  {
    sendCommand("R1");

    while (digitalRead(BUTTON_1) == LOW);
    delay(50);
  }

  /******** BUTTON 2 ********/
  if (digitalRead(BUTTON_2) == LOW)
  {
    sendCommand("R2");

    while (digitalRead(BUTTON_2) == LOW);
    delay(50);
  }

  /******** BUTTON 3 ********/
  if (digitalRead(BUTTON_3) == LOW)
  {
    sendCommand("R3");

    while (digitalRead(BUTTON_3) == LOW);
    delay(50);
  }

  /******** BUTTON 4 ********/
  if (digitalRead(BUTTON_4) == LOW)
  {
    sendCommand("R4");

    while (digitalRead(BUTTON_4) == LOW);
    delay(50);
  }
}
