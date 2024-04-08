#include <stdio.h>

void lerVetor(int vetor[], int tamanho){
    printf("Digite o numero de cada competidor: ");

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

int comparaVetores(int inicial[], int final[], int tamanho){

    int contador = 0;
    for(int i = tamanho-1; i >= 0; i--){
        // print usado para conferir as trocas de posicoes
        // printf("%d --- %d %d %d %d %d\n", i, inicial[0], inicial[1], inicial[2], inicial[3], inicial[4]);
        
        // executa ate que a posicao seja igual a final
        while(inicial[i] != final[i]){
            // confere as ultrapassagem de tras para frente 
            for(int j = i - 1; j >= 0; j--){
                int antigo = inicial[i];
                int novo = inicial[j];
                inicial[i] = novo;
                inicial[j] = antigo;
                contador++; 

                // se chegar na posicao certa, para as ultrapassagens desta posicao
                if(inicial[i] == final[i]){
                    break;
                }
            }    
        }
    }

    return contador;
    
}

int main (){
    int ultrapassagens;
    int numeroCompetidores;

    printf("Digite o numero de corredores: ");
    scanf("%d", &numeroCompetidores);

    int posicaoInicial[numeroCompetidores];
    int posicaoFinal[numeroCompetidores];

    lerVetor(posicaoInicial, numeroCompetidores);
    lerVetor(posicaoFinal, numeroCompetidores);

    ultrapassagens = comparaVetores(posicaoInicial, posicaoFinal, numeroCompetidores);

    printf("Ocorreram %d ultrapassagens", ultrapassagens);

    return 0;
}