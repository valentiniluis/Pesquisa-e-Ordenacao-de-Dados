#include <stdio.h>

// 5) Contagem de Caracteres Específicos: Crie um programa que conte quantas vezes
// um caractere específico aparece em um arquivo de texto. Permita que o usuário
// especifique o caractere a ser contado.

int contarOcorrencias(FILE *arq, char caractere) {
    char c;
    int contador = 0;

    while ((c=fgetc(arq)) != EOF) {
        if (c == caractere) contador++;
    }

    return contador;
}

int main() {
    char c;
    
    printf("Insira um caractere a ser contado: ");
    scanf("%c", &c);

    FILE *arquivo = fopen("e1.txt", "r");

    printf("O caractere %c aparece %d vez(es) no arquivo.\n", c, contarOcorrencias(arquivo, c));

    fclose(arquivo);

    return 0;
}