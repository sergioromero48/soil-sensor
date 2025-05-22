#include <Arduino.h>
#include <DHT.h>

// --- DHT Sensor Setup ---
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// --- Moisture Sensor & LEDs ---
#define red 3
#define yellow 4
#define green 5
#define moist0 A0
#define moist1 A1

void setup() {
  Serial.begin(9600);
  delay(500);

  dht.begin();

  pinMode(moist0, INPUT);
  pinMode(moist1, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  delay(1000);
}

void loop() {
  // --- DHT Readings ---
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();


  // --- Moisture Sensor Readings ---
  int moisture = analogRead(moist0);
  int moisture1 = analogRead(moist1);
  Serial.print(moisture);
  Serial.print(",");
  Serial.print(moisture1);
  Serial.print(",");

  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(",");
    Serial.print(temp);
  }
  Serial.print("\n");

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  if (moisture < 200) {
    digitalWrite(red, HIGH);     // Dry soil
  } else if (moisture < 350) {
    digitalWrite(yellow, HIGH);  // Moderate
  } else {
    digitalWrite(green, HIGH);   // Wet
  }

  delay(5000); // Wait 5 seconds before next reading
}
