// Alunos: Roberto Fortes e Pedro Nicoletti
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"


int main(){
    // "menu"
    //------------------------------------------------------------
    // declaração de variáveis que serão necessárias para execução
    printf("\n");
    int inc, fim, stp, rpt;
    printf("Digite o tamanho inicial, final, intervalo e número de repetições desejadas, repectivamente: \n");
    printf("\n");
    scanf("%d %d %d %d", &inc, &fim, &stp, &rpt);
    int i = 0;
    int j = 0;
    int aux;
    int quantidadeDeN = (fim - inc)/stp;
    int n = inc;
    srand(time(NULL));
    float somaInsertion = 0, somaSelection = 0, somaMerge = 0, somaQuick = 0, somaHeap = 0, somaCount = 0;
    float timeInsertion, timeSelection, timeMerge, timeQuick, timeHeap, timeCount;

    //---------------------------------------------------------
    //Primeiro Caso (execução dos processos repetidas vezes)
    printf("\n");
    printf("[ [RANDOM] ]\n");
    printf("               InsertionSort     SelectionSort    Mergesort        Quicksort        HeapSort         CountingSort\n");
    while (i <= quantidadeDeN && n <= fim){
        
        j = 0; //controla a quantidade de repetições para cada caso de teste
        aux = 0;

        int *v = (int*)malloc((n+1)* sizeof(int)); // alocando vetor de tamanho n 
        int *w = (int*)malloc((n+1)* sizeof(int)); // vetor controle (copia)
        while (j < rpt){ //realizar operações com vetor atual

            while (aux < n){ //preencher vetor e copiar
                int x = rand();
                if (x >= 0){
                    v[aux] = x;
                    w[aux] = x;
                    aux++;
                }
            }

            clock_t insertionBegin = clock();
            insertionSort(n, w);
            clock_t insertionEnd = clock();
            
            for (aux = 0; aux < n; aux++){ //copiando vetor desordenado
                w[aux] = v[aux];
            }

            clock_t selectionBegin = clock();
            selectionSort(w, n);
            clock_t selectionEnd = clock();
            
            for (aux = 0; aux < n; aux++){ //copiando vetor desordenado
                w[aux] = v[aux];
            }

            clock_t mergeBegin = clock();
            mergeSort(0, n, w);
            clock_t mergeEnd = clock();
            
            for (aux = 0; aux < n; aux++){ //copiando vetor desordenado
                w[aux] = v[aux];
            }

            clock_t quickBegin = clock();
            quickSort(w, 0, n);
            clock_t quickEnd = clock();
            
            for (aux = 0; aux < n; aux++){ //copiando vetor desordenado
                w[aux] = v[aux];
            }

            clock_t heapBegin = clock();
            heapSort(n, w);
            clock_t heapEnd = clock();
            
            for (aux = 0; aux < n; aux++){ //copiando vetor desordenado
                w[aux] = v[aux];
            }

            clock_t countBegin = clock();
            countingSort(w, n);
            clock_t countEnd = clock();

            //obter soma dos tempos de execução para cada algorítimo
            
            somaInsertion = somaInsertion + ((float)insertionEnd - (float)insertionBegin) / CLOCKS_PER_SEC;
            somaSelection = somaSelection + ((float)selectionEnd - (float)selectionBegin) / CLOCKS_PER_SEC;
            somaMerge = somaMerge + ((float)mergeEnd - (float)mergeBegin) / CLOCKS_PER_SEC;
            somaQuick = somaQuick + ((float)quickEnd - (float)quickBegin) / CLOCKS_PER_SEC;
            somaHeap = somaHeap + ((float)heapEnd - (float)heapBegin) / CLOCKS_PER_SEC;
            somaCount = somaCount + ((float)countEnd - (float)countBegin) / CLOCKS_PER_SEC;

            j++;

        }

        //calcular media para cada n e exibir
        float mediaInsertion = somaInsertion/rpt;
        float mediaSelection = somaSelection/rpt;
        float mediaMerge = somaMerge/rpt;
        float mediaQuick = somaQuick/rpt;
        float mediaHeap = somaHeap/rpt;
        
        float mediaCount = somaCount/rpt;
        
        printf("\nn:%d        %f          %f         %f         %f         %f         %f\n", n, mediaInsertion, mediaSelection, mediaMerge, mediaQuick, mediaHeap, mediaCount);
        
        n = n + stp;
        i++;
        free(v); //liberando vetor
        free(w);
    }
    
    //---------------------------------------------------------------
    // Para os restante dos casos, utilizar os mesmos valores de entrada, porém com apenas uma execução para cada vetor de tamanho n
    
    i = 0;
    printf("\n\n[ [REVERSE] ]\n");
    printf("               InsertionSort     SelectionSort    Mergesort        Quicksort        HeapSort         CountingSort\n");
    n = inc;
    while (i <= quantidadeDeN){
        int *v = (int *)malloc((n+1)*sizeof(int));
        int *w = (int *)malloc((n+1)*sizeof(int));
        aux = 0;
        while (aux < n){ //preencher vetor
            int x = rand();
            if (x >= 0){
                v[aux] = x;
                aux++;
            }
        }
        
        mergeSort(0, n, v); //Primeiramente, ordena
        
        for (aux = 0; aux < n/2; aux++){
            troca(&v[aux], &v[n-1-aux]); //invertendo vetor
        }
        
        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }
        

        clock_t insertionBegin = clock();
        insertionSort(n, w);
        clock_t insertionEnd = clock();
        timeInsertion = ((float)insertionEnd - (float)insertionBegin)/CLOCKS_PER_SEC;

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t selectionBegin = clock();
        selectionSort(w, n);
        clock_t selectionEnd = clock();
        timeSelection = ((float)selectionEnd - (float)selectionBegin)/CLOCKS_PER_SEC;
        
        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t mergeBegin = clock();
        mergeSort(0, n, w);
        clock_t mergeEnd = clock();
        timeMerge = ((float)mergeEnd - (float)mergeBegin)/CLOCKS_PER_SEC;

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t quickBegin = clock();
        quickSort(w, 0, n);
        clock_t quickEnd = clock();
        timeQuick = ((float)quickEnd - (float)quickBegin)/CLOCKS_PER_SEC;

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t heapBegin = clock();
        heapSort(n, w);
        clock_t heapEnd = clock();
        timeHeap = ((float)heapEnd - (float)heapBegin)/CLOCKS_PER_SEC;
        
        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t countBegin = clock();
        countingSort(w, n);
        clock_t countEnd = clock();
        timeCount = ((float)countEnd - (float)countBegin)/CLOCKS_PER_SEC;

        printf("\nn:%d        %f          %f         %f         %f         %f         %f\n", n, timeInsertion, timeSelection, timeMerge, timeQuick, timeHeap, timeCount);

        free(v);
        free(w);
        n = n + stp;
        i++;
    }

    //---------------------------------------
    i = 0;
    printf("\n\n[ [SORTED] ]\n");
    printf("               InsertionSort     SelectionSort    Mergesort        Quicksort        HeapSort         CountingSort\n");
    n = inc;
    while (i <= quantidadeDeN){
        int *v = (int *)malloc((n+1)*sizeof(int));
        int *w = (int *)malloc((n+1)*sizeof(int));
        aux = 0;
        while (aux < n){ //preencher vetor
            int x = rand();
            if (x >= 0){
                v[aux] = x;
                aux++;
            }
        }
        
        mergeSort(0, n, v); //Primeiramente, ordena
        //não precisa de cópia pois basta um vetor ordenado

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
    

        clock_t countBegin = clock();
        countingSort(v, n);
        clock_t countEnd = clock();
        timeCount = ((float)countEnd - (float)countBegin)/CLOCKS_PER_SEC;

        printf("\nn:%d        %f          %f         %f         %f         %f         %f\n", n, timeInsertion, timeSelection, timeMerge, timeQuick, timeHeap, timeCount);

        free(v);
        free(w);
        n = n + stp;
        i++;
    }

    //----------------------------------------
    i = 0;
    printf("\n\n[ [NEARLY SORTED] ]\n");
    printf("               InsertionSort     SelectionSort    Mergesort        Quicksort        HeapSort         CountingSort\n");
    n = inc;
    while (i <= quantidadeDeN){
        int *v = (int *)calloc((n+1), sizeof(int));
        int *w = (int *)calloc((n+1), sizeof(int));
        aux = 0;
        while (aux < (90*n)/100){ //preencher 90% do vetor
            int x = rand();
            if (x >= 0){
                v[aux] = x;
                aux++; 
            }

        }
        
        mergeSort(0, n, v); //Primeiramente, ordena os 90%
        
        while (aux < n){
            int x = rand();
            if (x >= 0){
                v[aux] = x;
                aux++; 
            }
        } // vetor parcialmente ordenado pronto

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }
        

        clock_t insertionBegin = clock();
        insertionSort(n, w);
        clock_t insertionEnd = clock();
        timeInsertion = ((float)insertionEnd - (float)insertionBegin)/CLOCKS_PER_SEC;

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t selectionBegin = clock();
        selectionSort(w, n);
        clock_t selectionEnd = clock();
        timeSelection = ((float)selectionEnd - (float)selectionBegin)/CLOCKS_PER_SEC;
        
        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t mergeBegin = clock();
        mergeSort(0, n, w);
        clock_t mergeEnd = clock();
        timeMerge = ((float)mergeEnd - (float)mergeBegin)/CLOCKS_PER_SEC;

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t quickBegin = clock();
        quickSort(w, 0, n);
        clock_t quickEnd = clock();
        timeQuick = ((float)quickEnd - (float)quickBegin)/CLOCKS_PER_SEC;

        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t heapBegin = clock();
        heapSort(n, w);
        clock_t heapEnd = clock();
        timeHeap = ((float)heapEnd - (float)heapBegin)/CLOCKS_PER_SEC;
        
        for (aux = 0; aux < n; aux++){
            w[aux] = v[aux]; //cópia controle
        }

        clock_t countBegin = clock();
        countingSort(w, n);
        clock_t countEnd = clock();
        timeCount = ((float)countEnd - (float)countBegin)/CLOCKS_PER_SEC;

        printf("\nn:%d        %f          %f         %f         %f         %f         %f\n", n, timeInsertion, timeSelection, timeMerge, timeQuick, timeHeap, timeCount);

        free(v);
        free(w);
        n = n + stp;
        i++;
    }
}