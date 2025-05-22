#include <Arduino.h>

#define red 3
#define yellow 4
#define green 5
#define moist A0

float moisture = 0.0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  moisture = analogRead(moist);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  if (moisture < 200) {
    digitalWrite(red, HIGH); // Blue
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  } else {
    if (moisture < 350) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH); // White
      digitalWrite(green, LOW);
    } else {
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(green, HIGH); // small blue
    }
  }
  Serial.print("Moisture: ");
  Serial.println(moisture);
  delay(5000); // Wait for 5 seconds
}