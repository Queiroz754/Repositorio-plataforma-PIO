#include <Arduino.h>
#include <ezTime.h>
#include "internet.h"


void ordilei();


Timezone tempo;

void setup()
{
  Serial.begin(9600);
  conectaWiFi();


  waitForSync();

  tempo.setLocation("America/Sao_Paulo");
}

void loop()
{
  checkWiFi();
Serial.println(tempo.dateTime()); //? data completa dia da semana , dia-mes-ano , hora completa e fuso horario
Serial.println(tempo.day()); //? dia do mes
Serial.println(tempo.month()); //? mes do ano
Serial.println(tempo.year()); //? Ano atual
Serial.println(tempo.yearISO()); //? Ano atual
Serial.println(tempo.dayOfYear()); //? total de dias passado no ano
Serial.println(tempo.hour()); //? Hora atual
Serial.println(tempo.hourFormat12()); //?Hora atual
Serial.println(tempo.minute()); //? minuto atual
Serial.println(tempo.second()); //? segundo atual
Serial.println(tempo.getPosix());
Serial.println(tempo.isAM());//? se esta de dia
Serial.println(tempo.isPM());//? se esta de noite
Serial.println(tempo.now()); //? Retorna a data e hora atual como um numero unsigned long
Serial.println(tempo.ms());//? retorna os milisegundos da hora atual
Serial.println(tempo.weekday());//? retorna o dia da semana
Serial.println("------------------");





ordilei();
}

void ordilei()
{
  delay(2000);
}
