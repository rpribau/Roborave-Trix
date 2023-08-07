#include "Arduino.h"
#include "MotoresRave.h"

MotoresRave::MotoresRave (int m1p1, int m1p2, int m1en, int m2p1, int m2p2, int m2en, int m3p1, int m3p2, int m3en){
  motor1.set(m1p1,m1p2,m1en);
  motor2.set(m2p1,m2p2,m2en);
  motor3.set(m3p1,m3p2,m3en);
}

void MotoresRave::iniciar(){
  motor1.iniciarMotor();
  motor2.iniciarMotor();
  motor3.iniciarMotor();
}

void MotoresRave::adelante(int motor){
  if (motor == 1){
    analogWrite(motor1.getMotorSpeed(), 255);
    motor1.motorAdelante();
  }
  else if (motor == 2){
    analogWrite(motor2.getMotorSpeed(), 255);
    motor2.motorAdelante();
  }
  else if (motor == 3){
    analogWrite(motor3.getMotorSpeed(), 255);
    motor3.motorAdelante();
  }
  
}

void MotoresRave::movimiento(int degree, int velocidad){
//En base a los grados se definen las velocidades de cada motor
  float m1 = cos(((150 - degree) * PI / 180));
  float m2 = cos(((30 - degree) * PI / 180));;
  float m3 = cos(((270 - degree) * PI / 180));
  int speedA = abs(int(m1 * velocidad));
  int speedB = abs(int(m2 * velocidad));
  int speedC = abs(int(m3 * velocidad));

  //Definir la velocidad de cada motor
  analogWrite(motor1.getMotorSpeed(), speedA);
  analogWrite(motor2.getMotorSpeed(), speedB);
  analogWrite(motor3.getMotorSpeed(), speedC);

  //Mover motores según la velocidad (positiva o negativa)
  if (m1 >= 0) {
    //          analogWrite(motor1.pin1, speedA);
    //          analogWrite(motor1.pin2, 0);
    motor1.motorAdelante();
  } else {
    //            analogWrite(motor1.pin1, 0);
    //            analogWrite(motor1.pin2, -1*speedA);
    motor1.motorAtras();
  }

  if (m2 >= 0) {
    //          analogWrite(motor2.pin1, speedB);
    //          analogWrite(motor2.pin2, 0);
    motor2.motorAdelante();
  } else {
    //          analogWrite(motor2.pin1, 0);
    //          analogWrite(motor2.pin2, -1*speedB);
    motor2.motorAtras();
  }

  if (m3 >= 0) {
    //          analogWrite(motor3.pin1, speedC);
    //          analogWrite(motor3.pin2, 0);
    motor3.motorAdelante();
  } else {
    //          analogWrite(motor3.pin1, 0);
    //          analogWrite(motor3.pin2, -1*speedC);
    motor3.motorAtras();
  }
}


void MotoresRave::giro(bool direccion, int velocidad){

  int velocidadMotor = constrain(velocidad, 0, 255);

  if (direccion == 0){ 		// izquierda
    motor1.motorAdelante();
    motor2.motorAdelante();
    motor3.motorAdelante();
  }

  else{		// derecha
    motor1.motorAtras();
    motor2.motorAtras();
    motor3.motorAtras();
  }

  analogWrite(motor1.getMotorSpeed(), velocidadMotor);
  analogWrite(motor2.getMotorSpeed(), velocidadMotor);
  analogWrite(motor3.getMotorSpeed(), velocidadMotor);

}

void MotoresRave::alto() {
  
  motor1.motorAlto();
  motor2.motorAlto();
  motor3.motorAlto();

}