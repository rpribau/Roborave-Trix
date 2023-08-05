#ifndef Flama_h
  #define Flama_h

  #pragma once
  #include "Arduino.h"
  #include "Servo.h"

  class Flama {
    private: 
      int flama = 0;
      int valorVela = 0;
/*
      int flama10 = 0; // Sensores (10cm, 20cm, 40cm)
      int flama20 = 0; 
      int flama40 = 0;
      int valorVela = 40;
      short servo1 = 0;
      short servo2 = 0;
      short servo3 = 0;
      Servo servo10;
      Servo servo20;
      Servo servo40;
*/

    public:
      Flama (int s1, int valorVela);
	bool check();
/*
        void iniciar();
        int checkIndividual(byte sensor);
	int checkPromedio();
	bool check();
        int degreeIndividual(byte servo);
	int degreePromedio();
        void servoMove(byte servo, int angle);
*/
        

  };


#endif