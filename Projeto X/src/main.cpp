#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define pinLed 19
#define botao 23

LiquidCrystal_I2C lcd (0x27,20,4);

void setup() 
{
 lcd.init();
 pinMode(botao,INPUT_PULLUP);
  pinMode(pinLed,OUTPUT);
}

void loop()
{

}

