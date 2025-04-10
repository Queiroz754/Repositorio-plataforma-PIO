#include <Arduino.h>
#include "BluetoothSerial.h"
#define pinLed 2
BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("espallan");
  Serial.println("Esperando uma conexao Bluetooh");
  pinMode(pinLed,OUTPUT);
}

void loop()
{
  if (SerialBT.available())
  {
    String mensagem = Serial.readStringUntil('\r');
    Serial.printf("Comando Recebido: %s", mensagem);
    if (mensagem.equals("liga"))
    {
      digitalWrite(pinLed, HIGH);
      Serial.println("LED ligado");
    }
    else if (mensagem.equals("desliga"))
    {
      digitalWrite(pinLed, LOW);
      Serial.println("LED Desligado");
    }

  }
}
