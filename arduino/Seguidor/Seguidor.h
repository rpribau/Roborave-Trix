#ifndef Seguidor_h
  #define Seguidor_h

  #pragma once
  #include "Arduino.h"

  class Seguidor {
    private:
      int s1 = 0;
      int s2 = 0;
      int s3 = 0;

    public: 
      Seguidor (int pin1, int pin2, int pin3);
        void iniciar();
        bool lineaCheckIndividual(byte sensor);
        bool lineaCheck();

  };

#endif