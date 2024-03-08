#include <Wire.h>

uint8_t COMMS_ADDR = 0x10;
uint16_t sensor_out;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Wire.begin(COMMS_ADDR);
  Wire.onReceive(receiveEvent);
  //Wire.onRequest(requestEvent);
  
}

void receiveEvent(int numBytes) {
  if (numBytes >= 2) {                // Ensure at least 2 bytes are available
    uint8_t msb = Wire.read();        // Most significant byte
    uint8_t lsb = Wire.read();        // Least significant byte
    sensor_out = (msb << 8) | lsb;    // Combine the two bytes into a uint16_t value
    Serial.println(sensor_out);
  }
}

void requestEvent() {
      if (Serial.available()) {
      String data = Serial.readString();
      Serial.println(data);
      if (data == "up\n") {
        Wire.write(2);  // send value 2
        Serial.println("up sent");
      }
      if (data == "down\n") {
        Wire.write(1);  // send value 1
        Serial.println("down sent");
      }
  }
}

// void requestEvent() {
    // if (Serial.available() > 0) {
  //       String direction = Serial.readString(); 
  //       Serial.println(direction);
        
  //       switch (direction) {
  //           case "u\n":
  //               Wire.write(2);
  //               Serial.println("up sent");  // for debugging
  //               break;
  //           case "d\n":
  //               Wire.write(1); 
  //               Serial.println("down sent"); // for debugging
  //               break;
  //           default:
  //               Serial.println("Invalid direction");
  //       }
  //   }  
// }



void loop() {
//  if (Serial.available()) {
//     String data = Serial.readString();
//     Serial.println(data);
//     Serial.println (data == "up\n");
//   } 


    // if (Serial.available()) {
    // String data = Serial.readString();
    // Serial.println(data);
    // if (data == "up\n") {
    //   Wire.write(2);  // send value 2
    //   Serial.println("up sent");
    // }
    // if (data == "down\n") {
    //   Wire.write(1);  // send value 1
    //   Serial.println("down sent");
    // }
    // }
}
  