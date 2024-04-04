#include <stdio.h>

float media (float a, float b){
    return (a * 0.33) + (b * 0.67);
}

int main(){

    float nota1, nota2;

    printf("Digite nota do grau A: ");
    scanf("%f", &nota1);
    printf("Digite nota do grau B: ");
    scanf("%f", &nota2);

    float total;
    total = media(nota1, nota2);

    printf("Media final: %0.2f", total);

    return 0;
}


