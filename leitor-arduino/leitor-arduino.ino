// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 2
#define DHTPIN2 3
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  dht2.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  if (isnan(h) || isnan(t) || isnan(h2) || isnan(t2)  ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  float hic2 = dht2.computeHeatIndex(t2, h2, false);
  Serial.print(F("Humidity(1): "));
  Serial.print(h);
  Serial.print(F("%  Temperature(1): "));
  Serial.print(t);
  Serial.print(F("Humidity(2): "));
  Serial.print(h2);
  Serial.print(F("%  Temperature(2): "));
  Serial.print(t2);
  Serial.print(("\n"));
}
