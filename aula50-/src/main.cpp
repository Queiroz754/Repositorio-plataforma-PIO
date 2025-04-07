#include <Arduino.h>
#define canalA 5 //! Pino CLK
#define canalB 18 //! pino DT

const int8_t tabelaTransicao[4][4] = {

//*   +1 Horario
//?    0 Parado
//!   -1 antihorario
//* Tabela de transicao que vai combinar a posicao anterior com a posicao atual e retornar
//* se dever ser incrementado ou decremento com o movimento

        /* 0  1  2  3  */ 
   /*0*/ { 0, 1,-1, 0},
   /*1*/ {-1, 0, 0, 1},
   /*2*/ { 1, 0, 0,-1},
   /*3*/ { 0,-1, 1, 0}
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
    //* Leitura do canal de cada estado
bool leituraCanalA = digitalRead(canalA);
bool leituraCanalB = digitalRead(canalB);

//* junta as duas leituras em uma so variavel
//* Rotacionando o valor da variavel leituraCanalA 1 para a esquerda e lendo o valor da variavel leituraCanalB e deixando na
//* direita 
int estadoAtualEncoder = ((leituraCanalA << 1) | leituraCanalB);
static int estadoAnteriorEncoder = 3;

static int posicaoSeta = 0;
static int acumuladorMovimento =0; //* variavel para verificar se foi dado 4 pulso corretos

//* caso houver uma movimenacao no encoder, adicione ou subtraia uma unidade do acumulador de movimento
if(estadoAnteriorEncoder != estadoAtualEncoder)
{
acumuladorMovimento += tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];
    //* se o encoder esta na posicao 3 (posicao de repolso)
    if (estadoAtualEncoder == 3)
    {
     //* se o acumulador de movimento chegou a 3 ouve 4 pulsos corretos no sentido horario
        if (acumuladorMovimento == 3 && posicaoSeta < 3)
        {
         posicaoSeta++;
        }
     //* se o acumulador de movimento chegou a -3 ouve 4 pulsos corretos no sentido antihorario
        else if(acumuladorMovimento == -3 && posicaoSeta > 0)
        {
         posicaoSeta--;
        }
     //* Reinicia o acumulador de movimento 
        acumuladorMovimento = 0;
    }
}
//* atualiza o estado do encoder
estadoAnteriorEncoder = estadoAtualEncoder;
}