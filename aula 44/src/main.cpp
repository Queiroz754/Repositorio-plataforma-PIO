#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// ********Intancia do objeto ******
LiquidCrystal_I2C lcd(0x27,20,4);
void setup()
{
Serial.begin(9600);//*bauRate
lcd.init();
lcd.backlight();
lcd.print("OLA MUNDO!!!!");
}

void loop() 
{

}
