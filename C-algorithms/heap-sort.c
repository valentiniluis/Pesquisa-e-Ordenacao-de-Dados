#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void criaHeap(int *vetor, int i, int tamanho) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < tamanho && vetor[left] > vetor[i]) maior = left;
    if (right < tamanho && vetor[right] > vetor[maior]) maior = right;

    if (maior != i) {
        troca(vetor, i, maior);
        criaHeap(vetor, maior, tamanho);
    }
}

void heapSort(int *vetor, int tamanho) {
    for (int k = tamanho/2 - 1; k >= 0; k--) {
        criaHeap(vetor, k, tamanho);
    }

    for (int k = tamanho - 1; k >= 1; k--) {
        troca(vetor, 0, k);
        criaHeap(vetor, 0, k);
    }
}

int main() {
    int v[] = {7, 3, 5, 8, 11, 12, 14, 15, 1, 10, 13, 6, 2, 4, 9};
    int t = sizeof(v) / sizeof(v[0]);


    printf("Unsorted: ");
    displayArray(v, t);

    heapSort(v, t);

    printf("Sorted: ");
    displayArray(v, t);

    return 0;
}