#include "MotoresRave.h"

MotoresRave motores(8, 9, 10, 11, 12, 13, 5, 6, 7); // derecha, izquierda, atrás, viéndolo de frente

void setup(){
  Serial.begin(9600);
  motores.iniciar();
}


void loop(){
  motores.movimiento(45,255);
}