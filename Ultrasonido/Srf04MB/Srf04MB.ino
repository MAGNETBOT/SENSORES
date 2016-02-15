#include <srf04.h>

#define ECHOPIN 27                            
#define TRIGGERPIN 25 

srf04 mySrf04(TRIGGERPIN,ECHOPIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  double distance=0;
  distance = mySrf04.measure();
  //Serial.println("distancia=");
  Serial.println(distance);
}
