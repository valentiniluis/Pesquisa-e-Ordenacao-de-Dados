#include <stdlib.h>
#include "util.h"

list* insert(list *head, int valor) {
    list *newNode = (list*)malloc(sizeof(list));
    newNode->valor = valor;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    list *aux;
    for (aux = head; aux->next != NULL; aux = aux->next);
    aux->next = newNode;
    return head;
}


void freeList(list *head) {
    list *aux = head;
    while (aux != NULL) {
        head = head->next;
        free(aux);
        aux = head;
    }
}


void printList(list *head) {
    for (list *aux = head; aux != NULL; aux = aux->next) {
        printf("%d -> ", aux->valor);
    }
    printf("NULL");
    printf("\n");
}


int getNextInt(FILE *arq) {
    
    char c = fgetc(arq);

    if (c == EOF) return -1;

    int numero = c - '0';

    // A cada iteração, avança-se uma casa decimal do número. Por isso, é feita a multiplicação por 10 e soma com o próximo algarismo lido.
    while ((c = fgetc(arq)) != EOF) {

        if (c == ';') return numero;

        numero *= 10;
        numero += c - '0';
    }

    return -1;
}