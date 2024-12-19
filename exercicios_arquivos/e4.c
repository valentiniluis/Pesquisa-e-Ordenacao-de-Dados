#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 4) Leitura e Impressão de Linhas Específicas: Escreva um programa que leia um
// arquivo de texto linha por linha e imprima apenas as linhas que começam com uma
// determinada letra ou palavra especificada pelo usuário.

int comecaCom(char *string1, char *string2) {
    for (int i = 0; i < strlen(string2); i++) {
        if (string1[i] != string2[i]) return 0;
    }
    return 1;
} 

void imprimirLinhasComecandoCom(FILE *arq, char *string) {
    char linhaAtual[300];
    while (fgets(linhaAtual, 300, arq)) {
        if (comecaCom(linhaAtual, string)) printf("%s\n", linhaAtual);
    }
}

int main() {

    FILE *arq = fopen("e4.txt", "r");

    char s[30];

    printf("Com qual caractere ou palavra as linhas devem começar? ");
    scanf("%s", s);
    printf("\n");
    
    imprimirLinhasComecandoCom(arq, s);

    fclose(arq);

    return 0;
}