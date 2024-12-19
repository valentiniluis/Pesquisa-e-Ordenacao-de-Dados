#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

struct tlist {
    int valor;
    struct tlist* next;
};
typedef struct tlist list;


// Funções para encadeamento, impressão e liberação de lista encadeada
list* insert(list *head, int valor);
void printList(list *head);
void freeList(list *head);


// Função que lê, um por vez, os inteiros do arquivo aberto; contém uma flag 'eof' que é passada por referência,
// assim pode ser setado na função main para indicar que o arquivo acabou
int getNextInt(FILE *arq);

#endif