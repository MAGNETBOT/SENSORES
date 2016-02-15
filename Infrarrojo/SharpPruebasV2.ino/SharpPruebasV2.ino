#include <sharpIR.h>

void setup() {
  Serial.begin(9600);  

}

void loop() {
  sharpIR mySharp(0);
  double distancia = mySharp.measure();
  bool printFlag= mySharp.tooClose();
  if(!printFlag){
  Serial.print("Distancia = ");                                                        // \  Rutinas para imprimir en el monitor serial el resultado de las conversiones.
  Serial.println(distancia);                                                           // /
  }
  delay(2); 
}
