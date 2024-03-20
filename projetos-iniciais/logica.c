#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int a = 5, b = 5;
    printf("a == b: %d\n", a==b);

    int c = 10, d = 5;
    printf("c != d: %d\n", c !=  d);

    int e = 10, f = 5;
    printf("e < f: %d\n", e < f);


    bool condicao1= true, condicao2 = false;

    bool resultado_and = condicao1 && condicao2;
    printf("Resultado AND: %d\n", resultado_and);

    bool resultado_or = condicao1 || condicao2;
    printf("Resultado OR: %d\n", resultado_or);
    return 0;
}
