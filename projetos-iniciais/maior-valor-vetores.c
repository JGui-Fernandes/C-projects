#include <stdio.h>
#include <math.h>

int main (){

    int valores[10], maiorValor = 0;

    for(int i = 0; i < 10; i++){
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &valores[i]);

        if(i == 0){
            maiorValor = valores[i];
        } else if(valores [i] > maiorValor){
                maiorValor = valores[i];
            }
        
    }

    printf("\nO maior valor digitado foi: %d\n", maiorValor);
    return 0;
}