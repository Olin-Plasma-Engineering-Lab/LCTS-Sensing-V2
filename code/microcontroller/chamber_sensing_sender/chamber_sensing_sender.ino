#include <Wire.h>

int const  COMMS_ADDR = 0x10;
uint16_t   force;
uint8_t    FORCE_SENSOR = A0;

void setup() {
  pinMode(FORCE_SENSOR, INPUT);
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  delay(50);
  force = analogRead(FORCE_SENSOR);

  // Split the 16-bit force value into two 8-bit values
  uint8_t msb = (force >> 8) & 0xFF;
  uint8_t lsb = force & 0xFF;

  Wire.beginTransmission(COMMS_ADDR);
  Wire.write(msb);                      // Send the most significant byte first
  Wire.write(lsb);                      // Send the least significant byte
  int result = Wire.endTransmission();

  // Debugging (if need be)

  // if (result != 0) {
  //   Serial.print("Error in I2C transmission: ");
  //   Serial.println(result);
  // }

  Serial.println(force);
}



