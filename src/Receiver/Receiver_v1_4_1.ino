/************************************************
 *              LORA RECEIVER v1.4.1
 * ----------------------------------------------
 * R1 -> Toggle Relay 1
 * R2 -> Toggle Relay 2
 * R3 -> Toggle Relay 3
 * R4 -> Toggle Relay 4
 *
 * STATUS LED (GPIO15)
 * Blinks whenever valid data is received
 ************************************************/

#include <LoRa_E220.h>

/************ LORA PINS ************/
#define LORA_RX    16
#define LORA_TX    17
#define PIN_M0     18
#define PIN_M1     5
#define PIN_AUX    4

/************ RELAY PINS ************/
#define RELAY_1    13
#define RELAY_2    12
#define RELAY_3    14
#define RELAY_4    27

/************ STATUS LED ************/
#define STATUS_LED 15

/************ RECEIVE PROTECTION ************/
const unsigned long RECEIVE_LOCKOUT = 500;
unsigned long lastReceiveTime = 0;

/************ RELAY STATES ************/
bool relay1State = LOW;
bool relay2State = LOW;
bool relay3State = LOW;
bool relay4State = LOW;

/************ LORA OBJECT ************/
HardwareSerial LoRaSerial(2);
LoRa_E220 e220(&LoRaSerial, PIN_M0, PIN_M1, PIN_AUX);

/************************************************
 * BLINK STATUS LED
 ************************************************/
void blinkStatusLED()
{
  digitalWrite(STATUS_LED, HIGH);
  delay(100);
  digitalWrite(STATUS_LED, LOW);
}

/************************************************
 * TOGGLE RELAY 1
 ************************************************/
void toggleRelay1()
{
  relay1State = !relay1State;
  digitalWrite(RELAY_1, relay1State);

  Serial.print("Relay 1 : ");
  Serial.println(relay1State ? "ON" : "OFF");
}

/************************************************
 * TOGGLE RELAY 2
 ************************************************/
void toggleRelay2()
{
  relay2State = !relay2State;
  digitalWrite(RELAY_2, relay2State);

  Serial.print("Relay 2 : ");
  Serial.println(relay2State ? "ON" : "OFF");
}

/************************************************
 * TOGGLE RELAY 3
 ************************************************/
void toggleRelay3()
{
  relay3State = !relay3State;
  digitalWrite(RELAY_3, relay3State);

  Serial.print("Relay 3 : ");
  Serial.println(relay3State ? "ON" : "OFF");
}

/************************************************
 * TOGGLE RELAY 4
 ************************************************/
void toggleRelay4()
{
  relay4State = !relay4State;
  digitalWrite(RELAY_4, relay4State);

  Serial.print("Relay 4 : ");
  Serial.println(relay4State ? "ON" : "OFF");
}

/************************************************
 * SETUP
 ************************************************/
void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  pinMode(STATUS_LED, OUTPUT);

  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, LOW);
  digitalWrite(RELAY_3, LOW);
  digitalWrite(RELAY_4, LOW);

  digitalWrite(STATUS_LED, LOW);

  LoRaSerial.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);

  e220.begin();
  e220.setMode(MODE_0_NORMAL);

  Serial.println("================================");
  Serial.println("4 CHANNEL LORA RECEIVER");
  Serial.println("================================");
  Serial.println("Receiver Ready!");
}

/************************************************
 * LOOP
 ************************************************/
void loop()
{
  if (e220.available() > 0)
  {
    // Prevent duplicate packet processing
    if (millis() - lastReceiveTime < RECEIVE_LOCKOUT)
    {
      while (e220.available())
      {
        e220.receiveMessage();
      }
      return;
    }

    lastReceiveTime = millis();

    ResponseContainer rc = e220.receiveMessage();

    if (rc.status.code == E220_SUCCESS)
    {
      Serial.print("Received: ");
      Serial.println(rc.data);

      blinkStatusLED();

      if (rc.data == "R1")
      {
        toggleRelay1();
      }
      else if (rc.data == "R2")
      {
        toggleRelay2();
      }
      else if (rc.data == "R3")
      {
        toggleRelay3();
      }
      else if (rc.data == "R4")
      {
        toggleRelay4();
      }
      else
      {
        Serial.println("Unknown Command");
      }
    }
  }
}
