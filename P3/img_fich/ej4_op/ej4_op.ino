//C++ code
//
#include <Servo.h>

Servo miServo;
int boton = 7;

void setup() {
  miServo.attach(9);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(boton) == LOW) {
    miServo.write(90);  // Movimiento
  } else {
    miServo.write(0);   // Pos inicio
  }
}
