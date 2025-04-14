#include <Arduino.h>

#define pinLed 2

void setup()
{
    pinMode(pinLed, OUTPUT);
    Serial.begin(9600);
    Serial.print("comunicacao Serial Iniciada \n");
}

void loop()
{
    static bool estadoLed = 0;
    static bool piscaLed = 0;

    unsigned long tempoAtual = millis();
    static unsigned long tempoInicial = 0;
    static int tempo = 300;
    map(tempo, 0, 1000, 0, 100);

    if (Serial.available())
    {
        String msg = Serial.readStringUntil('\n');
        msg.trim();
        msg.toLowerCase();

        if (msg.equals("liga"))
        {
            estadoLed = true;
            piscaLed = false;
        }
        else if (msg.equals("desliga"))
        {
            estadoLed = false;
            piscaLed = false;
        }
        else if (msg.equals("pisca"))
        {
            piscaLed = true;
        }

        if (msg.startsWith("vel = "))
        {
            int tamanho = msg.length();
            String extracao = msg.substring(6, tamanho);
            int valorVelocidade = extracao.toInt();
            if (valorVelocidade >= 0 && valorVelocidade <= 1000)
            {
                tempo = map(valorVelocidade, 0, 100, 1000, 50);
            }
            else
            {
                Serial.println("velocidade aceito apenas entre 0 e 100");
            }
        }

    }

    if (piscaLed)
    {

        if (tempoAtual - tempoInicial > tempo)
        {
            estadoLed = !estadoLed;
            tempoInicial = tempoAtual;
        }
    }

    digitalWrite(pinLed, estadoLed);
}
