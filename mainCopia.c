#include <stdio.h>
#include<math.h>

double function1(double x);
double function2(double x);
double function3(double x);
double dfunction1(double x);
double dfunction2(double x);
double dfunction3(double x);
double ddfunction1(double x);
double ddfunction2(double x);
double ddfunction3(double x);

//--------------------------------------//

int main(void) {
  double i;
  i = cos(2*M_PI);
  printf("%f\n", i);
  return 0;
}

double function1(double x){
  return (x - cos(x));
}

double function2(double x){
  return (x*x*x - 9*x*x + 27*x -27);
}

double function3(double x){
  return (exp(x) - cos(x));
}

double dfunction1(double x){
  return (1 + sin(x));
}

double dfunction2(double x){
  return (3*x*x-18*x+27);
}

double dfunction3(double x){
  return (exp(x) + sin(x));
}

double ddfunction1(double x){
  return (cos(x));
}

double ddfunction2(double x){
  return (6*x-18);
}

double ddfunction3(double x){
  return (exp(x) + cos(x));
}