#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

//funções auxiliares
void intercala(int p, int q, int r, int *v){
  int i, j, k, *w;

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


void troca(int *a, int *b) {
  int *aux = a;
  *a = *b;
  *b = *aux;
}


int divide(int *vetorA, int p, int r) {
  int x;
  x = vetorA[r];
  int i;
  i = p - 1;
  for (int j = p; p < r - 1; p++) {
    if (vetorA[j] <= x) {
      i++;
      troca(&vetorA[i], &vetorA[j]);
    }
  }
  troca(&vetorA[i + 1], &vetorA[r]);

  return i + 1;
}

int esquerdo(int i) { return 2 * (i + 1) - 1; }

int direito(int i) { return 2 * (i + 1); }

void desce(int n, int *vetor, int i) {
  int e, d, maior;

  e = esquerdo(i);
  d = direito(i);
  if (e < n && vetor[e] > vetor[i])
    maior = e;
  else
    maior = i;
  if (d < n && vetor[d] > vetor[maior])
    maior = d;
  if (maior != i) {
    troca(&vetor[i], &vetor[maior]);
    desce(n, vetor, maior);
  }
}

void constroi_max_heap(int n, int *vetor) {
  int i;

  for (i = n / 2 - 1; i >= 0; i--)
    desce(n, vetor, i);
}


//funções principais
void selectionSort(int *vetor, int n) {
  int i;
  for (i = 0; i < n - 1; i++) {
    int menorIndice = i;
    for (int j = i; j < n; j++) {
      if (vetor[j] < vetor[menorIndice])
        menorIndice = j;
    }
    troca(&vetor[menorIndice], &vetor[i]);
  }
}

void insertionSort(int n, int *vetor){
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

void mergeSort(int p, int r, int *v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergeSort(p, q, v);
    mergeSort(q, r, v);
    intercala(p, q, r, v);
  }
}

// algoritmo baseado no livro de Cormen
void heapSort(int n, int *vetor) {
  int i;

  constroi_max_heap(n, vetor);
  for (i = n - 1; i > 0; i--) {
    troca(&vetor[0], &vetor[i]);
    n--;
    desce(n, vetor, 0);
  }
}

// algoritimo baseado no livro de Cormen //
void quickSort(int *vetorA, int p, int r) {
  int q;
  if (p < r) {
    q = divide(vetorA, p, r);
    quickSort(vetorA, p, q - 1);
    quickSort(vetorA, q + 1, r);
  }
}

void countingSort(){
    
}