#include "util.h"

// Divisão do quicksort em duas funções: particiona (separa os elementos conforme o valor do pivô) e quicksort (invoca o particionamento recursivamente)
int particiona(list **v, int inicio, int fim) {
    int indexPivo = fim;
    int k = inicio;

    for (int i = inicio; i < fim; i++) {
        if (v[i]->valor <= v[indexPivo]->valor) {
            trocarNodos(v, i, k);
            k++;
        }
    }

    if (v[k]->valor > v[indexPivo]->valor) trocarNodos(v, k, indexPivo);
    
    return indexPivo;
}

void quicksort(list **v, int inicio, int fim) {
    if (inicio < fim) {
        int posPivo = particiona(v, inicio, fim);
        quicksort(v, inicio, posPivo-1);
        quicksort(v, posPivo+1, fim);
    }
}

int main() {
    int vetorInteiros[] = {10, 32, 4, 6, 19, 11, 8, -10, -15, 50, 41, -88, 96, 2, 15, 60, 71};
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

    quicksort(vetorNodos, 0, tamanho-1);

    sentinela fila;
    initQueue(&fila);
    copiarVetorNodosParaFila(vetorNodos, tamanho, &fila);

    printf("Itens ordenados com quick sort:\n");
    printQueue(fila);

    freeList(&head);
    free(vetorNodos);
    vetorNodos = NULL;
    freeQueue(&fila);

    return 0;
}