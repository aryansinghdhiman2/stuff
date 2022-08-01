#include <SoftwareSerial.h>

SoftwareSerial loraSerial(2, 3); // TX, RX pinos digitais do lora e32


void setup() {
  Serial.begin(9600);
  loraSerial.begin(9600); // velocidade da porta serial do mdulo configurada antes

}
int i=0;
void loop() {
   loraSerial.print("Hello RX "+String(i)+ "\n");
   Serial.println("Hello RX "+String(i)+ "\n");
   i++;
   delay(200);
}
