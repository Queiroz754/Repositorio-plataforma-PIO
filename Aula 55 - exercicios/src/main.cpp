#include <Arduino.h>



String palavra;

bool pinLeds[3];

void setup()
{
  for (int i =0 ; i == 3 ;i++)
  {
    pinMode(pinLeds[i],OUTPUT);
  }
Serial.begin(9600);
Serial.println("Escolha um led:");
}

void loop()
{
while(Serial.available())
{
  char caracter = Serial.read();
  if(caracter == '\n')
  {
   Serial.println(palavra);
   if (palavra.equals ("0"))
   {
    pinLeds[0] = !pinLeds[0];
    Serial.println("LED 0 ligado");
    Serial.println(pinLeds[0]);
   }
   palavra = "";
  }
  else if (caracter != '\r')
  {
    palavra += caracter;
  }
}

}