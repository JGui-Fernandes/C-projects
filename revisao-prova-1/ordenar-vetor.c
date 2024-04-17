#include <stdio.h>
#define TAMANHO_VETOR 10

int main(){

    int vetor[TAMANHO_VETOR];

    printf("Digite 10 valores.\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < TAMANHO_VETOR; i++){
        for(int j = TAMANHO_VETOR; j > i; j--){
            if(vetor[i] < vetor[j]){
                int var = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = var;
            }
        }
    }

    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        printf("%do: %d\n", i+1, vetor[i]);
    }
    
    return 0;
}