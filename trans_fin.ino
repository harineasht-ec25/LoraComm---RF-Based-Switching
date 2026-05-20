#include <LoRa_E220.h>
#include <SoftwareSerial.h>

#define RX 2
#define TX 3
#define M0 4
#define M1 5
#define AUX 6

SoftwareSerial mySerial(RX, TX);
LoRa_E220 e22(&mySerial, M0, M1, AUX);

int counter = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  e22.begin();

  Serial.println("E22 Transmitter Ready");
}

void loop() {
  String message = "PING:" + String(counter);

  e22.sendMessage(message);

  Serial.println("Sent: " + message);

  counter++;
  delay(2000);
}