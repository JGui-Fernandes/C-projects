#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char Str[100];
    int result;
    FILE *arq;

    arq = fopen("./output/write-teste.txt", "wt");

    if(arq == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
        return 1;
    }

    strcpy(Str, "Linha de teste");

    result = fputs(Str, arq);

    if(result == EOF){
        printf("Erro na Gravacao\n");
    }

    fclose(arq);
    return 0;
}