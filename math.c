#include <stdio.h>
#include <math.h>

int main()
{
    double numero = 16;
    double resultado = sqrt(numero);
    printf("Raiz de %.1f é %.1f\n", numero, resultado);

    numero = 100;
    resultado = log(numero);
    printf("O logaritmo de %.1f é %.1f.\n", numero, resultado);

    double angulo = 45;
    resultado = sin(angulo * M_PI / 180);
    printf("o seno de %.1f é %.1f", angulo, resultado);


    return 0;
}
