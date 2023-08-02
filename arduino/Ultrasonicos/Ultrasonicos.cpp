#include "Arduino.h"
#include "Ultrasonicos.h"

Ultrasonicos::Ultrasonicos (int trigIz, int echoIz, int trigDe, int echoDe){

  this-> trigIz = trigIz;
  this-> trigDe = trigDe;
  this-> echoIz = echoIz;
  this-> echoDe = echoDe;

}

void Ultrasonicos::iniciar(){

  pinMode(trigIz,OUTPUT);
  pinMode(echoIz,INPUT);
  pinMode(trigDe,OUTPUT);
  pinMode(echoDe,INPUT);

}


float Ultrasonicos::getDistanciaIz(){

  digitalWrite(trigIz, LOW);
  delayMicroseconds(2);
  digitalWrite(trigIz, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigIz, LOW);
  int duracion = pulseIn(echoIz, HIGH); //Mide el tiempo entre Trig y el Echo
  float distanciaIz = 0;
  return distanciaIz = (duracion/2) / 29.1; //y calcula la distancia  otra forma sería distancia = (duracion * 0.034) / 2;
  // return ultimaDistanciaIz = distanciaIz;

}


float Ultrasonicos::getDistanciaDe(){

  digitalWrite(trigDe, LOW);
  delayMicroseconds(2);
  digitalWrite(trigDe, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigDe, LOW);
  int duracion = pulseIn(echoDe, HIGH); //Mide el tiempo entre Trig y el Echo
  float distanciaDe = 0;
  return distanciaDe = (duracion/2) / 29.1; //y calcula la distancia  otra forma sería distancia = (duracion * 0.034) / 2;
  // return ultimaDistanciaIz = distanciaIz;

}