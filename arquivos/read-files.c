#include <stdio.h>
#include <stdlib.h>

int main(){

    char nome[50];
    int idade;
    FILE *arq;

    arq = fopen("./output/read-teste.txt", "r");

    if( arq == NULL ){
        printf("Problemas na CRIACAO do arquivo\n");
        return 1;
    }

    while (fscanf(arq, "%s %d", nome, &idade) == 2)
    {
        printf("%s %d\n", nome, idade);
    }

    fclose(arq);
    
    return 0;
}