#include <stdio.h>
#include<math.h>

//-----Protótipos------------------------//
double f(double x);                                                               //Equação 1
double df_first(double x);                                                        //Primeira derivada da equação 1
double df_second(double x);                                                       //Segunda derivada da equação 2

//---------------------------------------//
double g(double x);                                                               //Equação 2
double dg_first(double x);                                                        //Primeira derivada da equação 2
double dg_second(double x);                                                       //Segunda derivada da equação 2

//---------------------------------------//
double h(double x);                                                               //Equação 3
double dh_first(double x);                                                        //Primeira derivada da equação 3
double dh_second(double x);                                                       //Segunda derivada da equação 3

double bissectionMethod(double x);  //Método de Bissecção aplicado à equação 1
double secantMethod(double x);      //Método de Secante aplicado à equação 1
double newtonMethod(double x, double function(), double dFunction_first());       //Método de Newton 
double halleyMethod(double x);      //Método de Halley aplicado à equação 1

//---------------------------------------//

int main(void) {
  double i;
  i = cos(2*M_PI);
  printf("%.16f\n", i);
  return 0;
}

//-----Equações-------------------------//

double f(double x){
  return (x - cos(x));
}

double df_first(double x){
  return (1 + sin(x));
}

double df_second(double x){
  return (cos(x));
}

double g(double x){
  return (x*x*x - 9*x*x + 27*x -27);
}

double dg_first(double x){
  return (3*x*x-18*x+27);
}

double dg_second(double x){
  return (6*x-18);
}

double h(double x){
  return (exp(x) - cos(x));
}

double dh_first(double x){
  return (exp(x) + sin(x));
}

double dh_second(double x){
  return (exp(x) + cos(x));
}

//------Métodos-------------------------//
double newtonMethod(double x, double function(), double dFunction_first()){
  return (x -(function(x)/dFunction_first(x)));
}




//while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001

