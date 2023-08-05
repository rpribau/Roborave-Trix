#include "Seguidor.h"
#include "Arduino.h"

Seguidor::Seguidor(int pin1){

  this-> s1 = pin1;

}


void Seguidor::iniciar(){

  pinMode(s1,INPUT_PULLUP);

}

bool Seguidor::lineaCheckIndividual(byte sensor){

  if (sensor == 1){
    if (digitalRead(s1) == true){ return true; }
    else { return false; }
  }

}


bool Seguidor::lineaCheck(){

  if ((digitalRead(s1) == true)){ return true; }
  else { return false; }

}
