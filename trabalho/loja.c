#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char descricao[50];
    int estoque;
    float valor;
} Produto;

typedef struct {
    int id;
    char nomeComprador[50];
    Produto produto;
    float valorTotal;
} Venda;

int menu();
void setProduto(Produto *P, int *id, char descricao[], int estoque, float valor);


int main (){
    Produto produtos[10];
    Produto P;
    int idProduto = 1;
    char descricao[50];
    int estoque;
    float valor;
    int resposta = -1;

    while (resposta != 0){
        resposta = menu();

        switch (resposta) {
            case 1:
            // Registrar venda
                printf("Digite o titulo: ");
                
                break;
            case 2:
            // Repor estoque
                printf("Digite o nome do usuario: ");
                break;

            case 3:
            // Mostrar estoque
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
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';

                printf("Digite a quantidade em estoque:\n");
                scanf("%d", &estoque);

                printf("Digite o valor do produto:\n");
                scanf("%f", &valor);

                setProduto(&P, &idProduto, descricao, estoque, valor);

                produtos[idProduto - 1] = P;
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
        printf("\nOla, o que deseja fazer?\n");
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
