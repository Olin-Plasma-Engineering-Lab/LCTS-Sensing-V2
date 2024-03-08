#include <Wire.h>
#include "Stepper.h"


int const  COMMS_ADDR = 0x10;
uint16_t   force;
uint8_t    FORCE_SENSOR = A0;
const int REVOLUTION_STEPS = 200;
uint16_t step = 10;

Stepper calibration(REVOLUTION_STEPS, 9, 10, 11, 12);

void setup() {
  calibration.setSpeed(60);
  pinMode(FORCE_SENSOR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
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

  if (result != 0) {
    Serial.print("Error in I2C transmission: ");
    Serial.println(result);
  }

    Wire.requestFrom(COMMS_ADDR, 1);
  //  if(Wire.available()){
  //   Serial.println("RC");
  //  }
    // byte direction = Wire.read();
    // if (direction == 2) {
    //   calibration.step(step);
    // } else if (direction == 1) {
    //   calibration.step(-step);
    // }
    // Serial.println(direction);
    
  

  //Serial.println(force);

  }




