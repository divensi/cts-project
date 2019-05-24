#include "ACS712.h"
#include "DHT.h"
#define DHTPIN 2
#define DHTPIN2 3
#define DHTTYPE DHT11   // DHT 11
ACS712 sensor(ACS712_30A, A0);
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
 
void setup() {
  // É necessário calibrar o sensor antes de usar a primeira vez com o método abaixo
  Serial.begin(9600);
  sensor.calibrate();
  dht.begin();
  dht2.begin();
}
 
void loop() {
  // A frequência da corrente alternada no Brasil é 60 Hz. Mude caso necessário
  // A voltagem, no meu caso é 127
  delay(1000);
  float V = 127;
  float I = sensor.getCurrentAC(60);
  float P = V * I;
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
// 
//  Serial.println(String("Corrente = ") + I + " A");
//  Serial.println(String("Potência  = ") + P + " Watts");
 I = I ;
 
 P = P ;
 
 Serial.println(String("")+ (I) + String(",") + P + String(",") + t + String(",") + t2 );
}
