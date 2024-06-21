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
    Carrinho carrinho[20];
    int numItens;
    float valorTotal;
} Venda;

int menu();
void setProduto(Produto *P, int *id, char descricao[], int estoque, float valor);
void listarEstoque(Produto produtos[], int qtdeProdutos);
void setVenda(Venda *V, int *id, char nomeComprador[], Carrinho carrinho[], int numItens, float valorTotal);
void inicializarProdutos(Produto produtos[], int *numeroProdutos);

#endif