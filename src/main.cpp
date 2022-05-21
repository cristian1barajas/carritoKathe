#include <Arduino.h>
#include "BluetoothSerial.h"

#define M1_IN1 32
#define M1_IN2 33

#define M2_IN1 25
#define M2_IN2 26

#define M3_IN1 27
#define M3_IN2 14

#define M4_IN1 12
#define M4_IN2 13

#define PWM 18
#define PWM2 19

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

int dutyCycle = 126;

BluetoothSerial SerialBT;

void setup() {
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(PWM, ledChannel);
  ledcAttachPin(PWM2, ledChannel);
  ledcWrite(ledChannel, dutyCycle);
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M3_IN1, OUTPUT);
  pinMode(M3_IN2, OUTPUT);
  pinMode(M4_IN1, OUTPUT);
  pinMode(M4_IN2, OUTPUT);
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, LOW);
  digitalWrite(M3_IN1, LOW);
  digitalWrite(M3_IN2, LOW);
  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, LOW);
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
  char letra = SerialBT.read();
  switch (letra)
  {
  case 'c':
    digitalWrite(M1_IN1, HIGH);
    digitalWrite(M2_IN1, HIGH);
    digitalWrite(M3_IN1, HIGH);
    digitalWrite(M4_IN1, HIGH);
    break;
  case 'g':
    digitalWrite(M1_IN2, HIGH);
    digitalWrite(M2_IN2, HIGH);
    digitalWrite(M3_IN2, HIGH);
    digitalWrite(M4_IN2, HIGH);
    break;
  case 'f':
    digitalWrite(M1_IN1, HIGH);
    digitalWrite(M2_IN2, HIGH);
    digitalWrite(M3_IN1, HIGH);
    digitalWrite(M4_IN2, HIGH);
    break;
  case 'd':
    digitalWrite(M1_IN2, HIGH);
    digitalWrite(M2_IN1, HIGH);
    digitalWrite(M3_IN2, HIGH);
    digitalWrite(M4_IN1, HIGH);
    break;
  case 'e':
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, LOW);
    digitalWrite(M2_IN1, LOW);
    digitalWrite(M2_IN2, LOW);
    digitalWrite(M3_IN1, LOW);
    digitalWrite(M3_IN2, LOW);
    digitalWrite(M4_IN1, LOW);
    digitalWrite(M4_IN2, LOW);
    break;
  case 'h':
    dutyCycle = 64;
    ledcWrite(ledChannel, dutyCycle);
    break;
  case 'i':
    dutyCycle = 126;
    ledcWrite(ledChannel, dutyCycle);
    break;
  case 'j':
    dutyCycle = 255;
    ledcWrite(ledChannel, dutyCycle);
    break;
  default:
    break;
  }
  }
}