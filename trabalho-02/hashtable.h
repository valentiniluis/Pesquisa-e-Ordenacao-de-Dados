#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "util.h"

// Constante global contendo o valor de M = 23
#define M 23


// Função hash que recebe um valor e mapeia a um index
int hashFunction(int value);


// Função que gera a estrutura da hashtable (array de listas encadeadas)
list** createHashTable();


// Função que insere elemento na hashtable
void insertValue(list **hashtable, int value);


// Função que imprime a lista encadeada de cada posição do vetor (hashtable)
void printHashtable(list **hashtable);


// Função que libera todas as listas encadeadas e posteriormente libera o vetor de listas
void freeHashtable(list** hashtable);


#endif
