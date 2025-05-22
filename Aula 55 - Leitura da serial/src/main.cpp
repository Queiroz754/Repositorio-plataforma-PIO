#include <Arduino.h>
#include "BluetoothSerial.h"
#define pinLed 2

String palavra = "";
//*     ********instancias de objeto*********

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("espAllan");
  SerialBT.println("Digite algo no monitor Serial:.");
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  while (SerialBT.available())
  {
    char caracter = Serial.read();
    if (caracter == '\n')
    {
      Serial.println(palavra);
      if (palavra.equals("liga")) //*equals serve para saber se a string e igual a um apalavra
      {
        digitalWrite(pinLed, HIGH);
        SerialBT.println("LED ligado");
      }
      else if (palavra.equals("desliga"))
      {
        digitalWrite(pinLed, LOW);
        Serial.println("LED desligado");
      }
      else
      {
        Serial.println("comando nao reconhecido");
      }
      palavra = "";
    }
    else if (caracter != '\r')
    {
      palavra += caracter;
    }
  }
}
