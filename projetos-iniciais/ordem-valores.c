#include <stdio.h>
#include <math.h>

int main(){

    int numeros[10], ordem[10];
    int tamanhoVetor = (sizeof(numeros) / sizeof(numeros[0]));

    for(int i = 0; i < tamanhoVetor; i++){
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for(int i = 0; i < tamanhoVetor; i++){
        
    }
    return 0;
}