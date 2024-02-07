#include <Wire.h>

uint8_t PRIMARY_ADDR = 8;
uint16_t sensor_out;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(PRIMARY_ADDR);
  Wire.onReceive(receiveEvent);
}

void receiveEvent() {
  sensor_out = Wire.read();
  // Math to convert raw output to force reading
  Serial.println(sensor_out);
}

void loop() {
  // put your main code here, to run repeatedly:

}
