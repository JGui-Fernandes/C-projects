#include <stdio.h>
#include <math.h>

int fatorial(int valor){
    int resultado = 1;
    for(int i = valor; i > 0; i--){
        resultado *= i;
    }

    return resultado;
}

int main(){

    int numero = 0;
    printf("Digite o numero desejado: ");
    scanf("%d", &numero);

    int resultado;
    resultado = fatorial(numero);

    printf("O fatorial de %d eh %d", numero, resultado);

    return 0;
}

