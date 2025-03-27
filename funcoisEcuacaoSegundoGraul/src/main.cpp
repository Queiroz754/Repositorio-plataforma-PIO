#include <Arduino.h>
int calculaSegundoGrau(int a,int b,int c);


void setup() 
{
 Serial.begin(9600);
 int raizDaFuncao = calculaSegundoGrau(1,3,4);
 Serial.println(raizDaFuncao);
}

void loop() 
{
 
}

int calculaSegundoGrau(int a,int b,int c)
{
  int resultado;
  int delta = (b*2) - (4*a*c);
resultado = (-b + sqrt(delta)) / (2*a);


  return resultado;
} 