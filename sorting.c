#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

//funções auxiliares

//funções principais
void selectionSort(){

}

void insertionSort(int n, float *vetor){
    int i, j;
    float valor;

    for (i = 1; i < n; i++){
        valor = vetor[i];
        for (j = i - 1; j >= 0 && vetor[j] > valor; j--){
            vetor[j+1] = vetor[j]; 
        }
        vetor[j+1] = valor;
    }
}

void mergeSort(){

}

void heapSort(){

}

void quickSort(){

}

void countingSort(){
    
}