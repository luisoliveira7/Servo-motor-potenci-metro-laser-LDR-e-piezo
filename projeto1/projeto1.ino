#include <Servo.h>

Servo servo;

int potAngulo = A0;
int potVelocidade = A1;

int posicao = 0;
int passo = 1;

void setup() {
  servo.attach(9);
}

void loop() {
  // le os potenciometros e converte para os valores que queremos
  int anguloMax = map(analogRead(potAngulo), 0, 1000, 0, 180);
  anguloMax = constrain(anguloMax, 0, 180); // nunca passa de 180
  int espera = map(analogRead(potVelocidade), 0, 1023, 50, 2); // girou mais = delay menor = mais rapido

  servo.write(posicao);
  delay(espera);

  posicao = posicao + passo;

  // chegou no angulo maximo, volta
  if (posicao >= anguloMax) {
    posicao = anguloMax;
    passo = -1;
  }
  // chegou no zero, vai de novo
  if (posicao <= 0) {
    posicao = 0;
    passo = 1;
  }
}
