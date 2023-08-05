#ifndef Seguidor_h
  #define Seguidor_h

  #pragma once
  #include "Arduino.h"

  class Seguidor {
    private:
      int s1 = 0;

    public: 
      Seguidor (int pin1);
        void iniciar();
        bool lineaCheckIndividual(byte sensor);
        bool lineaCheck();

  };

#endif