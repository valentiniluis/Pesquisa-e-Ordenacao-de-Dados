#include "util.h"

// Implementação do counting sort, que será usado pelo radix sort para ordenar a estrutura com base nos dígitos dos itens
void countingSort(list **v, int n, int pos) {
    list **aux = (list**)malloc(sizeof(list*) * n);
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < n; i++) {
        int digito = (v[i]->valor / pos) % 10;
        count[digito]++;
    }

    for (int i = 1; i < 10; i++) count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        int digito = (v[i]->valor / pos) % 10;
        count[digito]--;
        aux[count[digito]] = v[i];
    }

    for (int i = 0; i < n; i++) v[i] = aux[i];

    free(aux);
}

void radixSort(list **v, int n) {
    int max = getMax(v, n);
    for (int pos = 1; max/pos > 0; pos *= 10) {
        countingSort(v, n, pos);
    }
}

int main() {
    int vetorInteiros[] = {10, 3, 4, 6, 9, 11, 8, 1, 15, 5, 1, 8, 6, 2, 15, 6, 7, 1, 12, 3, 16, 14, 7, 8, 9, 10, 11, 1, 4, 2, 6};
    int tamanho = sizeof(vetorInteiros) / sizeof(vetorInteiros[0]);

    list *head = NULL;
    copiarVetorIntParaLista(vetorInteiros, tamanho, &head);

    list **vetorNodos = (list**)malloc(sizeof(list*) * tamanho);
    copiarListaParaVetorNodos(head, vetorNodos, tamanho);

    printf("Itens desordenados:\n");
    imprimirVetorNodos(vetorNodos, tamanho);

    printf("\n");
    printf("========================================\n");
    printf("\n");

    radixSort(vetorNodos, tamanho);

    sentinela fila;
    initQueue(&fila);
    copiarVetorNodosParaFila(vetorNodos, tamanho, &fila);

    printf("Itens ordenados com radix sort:\n");
    printQueue(fila);

    freeList(&head);
    free(vetorNodos);
    vetorNodos = NULL;
    freeQueue(&fila);

    return 0;
}