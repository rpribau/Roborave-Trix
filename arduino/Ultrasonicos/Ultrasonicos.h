#ifndef Ultrasonicos_h
  #define Ultrasonicos_h

  #pragma once
  #include "Arduino.h"

  class Ultrasonicos {
    private: 
      int trigIz = 0;
      int trigDe = 0;
      int echoIz = 0;
      int echoDe = 0;

    public:
      Ultrasonicos (int trigIz, int echoIz, int trigDe, int echoDe);
        void iniciar();
        float getDistanciaIz();
        float getDistanciaDe();




  };

#endif