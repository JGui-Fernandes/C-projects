#include <stdio.h>
#include <math.h>

int main(){

    int vet[10];
    int aux;

    printf("Digite os numeros do vetor\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 10; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    printf("Ordem correta: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", vet[i]);
    }
    
    

    return 0;
}