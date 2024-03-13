#include <stdio.h>

int main()
{

    char nome[50];
    char nome2[50];
    printf("Digite seu nome\n");
    scanf("%s", nome);

    printf("nome: %s\n", nome);

    fflush(stdin);
    
    printf("Digite outro nome\n");
    fgets(nome2, sizeof(nome2), stdin);
    printf("Outro nome: %s\n", nome2);

    return 0;
}
