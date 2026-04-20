//C++ code
//
int sensorLuz = A0;
int led = 9;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorLuz = analogRead(sensorLuz);  

  int brillo = map(valorLuz, 0, 1023, 255, 0);

  analogWrite(led, brillo);

  Serial.println(valorLuz);
  delay(100);
}
