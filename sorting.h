#include <stdio.h>
#include <stdlib.h>

//funções auxiliares
void troca(int *a, int *b);

int divide(int *vetorA, int p, int r);

void constroi_max_heap(int n, int *vetor);

void desce(int n, int *vetor, int i);

int direito(int i);

int esquerdo(int i);


//funções principais
void selectionSort(int *vetor, int n);

void insertionSort(int n, int *vetor);

void mergeSort(int p, int r, int *v);

void heapSort(int n, int *vetor);

void quickSort(int *vetorA, int p, int r);

void countingSort();