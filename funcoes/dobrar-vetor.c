#include <stdio.h>

#define TAMANHO_VETOR 5

void dobrar_vetor(int vetor[]){
    printf("Vetor: \n");
    for(int i = 0; i < TAMANHO_VETOR; i++){
        vetor[i] *=2;
    }
    
}

int main(){

    int vetor[TAMANHO_VETOR] = {1,2,3,4,5};

    dobrar_vetor(vetor);

    for(int i = 0; i < TAMANHO_VETOR; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}