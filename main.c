#include <stdio.h>
#include<math.h>

//-----Prototypes------------------------//

double f(double x);                   //Equação 1
double df_first(double x);            //Primeira derivada da equação 1
double df_second(double x);           //Segunda derivada da equação 2

double bissectionMethod_f(double x);
double secantMethod_f(double x);
double newtonMethod_f(double x);
double halleyMethod_f(double x);

double g(double x);                   //Equação 2
double dg_first(double x);            //Primeira derivada da equação 2
double dg_second(double x);           //Segunda derivada da equação 2

double bissectionMethod(double x);    
double g_secantMethod(double x);
double g_newtonMethod(double x);
double g_halleyMethod(double x);

double h(double x);                   //Equação 3
double dh_first(double x);            //Primeira derivada da equação 3
double dh_second(double x);           //Segunda derivada da equação 3

double h_bissectionMethod(double x);
double h_secantMethod(double x);
double h_newtonMethod(double x);
double h_halleyMethod(double x);
//---------------------------------------//

int main(void) {
  double i;
  i = cos(2*M_PI);
  printf("%.16f\n", i);
  return 0;
}

//-----Equations-------------------------//

double f(double x){
  return (x - cos(x));
}

double g(double x){
  return (x*x*x - 9*x*x + 27*x -27);
}

double h(double x){
  return (exp(x) - cos(x));
}

double df_first(double x){
  return (1 + sin(x));
}

double dg_first(double x){
  return (3*x*x-18*x+27);
}

double dh_first(double x){
  return (exp(x) + sin(x));
}

double df_second(double x){
  return (cos(x));
}

double dg_second(double x){
  return (6*x-18);
}

double dh_second(double x){
  return (exp(x) + cos(x));
}

//------Methods-------------------------//