#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanhoVetor;
    int *vetor;

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &tamanhoVetor);

    vetor = (int*)malloc(sizeof(int)*tamanhoVetor);

    for(int i = 0; i < tamanhoVetor; i++){
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for(int i = tamanhoVetor - 1; i >= 0; i--){
        printf("%d: %d %d\n", i+1, vetor[i], &vetor[i]);
    }

    free(vetor);

    return 0;
}