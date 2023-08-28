#include <stdio.h>
#include <stdlib.h>

//funções auxiliares
void troca(int *a, int *b);

int divide(int *vetorA, int p, int r);


//funções principais
void selectionSort(int *vetor, int n);

void insertionSort(int n, int *vetor);

void mergeSort(int p, int r, int *v);

void heapSort();

void quickSort(int *vetorA, int p, int r);

void countingSort();