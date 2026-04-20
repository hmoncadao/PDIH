// C++ code
//
int ledRojo = 12;
int ledAmarillo = 11;
int ledVerde = 13;
int interruptor = 7;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pinMode(interruptor, INPUT_PULLUP);
}

void loop() {
  int estado = digitalRead(interruptor);

  if (estado == LOW) {  
    //Si está el botón pulsado solo Rojo
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
  } 
  else {
    digitalWrite(ledRojo, LOW);

    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
    delay(1500);

    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    delay(1500);
  }
}
