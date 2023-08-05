#include "Servo.h"

Ventilador::Ventilador (){};

void Ventilador::calibrar(){

    ESC.attach(9,1000,2000);
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