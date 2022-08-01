#include <SoftwareSerial.h>

SoftwareSerial loraSerial(2, 3);


void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600); 
}

void loop() {
  while (loraSerial.available()) {
    Serial.write(loraSerial.read());
    
  }
}
