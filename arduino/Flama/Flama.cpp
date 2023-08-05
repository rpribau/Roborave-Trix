#include "Arduino.h"
#include "Flama.h"
#include "Servo.h"

Flama::Flama (int s1, int valorVela){

  this-> flama = s1;
  this-> valorVela = valorVela;

}

/*
void Flama::iniciar(){

  servo10.attach(servo1);
  servo20.attach(servo2);
  servo40.attach(servo3);

  servo10.write(0);
  servo20.write(0);
  servo40.write(0);

}


void Flama::servoMove(byte servo, int angle){

	if (servo == 1){
	  servo10.write(angle);
	}

	else if (servo == 2){
	  servo20.write(angle);
	}

	if (servo == 3){
	  servo40.write(angle);
	}

}

int Flama::checkIndividual(byte sensor){

  if (sensor == 1){ return analogRead(flama10); }
  else if (sensor == 2){ return analogRead(flama20); }
  else if (sensor == 3){ return analogRead(flama40); }

}

int Flama::checkPromedio(){
  int promedio = (analogRead(flama10)+analogRead(flama20)+analogRead(flama40))/3;
  return promedio; 
}


bool Flama::check(){

  if ((analogRead(flama10) <= valorVela) || (analogRead(flama20) <= valorVela) || (analogRead(flama40) <= valorVela)){ return true; }
  else { return false; }

}



int Flama::degreeIndividual(byte servo){

  if (servo == 1){
    short anguloMax = 0;
    int lecturaMin = 1023;
    for (short i=10; i<171; i++){
      servo10.write(i);
      delay(10);
      int lectura = analogRead(flama10);
      // Serial.println(lectura);
      if (lectura < lecturaMin){ lecturaMin = lectura; anguloMax = i; }
    }
    servo10.write(0);
    return anguloMax;
  }

  else if (servo == 2){
    short anguloMax = 0;
    int lecturaMin = 1023;
    for (short i=10; i<171; i++){
      servo20.write(i);
      delay(10);
      int lectura = analogRead(flama20);
      if (lectura < lecturaMin){ lecturaMin = lectura; anguloMax = i; }
    }
    servo20.write(0);
    return anguloMax;
  }

  else if (servo == 3){
    short anguloMax = 0;
    int lecturaMin = 1023;
    for (short i=10; i<171; i++){
      servo40.write(i);
      delay(10);
      int lectura = analogRead(flama40);
      if (lectura < lecturaMin){ lecturaMin = lectura; anguloMax = i; }
    }
    servo40.write(0);
    return anguloMax;
  }
  
}


int Flama::degreePromedio(){

    short anguloMax1 = 0;
    short anguloMax2 = 0;
    short anguloMax3 = 0;
    int lecturaMin1 = 1023;
    int lecturaMin2 = 1023;
    int lecturaMin3 = 1023;
    for (short i=0; i<181; i++){
      servo10.write(i);
      servo20.write(i);
      servo40.write(i);
      delay(10);
      int lectura1 = analogRead(flama10);
      int lectura2 = analogRead(flama20);
      int lectura3 = analogRead(flama40);
      if (lectura1 < lecturaMin1){ lecturaMin1 = lectura1; anguloMax1 = i; }
      if (lectura2 < lecturaMin2){ lecturaMin2 = lectura2; anguloMax2 = i; }
      if (lectura3 < lecturaMin3){ lecturaMin3 = lectura3; anguloMax3 = i; }
    }
    servo10.write(0);
    servo20.write(0);
    servo40.write(0);

    int promedio = ((anguloMax1 + anguloMax2 + anguloMax3)/3);
    return promedio;
  
}

*/


bool Flama::check(){

  if (analogRead(flama) <= valorVela){
    return true;
  }
  
  else { return false; }

}
