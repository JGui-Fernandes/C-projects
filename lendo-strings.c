#include <stdio.h>

int main(){

    char nome[50];
    char nome1[50];

    fgets(nome, sizeof(nome), stdin);

    scanf("%[^\n]", nome1);

    printf("Olá, %s!\n", nome);
    printf("Olá, %s!\n", nome1);

    return 0;
}