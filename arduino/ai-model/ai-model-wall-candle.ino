char command;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    command = Serial.read();
    if (command == '1')
    {
      digitalWrite(3, HIGH); // Encender el LED en el puerto 3 (wall)
    }
    else if (command == '0')
    {
      digitalWrite(3, LOW); // Apagar el LED en el puerto 3 (wall)
    }
    else if (command == '2')
    {
      digitalWrite(2, HIGH); // Encender el LED en el puerto 2 (candle)
    }
    else if (command == '3')
    {
      digitalWrite(2, LOW); // Apagar el LED en el puerto 2 (candle)
    }
  }
}
