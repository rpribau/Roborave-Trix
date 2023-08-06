#include <MotoresRave.h>
#include <Ultrasonicos.h>
#include <Ventilador.h>
#include <Flama.h>
#include <Seguidor.h>
#include <Servo.h>
#include "Wire.h"

MotoresRave motores(12, 13, 11, 7, 8, 6, A0, 4, 9); // Motor derecho, motor izquierdo, motor trasero
// viéndolo de frente al robot. Cada uno tiene 3 pines: enable, input1 e input2

Ultrasonicos sensoresUltrasonicos(10, A3, 2, A5); // Sensor ultrasónico izquierdo y derecho. Cada uno tiene
// 2 pines: trig y echo

Flama flama(A4, 100); // Sensor de flama. Tiene 1 pin y un valor mínimo de detección de flama

Servo ventiladorServo; // Objeto servomotor para el ventilador
Ventilador ventilador(ventiladorServo, 5); // Servomotor del ventilador con objeto servomotor y pin

const short seguidorF = 3; // Variable que contiene pin digital 2 de seguidor de línea

Seguidor seguidorDeLinea(seguidorF); // Asignación de pin digital 2 a objeto seguidor de línea

int angulo = 0; // Ángulo en donde se encuentra la vela prendida con valor dividido por 4 para permitir la recepción de valores execedentes a 255 en bytes
int x = 0; // Variable con valor de angulo multiplicado por cuatro (verdadero ángulo)
bool vela = false; // Variable que menciona la detección o no de una vela
bool fuego = false; // Variable que menciona la detección o no de flama
int distanciaIz; // Variable que contiene la distancia detectada por el sensor ultrasónico izquierdo de un objeto externo
int distanciaDe; // Variable que contiene la distancia detectada por el sensor ultrasónico derecho de un objeto externo
boolean vela_prendida = false; // Variable que menciona si una vela está prendida
int velocidad = 100;

void setup() {

  Serial.begin(9600); // Inicio de comunicación serial a 9600 bits/s

  motores.iniciar(); // Asignación de pines de entradas 1 y 2 y el enable como salidas
  
  sensoresUltrasonicos.iniciar(); // Asignaciones de pines y modos de pines a sensores ultrasónicos
  // Aquí, los pines TRIG son OUTPUT y los pines ECHO son INPUT

  seguidorDeLinea.iniciar(); // Asignación de pin y modo de pin como INPUT_PULLUP a seguidor de línea

  ventilador.calibrar(); // Inicio y calibración de ventilador

  attachInterrupt(seguidorF, apagar, LOW); // Definición de función attachInterrupt que cuando se 
  // detecta flama (HGIH) se apaga la flama con la función void apagar() de este código principal
  
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
      
      motores.giro(0, velocidad); // izquierda
      
    }
    
    else {
      
      motores.movimiento(0, velocidad); // frente
      delay(200);
      motores.movimiento(0,0); // Para
      distanciaIz = sensoresUltrasonicos.getDistanciaIz();
      distanciaDe = sensoresUltrasonicos.getDistanciaDe();

      if (distanciaIz < 7){     // Moverse a la derecha porque hay pared a la izquierda
        motores.movimiento(60, velocidad);
        delay(100);
        motores.movimiento(0, 0);
      }
      
      if (distanciaDe < 7){     // Moverse a la izquierda porque hay pared a la derecha
        motores.movimiento(300, velocidad);
        delay(100);
        motores.movimiento(0, 0);
      } 
      
    }
    
  delay(200);
}

void apagar(){
  velocidad = 70;
  vela_prendida = flama.check();
  
  if (fuego == true) {
    while (fuego == true) {
      ventilador.fuego();
      fuego = flama.check();
    }
  }
  
  delay(500);
  motores.giro(1, velocidad); // derecha
  delay(200);
  motores.giro(0, velocidad); // izquierda
  delay(200);
  
}
