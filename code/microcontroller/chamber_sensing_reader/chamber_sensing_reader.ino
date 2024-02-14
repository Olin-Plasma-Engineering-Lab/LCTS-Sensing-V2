#include <Wire.h>

uint8_t COMMS_ADDR = 0x10;
uint16_t sensor_out;

void setup() {
  Serial.begin(9600);
  Wire.begin(COMMS_ADDR);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int numBytes) {
  if (numBytes >= 2) {                // Ensure at least 2 bytes are available
    uint8_t msb = Wire.read();        // Most significant byte
    uint8_t lsb = Wire.read();        // Least significant byte
    sensor_out = (msb << 8) | lsb;    // Combine the two bytes into a uint16_t value
    Serial.println(sensor_out);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}