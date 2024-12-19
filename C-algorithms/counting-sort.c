#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void countingSort(int *v, int n) {
    int k = getMax(v, n);
    int *count = (int*)malloc(sizeof(int) * (k + 1));
    int *aux = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i <= k; i++) count[i] = 0;

    for (int i = 0; i < n; i++) count[v[i]]++;

    for (int i = 1; i <= k; i++) count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        count[v[i]]--;
        aux[count[v[i]]] = v[i];
    }

    for (int i = 0; i < n; i++) v[i] = aux[i];

    free(aux);
    free(count);
}

int main() {
    int v[] = {15, 2, 5, 10, 9, 6, 7, 8, 3, 2, 1};
    int t = sizeof(v) / sizeof(v[0]);

    displayArray(v, t);
    countingSort(v, t);
    displayArray(v, t);

    return 0;
}