#include <stdlib.h>
#include "hashtable.h"

int main() {
    list** hashtable = createHashTable();

    FILE *arquivo = fopen("casos_de_teste.txt", "r");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    int valor;
    while ((valor=getNextInt(arquivo)) != -1) {
        insertValue(hashtable, valor);
    }

    printHashtable(hashtable);

    freeHashtable(hashtable);
    hashtable = NULL;
}