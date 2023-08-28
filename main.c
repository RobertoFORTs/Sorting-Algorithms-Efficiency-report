#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"


int main(){
    // "menu"
    //------------------------------------------------------------
    // declaração de variáveis que serão necessárias para execução
    int inc, fim, stp, rpt;
    printf("Digite o tamanho inicial, final, intervalo e número de repetições desejadas, repectivamente: \n");
    scanf("%d %d %d %d", &inc, &fim, &stp, &rpt);
    int i = 0;
    int j = 0;
    int aux;
    int quantidadeDeN = (fim - inc)/stp;
    int n = inc;
    srand(time(NULL));
    float somaMerge;

    //---------------------------------------------------------
    //Primeiro Caso (execução dos processos repetidas vezes)
    printf("Primeiro caso, Vetor preenchido aleatóriamente:\n");
    printf("            Mergesort");
    while (i <= quantidadeDeN && n <= fim){
        
        j = 0; //controla a quantidade de repetições para cada caso de teste
        
        int *v = malloc(n* sizeof(int)); // alocando vetor de tamanho n 
        
        for (aux = 0; aux < n; aux++){ //preencher vetor
            int x = rand();
            if (x >= 0)
                v[aux] = x;
            
        }

        while (j < rpt){ //realizar operações com vetor atual
            
            clock_t mergeBegin = clock();
            insertionSort(n, v);
            clock_t mergeEnd = clock();
            
            //obter soma dos tempos de execução para cada algorítimo
            somaMerge = somaMerge + ((float)mergeEnd - (float)mergeBegin) / 1000000.0F;

            j++;
        }
        //calcular media para cada n e exibir
        float mediaMerge = somaMerge/rpt;
        
        printf("\nn:%d        %f\n", n, mediaMerge);
        free(v); //liberando vetor
        n = n + stp;
        i++;
    }
    
    //---------------------------------------------------------------
    // Para os restante dos casos, utilizar os mesmos valores de entrada, porém com apenas uma execução para cada vetor de tamanho n
    
    i = 0;
    printf("Segundo caso\n");
    while (i < quantidadeDeN){

        i++;
    }

    //---------------------------------------
    i = 0;
    printf("terceiro caso\n");
    while (i < quantidadeDeN){

        i++;
    }

    //----------------------------------------
    i = 0;
    printf("Quarto caso \n");
    while (i < quantidadeDeN){

        i++;
    }
}