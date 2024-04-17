#include <stdio.h>

void somar(int a, int b, int *resposta){
    *resposta = a + b;
}

int main(){
    int a, b, resultado;

    scanf("%d", &a);
    scanf("%d", &b);
    
    somar(a, b, &resultado);

    printf("Resultado: %d", resultado);
    return 0;
}