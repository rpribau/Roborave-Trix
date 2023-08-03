#include "Seguidor.h"
#include "Arduino.h"

Seguidor::Seguidor(int pin1, int pin2, int pin3){

  this-> s1 = pin1;
  this-> s2 = pin2;
  this-> s3 = pin3;

}


void Seguidor::iniciar(){

  pinMode(s1,INPUT_PULLUP);
  pinMode(s2,INPUT_PULLUP);
  pinMode(s3,INPUT_PULLUP);

}


bool Seguidor::lineaCheckIndividual(byte sensor){

  if (sensor == 1){
    if (digitalRead(s1) == true){ return true; }
    else { return false; }
  }

  else if (sensor == 2){
    if (digitalRead(s2) == true){ return true; }
    else { return false; }
  }

  else if (sensor == 3){
    if (digitalRead(s3) == true){ return true; }
    else { return false; }
  }

}


bool Seguidor::lineaCheck(){

  if ((digitalRead(s1) == true) || (digitalRead(s2) == true) || (digitalRead(s3) == true)){ return true; }
  else { return false; }

}
