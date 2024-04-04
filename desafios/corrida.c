#include <stdio.h>

void lerVetor(int vetor[], int tamanho){
    printf("Digite o numero de cada competidor: ");

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

int comparaVetores(int inicial[], int final[], int tamanho){

    int contador = 0;

    for(int i = 0; i < tamanho; i++){
        if(inicial[i] != final[i]){
            contador++;
        }
    }
    return contador;
    
}

int main (){
    int ultrapassagens;
    int numeroCompetidores;
    
    scanf("%d", &numeroCompetidores);

    int posicaoInicial[numeroCompetidores];
    int posicaoFinal[numeroCompetidores];

    lerVetor(posicaoInicial, numeroCompetidores);
    lerVetor(posicaoFinal, numeroCompetidores);

    ultrapassagens = comparaVetores(posicaoInicial, posicaoFinal, numeroCompetidores);

    printf("%d", ultrapassagens);

    return 0;
}