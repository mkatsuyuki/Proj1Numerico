  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "equations.h"
  #include "methods.h"

//----Hey----//cls


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
    fp=fopen("resultados1.csv", "w+");
    //--------Equação 1------------------------------------//
    //A função retorna o tamanho do vetor bissection_results após fazer o cálculo da raiz
    tamanho1 = f_bissection_method(0, 2, bissection_results); //Execução do método de bissecção aplicado na equação 1
    tamanho2 = f_secant_method(0, 2, secant_results);         //Execução do método de secante aplicado na equação 1
    tamanho3 = f_newton_method(1, newton_results);            //Execução do método de newton aplicado na equação 1
    tamanho4 = f_halley_method(1, halley_results);            //Execução do método de halley aplicado na equação 1

    fprintf(fp, "i;Bissection;Section;Newton;Halley\n");
    for(i = 0; i < 52 ; i++){
      fprintf(fp, "%s\n", concatena_linha(bissection_results, tamanho1, secant_results, tamanho2, newton_results, tamanho3, halley_results, tamanho4, i));
    }
    fclose(fp);


    fp=fopen("resultados2.csv", "w+");
    //--------Equação 2------------------------------------//
    //A função retorna o tamanho do vetor bissection_results após fazer o cálculo da raiz
    tamanho1 = g_bissection_method(1, 6, bissection_results); //Execução do método de bissecção aplicado na equação 1
    tamanho2 = g_secant_method(1, 5, secant_results);         //Execução do método de secante aplicado na equação 1
    tamanho3 = g_newton_method(2, newton_results);            //Execução do método de newton aplicado na equação 1
    tamanho4 = g_halley_method(2, halley_results);            //Execução do método de halley aplicado na equação 1

     printf("\n\n/---------------/\n\n");
    for(i=0;i<tamanho4;i++){
      printf("x:%.16f i:%d\n", halley_results[i], i);
    }
    printf("\n\n/------------------/\n\n");

    fprintf(fp, "i;Bissection;Section;Newton;Halley\n");
    for(i = 0; i < 52 ; i++){
      fprintf(fp, "%s\n", concatena_linha(bissection_results, tamanho1, secant_results, tamanho2, newton_results, tamanho3, halley_results, tamanho4, i));
    }
    fclose(fp);

    fp=fopen("resultados3.csv", "w+");
    //--------Equação 3------------------------------------//
    //A função retorna o tamanho do vetor bissection_results após fazer o cálculo da raiz
    tamanho1 = h_bissection_method(-1, 2, bissection_results); //Execução do método de bissecção aplicado na equação 1
    tamanho2 = h_secant_method(1, 2, secant_results);         //Execução do método de secante aplicado na equação 1
    tamanho3 = h_newton_method(1, newton_results);            //Execução do método de newton aplicado na equação 1
    tamanho4 = h_halley_method(1, halley_results);            //Execução do método de halley aplicado na equação 1
    


    fprintf(fp, "i;Bissection;Section;Newton;Halley\n");
    for(i = 0; i < 52 ; i++){
      fprintf(fp, "%s\n", concatena_linha(bissection_results, tamanho1, secant_results, tamanho2, newton_results, tamanho3, halley_results, tamanho4, i));
    }
    fclose(fp);
    

    return 0;
  }

  //---------------------------------------//
  const char* concatena_linha(double* bissection_results, int tamanho_bissection,double* secant_results, int tamanho_secant,double* newton_results,int tamanho_newton, double* halley_results,int tamanho_halley, int i){
    char* saida = (char *) malloc(sizeof(char ) * 80);
    char* aux = (char *) malloc(sizeof(char ) * 17);
    sprintf(saida, "%d;", i);
    if(i < tamanho_bissection){
      sprintf(aux, "%.16f;", bissection_results[i]);
      strcat(saida, aux);
    }else{
      strcat(saida, ";"); 
    }
    if(i < tamanho_secant){
      sprintf(aux, "%.16f;", secant_results[i]);
      strcat(saida, aux); 
    }else{
      strcat(saida, ";");
    }
    if(i < tamanho_newton){
      sprintf(aux, "%.16f;", newton_results[i]);
      strcat(saida, aux); 
    }else{
      strcat(saida, ";");
    }
    if(i < tamanho_halley){
      sprintf(aux, "%.16f", halley_results[i]);
      strcat(saida, aux); 
    }else{
      strcat(saida, ";");
    }
    puts(saida);
    return saida;
  }