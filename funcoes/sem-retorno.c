#include <stdio.h>

void imprime(){
    printf("Entrando na funcao...\n");
    printf("Saindo da funcao...\n");
}

int main(){

    printf("Chamando funcao...\n");
    
    imprime();

    printf("Terminando...\n");

    return 0;
}