#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "header.h"

void setCarro(Carro *C, int *id, char fabricante[], char modelo[], int ano, int tanque, float consumo){
    (*id)++;
    C->id = *id;
    strcpy(C->fabricante, fabricante);
    strcpy(C->modelo, modelo);
    C->ano = ano;
    C->tanque = tanque;
    C->consumo = consumo;
}

void verificaAno(Carro carros[], int tamanhoVetor){
    printf("Carros construidos entre 2015 e 2018:\n\n");
    for(int i = 0; i < tamanhoVetor; i++){
        if(carros[i].ano >= 2015 && carros[i].ano <= 2018){
            printf("Fabricante: %s;  Modelo: %s\n", carros[i].fabricante, carros[i].modelo);
        }
    }
    printf("\n");
}

void verificaVogalOuConsoante(Carro carros[], int tamanhoVetor){
    printf("Carros que comecam com vogal ou terminam com consoante:\n\n");
    for(int i = 0; i < tamanhoVetor; i++){
        if(verificaNumero(carros[i].modelo) == 0){
            int tamanhoString = strlen(carros[i].modelo);
            if(verificaVogal(carros[i].modelo[0]) == 1 || verificaVogal(carros[i].modelo[tamanhoString - 1]) == 0){
                printf("Modelo: %s\n", carros[i].modelo);
            }
        }
    }
    printf("\n");
}

void menosAutonomia(Carro carros[], int tamanhoVetor){
    Carro menos;
    float menorAutonomia, autonomia;
    printf("Carro com a menor autonomia:\n");
    for(int i = 0; i < tamanhoVetor; i++){
        if(i == 0){
            menos = carros[0];
            menorAutonomia = (float)carros[0].tanque * carros[0].consumo;
        }
        else{
            autonomia = (float)carros[i].tanque * carros[i].consumo;
            if(autonomia < menorAutonomia){
                menos = carros[i];
                menorAutonomia = autonomia;
            }
        }
    }

    printf("Modelo: %s;  Ano: %d;  Autonomia: %.2f\n\n", menos.modelo, menos.ano, menorAutonomia);
}

void maiorAutonomia(Carro carros[], int tamanhoVetor){
    Carro maior;
    float maiorAutonomia, autonomia;
    printf("Carro com a maior autonomia:\n");
    for(int i = 0; i < tamanhoVetor; i++){
        if(i == 0){
            maior = carros[0];
            maiorAutonomia = (float)carros[0].tanque * carros[0].consumo;
        }
        else{
            autonomia = (float)carros[i].tanque * carros[i].consumo;
            if(autonomia > maiorAutonomia){
                maior = carros[i];
                maiorAutonomia = autonomia;
            }
        }
    }

    printf("Modelo: %s;  Ano: %d;  Autonomia: %.2f", maior.modelo, maior.ano, maiorAutonomia);
}

int verificaVogal(char letra){
    if(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U'){
        return 1;
    }
    return 0;
}

int verificaNumero(char str[]){
    if(str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' ){
        return 1;
    }
    return 0;
}