#include <Arduino.h>

int ledpin=2;
int delaytime=700;

void setup() {
  pinMode(ledpin,OUTPUT);
  
}

void loop() {
  digitalWrite(ledpin,HIGH);
  delay(delaytime);
  digitalWrite(2,LOW);
  delay(delaytime);



}


