#ifndef MotoresRave_h
  #define MotoresRave_h

  #pragma once
  #include "MotorBase.h"
  #include "Arduino.h"
  
  class MotoresRave {
    public:
      MotorBase motor1;
      MotorBase motor2;
      MotorBase motor3;

    MotoresRave (int m1p1, int m1p2, int m1en, int m2p1, int m2p2, int m2en, int m3p1, int m3p2, int m3en);
      void iniciar();
      void movimiento(int degree, int velocidad);
      void adelante(int motor);
      void giro(bool direccion, int velocidad);

  };

#endif