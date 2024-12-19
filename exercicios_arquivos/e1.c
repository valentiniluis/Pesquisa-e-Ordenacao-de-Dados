#include <stdio.h>

// 1) Contagem de Palavras em um Arquivo: Escreva um programa que abra um arquivo
// de texto, conte o número de palavras nele e exiba o resultado na tela.

int contarPalavras(FILE *arq) {
    char c = fgetc(arq);
    if (c == EOF) return 0;

    int contador = 1;

    while ((c=fgetc(arq)) != EOF) {
        if (c == ' ') contador++;
    }

    return contador;
}

int main() {
    FILE *arq = fopen("e1.txt", "r");
    
    if (arq == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    printf("%d\n", contarPalavras(arq));

    fclose(arq);

    return 0;
}