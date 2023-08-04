char command;
int in1 = 11;
int in2 = 12;
int EnA = 10;
int motorSpeed = 0;
int voltage11 = 0;
int voltage12 = 0;
int voltage10 = 0;

int in3 = 13;
int in4 = 8;
int EnB = 9;
int motor2Speed = 0;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(EnA, OUTPUT);
  
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(EnB, OUTPUT);

  Serial.begin(9600);  // Inicializar comunicación serial a 9600 bps
}

void loop()
{
  // Leer los valores analógicos de los pines 11, 12 y 10
  voltage11 = analogRead(11);
  voltage12 = analogRead(12);
  voltage10 = analogRead(10);

  // Escalar los valores leídos (0-1023) a un rango de 0-5V
  float voltageScale = 5.0 / 1023.0;
  float voltage11Scaled = voltage11 * voltageScale;
  float voltage12Scaled = voltage12 * voltageScale;
  float voltage10Scaled = voltage10 * voltageScale;

  // Enviar los valores a través de la comunicación serial
  Serial.print("Voltaje en Pin 11: ");
  Serial.print(voltage11Scaled);
  Serial.print("V\t");

  Serial.print("Voltaje en Pin 12: ");
  Serial.print(voltage12Scaled);
  Serial.print("V\t");

  Serial.print("Voltaje en Pin 10: ");
  Serial.print(voltage10Scaled);
  Serial.println("V");

  if (Serial.available() > 0)
  {
    command = Serial.read();
    if (command == '1')
    {
      motorSpeed = 250;  // Velocidad para el comando '1'
      motor2Speed = 250;
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (command == '0')
    {
      motorSpeed = 0;  // Velocidad para el comando '0'
      motor2Speed = 0;
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    analogWrite(EnA, motorSpeed);  // Establecer la velocidad del motor
    analogWrite(EnB, motor2Speed);  // Establecer la velocidad del motor
  }
}
