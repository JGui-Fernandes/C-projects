#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "loja.h"

int main (){
    Produto produtos[10];
    Venda vendas[10];
    Produto P;
    int numeroProdutos = 0, numeroCompras = 0;
    char descricao[50], nomeComprador[50];
    int estoque, id, quantidade, produtosCarrinho;
    float valor;
    int resposta = -1;
    float valorTotal;

    while (resposta != 0){
        resposta = menu();

        switch (resposta) {
            case 1:
            // Registrar venda
                printf("Digite o nome do comprador: \n");
                while (getchar() != '\n');
                fgets(nomeComprador, sizeof(nomeComprador), stdin);
                nomeComprador[strcspn(nomeComprador, "\n")] = '\0';
                valor = 0;
                produtosCarrinho = 0;
                Carrinho carrinho[10];
                while(resposta != 0){

                    listarEstoque(produtos, numeroProdutos);

                    if(numeroCompras > 0){
                        printf("Digite o ID do produto desejado (0 para confirmar produtos): \n");
                        scanf("%d", &id);

                        if(id < 0 || id > numeroCompras){
                            printf("Produto com ID %d não encontrado!\n\n", id);
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
                                    printf("Quantidade indisponivel.\n");
                                }
                                else{
                                    carrinho[produtosCarrinho].produto = p;
                                    carrinho[produtosCarrinho].quantidade = quantidade;
                                    valor += p.valor * quantidade;
                                    printf("Produto adicionado no carrinho.\n");
                                }
                            }
                        }
                        else if(id == 0){
                            printf("Finalizando compra.");
                            printf("%d", valor);
                        }
                    }



                }
                resposta = 1;
                
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
                printf("%-8d %-20s %-10.2f %-8d\n\n", p.id, descricao, p.valor, p.estoque);

            }
        }
    }
}