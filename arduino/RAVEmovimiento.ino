#include "MotoresRave.h"

MotoresRave motores(12, 13, 11, 7, 8, 6, 2, 4, 3); // derecha, izquierda, atrás, viéndolo de frente

void setup(){
  Serial.begin(9600);
  motores.iniciar();
}



void loop(){
  motores.movimiento(0,195);
}


void adelante(){
  motores.movimiento(0,255);
}