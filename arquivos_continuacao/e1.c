#include <stdio.h>

void copiarArquivoInverso(FILE  *arqEntrada, FILE *arqSaida) {
    int flag = 0;    
    char s[200];
    long int j;
    for (int i = 0; flag == 0; i++) {

        fseek(arqEntrada, 0, (j=SEEK_END-i-1));
        printf("j: %d\n", j);
        
        if (ftell(arqEntrada) == 0) flag = 1;

        fgets(s, 200, arqEntrada);
        fputs(s, arqSaida);

    }
}

int main() {
    FILE *arq = fopen("/home/luisval/Documentos/pod/exercicios_arquivos/e4.txt", "r");
    FILE *arqSaida = fopen("e1.txt", "a");

    copiarArquivoInverso(arq, arqSaida);

    fclose(arq);
    fclose(arqSaida);
    return 0;
}