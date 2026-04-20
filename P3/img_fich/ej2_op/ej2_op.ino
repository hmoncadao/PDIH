//C++ code
//
int trig = 9;
int echo = 10;
int buzzer = 8;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duracion;
  int distancia;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duracion = pulseIn(echo, HIGH);

  // Calculo disntancia
  distancia = duracion * 0.034 / 2;

  Serial.println(distancia);

  // Control del buzzer según distancia
  if (distancia < 10) {
    //Cerca, mucho pitido
    tone(buzzer, 1000);
  }
  else if (distancia < 30) {
    // Media distancia
    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(100);
  }
  else if (distancia < 60) {
    // Lejos
    tone(buzzer, 1000);
    delay(400);
    noTone(buzzer);
    delay(400);
  }
  else {
    // Muy lejos (sin ruido)
    noTone(buzzer);
  }
}
