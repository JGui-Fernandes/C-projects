#include <stdio.h>

int main (){

    int vetor[20];
    int aux = 0;
    int anterior = -1;
    

    for(int i = 0; i < 20; i++){
        scanf("%d", &aux);
        while(aux < i+1 || aux < anterior){
            printf("Valor invalido, digite novamente.\n");
            scanf("%d", &aux);
        }
        vetor[i] = aux;
        anterior = aux;
    }

    return 0;
}