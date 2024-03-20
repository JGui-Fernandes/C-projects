#include <stdio.h>

int main(){

    fflush(stdin);

    float peso, altura, imc;

    printf("Digite seu peso: \n");
    scanf("%f", &peso);
    
    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("IMC: %f", imc);
    
    return 0;
}
