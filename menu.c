#include <stdio.h>
#include <math.h>

int main()
{
    int resposta;
    double num1, num2;

    printf("Voce deseja fazer uma multiplicação (1), divisão(2) ou soma(3)?\n");
    scanf("%d", &resposta);

    printf("Digite o numero 1:\n");
    scanf("%lf", &num1);
    fflush(stdin);
    printf("Digite o numero 2:\n");
    scanf("%lf", &num2);

    switch (resposta)
    {
    case 1:
        printf("Resultado: %.2lf", num1 * num2);
        break;
    
    case 2:
        printf("Resultado: %.2lf", num1 / num2);
        break;
    case 3:
        printf("Resultado: %.2lf", num1 + num2);
        break;
    default:
        printf("Opção inválida!");
        break;
    }
    return 0;
}
