#ifndef Ventilador_h
    #define Ventilador_h

    #pragma once
    #include "Arduino.h"
    #include "Servo.h"

    class Ventilador {
        private:
	  int escPin = 0;
	  Servo ESC;

        public:
        Ventilador (int pin);
            void calibrar();
            void fuego();
    };

#endif