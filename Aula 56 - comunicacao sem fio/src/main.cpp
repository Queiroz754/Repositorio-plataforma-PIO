#include <Arduino.h>
#include "BluetoothSerial.h"
#define pinLed 2
BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("espAllan");
  Serial.println("Esperando uma conexao Bluetooth");
  pinMode(pinLed,OUTPUT)
}
void loop()
{
if (Serial.available())
{
  String mensage = SerialBT.readStringUntil('\r');
  Serial.printf("Mensagem Recebida %s",mensage);
  
  if (mensage.equals("liga"))
  {
    digitalWrite(pinLed,HIGH);
  }
}

}
