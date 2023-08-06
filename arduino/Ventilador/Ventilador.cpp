#include "Servo.h"
#include "Ventilador.h"

Ventilador::Ventilador (Servo ESC, int escPin){
    this-> ESC = ESC;
    this-> escPin = escPin;
};

void Ventilador::calibrar(){

    ESC.attach(escPin);
    delay(2000);
    ESC.write(100);
    delay(500);
    ESC.write(0);
    delay(500);

}

void Ventilador::fuego(){

    ESC.write(100);
    delay(3000);
    ESC.write(0);

}