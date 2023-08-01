#include "Arduino.h"
#include "MotorBase.h"

MotorBase::MotorBase() {};

void MotorBase::set(int pin1, int pin2, int motorSpeed) {
  this-> motorSpeed = motorSpeed;
  this-> pin1 = pin1;
  this-> pin2 = pin2;
}

void MotorBase::iniciarMotor(){
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(motorSpeed,OUTPUT);
}

void MotorBase::motorAdelante(){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
}

void MotorBase::motorAtras(){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
}

int MotorBase::getMotorSpeed(){
  return motorSpeed;
}
