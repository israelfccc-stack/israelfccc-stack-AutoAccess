#include <Servo.h>

const int pinPIR = 2;
const int pinServo = 9;
const int pinLedVerde = 3;
const int pinLedRojo = 4;
const int pinBuzzer = 5;

Servo barreraServo;

void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedRojo, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  barreraServo.attach(pinServo);
  
  barreraServo.write(0);
  digitalWrite(pinLedRojo, HIGH);
  digitalWrite(pinLedVerde, LOW);
  digitalWrite(pinBuzzer, LOW);

  Serial.begin(9600);
}

void loop() {
  int estadoPIR = digitalRead(pinPIR);

  if (estadoPIR == HIGH) {
    Serial.println("¡Vehículo detectado! Abriendo barrera...");

    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde, HIGH);
    tone(pinBuzzer, 1000);

    barreraServo.write(90);

    delay(5000);

    barreraServo.write(0);

    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedRojo, HIGH);
    noTone(pinBuzzer);

    Serial.println("Barrera cerrada. Esperando nuevo vehículo...");
    
    delay(1000);
  }
}