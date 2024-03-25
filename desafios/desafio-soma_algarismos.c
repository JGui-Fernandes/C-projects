#include <stdio.h>
#include <math.h>

int main()
{
    int numero, soma = 0;

    printf("Digite um número: ");
    scanf("%d", &numero);

    int numeroAux = numero;

    while (numero != 0) 
    {
        soma += numero % 10;
        numero /= 10;     
    }

    printf("Resultado: %d\n", soma);

    return 0;
}