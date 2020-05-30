#include "equations.h"

/*
  @parâmetros 
              x 
              i ordem da derivada:
                0 - Função original
                1 - Primeira derivada
                2 - Segunda derivada
*/

  double f(double x, int i){
    switch (i){
        case 0:
          return (x - cos(x));

        case 1:
          return (1 + sin(x));

        case 2:
          return (cos(x));

        default:
          return -1;
    }
  }

  double g(double x, int i){
    switch (i){
        case 0:
          return (x*x*x - 9*x*x + 27*x -27);

        case 1:
          return (3*x*x-18*x+27);

        case 2:
          return (6*x-18);

        default:
          return -1;
    }
  }
  double h(double x, int i){
    switch (i){
        case 0:
          return (exp(x) - cos(x));

        case 1:
          return (exp(x) + sin(x));

        case 2:
          return (exp(x) + cos(x));

        default:
          return -1;
    }
  }