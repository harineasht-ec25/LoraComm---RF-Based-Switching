/************************************************
 *     LORA CHANNEL CONFIGURATION UTILITY
 * Use this sketch to configure LoRa E220 module
 * frequency, air data rate, and other parameters
 ************************************************/

#include <LoRa_E220.h>

/************ LORA PINS ************/
#define LORA_RX    16
#define LORA_TX    17
#define PIN_M0     18
#define PIN_M1     5
#define PIN_AUX    4

/************ LORA OBJECT ************/
HardwareSerial LoRaSerial(2);
LoRa_E220 e220(&LoRaSerial, PIN_M0, PIN_M1, PIN_AUX);

void setup()
{
  Serial.begin(115200);
  LoRaSerial.begin(9600, SERIAL_8N1, LORA_RX, LORA_TX);
  
  delay(1000);
  
  Serial.println("LoRa E220 Configuration Utility");
  Serial.println("================================");
  
  // Initialize LoRa module
  e220.begin();
  
  // Get current configuration
  ResponseStructContainer c;
  c = e220.getConfiguration();
  
  // Display current settings
  Serial.println("Current Configuration:");
  Serial.print("FREQ: ");
  Serial.println(c.data.FREQ);
  Serial.print("ADDR H: ");
  Serial.println(c.data.ADDH);
  Serial.print("ADDR M: ");
  Serial.println(c.data.ADDM);
  Serial.print("ADDR L: ");
  Serial.println(c.data.ADDL);
}

void loop()
{
  // Configuration is applied at startup
  delay(10000);
}