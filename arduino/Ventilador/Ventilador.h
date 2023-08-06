#ifndef Ventilador_h
    #define Ventilador_h

    #pragma once
    #include "Arduino.h"

    class Ventilador {
        private:
            Servo ESC;
            int escPin;

        public:
            Ventilador (Servo ESC, int escPin);
            void calibrar();
            void fuego();
    }

#endif