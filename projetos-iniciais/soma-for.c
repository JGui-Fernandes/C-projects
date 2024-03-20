#include <stdio.h>
#include <math.h>

int main()
{
    int soma = 0;
    for (int i = 0; i <= 10; i++)
    {
        soma += i;
    }
    
    printf("%d\n", soma);
    return 0;
}
