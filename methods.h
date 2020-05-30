#ifndef _METHODS_H_
#define _METHODS_H_
#include <stdio.h>
#include <math.h>

int f_bissection_method(double a, double b, double* bissection_results);           //Método de Bissecção aplicado à equação 1
int f_secant_method(double x0, double x1, double* secant_results);                 //Método de Secante aplicado à equação 1
int f_newton_method(double x, double* newton_results);                             //Método de Newton aplicado à equação 1
int f_halley_method(double x, double* halley_results);                             //Método de Halley aplicado à equação 1
//---------------------------------------//                                                   

int g_bissection_method(double a, double b, double* bissection_results);           //Método de Bissecção aplicado à equação 2
int g_secant_method(double x0, double x1, double* secant_results);                 //Método de Secante aplicado à equação 2
int g_newton_method(double x, double* newton_results);                             //Método de Newton aplicado à equação 2
int g_halley_method(double x, double* halley_results);                             //Método de Halley aplicado à equação 2
//---------------------------------------//                                                      

int h_bissection_method(double a, double b, double* bissection_results);           //Método de Bissecçãoaplicado à equação 3
int h_secant_method(double x0, double x1, double* secant_results);                 //Método de Secante aplicado à equação 3
int h_newton_method(double x, double* newton_results);                             //Método de Newton aplicado à equação 3
int h_halley_method(double x, double* halley_results);                             //Método de Halley aplicado à equação 3

#endif