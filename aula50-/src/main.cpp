#include <Arduino.h>
#define canalA 5
#define canalB 18

const int8_t tabelaTransicao[4][4] = {

//*   +1 Horario
//?    0 Parado
//!   -1 antihorario



        /* 0  1  2  3  */ 
   /*0*/ { 0, 1, -1,  0},
   /*1*/ { -1,  0, 0, 1},
   /*2*/ {1,  0, 0,  -1},
   /*3*/ { 0,  -1, 1, 0}
};

//* 32013201 Horario
//! 10231023 Antihorario
void setup()
{
    pinMode(canalA, INPUT);
    pinMode(canalB, INPUT);
    Serial.begin(9600);

}

void loop()
{
bool leituraCanalA = digitalRead(canalA);
bool leituraCanalB = digitalRead(canalB);
int estadoAtualEncoder = ((leituraCanalA << 1) | leituraCanalB);
static int estadoAnteriorEncoder = 3;

static int posicaoSeta = 0;
static int acumuladorMovimento =0;

if(estadoAnteriorEncoder != estadoAtualEncoder)
{
acumuladorMovimento += tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];
    
    if (estadoAtualEncoder == 3)
    {
        if (acumuladorMovimento == 3 && posicaoSeta < 3)
        {
         posicaoSeta++;
        }
        else if(acumuladorMovimento == -3 && posicaoSeta > 0)
        {
         posicaoSeta--;
        }
    }
}
estadoAnteriorEncoder = estadoAtualEncoder;

}