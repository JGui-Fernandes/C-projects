#include <stdio.h>

float soma( float a, float b);
float divide( float a, float b);
float multiplica( float a, float b);
float diminui( float a, float b);

float main(){
    float a, b, resultado;
    int opcao = 0;
    while (opcao == 0 || opcao > 4){
        printf("Digite a opcao de calculo desejada: \n1 - soma\n2 - subtracao\n3 - multiplicacao\n4 - divisao\n");
        scanf("%d", &opcao);

        if(opcao == 0 || opcao > 4){
            printf("Valor invalido.\n");
        }
    }

    printf("Digite o primeiro valor: ");
    scanf("%f", &a);
    printf("Digite o segundo valor: ");
    scanf("%f", &b);

    switch (opcao)
        {
        case 1:
            resultado = soma(a, b);
            break;
        case 2:
            resultado = diminui(a, b);
            break;
        case 3:
            resultado = multiplica(a, b);
            break;
        case 4:
            resultado = divide(a, b);
            break;
        default:
            break;
        }

    printf("Resultado: %.2f", resultado);
}

float soma(float a, float b){
    return a + b;
}
float diminui(float a, float b){
    return a - b;
}
float multiplica(float a, float b){
    return a * b;
}
float divide(float a, float b){
    return a / b;
}