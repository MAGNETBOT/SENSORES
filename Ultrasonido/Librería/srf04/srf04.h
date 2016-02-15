/*
  srf04.h - Librería para medir distancias con el sensor: srf04 de ultrasonido.
  Creado por Roboteam para el MAGNETBOT, Febrero,9, 2016.
  Librería de código abierto.
*/

#ifndef srf04_h
#define srf04_h

#include "Arduino.h"

class srf04
{
  public:
    srf04(int pin, int pin2);                     //pin= TRIGGER , pin2= ECHO.
    double measure();
  
  private:
  const double _vSound = 0.0171;
  int _trigger=0;
  int _echo=0;
};

#endif
