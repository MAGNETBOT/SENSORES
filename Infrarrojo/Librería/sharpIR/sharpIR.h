/*
  sharpIR.h - Librería para medir distancias con el sensor: Sharp 2YA021.
  Creado por Roboteam para el MAGNETBOT, Febrero,7, 2016.
  Librería de código abierto.
*/
#ifndef sharpIR_h
#define sharpIR_h

#include "Arduino.h"

class sharpIR
{
  public:
    sharpIR(int pin);
    bool tooClose();
    double measure();
	
  private:
    const double _res = 0.0049;
	const double _poly[7]= {0.0022, - 0.0146, + 0.0313, - 0.0185, - 0.0097, + 0.0517, - 0.0063};
	int _digitalSignal=0;
	int _signalPin=0;
	double _volts=0;
	int _grado=0;
	double _horner(int grado);
};

#endif
