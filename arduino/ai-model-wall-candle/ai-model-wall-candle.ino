/* ESTE ES UN ESQUELETO PARA PODER TRABAJAR CON EL ARCHIVO DE /python/testModel.py. */

/* Lo que manda el archivo testModel.py es lo siguiente:
 *  
 *  0 = No hay pared
 *  1 = Hay pared
 *  2 = Hay vela
 *  3 = No hay vela
 */

#include <Arduino.h>
#include "arduino/headers/motor_control.h"

void setup()
{
  Serial.begin(9600);
  setupMotors(); // Configurar los pines de los motores
}

void loop()
{
  // Tu código de detección de objetos aquí

  // Ejemplo de control de motores según la detección
  // Suponemos que 'object_detected' es una variable booleana que indica si se detectó un objeto

  if (object_detected)
  {
    // Se detectó "wall", mover los tres motores hacia adelante
    moveMotorsForward();
    delay(5000); // Esperar 5 segundos
    stopMotors(); // Detener los motores
  }
  else if (candle_detected)
  {
    // Se detectó "candle", mover dos motores hacia atrás
    moveMotorsBackward();
    delay(5000); // Esperar 5 segundos
    stopMotors(); // Detener los motores
  }

  // Continuar con la detección de objetos y control de motores
}
