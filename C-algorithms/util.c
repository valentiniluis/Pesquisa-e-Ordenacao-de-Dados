#include <stdio.h>
#include "util.h"

void displayArray(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("\n");
}

void troca(int *v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

int getMax(int *v, int n) {
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
    }
    return max;
}
