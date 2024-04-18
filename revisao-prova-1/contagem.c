#include <stdio.h>

int main (){

    int numero;

    printf("Digite o numero desejado: ");
    scanf("%d", &numero);

    for(int i = 0; i < 5; i++){
        for(int j = 1; j < numero; j++){
            printf("%d", j);
        }
        for(int j = numero; j > 1; j--){
            printf("%d", j);
        }
    }

    return 0;
}