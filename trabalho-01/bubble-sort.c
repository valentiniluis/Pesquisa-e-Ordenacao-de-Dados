#include "util.h"

// Implementação de ordenação com bubble sort
void bubbleSort(list *v[], int tamanho) {
    for (int i = tamanho - 1; i >= 1; i--) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if ((v[j])->valor > (v[j+1])->valor) {
                trocarNodos(v, j, j+1);
                flag = 0;
            }
        }
        if (flag) break;
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
    
    bubbleSort(vetorNodos, tamanho);

    sentinela fila;
    initQueue(&fila);
    copiarVetorNodosParaFila(vetorNodos, tamanho, &fila);
    
    printf("Itens ordenados com bubble sort:\n");
    printQueue(fila);

    freeList(&head);
    free(vetorNodos);
    vetorNodos = NULL;
    freeQueue(&fila);

    return 0;
}