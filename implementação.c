    //--------Método da Bissecção------------------------------------//
    //A função retorna o tamanho do vetor bissection_results após fazer o cálculo da raiz
    FILE *fp;
    fp=fopen("resultados.txt", "w+");

    printf("Metodo da Bisseccao:\n");
    printf("Equacao 1:\n");
    tamanho = f_bissection_method(0, 2, bissection_results);

    for(i=0;i<tamanho;i++){
      //printf("x:%.16f i:%d\n", bissection_results[i], i);
      fprintf(fp,"x:%.16f i:%d\n", bissection_results[i], i);
    }
    fclose(fp);
    
    printf("\nEquacao 2:\n");
    tamanho = g_bissection_method(1, 6, bissection_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", bissection_results[i], i);
    }
    
    
    printf("\nEquacao 3:\n");
    tamanho = h_bissection_method(-1, 2, bissection_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", bissection_results[i], i);
    }
    
    //--------Método da Secante----------------------------------------//
    printf("\nMetodo da Secante:\n");
    printf("Equacao 1:\n");
    tamanho = f_secant_method(0, 2, secant_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", secant_results[i], i);
    }
    
    
    printf("\nEquacao 2:\n");
    tamanho = g_secant_method(1, 5, secant_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", secant_results[i], i);
    }
    
    
    printf("\nEquacao 3:\n");
    tamanho = h_secant_method(1, 2, secant_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", secant_results[i], i);
    }
    
     //--------Método de Newton----------------------------------------//
    printf("\nMetodo de Newton:\n");
    printf("Equacao 1:\n");
    tamanho = f_newton_method(1, newton_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", newton_results[i], i);
    }
    
    
    printf("\nEquacao 2:\n");
    tamanho = g_newton_method(2, newton_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", newton_results[i], i);
    }
    
    
    printf("\nEquacao 3:\n");
    tamanho = h_newton_method(1, newton_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", newton_results[i], i);
    }
    
   //--------Método de Halley----------------------------------------//
    printf("\nMetodo de Halley:\n");
    printf("Equacao 1:\n");
     tamanho = f_halley_method(1, halley_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", halley_results[i], i);
    }
    
    
    printf("Equacao 2:\n");
     tamanho = g_halley_method(2, halley_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", halley_results[i], i);
    }
    
    
    printf("Equacao 3:\n");
     tamanho = h_halley_method(1, halley_results);
    for(i=0;i<tamanho;i++){
      printf("x:%.16f i:%d\n", halley_results[i], i);
    }