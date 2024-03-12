#include <stdio.h>

#define VALOR_DOLAR 4.95;
int main(){
    float reais, dolares;
    scanf("%f", &dolares);

    reais = dolares * VALOR_DOLAR; 

    printf("Reais: %f\n", reais);
    return 0;
}
