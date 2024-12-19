#include <stdio.h>
#include "util.h"

void selectionSort(int *v, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (v[j] < v[minimo]) minimo = j;
        }
        int temp = v[i];
        v[i] = v[minimo];
        v[minimo] = temp;
    }
}

int main() {
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tamanho = sizeof(v)/sizeof(v[0]);

    displayArray(v, tamanho);
    selectionSort(v, tamanho);
    displayArray(v, tamanho);

    return 0;
}