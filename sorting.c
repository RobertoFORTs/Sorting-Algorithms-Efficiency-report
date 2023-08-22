#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#define MAX 20000

//funções auxiliares
void intercala(int p, int q, int r, int v[MAX]){
  int i, j, k, w[MAX];

  i = p; j = q; k = 0; 
  while(i < q && j < r) {
    if(v[i] < v[j]){
      w[k] = v[i]; i++;
    }
    else{
      w[k] = v[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v[i]; i++; k++;
    }
  while(j < r){
    w[k] = v[j]; j++; k++;  
  }
  for(i = p; i < r; i++) {
    v[i] = w[i - p];
  }
}

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