#include <Arduino.h>
int redledpin=8;
int ledpin=2;
int delaytime=700;

void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(redledpin,OUTPUT);
}

void loop() {
digitalWrite(ledpin,HIGH);
delay(delaytime);
digitalWrite(ledpin,LOW);
delay(delaytime);
digitalWrite(redledpin,HIGH);
delay(delaytime);
digitalWrite(redledpin,LOW);
delay(delaytime);
}
