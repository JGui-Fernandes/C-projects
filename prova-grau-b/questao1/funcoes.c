#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

void createSensorData(SensorData *S, int *id, char name[]){
    S->capacity = 20;
    S->size = 0;
    S->readings = malloc(sizeof(float) * S->capacity);
    strcpy(S->name, name);
    S->name[strcspn(S->name, "\n")] = '\0';
    (*id)++;
    S->id = *id;
}

void addReading(SensorData *S, float valor){
    if(S->size == S->capacity){
        S->capacity = S->capacity * 1.5;
        S->readings = (float *)realloc(S->readings, S->capacity * sizeof(float));
    }
    S->readings[S->size] = valor;
    S->size++;

    printf("Valor adicionado com sucesso!\n\n");
}

void freeSensorData(SensorData *S){
    free(S->readings);
}

int menu(){
    int ans = -1;
    while(ans < 0 || ans > 4){
        printf("Ola, o que deseja fazer?\n\n");
        printf("1 - Criar um novo sensor\n");
        printf("2 - Listar os sensores criados\n");
        printf("3 - Ler dado de sensor\n");
        printf("4 - Liberar espaco de um sensor\n");
        printf("0 - Fechar o programa\n");
        scanf("%d", &ans);
        while (getchar() != '\n');
        printf("\n\n");
    }
    return ans;
}

void listSensorData(SensorData S[], int size){
    if(size != 0){
        for(int i = 0; i < size; i++){
            printf("ID: %d; Nome: %s; Capacidade: %d\n", S[i].id, S[i].name, S[i].capacity);
            printf("Valores lidos: \n");
            for(int j = 0; j < S[i].size; j++){
                printf("   -  %.2f\n", S[i].readings[j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Nenhum sensor registrado.\n");
    }
    printf("\n");
}
