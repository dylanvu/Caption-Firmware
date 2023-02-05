#include <vector>
#include <WiFi.h>
const int micPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(micPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  const int soundVal = analogRead(micPin);
  Serial.println(soundVal);
  // Serial.write(soundVal);
}
