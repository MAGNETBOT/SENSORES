/*
  sharpIR.cpp - Librería para medir distancias con el sensor: Sharp 2YA021.
  Creado por Roboteam para el MAGNETBOT, Febrero,7, 2016.
  Librería de código abierto.
*/

#include "Arduino.h"
#include "sharpIR.h"


sharpIR::sharpIR(int pin)
{
  pinMode(pin, INPUT);
  _signalPin = pin;
  _grado=6;
  
}

double sharpIR::_horner(int grado){
  int n= grado;
  double b= 0;
    if(n==0){
        return _poly[n];
    }
    else{
        b= _poly[n]+ _volts*_horner(n-1);
        return b;
    }
}

bool sharpIR::tooClose()
{
  _digitalSignal=analogRead(_signalPin);
  _volts= (double)_digitalSignal*_res;
  if(_volts>3.0){                                                                         
   return true;
  }
  else return false;
}

double sharpIR::measure()
{
  _digitalSignal=analogRead(_signalPin);
  _volts= (double)_digitalSignal*_res;
  if(_volts>3.0){                                                                      
   return 0;
  }
  else{
    _volts = _horner(_grado);
    _volts = 1/_volts;
    return _volts;
  }
 }

  


