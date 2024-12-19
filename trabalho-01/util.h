#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

struct tlist {
    int valor;
    struct tlist* next;
};
typedef struct tlist list;

struct tqueue {
    int valor;
    struct tqueue* next;
};
typedef struct tqueue queue;

struct sentinelaFila {
    queue *head, *tail;
};
typedef struct sentinelaFila sentinela;


// Métodos para encadeamento, impressão e liberação de lista encadeada
void pushNode(list **head, int valor);

void freeList(list **head);

void printList(list *head);


// Métodos para filas
void enqueue(sentinela *s, int valor);

void initQueue(sentinela *s);

void dequeue(sentinela *s);

int isEmpty(sentinela *s);

void freeQueue(sentinela *s);

void printQueue(sentinela s);


// Funções de utilidade
void copiarListaParaVetorNodos(list *head, list **vetor, int tamanho);
void copiarVetorIntParaLista(int *v, int tamanho, list **head);
void copiarVetorNodosParaFila(list **v, int tamanho, sentinela *fila);
void imprimirVetorNodos(list **v, int tamanho);
void trocarNodos(list **v, int posicaoX, int posicaoY);
int getMax(list **v, int n);

#endif