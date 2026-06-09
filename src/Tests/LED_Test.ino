/************************************************
 *           ESP32 LED TEST SKETCH
 * Simple test to verify LED functionality
 * on GPIO15
 ************************************************/

#define LED_PIN 15

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("LED Test Starting...");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
