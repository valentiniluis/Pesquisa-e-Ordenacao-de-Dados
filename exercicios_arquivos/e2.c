#include <stdio.h>

// 2) Cópia de Arquivo: Crie um programa que copie o conteúdo de um arquivo de texto
// para outro arquivo. Certifique-se de que o arquivo de destino seja criado se ainda
// não existir.

void copiarConteudo(FILE* arqLer, FILE* arqEscrever) {
    char c;

    while ((c=fgetc(arqLer)) != EOF) fputc(c, arqEscrever);
}

int main() {
    FILE* arq1 = fopen("e1.txt", "r");
    FILE* arq2 = fopen("e2.txt", "a+");

    if (arq1 == NULL || arq2 == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }


    copiarConteudo(arq1, arq2);

    fclose(arq1);
    fclose(arq2);

    return 0;
}