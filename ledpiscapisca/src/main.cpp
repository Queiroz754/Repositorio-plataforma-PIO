#include <Arduino.h>

#define pinLed 21
#define botao 23

void setup() 
{
Serial.begin(9600);
pinMode(pinLed,OUTPUT);
pinMode(botao,INPUT_PULLUP);

}

void loop()
{
bool estadoDoBotao = digitalRead(botao);
static bool estadoAnteriorDoBotao = 1;
static bool estadoDoLed = 0;


if (estadoDoBotao ==0 && estadoAnteriorDoBotao == 1)
{
//estadoDoLed = !estadoDoLed;
digitalWrite (pinLed,HIGH);
Serial.print("1");
}
else
{
  digitalWrite (pinLed,LOW);

}


 estadoAnteriorDoBotao = estadoDoBotao; 
}

