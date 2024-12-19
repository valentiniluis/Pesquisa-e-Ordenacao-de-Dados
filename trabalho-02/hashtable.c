#include <stdlib.h>
#include "hashtable.h"


int hashFunction(int value) {
    return value % M;
}

list** createHashTable() {
    return (list**)malloc(sizeof(list*) * M);;
}

void insertValue(list **hashtable, int value) {
    int index = hashFunction(value);
    hashtable[index] = insert(hashtable[index], value);
    
    // list *head = hashtable[index];
    // head = insert(head, value);
    // hashtable[index] = head;
}

void printHashtable(list **hashtable) {
    for (int i = 0; i < M; i++) {
        printf("%d - ", i);
        list *head = hashtable[i];
        printList(head);
    }
}

void freeHashtable(list** hashtable) {
    for (int i = 0; i < M; i++) {
        freeList(hashtable[i]);
        hashtable[i] = NULL;
    }
    free(hashtable);
}
