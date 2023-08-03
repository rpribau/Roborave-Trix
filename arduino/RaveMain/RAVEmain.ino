#include "Servo.h"
#include "Ultrasonicos.h"
#include "MotoresRave.h"
#include "Flama.h"

Servo servo10;
Servo servo20;
Servo servo40;

Flama flama(A0, A1, A2, 50, 2, 3, 4); // pines 10cm, 20cm, 40cm, valor de detección de vela, pines de servos en el mismo orden

Ultrasonicos sonic(53, 52, 51, 50); // trigIz, echoIz, trigDe, echoDe

MotoresRave motores(11, 12, 13, 8, 9, 10, 5, 6, 7); // derecha, izquierda, atrás, viéndolo de frente

const short seguidorF = 19;
const short seguidorDe = 20;
const short seguidorIz = 21;



void setup(){

  Serial.begin(9600);

  pinMode(seguidorF,INPUT_PULLUP);
  pinMode(seguidorDe,INPUT_PULLUP);
  pinMode(seguidorIz,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(seguidorF), detectarF, RISING);
  attachInterrupt(digitalPinToInterrupt(seguidorIz), detectarIz, RISING);
  attachInterrupt(digitalPinToInterrupt(seguidorDe), detectarDe, RISING);

  servo10.attach(2);
  servo20.attach(3);
  servo40.attach(4);

  sonic.iniciar();
  motores.iniciar();

}




void loop(){
  if (digitalRead(seguidorF == true)){
    if (flama.check() == true){

    }
    else {

    }
  }


}





void detectarF(){

}


void detectarDe(){

}


void detectarIz(){

}