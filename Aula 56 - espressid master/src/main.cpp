#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  if (!SerialBT.begin("MasterAllan", true)) //* O begin tem como uma variavel primitiva bool podendo nos informar caso a conexao bluetooth falhar
  {
    Serial.println("Erro ao Iniciar o bluetooth no modo master");
  }
  if (SerialBT.connect("SlaveAllan"))
  {
    Serial.println("conectado com sucesso no SlaveAllan");
  }
  else
  {
    Serial.println("Falha ao se conectar no SlaveAllan");
  }
}

void loop()
{
  if (Serial.available())
  {
    String comandoEnviado = Serial.readStringUntil('\n');
    comandoEnviado.trim();
    SerialBT.println(comandoEnviado);
  }
  if (SerialBT.available())
  {
    String comandoReceber = SerialBT.readStringUntil('\n');
    comandoReceber.trim();
    Serial.printf("Comando recebido %s\n\r", comandoReceber);
    if (comandoReceber.equals("liga"))
    {
    }
    else if (comandoReceber.equals("desliga"))
    {
    }
    else if (comandoReceber.equals("pisca"))
    {
    }
    else
    {
      Serial.println("Comando nao reconhecido");
    }
  }
}
