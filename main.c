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
    float somaInsertion, somaSelection, somaMerge, somaQuick, somaHeap, somaCount;

    //---------------------------------------------------------
    //Primeiro Caso (execução dos processos repetidas vezes)
    printf("Primeiro caso, Vetor preenchido aleatóriamente:\n");
    printf("            InsertionSort     SelectionSort     Mergesort     Quicksort     HeapSort     CountingSort     ");
    while (i <= quantidadeDeN && n <= fim){
        
        j = 0; //controla a quantidade de repetições para cada caso de teste
        
        int *v = malloc(n* sizeof(int)); // alocando vetor de tamanho n 
        
        for (aux = 0; aux < n; aux++){ //preencher vetor
            int x = rand();
            if (x >= 0)
                v[aux] = x;
        }
        
        while (j < rpt){ //realizar operações com vetor atual
            
            clock_t insertionBegin = clock();
            insertionSort(n, v);
            clock_t insertionEnd = clock();
            
            clock_t selectionBegin = clock();
            selectionSort(v, n);
            clock_t selectionEnd = clock();
            
            // clock_t mergeBegin = clock();
            // mergeSort(0, n, v);
            // clock_t mergeEnd = clock();

            clock_t quickBegin = clock();
            quickSort(v, 0, n);
            clock_t quickEnd = clock();

            // clock_t heapBegin = clock();
            // heapSort();
            // clock_t heapEnd = clock();
            
            // clock_t countBegin = clock();
            // countingSort();
            // clock_t countEnd = clock();

            //obter soma dos tempos de execução para cada algorítimo
            somaInsertion = somaInsertion + ((float)insertionEnd - (float)insertionBegin) / 1000000.0F;
            somaSelection = somaSelection + ((float)selectionEnd - (float)selectionBegin) / 1000000.0F;
            //somaMerge = somaMerge + ((float)mergeEnd - (float)mergeBegin) / 1000000.0F;
            somaQuick = somaQuick + ((float)quickEnd - (float)quickBegin) / 1000000.0F;
            //somaHeap = somaHeap + ((float)heapEnd - (float)heapBegin) / 1000000.0F;
            //somaCount = somaCount + ((float)countEnd - (float)countBegin) / 1000000.0F;

            

            j++;
        }
        //calcular media para cada n e exibir
        float mediaInsertion = somaInsertion/rpt;
        float mediaSelection = somaSelection/rpt;
        // float mediaMerge = somaMerge/rpt;
        float mediaQuick = somaQuick/rpt;
        // float mediaHeap = somaHeap/rpt;
        // float mediaCount = somaCount/rpt;
        
        printf("\nn:%d        %f          %f         merge         %f\n", n, mediaInsertion, mediaSelection, mediaQuick);
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