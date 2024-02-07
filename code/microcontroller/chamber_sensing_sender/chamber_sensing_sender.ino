#include <Wire.h>

int const  SECONDARY_ADDR = 8;
uint16_t   force;
uint8_t    FORCE_SENSOR;

void setup() {
  pinMode(FORCE_SENSOR, INPUT);
  Serial.begin(9600);
  Wire.begin(SECONDARY_ADDR);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  force = analogRead(FORCE_SENSOR);
  Serial.println(force);
  Wire.beginTransmission(SECONDARY_ADDR);
  Wire.write(force);
  Wire.endTransmission();
}
