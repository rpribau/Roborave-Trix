#include <MotoresRave.h>
#include <Ultrasonicos.h>
#include <Ventilador.h>
#include "Wire.h"

MotoresRave motores(12, 13, 11, 7, 8, 6, A0, 4, 3); // derecha, izquierda, atrás, viéndolo de frente
// Ventilador propeller(5);

Ultrasonicos (10, A3, 9, 5);

Flama (A4, 100);

Ventilador();

const short seguidorF = 2;

int angulo = 0;
int x = 0;
bool vela = false;

int velocidad = 70;

int distanciaIz;
int distanciaDe;

boolean vela_prendida = false;

void setup() {
  Ultrasonicos.iniciar();
  Serial.begin(9600);
  // Wire.begin();

  pinMode(seguidorF, INPUT_PULLUP);

  attachInterrupt(seguidorF,apagar(), HIGH) //

  // propeller.calibrar();  // Para calibrar el ventilador

  motores.iniciar();

  ventilador.calibrar();
}

void loop() {
    String mensaje = "0";
    angulo = 0;
    x = 0;
    while (Serial.available() > 0){
      String command = Serial.readString(); 
      mensaje = mensaje + command;
    }
    angulo = mensaje.toInt();
    x = angulo * 4;

    if (x > 320) {
      motores.giro(1, velocidad); // derecha
    }
    else if (x < 290) {
      motores.giro(0,velocidad); // izquierda
    }
    else {
      motores.movimiento(0,velocidad); // frente
      delay(200);
      motores.movimiento(0,0); // Para
      distanciaIz = Ultrasonicos.getDistanciaIz()
      distanciaDe = Ultrasonicos.getDistanciaDe()

      if (distanciaIz < 7){     // Moverse a la derecha porque hay pared a la izquierda
        motores.movimiento(60,velocidad);
        delay(100);
        motores.movimiento(0,0);
      }
      
      if (distanciade < 7){     // Moverse a la izquierda porque hay pared a la derecha
        motores.movimiento(300,velocidad);
        delay(100);
        motores.movimiento(0,0);
      } 
    }
  delay(200);
}

void apagar(){
  vela_prendida = check();

  if (fuego == true);{
    while (fuego == true);{
      ventilador.fuego();
      vela_prendida = check();
    }
  }
  delay(500);
  motores.giro(1, velocidad);
  delay(200);
  motores.movimiento(0, velocidad);
  delay(200);
}
