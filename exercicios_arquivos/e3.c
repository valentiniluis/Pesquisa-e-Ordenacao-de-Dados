#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3) Edição de Arquivo: Desenvolva um programa que permita ao usuário editar um
// arquivo de texto. Ele deve solicitar ao usuário que insira o texto que deseja adicionar
// ao arquivo existente e, em seguida, deve adicionar esse texto ao final do arquivo.

void adicionarTextoPorLinha(FILE *arq, int max_size) {

    char *string = (char*)malloc(sizeof(char) * max_size);
    int flag = 0;


    while (!flag) {
        scanf("%s", string);
        if ((strcmp(string, "exit") == 0)) {
            flag = 1;
        }
        else {
            fprintf(arq, "%s\n", string);
        }
    }

}

int main() {
    FILE *arq = fopen("e3.txt", "a");

    if (arq == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }


    adicionarTextoPorLinha(arq, 100);

    fclose(arq);

    return 0;
}