#include <Arduino.h>
#define pinLed 2

void setup()
{
  pinMode(pinLed, OUTPUT);
}

void loop()
{
 
  digitalWrite(pinLed, HIGH);
  delay(300);
  digitalWrite(pinLed, LOW);
  delay(300);
}
