  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>

  //-----Protótipos------------------------//
  double f(double x, int i);                                                          //Equação 1

  int f_bissection_method(double a, double b, double* bissection_results);           //Método de Bissecção aplicado à equação 1
  int f_secant_method(double x0, double x1, double* secant_results);                 //Método de Secante aplicado à equação 1
  int f_newton_method(double x, double* newton_results);                             //Método de Newton aplicado à equação 1
  int f_halley_method(double x, double* halley_results);                             //Método de Halley aplicado à equação 1
  //---------------------------------------//
  double g(double x, int i);                                                         //Equação 2

  int g_bissection_method(double a, double b, double* bissection_results);           //Método de Bissecção aplicado à equação 2
  int g_secant_method(double x0, double x1, double* secant_results);                 //Método de Secante aplicado à equação 2
  int g_newton_method(double x, double* newton_results);                             //Método de Newton aplicado à equação 2
  int g_halley_method(double x, double* halley_results);                             //Método de Halley aplicado à equação 2
  //---------------------------------------//
  double h(double x, int i);                                                         //Equação 3

  int h_bissection_method(double a, double b, double* bissection_results);           //Método de Bissecçãoaplicado à equação 3
  int h_secant_method(double x0, double x1, double* secant_results);                 //Método de Secante aplicado à equação 3
  int h_newton_method(double x, double* newton_results);                             //Método de Newton aplicado à equação 3
  int h_halley_method(double x, double* halley_results);                             //Método de Halley aplicado à equação 3

  //---------------------------------------//

  const char* concatena_linha(double* bissection_results, int tamanho_bissection,double* secant_results, int tamanho_secant,double* newton_results,int tamanho_newton, double* halley_results,int tamanho_halley, int i);

  int main(void) {
    //Declaração de variáveis
    int i, tamanho1,tamanho2,tamanho3,tamanho4;
    double a, b;
    double bissection_results[60];
    double secant_results[50];
    double newton_results[50];
    double halley_results[20];

    FILE *fp;
    fp=fopen("resultados.txt", "w+");

    //--------Método da Bissecção------------------------------------//
    //A função retorna o tamanho do vetor bissection_results após fazer o cálculo da raiz
    printf("Metodo da Bisseccao:\n");
    printf("Equacao 1:\n");
    tamanho1 = f_bissection_method(0, 2, bissection_results);
    for(i=0;i<tamanho1;i++){
      //printf("x:%.16f i:%d\n", bissection_results[i], i);
      fprintf(fp,"x:%.16f i:%d\n", bissection_results[i], i);
    }
    //--------Método da Secante----------------------------------------//
    printf("\nMetodo da Secante:\n");
    printf("Equacao 1:\n");
    tamanho2 = f_secant_method(0, 2, secant_results);
    for(i=0;i<tamanho2;i++){
      printf("x:%.16f i:%d\n", secant_results[i], i);
    }
     //--------Método de Newton----------------------------------------//
    printf("\nMetodo de Newton:\n");
    printf("Equacao 1:\n");
    tamanho3 = f_newton_method(1, newton_results);
    for(i=0;i<tamanho3;i++){
      printf("x:%.16f i:%d\n", newton_results[i], i);
    }
   //--------Método de Halley----------------------------------------//
    printf("\nMetodo de Halley:\n");
    printf("Equacao 1:\n");
     tamanho4 = f_halley_method(1, halley_results);
    for(i=0;i<tamanho4;i++){
      printf("x:%.16f i:%d\n", halley_results[i], i);
    }
    //puts(concatena_linha(bissection_results, tamanho1, secant_results, tamanho2, newton_results, tamanho3, halley_results, tamanho4, 2));
    concatena_linha(bissection_results, tamanho1, secant_results, tamanho2, newton_results, tamanho3, halley_results, tamanho4, 2);
    char teste[]="teste";
    puts(teste);
    printf("You entered %s",teste);  
    return 0;
  }

  //-----Equações-------------------------//
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
    } while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001); 
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
    } while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001);
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
    } while(fabs(bissection_results[i]-bissection_results[i-1]) > 0.000000000000001);
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
    } while(fabs(secant_results[i]-secant_results[i-1]) > 0.000000000000001);
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
    } while(fabs(secant_results[i]-secant_results[i-1]) > 0.000000000000001);
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
    } while(fabs(secant_results[i]-secant_results[i-1]) > 0.000000000000001);
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
    } while(fabs(newton_results[i]-newton_results[i-1]) > 0.000000000000001);
    i++;
    return i; 
  }

  int g_newton_method(double x, double* newton_results){
    newton_results[0] = x;

    int i = 0;
    do{
      i++;
      newton_results[i]= (newton_results[i-1] - (g(newton_results[i-1],0)/g(newton_results[i-1],1)));
    } while(fabs(newton_results[i]-newton_results[i-1]) > 0.000000000000001);
    i++;
    return i; 
  }

  int h_newton_method(double x, double* newton_results){
        newton_results[0] = x;

    int i = 0;
    do{
      i++;
      newton_results[i]= (newton_results[i-1] - (h(newton_results[i-1],0)/h(newton_results[i-1],1)));
    } while(fabs(newton_results[i]-newton_results[i-1]) > 0.000000000000001);
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
    } while(fabs(halley_results[i]-halley_results[i-1]) > 0.000000000000001);
    i++;
    return i; 
  }

  int g_halley_method(double x, double* halley_results){
    halley_results[0] = x;
    int i = 0;
    do{
      i++;
      halley_results[i] = (halley_results[i-1]-(g(halley_results[i-1],0)*g(halley_results[i-1],1))/(g(halley_results[i-1],1)*g(halley_results[i-1],1)-0.5*g(halley_results[i-1],0)*g(halley_results[i-1],2))); 
    } while(fabs(halley_results[i]-halley_results[i-1]) > 0.000000000000001);
    i++;
    return i; 
  }

  int h_halley_method(double x, double* halley_results){
    halley_results[0] = x;
    int i = 0;
    do{
      i++;
      halley_results[i] = (halley_results[i-1]-(h(halley_results[i-1],0)*h(halley_results[i-1],1))/(h(halley_results[i-1],1)*h(halley_results[i-1],1)-0.5*h(halley_results[i-1],0)*h(halley_results[i-1],2))); 
    } while(fabs(halley_results[i]-halley_results[i-1]) > 0.000000000000001);
    i++;
    return i; 
  }
  //---------------------------------------//
  const char* concatena_linha(double* bissection_results, int tamanho_bissection,double* secant_results, int tamanho_secant,double* newton_results,int tamanho_newton, double* halley_results,int tamanho_halley, int i){
    char* saida = (char *) malloc(sizeof(char ) * 80);
    char aux[17];
    strcpy(saida, ";"); 
    printf("1");
    if(i <= tamanho_bissection){
      sprintf(aux, "%.16f;", bissection_results[i]);
      strcpy(saida, aux); 
    }else{
      strcpy(saida, ";"); 
    }
    if(i <= tamanho_secant){
      sprintf(aux, "%.16f;", secant_results[i]);
      strcpy(saida, aux); 
    }else{
      strcpy(saida, ";");
    }
    if(i <= tamanho_newton){
      sprintf(aux, "%.16f;", newton_results[i]);
      strcpy(saida, aux); 
    }else{
      strcpy(saida, ";");
    }
    if(i <= tamanho_halley){
      sprintf(aux, "%.16f;", newton_results[i]);
      strcpy(saida, aux); 
    }else{
      strcpy(saida, ";");
    }
    printf("3");
    puts(saida);
    printf("4");
    return saida;
  }