#include <Arduino.h>

struct Pessoa
{
  char nome [20];
  int idade;
  float altura;
  bool calvice;
};
struct rgb
{
  int r;
  int g;
  int b;
};

Pessoa aluno;
Pessoa professor;
rgb roxo;
rgb verde;
rgb vermelho;

void setup()
{
Serial.begin(9600);

strcpy(aluno.nome, "Allan");
aluno.idade = 19;
aluno.altura = 1.79;
aluno.calvice = false;

strcpy (professor.nome, "Ordilei");
professor.idade = 47;
professor.altura = 1.80;
professor.calvice = true;


Serial.printf("meu nome eh: %s \n\r",aluno.nome);
Serial.printf(" E tenho %d anos\n\r", aluno.idade);
Serial.printf("tenho %.2f metros de altura\n\r",aluno.altura);
Serial.printf("E %s calvo\n\r", aluno.calvice ? "sou" : "nao sou");

Serial.printf("meu nome eh: %s \n\r",professor.nome);
Serial.printf(" E tenho %d anos\n\r", professor.idade);
Serial.printf("tenho %.2f metros de altura\n\r",professor.altura);
Serial.printf("E %s calvo\n\r", professor.calvice ? "sou" : "nao sou");



verde.r = 52;
verde.g =71;
verde.b = 0;


roxo.r = 81;
roxo.g =0;
roxo.b = 85;



vermelho.r = 159;
vermelho.g =13;
vermelho.b = 9;

Serial.println("Para a cor verde eh necesario");
Serial.printf ("R: %d\n\r",verde.r);
Serial.printf ("G: %d\n\r",verde.g);
Serial.printf ("B: %d\n\r",verde.b);

Serial.println("Para a cor roxo eh necesario");
Serial.printf ("R: %d\n\r",roxo.r);
Serial.printf ("G: %d\n\r",roxo.g);
Serial.printf ("B: %d\n\r",roxo.b);

Serial.println("Para a cor vermelho eh necesario");
Serial.printf ("R: %d\n\r",vermelho.r);
Serial.printf ("G: %d\n\r",vermelho.g);
Serial.printf ("B: %d\n\r",vermelho.b);

}

void loop()
{

}
