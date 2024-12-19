#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void countingSort(int *v, int n, int pos) {
    int *aux = (int*)malloc(sizeof(int) * n);
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n; i++) {
        int digito = (v[i] / pos) % 10;
        count[digito]++;
    }

    for (int i = 1; i < 10; i++) count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        int digito = (v[i] / pos) % 10;
        count[digito]--;
        aux[count[digito]] = v[i];
    }

    for (int i = 0; i < n; i++) v[i] = aux[i];

    free(aux);
}

void radixSort(int *v, int n) {
    int max = getMax(v, n);
    for (int pos = 1; max/pos > 0; pos *= 10) {
        countingSort(v, n, pos);
    }
}

int main() {
    int v[] = {12, 4, 5, 1, 0, 2, 4, 5, 2, 1, 5, 7, 8, 5, 6, 7, 3, 4, 5, 2, 4, 3, 8, 9, 0, 9, 7, 6};
    int t = sizeof(v) / sizeof(v[0]);

    displayArray(v, t);
    radixSort(v, t);
    displayArray(v, t);

    return 0;
}