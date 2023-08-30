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
    float timeInsertion, timeSelection, timeMerge, timeQuick, timeHeap, timeCount;

    //---------------------------------------------------------
    //Primeiro Caso (execução dos processos repetidas vezes)
    printf("Primeiro caso, Vetor preenchido aleatóriamente:\n");
    printf("            InsertionSort     SelectionSort       Mergesort        Quicksort     HeapSort       CountingSort\n");
    while (i <= quantidadeDeN && n <= fim){
        
        j = 0; //controla a quantidade de repetições para cada caso de teste
        aux = 0;
        int *v = (int*)calloc(n, sizeof(int)); // alocando vetor de tamanho n 
        
        while (aux < n){ //preencher vetor
            int x = rand();
            if (x >= 0){
                v[aux] = x;
                aux++;
            }
        }
        
        while (j < rpt){ //realizar operações com vetor atual
            
            clock_t insertionBegin = clock();
            insertionSort(n, v);
            clock_t insertionEnd = clock();
            
            clock_t selectionBegin = clock();
            selectionSort(v, n);
            clock_t selectionEnd = clock();
            
            clock_t mergeBegin = clock();
            mergeSort(0, n, v);
            clock_t mergeEnd = clock();

            clock_t quickBegin = clock();
            quickSort(v, 0, n);
            clock_t quickEnd = clock();

            clock_t heapBegin = clock();
            heapSort(n, v);
            clock_t heapEnd = clock();
            
            // clock_t countBegin = clock();
            // countingSort(v, n, 2147483647);
            // clock_t countEnd = clock();

            //obter soma dos tempos de execução para cada algorítimo
            somaInsertion = somaInsertion + ((float)insertionEnd - (float)insertionBegin) / CLOCKS_PER_SEC;
            somaSelection = somaSelection + ((float)selectionEnd - (float)selectionBegin) / CLOCKS_PER_SEC;
            somaMerge = somaMerge + ((float)mergeEnd - (float)mergeBegin) / CLOCKS_PER_SEC;
            somaQuick = somaQuick + ((float)quickEnd - (float)quickBegin) / CLOCKS_PER_SEC;
            somaHeap = somaHeap + ((float)heapEnd - (float)heapBegin) / CLOCKS_PER_SEC;
            //somaCount = somaCount + ((float)countEnd - (float)countBegin) / CLOCKS_PER_SEC;

            

            j++;
        }
        
        free(v); //liberando vetor

        //calcular media para cada n e exibir
        float mediaInsertion = somaInsertion/rpt;
        float mediaSelection = somaSelection/rpt;
        float mediaMerge = somaMerge/rpt;
        float mediaQuick = somaQuick/rpt;
        float mediaHeap = somaHeap/rpt;
        //float mediaCount = somaCount/rpt;
        
        printf("\nn:%d        %f          %f         %f         %f         %f         count\n", n, mediaInsertion, mediaSelection, mediaMerge, mediaQuick, mediaHeap);
        
        n = n + stp;
        i++;
    }
    
    //---------------------------------------------------------------
    // Para os restante dos casos, utilizar os mesmos valores de entrada, porém com apenas uma execução para cada vetor de tamanho n
    
    i = 0;
    printf("Segundo caso: Vetor Ordenado Decrescentemente\n");
    printf("               InsertionSort     SelectionSort    Mergesort        Quicksort        HeapSort          CountingSort\n");
    n = inc;
    while (i <= quantidadeDeN){
        int *v = (int *)malloc(n*sizeof(int));
        for (aux = 0; aux < n; aux++){ //preencher vetor
            int x = rand();
            if (x >= 0)
                v[aux] = x;
        }
        
        mergeSort(0, n, v);
        
        for (aux = 0; aux < n; aux++){
            troca(&v[aux], &v[n-1-aux]);
        }
        

        clock_t insertionBegin = clock();
        insertionSort(n, v);
        clock_t insertionEnd = clock();
        timeInsertion = ((float)insertionEnd - (float)insertionBegin)/CLOCKS_PER_SEC;

        clock_t selectionBegin = clock();
        selectionSort(v, n);
        clock_t selectionEnd = clock();
        timeSelection = ((float)selectionEnd - (float)selectionBegin)/CLOCKS_PER_SEC;
        
        clock_t mergeBegin = clock();
        mergeSort(0, n, v);
        clock_t mergeEnd = clock();
        timeMerge = ((float)mergeEnd - (float)mergeBegin)/CLOCKS_PER_SEC;

        clock_t quickBegin = clock();
        quickSort(v, 0, n);
        clock_t quickEnd = clock();
        timeQuick = ((float)quickEnd - (float)quickBegin)/CLOCKS_PER_SEC;

        clock_t heapBegin = clock();
        heapSort(n, v);
        clock_t heapEnd = clock();
        timeHeap = ((float)heapEnd - (float)heapBegin)/CLOCKS_PER_SEC;

        // clock_t countBegin = clock();
        // countingSort();
        // clock_t countEnd = clock();

        printf("\nn:%d        %f          %f         %f         %f         %f         count\n", n, timeInsertion, timeSelection, timeMerge, timeQuick, timeHeap);

        free(v);
        n = n + stp;
        i++;
    }

    //---------------------------------------
    i = 0;
    printf("terceiro caso\n");
    while (i <= quantidadeDeN){

        i++;
    }

    //----------------------------------------
    i = 0;
    printf("Quarto caso \n");
    while (i <= quantidadeDeN){

        i++;
    }
}