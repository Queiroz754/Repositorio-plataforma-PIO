#include <Arduino.h>
#define pinLed 21
#define pinButton 23

void setup() 
{
Serial.begin(9600);
pinMode(pinButton,INPUT_PULLUP);
pinMode(pinLed,OUTPUT);
}

void loop() 
{
  bool estadoAtualBotao = digitalRead(pinButton);
static bool estadoAnteriorBotao = 1;
static bool ultimaAcao = 1;

static unsigned long tempoAnteriorDebounce =0;
unsigned long tempoAtual =millis();
const unsigned long tempoDebounce = 50;

static int contagem = 0;


//!Inicia o tratamento de ruido do botao

//* Marca quando uma mudanca de estado acontece
if(estadoAtualBotao != estadoAnteriorBotao)
{
tempoAnteriorDebounce = tempoAtual;
}

//*verificar se a mudanca de estado esta estavel
if((tempoAtual - tempoAnteriorDebounce) > tempoDebounce )
{
//* Houve uma alteracao proposital do estado do botao?
if(estadoAtualBotao != ultimaAcao)
{
  ultimaAcao = estadoAtualBotao;
  if(!estadoAtualBotao)
  {
    contagem++;
    Serial.println(contagem);
//*botao apertado
  }
  else
  {
//*botao solto
  }
}
}
estadoAnteriorBotao = estadoAtualBotao;
//!Final do tratamento do BOtao
}

