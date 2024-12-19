#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void sort(int *v, int inicio, int meio, int fim) {
    int *auxiliar = (int*)malloc(sizeof(int) * (fim - inicio + 1));
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            auxiliar[k] = v[i];
            i++;
        }
        else {
            auxiliar[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        auxiliar[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {
        auxiliar[k] = v[j];
        j++;
        k++;
    }

    for (k = inicio; k <= fim; k++) {
        v[k] = auxiliar[k - inicio];
    }

    free(auxiliar);
}

void mergeSort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        sort(v, inicio, meio, fim);
    }
}

int main() {
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int t = sizeof(v)/sizeof(v[0]);

    displayArray(v, t);
    mergeSort(v, 0, t - 1);
    displayArray(v, t);

    return 0;
}