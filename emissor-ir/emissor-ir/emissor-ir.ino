#include <IRremote.h>

IRrecv receptor(10);
 
decode_results resultado;

IRsend irsend;

void setup() {
  Serial.begin(9600);
  receptor.enableIRIn(); 
}

void loop() {
  char comando = Serial.read();
  ligaDesliga();
  if (comando == 'S')
      sobeCanal();
  else if (comando == 'D')
      desceCanal();
  leitura();
  
}

//Envia o comando LIGA com 32 bits utilizando protocolo NEC
void ligaDesliga() {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0x165B6CED, 32);
    Serial.println("EMITINDO");
  }
}
void leitura(){
  if (receptor.decode(&resultado)) 
  {
    Serial.println(resultado.value, HEX);
    receptor.resume(); 
  }
  delay(100);
}

//Envia o comando SOBE CANAL com 32 bits utilizando protolo NEC
void sobeCanal() {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0xE17A08F7, 32);
  }
}
//Envia o comando DESCE CANAL com 32 bits utilizando protocolo NEC
void desceCanal() {
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0xE17A58A7, 32);
  }
}
