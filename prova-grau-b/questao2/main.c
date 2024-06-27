#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funcoes.c"

#define TAM_VETOR 17

int main (){
    char fabricante[20], modelo[20];
    int ano, tanque;
    float consumo;
    Carro carro;
    int id = 0;

    Carro carros[TAM_VETOR];

    FILE *arq;

    arq = fopen("veiculos.txt", "r");

    if( arq == NULL ){
        printf("Problemas na CRIACAO do arquivo\n");
        return 1;
    }

    while (fscanf(arq, "%s %s %d %d %f", fabricante, modelo, &ano, &tanque, &consumo) == 5)
    {
        setCarro(&carro, &id, fabricante, modelo, ano, tanque, consumo);
        carros[id-1] = carro;
    }

    verificaAno(carros, TAM_VETOR);
    verificaVogalOuConsoante(carros, TAM_VETOR);
    menosAutonomia(carros, TAM_VETOR);
    maiorAutonomia(carros, TAM_VETOR);
    return 0;
}
