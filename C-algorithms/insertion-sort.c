#include <stdio.h>
#include "util.h"

void insertionSort(int *v, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int p = v[i];
        int j;
        for (j = i; j > 0; j--) {
            if (v[j-1] > p) v[j] = v[j-1];
            else break;
        }
        v[j] = p;
    }
}

int main() {
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int t = sizeof(v)/sizeof(v[0]);

    displayArray(v, t);
    insertionSort(v, t);
    displayArray(v, t);

    return 0;
}