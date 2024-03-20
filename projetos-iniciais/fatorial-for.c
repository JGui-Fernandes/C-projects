#include <stdio.h>
#include <math.h>

int main()
{
    int numero;
    int resultado = 1;
    scanf("%d", &numero);

    for(int i = numero; i >= 1; i--){
        resultado = resultado * i;
    }

    printf("O fatorial de %d eh: %d\n", numero, resultado);

    return 0;
}
