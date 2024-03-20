#include <stdio.h>
#include <math.h>

int main()
{
    double peso, altura, imc;
    scanf("%lf", &peso);
    scanf("%lf", &altura);

    imc = peso / (pow(altura, 2));

    if(imc < 18.5){
        printf("Magreza");
    }else if(imc >= 18.5 && imc <= 24.9 ){
        printf("Saudável");
    } else if( imc >= 25 && imc <= 29.5){
        printf("Sobrepeso");
    } else if( imc >= 30 && imc <= 34.9){
        printf("Obesidade");
    } else if( imc >= 35 && imc <= 39.5){
        printf("Obesidade classe 2");
    } else{
        printf("Obesidade classe 3");
    }

    return 0;
}
