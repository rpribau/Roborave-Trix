
short seguidorPin = 21;

void setup() {
  Serial.begin(9600);
  pinMode(seguidorPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(seguidorPin), detectar, FALLING);
}

void loop() {
  
  Serial.println(sin(90));

}

void detectar(){
  Serial.println("Línea");
  delay(1000);
}