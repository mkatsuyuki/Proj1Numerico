#include "methods.h"
#include "equations.h"
//extern double f(double x, int i); 
//extern double g(double x, int i); 
//extern double h(double x, int i); 

//------Métodos-------------------------//
//A função do método da bisseção recebe os valores a e b do intervalo onde será encontrado a raiz
//A função também recebe o vetor para guardar os valores de cada iteração

double bissection(double* a, double* b, double fa, double fx){
  double x = (*a+*b)/2;
  if(fa*fx < 0){
    *b = x;
  }  
  else{
    *a = x;
  }
  return x;
}

int f_bissection_method(double a, double b, double* bissection_results){
  int i = 0;

  //É necessário realizar o calculo do primeiro valor para poder calcular a tolerância utilizada no cálculo de parada 
  bissection_results[i] = bissection(&a, &b, f(a, 0), f((a+b)/2, 0));
  do
  {
    i++;
    bissection_results[i] = bissection(&a, &b, f(a, 0), f((a+b)/2, 0));
  } while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i;
}

int g_bissection_method(double a, double b, double* bissection_results){
  int i = 0;

  //É necessário realizar o calculo do primeiro valor para poder calcular a tolerância utilizada no cálculo de parada 
  bissection_results[i] = bissection(&a, &b, g(a, 0), g((a+b)/2, 0));
  do
  {
    i++;
    bissection_results[i] = bissection(&a, &b, g(a, 0), g((a+b)/2, 0));
  } while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i;
}

int h_bissection_method(double a, double b, double* bissection_results){
  int i = 0;

  //É necessário realizar o calculo do primeiro valor para poder calcular a tolerância utilizada no cálculo de parada 
  bissection_results[i] = bissection(&a, &b, h(a, 0), h((a+b)/2, 0));
  do
  {
    i++;
    bissection_results[i] = bissection(&a, &b, h(a, 0), h((a+b)/2, 0));
  } while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i;
}
//--------------------------------------//
int f_secant_method(double x0, double x1, double* secant_results){
  secant_results[0] = x0;
  secant_results[1] = x1;
  int i = 1;
  do{
    i++;
    secant_results[i] = ((secant_results[i-2]*f(secant_results[i-1],0) - secant_results[i-1]*f(secant_results[i-2],0))/(f(secant_results[i-1],0) - f(secant_results[i-2],0)));
  } while(fabs(secant_results[i]-secant_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

int g_secant_method(double x0, double x1, double* secant_results){
  secant_results[0] = x0;
  secant_results[1] = x1;
  int i = 1;
  do{
    i++;
    //secant_results[i] = ((secant_results[i-2]*g(secant_results[i-1],0) - secant_results[i-1]*g(secant_results[i-2],0))/(g(secant_results[i-1],0) - g(secant_results[i-2],0)));
    secant_results[i] = (secant_results[i-1]-g(secant_results[i-1],0)*((secant_results[i-1]-secant_results[i-2])/(g(secant_results[i-1],0)-g(secant_results[i-2],0)))); 
  } while(fabs(secant_results[i]-secant_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

int h_secant_method(double x0, double x1, double* secant_results){
  secant_results[0] = x0;
  secant_results[1] = x1;
  int i = 1;
  do{
    i++;
    //secant_results[i] = ((secant_results[i-2]*h(secant_results[i-1],0) - secant_results[i-1]*h(secant_results[i-2],0))/(h(secant_results[i-1],0) - h(secant_results[i-2],0)));
    secant_results[i] = (secant_results[i-1]-h(secant_results[i-1],0)*((secant_results[i-1]-secant_results[i-2])/(h(secant_results[i-1],0)-h(secant_results[i-2],0)))); 
  } while(fabs(secant_results[i]-secant_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

//--------------------------------------//
int f_newton_method(double x, double* newton_results){
  newton_results[0] = x;

  int i = 0;
  do{
    i++;
    newton_results[i]= (newton_results[i-1] - (f(newton_results[i-1],0)/f(newton_results[i-1],1)));
  } while(fabs(newton_results[i]-newton_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

int g_newton_method(double x, double* newton_results){
  newton_results[0] = x;

  int i = 0;
  do{
    i++;
    newton_results[i]= (newton_results[i-1] - (g(newton_results[i-1],0)/g(newton_results[i-1],1)));
  } while(fabs(newton_results[i]-newton_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

int h_newton_method(double x, double* newton_results){
      newton_results[0] = x;

  int i = 0;
  do{
    i++;
    newton_results[i]= (newton_results[i-1] - (h(newton_results[i-1],0)/h(newton_results[i-1],1)));
  } while(fabs(newton_results[i]-newton_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
  //return (x -(h(x,0)/h(x,1)));
}
//---------------------------------------//
int f_halley_method(double x, double* halley_results){
  halley_results[0] = x;
  int i = 0;
  do{
    i++;
    halley_results[i] = (halley_results[i-1]-(f(halley_results[i-1],0)*f(halley_results[i-1],1))/(f(halley_results[i-1],1)*f(halley_results[i-1],1)-0.5*f(halley_results[i-1],0)*f(halley_results[i-1],2))); 
  } while(fabs(halley_results[i]-halley_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

int g_halley_method(double x, double* halley_results){
  halley_results[0] = x;
  int i = 0;
  do{
    i++;
    halley_results[i] = (halley_results[i-1]-(g(halley_results[i-1],0)*g(halley_results[i-1],1))/(g(halley_results[i-1],1)*g(halley_results[i-1],1)-0.5*g(halley_results[i-1],0)*g(halley_results[i-1],2))); 
  } while(fabs(halley_results[i]-halley_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}

int h_halley_method(double x, double* halley_results){
  halley_results[0] = x;
  int i = 0;
  do{
    i++;
    halley_results[i] = (halley_results[i-1]-(h(halley_results[i-1],0)*h(halley_results[i-1],1))/(h(halley_results[i-1],1)*h(halley_results[i-1],1)-0.5*h(halley_results[i-1],0)*h(halley_results[i-1],2))); 
  } while(fabs(halley_results[i]-halley_results[i-1]) > 0.000000000000001); //Condição de parada, |xk - xk-1| > 10^15. Ou seja, assim que tal diferença atingir a ordem de 10^-16 o algoritmo para.
  i++;
  return i; 
}