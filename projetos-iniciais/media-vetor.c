#include <stdio.h>
#include <math.h>

int main(){

    float notas[5], soma = 0;
    int tamanho_vetor = (sizeof(notas) / sizeof(notas[0]));
    float media;
    for(int i = 0; i < tamanho_vetor; i++){
        printf("Digite o %d valor:\n", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    media = soma / tamanho_vetor;
    printf("A media e: %.2f", media);
    return 0;
}