#include <sharpIR.h>

sharpIR mySharp(15); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  double medida = mySharp.measure();
  bool flag= mySharp.tooClose();
  if(!flag){
      Serial.println(medida);
    }
  delay(20);

}
