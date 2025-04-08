#include <Arduino.h>


char nome [20];
char nome2 [20];
void setup()
{
Serial.begin(9600);
strcpy (nome,"Allan");//*atribui uma string a uma cadeia de caracteres
Serial.println(nome);   //*(juntou)
strcat (nome,"Barbosa"); //*concatenou as palavras
Serial.println(nome);
int tamanho = strlen(nome); //*informa o tamnho do dado
Serial.println(tamanho);

strcpy(nome2, "Allan BArbosa Q");

//*Compara duas strings e retorna zero se forem iguais
if (strcmp(nome2, nome) == 0) Serial.println("Sao iguais");
else Serial.println("Sao diferentes");

if (strcmp("Allan Barbosa ", nome) == 0) Serial.println("Sao iguais");
else Serial.println("Sao diferentes");

if(strncmp(nome2,nome, 6) == 0)//*compara se os 6 caracterers sao iguais
Serial.println("Os 6 primeiros sao iguais");
else Serial.println("O comeco nao e igual");


char buffer [50];
int temperatura = 25;
sprintf(buffer, "temperatura : %d°C", temperatura); //*adiciona a um vetor um texto como um printf
Serial.println(buffer);



}
void loop()
{

}
