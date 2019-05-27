#include <IRremote.h>
 
IRrecv receptor(10);
 
decode_results resultado;
 
void setup()
{
  Serial.begin(9600);
  receptor.enableIRIn(); 
}
void loop() 
{
  if (receptor.decode(&resultado)) 
  {
    Serial.println(resultado.value, HEX);
    receptor.resume(); 
  }
  delay(100);
}
