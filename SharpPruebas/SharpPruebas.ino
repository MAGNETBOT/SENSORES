// UNIVERSIDAD SIMÓN BOLÍVAR
// CI4431: INTRODUCCIÓN A LA ROBÓTICA
// PROFESOR: CAROLINA CHANG
// *Descripción*:
// Código de pruebas, empleado para medir distancias con el sensor Infrarrojo Sharp modelo: 2Y0A21
// Se estima la distancia usando un polinomio de grado 6 que sigue la tendencia de la gráfica 1/distancia vs voltaje dada por el datasheet del sensor. (Aproximación hecha en Excel)
// Hecho por: - Iván Escalona
//            - Alejandro Guevara
//            - Jhonny Rodríguez

//Implementado en : MAGNETBOT

//***********************************************//
//               VARIABLES GLOBALES              //
//***********************************************//

const int analogInPin = A0;                                                            // Pin al cual está conectado el sensorSharp
const double res= 0.0049;                                                              // Resolución del ADC del Arduino = 5 voltios / 1024, se utiliza para convertir de bits a voltios.
double poly[]= {0.0022, - 0.0146, + 0.0313, - 0.0185, - 0.0097, + 0.0517, - 00063};    // Polinomio que conforma el modelado matemático de la curva del Sharp. CURVA-> 1/DISTANCIA VS VOLTAJE (Ver hoja de excel)
double xo=0;                                                                           // Variable usada para evaluar el polinomio en la lectura de ADC deseada. (USADO POR LA FUNCION HORNER)
int SharpIR = 0;                                                                       // Variable que alberga la magnitud de la medida en bits.
double distancia;                                                                      // Variable destinada a guardar el valor final del cálculo de las distancias
double ajuste=2; //                                                                    // Párametro de ajuste se utiliza para acomodar las mediciones. (No se está usando)

void setup() {
                                                                                      
  Serial.begin(9600);                                                                  // Inicializa la comunicación serial a 9600 baudios (Comunicación con el monitor serial)
}

//***********************************************//
//             RUTINA PRINCIPAL                  //
//***********************************************//

void loop() {
  SharpIR = analogRead(analogInPin);                                                   //Tomamos el valor digital del SHARP IR
  xo = (double)SharpIR*res;                                                            //Tomamos el valor con el cual estimaremos la distancia (SharpIR -> Bits ,res-> voltios/bits, xo-> voltios
  if(xo>3.0){                                                                          //Caso especial: Para una señal menor a 3 voltios el valor de la distancia deducible es ambiguo. Se dejará en cero para indicar que es muy cerca.
    distancia = 0;
  }
  else{                                                                                //Se calcula con Horner el inverso de la distancia correspondiente al voltaje medido, luego se invierte.
    distancia = Horner(6);
    distancia = (1/distancia)- ajuste;                                                 //Se obtiene el valor de la distancia. La variable ajuste se introduce para calibrar el error de los resultados
  {
  Serial.print("Distancia = ");                                                        // \  Rutinas para imprimir en el monitor serial el resultado de las conversiones.
  Serial.println(distancia);                                                           // /
  delay(2);                                                                            // Retardo al final de Loop para darle tiempo al microcontrolador de adquirir la próxima señal del sensor.
}


//***********************************************//
//                   FUNCIONES                   //
//***********************************************//

double Horner(int grado){                                                              // Algoritmo de Horner para evaluar el polinomio eficientemente. (RECURSIVO)
    int n= grado;
    double b= 0;
    if(n==0){
        return poly[n];
    }
    else{
        b= poly[n]+ xo*Horner(n-1);
        return b;
    }
}

