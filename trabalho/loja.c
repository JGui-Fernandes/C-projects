#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "loja.h"

int main (){
    Produto produtos[20];
    Venda vendas[20];
    Produto P;
    Venda V;
    int numeroProdutos = 0, numeroVendas = 0;
    char descricao[50], nomeComprador[50];
    int estoque, id, quantidade, produtosCarrinho;
    float valor;
    int resposta = -1;
    float valorTotal;

    inicializarProdutos(produtos, &numeroProdutos);

    while (resposta != 0){
        resposta = menu();

        switch (resposta) {
            case 1:
            // Registrar venda
                printf("Digite o nome do comprador: \n");
                while (getchar() != '\n');
                fgets(nomeComprador, sizeof(nomeComprador), stdin);
                nomeComprador[strcspn(nomeComprador, "\n")] = '\0';
                produtosCarrinho = 0;
                Carrinho carrinho[20];
                id = -1;
                valorTotal = 0;
                int numItens = 0;
                while(id != 0){

                    listarEstoque(produtos, numeroProdutos);

                    if(numeroProdutos == 0){
                        break;
                    }

                    if(numeroProdutos > 0){
                        printf("Digite o ID do produto desejado (0 para confirmar produtos): \n");
                        scanf("%d", &id);

                        if(id < 0 || id > numeroProdutos){
                            printf("\nProduto com ID %d nao encontrado!\n\n", id);
                        }
                        else if (id != 0){
                            Produto p = produtos[id - 1];
                            
                            if(p.estoque < 1){
                                printf("Produto indisponivel!\n\n");
                            }
                            else{
                                printf("Digite a quantidade desejada: \n");
                                scanf("%d", &quantidade);

                                if(quantidade > p.estoque){
                                    printf("\nQuantidade indisponivel.\n\n");
                                }
                                else {
                                    carrinho[produtosCarrinho].produto = p;
                                    carrinho[produtosCarrinho].quantidade = quantidade;
                                    valorTotal += p.valor * quantidade;
                                    produtos[id - 1].estoque -= quantidade;
                                    produtosCarrinho++;
                                    numItens++;
                                    printf("\nProduto adicionado no carrinho!\n\n");
                                }
                            }
                        }
                        
                    }



                }

                if(numeroProdutos > 0){
                    printf("Finalizando compra.\n");

                    int temp = -1;

                    while(temp < 0 || temp > 1){
                    printf("Valor total: %.2f\n", valorTotal);
                    printf("Deseja confirmar a compra? (1 - Sim; 0 - Nao)\n");
                    scanf("%d", &temp);
                    }
                    if(!temp){
                        for(int i = 0; i < produtosCarrinho; i++){
                            produtos[carrinho[i].produto.id - 1].estoque += carrinho[i].quantidade;
                        }
                        printf("Compra cancelada com sucesso!\n\n");
                    }
                    else{
                        setVenda(&V, &numeroVendas, nomeComprador, carrinho, numItens, valorTotal);
                        vendas[numeroVendas - 1] = V;
                        printf("Compra efetuada com sucesso!\n\n");
                    }
                }
                
                
                break;
            case 2:
            // Repor estoque
                printf("Digite o nome do usuario: ");
                break;

            case 3:
            // Mostrar estoque
                listarEstoque(produtos, numeroProdutos);
                break;
            case 4:
            // Mostrar compras
                break;
            case 5:
            // Maior compra
                
                break;
            case 6:
            // Cadastrar produto

                printf("Digite a descricao do produto: \n");
                while (getchar() != '\n');
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';

                printf("Digite a quantidade em estoque:\n");
                scanf("%d", &estoque);

                printf("Digite o valor do produto:\n");
                scanf("%f", &valor);

                setProduto(&P, &numeroProdutos, descricao, estoque, valor);

                produtos[numeroProdutos - 1] = P;
                break;
            case 0:
                break;
        }
    }


    return 0;
}

int menu() {
    int resposta = -1;
    while (resposta < 0 || resposta > 6) {
        printf("\n\nOla, o que deseja fazer?\n");
        printf("1 - Registrar venda.\n");
        printf("2 - Repor estoque de produto.\n");
        printf("3 - Mostrar estoque.\n");
        printf("4 - Mostrar vendas.\n");
        printf("5 - Mostrar maior venda.\n");
        printf("6 - Adicionar produto.\n");
        printf("0 - Sair\n");
        scanf("%d", &resposta);
    }

    return resposta;
}

void setProduto(Produto *P, int *id, char descricao[], int estoque, float valor){
    strcpy(P->descricao, descricao);
    (*id)++;
    P->id = *id;
    P->estoque = estoque;
    P->valor = valor;
}

void listarEstoque(Produto produtos[], int qtdeProdutos){
    if(qtdeProdutos < 1){
        printf("\nNenhum produto em estoque\n");
    }
    else{
        printf("Produtos em estoque: \n\n");
        printf("%-8s %-20s %-10s %-8s\n", "ID", "Descricao", "Valor", "Estoque");
        for (int i = 0; i < qtdeProdutos; i++) {
            if (produtos[i].estoque > 0) {
                Produto p = produtos[i];
                char descricao[21];
                strncpy(descricao, p.descricao, 17);
                descricao[17] = '.';
                descricao[18] = '.';
                descricao[19] = '.';
                descricao[20] = '\0';
                printf("%-8d %-20s %-10.2f %-8d\n", p.id, descricao, p.valor, p.estoque);

            }
        }
    }
}

void setVenda(Venda *V, int *id, char nomeComprador[], Carrinho carrinho[], int numItens, float valorTotal){
    strcpy(V->nomeComprador, nomeComprador);
    (*id)++;
    V->id = *id;
    V->valorTotal = valorTotal;
    V->numItens = numItens;
    for (int i = 0; i < numItens; i++) {
        V->carrinho[i] = carrinho[i];
    }
}

void inicializarProdutos(Produto produtos[], int *numeroProdutos) {
    Produto P;

    setProduto(&P, numeroProdutos, "Calca", 20, 112.00);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Camisa", 18, 95.00);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Bermuda", 23, 49.90);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Saia", 12, 169.00);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Blusa", 9, 120.00);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Moletom", 4, 135.00);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Meia", 17, 12.99);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Tenis", 8, 183.00);
    produtos[*numeroProdutos - 1] = P;

    setProduto(&P, numeroProdutos, "Bota", 3, 219.90);
    produtos[*numeroProdutos - 1] = P;
}
