
short seguidorPin = 49;

void setup() {
  Serial.begin(9600);
  pinMode(seguidorPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(seguidorPin), detectar, FALLING);
}

void loop() {
  
  Serial.println(digitalRead(seguidorPin));

}

void detectar(){
  Serial.println("Línea");
  delay(1000);
}



