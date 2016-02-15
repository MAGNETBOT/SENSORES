/*
  srf04.cpp - Librería para medir distancias con el sensor: Srf04 de ultrasonido.
  Creado por Roboteam para el MAGNETBOT, Febrero,9, 2016.
  Librería de código abierto.
*/

#include "Arduino.h"
#include "srf04.h"


srf04::srf04(int pin, int pin2)
{
  pinMode(pin, OUTPUT);
  _trigger = pin;
  pinMode(pin2,INPUT);
  _echo=pin2;
}

double srf04::measure()
{
  int timePulse=0;
  double distance=0;
  digitalWrite(_trigger, LOW);                   
  delayMicroseconds(2);
  digitalWrite(_trigger, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(_trigger, LOW);                 
  timePulse = pulseIn(_echo, HIGH);        
  distance= (double)timePulse*_vSound;
  delay(50);
  return distance;
}
 
