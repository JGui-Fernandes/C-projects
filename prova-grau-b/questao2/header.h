#ifndef HEADER_H
#define HEADER_H

typedef struct {
    int id;
    char fabricante[20], modelo[20];
    int ano, tanque;
    float consumo;
} Carro;

void setCarro(Carro *C, int *id, char fabricante[], char modelo[], int ano, int tanque, float consumo);
void verificaAno(Carro carros[], int tamanhoVetor);
void verificaVogalOuConsoante(Carro carros[], int tamanhoVetor);
void menosAutonomia(Carro carros[], int tamanhoVetor);
void maiorAutonomia(Carro carros[], int tamanhoVetor);
int verificaVogal(char letra);
int verificaNumero(char str[]);

#endif