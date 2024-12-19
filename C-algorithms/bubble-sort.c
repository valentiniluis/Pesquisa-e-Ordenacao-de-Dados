#include <stdio.h>
#include "util.h"

void bubbleSortSemFlag(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (vetor[j] > vetor[j+1]) {
                int temp = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

void bubbleSort(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i >= 1; i--) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (vetor[j] > vetor[j+1]) {
                int temp = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = temp;
                flag = 0;
            }
        }
        if (flag) break;
    }
}

int main() {
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    displayArray(v, sizeof(v) / sizeof(v[0]));
    bubbleSort(v, sizeof(v) / sizeof(v[0]));
    displayArray(v, sizeof(v) / sizeof(v[0]));

    return 0;
}