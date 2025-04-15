#include <Arduino.h>
#include <BluetoothSerial.h>
#define pinLed 2
BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  if (!SerialBT.begin("SlaveAllan", false))
  {
    Serial.println("Erro ao Iniciar Bluetooth como Slave");
  }
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;
  static int velocidadePisca = 0;

  static bool estadoLed = false;
  static bool estadoPisca = false;
  if (Serial.available())
  {
    String comandoEnviar = Serial.readStringUntil('\n');
    comandoEnviar.trim();
    SerialBT.println(comandoEnviar);
  }
  if (SerialBT.available())
  {
    String comandoReceber = SerialBT.readStringUntil('\n');
    comandoReceber.trim();
    Serial.printf("Comando recebido %s\n\r", comandoReceber);
    if (comandoReceber.equals("liga"))
    {
      estadoPisca = false;
      estadoLed = true;
    }
    else if (comandoReceber.equals("desliga"))
    {
      estadoPisca = false;
      estadoLed = false;
    }
    else if (comandoReceber.equals("pisca"))
    {
      estadoPisca = true;
    }
    else
    {
      Serial.println("Comando nao reconhecido");
    }
    if (comandoReceber.startsWith("vel = "))
    {
      int tamanho = comandoReceber.length();
      String extracao = comandoReceber.substring(6, tamanho);
      int velocidade = extracao.toInt();
      if (velocidade > 0 && velocidade <= 1000)
      {
        velocidadePisca = map(velocidade, 1, 100, 1000, 50);
      }
      else if (velocidade == 0)
      {
        estadoPisca = false;
        digitalWrite(pinLed, true);
      }
      else
      {
        SerialBT.println("velocidade aceito apenas entre 0 a 100");
      }
    }
    if (comandoReceber.startsWith("Qual velocidade"))
    {
Serial.println(comandoReceber);
    }
  }
  

  if (estadoPisca)
  {
    if (tempoAtual - tempoInicial > velocidadePisca)
    {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
  }
  digitalWrite(pinLed, estadoLed);
}