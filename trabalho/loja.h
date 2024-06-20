#ifndef LOJA_H
#define LOJA_H

typedef struct {
    int id;
    char descricao[50];
    int estoque;
    float valor;
} Produto;

typedef struct{
    Produto produto;
    int quantidade;
} Carrinho;

typedef struct {
    int id;
    char nomeComprador[50];
    Produto produto;
    float valorTotal;
    Carrinho carrinho[20];
} Venda;

int menu();
void setProduto(Produto *P, int *id, char descricao[], int estoque, float valor);
void listarEstoque(Produto produtos[], int qtdeProdutos);

#endif