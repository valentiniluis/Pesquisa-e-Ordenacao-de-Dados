#include "util.h"


void pushNode(list **head, int valor) {
    list *newNode = (list*)malloc(sizeof(list));
    newNode->valor = valor;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    list *aux;
    for (aux = *head; aux->next != NULL; aux = aux->next);
    aux->next = newNode;
}


void freeList(list **head) {
    list *aux = *head;
    while (aux != NULL) {
        *head = (*head)->next;
        free(aux);
        aux = *head;
    }
}


void printList(list *head) {
    for (list *aux = head; aux != NULL; aux = aux->next) {
        printf("%d", aux->valor);
        if (aux->next != NULL) printf(", ");
    }
    printf("\n");
}


void initQueue(sentinela *s) {
    s->head = NULL;
    s->tail = NULL;
}


void enqueue(sentinela *s, int valor) {
    queue *newItem = (queue*)malloc(sizeof(queue));
    newItem->valor = valor;
    newItem->next = NULL;

    if (s->head == NULL) {
        s->head = newItem;
        s->tail = newItem;
        return;
    }

    s->tail->next = newItem;
    s->tail = newItem;
}


void dequeue(sentinela *s) {
    if (isEmpty(s)) return;

    queue *temp = s->head;
    if (s->head == s->tail) {
        initQueue(s);
    }
    else {
        s->head = s->head->next;
    }
    free(temp);
}


int isEmpty(sentinela *s) {
    return s->head == NULL && s->tail == NULL;
}


void freeQueue(sentinela *s) {
    while (!isEmpty(s)) {
        dequeue(s);
    }
}


void printQueue(sentinela s) {
    for (queue *aux = s.head; aux != NULL; aux = aux->next) {
        printf("%d", aux->valor);
        if (aux->next != NULL) printf(", ");
    }
    printf("\n");
}


void copiarListaParaVetorNodos(list *head, list **vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = head;
        head = head->next;
    }
}


void copiarVetorIntParaLista(int *v, int tamanho, list **head) {
    for (int i = 0; i < tamanho; i++) {
        pushNode(head, v[i]);
    }
}


void copiarVetorNodosParaFila(list **v, int tamanho, sentinela *fila) {
    for (int i = 0; i < tamanho; i++) {
        enqueue(fila, v[i]->valor);
    }
}


void imprimirVetorNodos(list **v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d", (v[i])->valor);
        if (i < tamanho-1) printf(", ");
    }
    printf("\n");
}


void trocarNodos(list **v, int posicaoX, int posicaoY) {
    list *temp = v[posicaoX];
    v[posicaoX] = v[posicaoY];
    v[posicaoY] = temp;
}

int getMax(list **v, int n) {
    int max = (v[0])->valor;
    for (int i = 1; i < n; i++) {
        if (v[i]->valor > max) max = v[i]->valor;
    }
    return max;
}
