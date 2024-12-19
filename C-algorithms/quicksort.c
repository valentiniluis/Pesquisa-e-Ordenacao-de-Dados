#include <stdio.h>
#include "util.h"
#include <stdlib.h>
#include <time.h>

int particiona(int *v, int inicio, int fim) {
    int indexPivo = fim;
    int k = inicio;

    for (int i = inicio; i < fim; i++) {
        if (v[i] <= v[indexPivo]) {
            troca(v, i, k);
            k++;
        }
    }

    if (v[k] > v[indexPivo]) troca(v, k, indexPivo);
    
    return indexPivo;
}

void quicksort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        int posPivo = particiona(v, inicio, fim);
        quicksort(v, inicio, posPivo-1);
        quicksort(v, posPivo+1, fim);
    }
}

int main() {
    srand(time(NULL));
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int t = sizeof(v)/sizeof(v[0]);

    displayArray(v, t);
    quicksort(v, 0, t - 1);
    displayArray(v, t);

    return 0;
}