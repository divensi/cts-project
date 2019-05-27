#include "ACS712.h"
#include "DHT.h"
#define DHTPIN 2
#define DHTPIN2 4
#define DHTTYPE DHT11   // DHT 11
#include <IRremote.h>
ACS712 sensor(ACS712_30A, A0);
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
IRsend irsend;
int tempTeste = 23;
unsigned int irSignalTurnOn[] = {8950,4450, 600,550, 550,550, 600,500, 550,600, 550,550, 600,500, 550,600, 550,550, 600,500, 600,550, 550,1650, 600,1650, 600,1650, 550,1650, 600,1650, 600,1600, 600,1650, 550,600, 550,1650, 550,600, 550,550, 600,500, 550,600, 550,1650, 550,600, 550,1650, 550,600, 550,1650, 550,1700, 550,1700, 550,1650, 550,600, 550,41850, 8950,2200, 600};
unsigned int irSignalTurnUp[] = {8950,4450, 600,550, 600,1650, 550,1650, 600,1650, 600,1600, 600,1650, 550,600, 550,1650, 550,600, 550,550, 600,500, 550,600, 550,1650, 550,600, 550,1650, 550,600, 550,1650, 550,1700, 550,1700, 550,1650, 550,600, 550,41850, 8950,2200,550,550, 600,500, 550,600, 550,550, 600,500, 550,600, 550,550, 600,500, 600,550, 550,1650, 600,1650, 600};
 
void setup() {
  // É necessário calibrar o sensor antes de usar a primeira vez com o método abaixo
  Serial.begin(9600);
  sensor.calibrate();
  dht.begin();
  dht2.begin();
  ligaDesliga();
}
 
void loop() {
  // A frequência da corrente alternada no Brasil é 60 Hz. Mude caso necessário
  // A voltagem, no meu caso é 127
  delay(1000);
  float V = 220;
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
 if(t<tempTeste){
  tempTeste--;
  desceTemp();
  delay(1000);   
 }
 
 Serial.println(String("")+ (I) + String(",") + P + String(",") + t + String(",") + t2 + String(",")+ tempTeste + String(".0"));
}

void ligaDesliga() {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(irSignalTurnOn, 32);
  }
}

void desceTemp() {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(irSignalTurnUp, 32);
  }
}
