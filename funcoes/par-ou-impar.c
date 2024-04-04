#include <stdio.h>
#include <math.h>

void par_ou_impar(int num){
    if(num % 2 == 1){
        printf("Impar.\n");
    }
    else{
        printf("Par.\n");
    }
}

int main(){

    int numero = 0;
    while(numero >= 0){
        printf("Digite um numero: ");
        scanf("%d", &numero);

        par_ou_impar(numero);
    }

    printf("Codigo terminado.");
    return 0;
}