#include "ACS712.h"
 
// Estou usando ACS de 30A. Mude para o modelo que está usando. Valores possíveis: 5,20 e 30
// Sensor ligado na porta analópgica A0
ACS712 sensor(ACS712_30A, A0);
 
void setup() {
  // É necessário calibrar o sensor antes de usar a primeira vez com o método abaixo
  Serial.begin(9600);
  sensor.calibrate();
}
 
void loop() {
  // A frequência da corrente alternada no Brasil é 60 Hz. Mude caso necessário
  // A voltagem, no meu caso é 127
  delay(1000);
  float V = 127;
  float I = sensor.getCurrentAC(60);
  float P = V * I;
// 
//  Serial.println(String("Corrente = ") + I + " A");
//  Serial.println(String("Potência  = ") + P + " Watts");
 I = I ;
 
 P = P ;
 
 Serial.println(String("")+ (I) + String(",") + P);
}
