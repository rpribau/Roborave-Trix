#ifndef MotorBase_h
  #define MotorBase_h
  #pragma once

  class MotorBase {
    private:
      int motorSpeed;
      int pin1;
      int pin2;

    public:

      MotorBase();
      void set(int pin1, int pin2, int motorSpeed);
      void iniciarMotor();
      void motorAdelante();
      void motorAtras();
      int getMotorSpeed();
  
  };

#endif