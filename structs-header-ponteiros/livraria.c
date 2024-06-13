#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[40];
    char autor[50];
    int id;
    int quantidadeDisponivel;
} Livro;

typedef struct {
    char nome[50];
    int id;
    Livro livrosEmprestados[10];
    int numeroLivros;
} Usuario;

void setLivro(Livro *L, char titulo[], char autor[], int *id, int quantidadeDisponivel);
void getLivro(Livro livro);
void listarLivros(Livro livros[], int qtdeLivros);
void setUsuario(Usuario *U, char nome[], int *id);
void getUsuario(Usuario U);
void listarUsuarios(Usuario usuarios[], int qtdeUsuarios);
void emprestarLivro(Livro *L, Usuario *U);
void devolverLivro(Livro *L, Usuario *U);
int menu();

int main() {
    int qtdeUsuarios = 0, qtdeLivros = 0;
    Usuario usuarios[10];
    Livro livros[10];
    char titulo[50], autor[50], nome[50];
    int quantidade, escolhaUsuario, escolhaLivro;
    Livro livro;
    Usuario usuario;
    int resposta = -1;

    while (resposta != 0){
        resposta = menu();

        switch (resposta) {
            case 1:
                printf("Digite o titulo: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';

                printf("Digite o nome do autor: ");
                fgets(autor, sizeof(autor), stdin);
                autor[strcspn(autor, "\n")] = '\0';

                printf("Digite a quantidade disponivel: ");
                scanf("%d", &quantidade);

                while (getchar() != '\n');
                
                setLivro(&livro, titulo, autor, &qtdeLivros, quantidade);
                livros[livro.id-1] = livro;
                break;
            case 2:
                printf("Digite o nome do usuario: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                setUsuario(&usuarios[qtdeUsuarios], nome, &qtdeUsuarios);
                break;

            case 3:
                listarLivros(livros, qtdeLivros);
                break;
            case 4:
                listarUsuarios(usuarios, qtdeUsuarios);
                break;
            case 5:
                if(qtdeLivros < 1){
                    printf("Nenhum livro cadastrado.\n\n");
                }
                else{
                    printf("Digite o ID do usuario desejado: \n");
                    listarUsuarios(usuarios, qtdeUsuarios);
                    scanf("%d", &escolhaUsuario);

                    printf("Digite o ID do livro desejado: \n");
                    listarLivros(livros, qtdeLivros);
                    scanf("%d", &escolhaLivro);
                    
                    emprestarLivro(&livros[escolhaLivro - 1], &usuarios[escolhaUsuario - 1]);
                }
                break;
            case 6:
                printf("Digite o ID do usuario: \n");
                listarUsuarios(usuarios, qtdeUsuarios);
                scanf("%d", &escolhaUsuario);

                escolhaUsuario--;

                if(usuarios[escolhaUsuario].numeroLivros < 1){
                    printf("Usuario nao possui livros emprestados no momento.\n\n");
                }
                else{
                    printf("Digite o ID do livro a ser devolvido: \n\n");
                    listarLivros(usuarios[escolhaUsuario].livrosEmprestados, usuarios[escolhaUsuario].numeroLivros);
                    scanf("%d", &escolhaLivro);
                    
                    escolhaLivro--;

                    devolverLivro(&usuarios[escolhaUsuario].livrosEmprestados[escolhaLivro], &usuarios[escolhaUsuario]);
                }
                break;
            case 0:
                printf("Saindo do programa.\n\n");
                break;
            default:
                printf("Opção inválida.\n\n");
                break;
        }
    }

    return 0;
}

void setLivro(Livro *L, char titulo[], char autor[], int *id, int quantidadeDisponivel) {
    strcpy(L->titulo, titulo);
    strcpy(L->autor, autor);
    (*id)++;
    L->id = *id;
    L->quantidadeDisponivel = quantidadeDisponivel;
}

void getLivro(Livro L) {
    printf("ID: %d, Titulo: %s, Autor: %s, Quantidade: %d\n\n", L.id, L.titulo, L.autor, L.quantidadeDisponivel);
}

void listarLivros(Livro livros[], int qtdeLivros) {
    if (qtdeLivros < 1) {
        printf("Nenhum livro cadastrado.\n\n");
    } else {
        printf("Livros cadastrados:\n");
        for (int i = 0; i < qtdeLivros; i++) {
            getLivro(livros[i]);
        }
    }
}

void setUsuario(Usuario *U, char nome[], int *id) {
    strcpy(U->nome, nome);
    (*id)++;
    U->id = *id;
    U->numeroLivros = 0;
}

void getUsuario(Usuario U) {
    printf("ID: %d, Nome: %s\n", U.id, U.nome);
    printf("Livros emprestados: ");
    if (U.numeroLivros > 0) {
        for (int i = 0; i < U.numeroLivros; i++) {
            getLivro(U.livrosEmprestados[i]);
        }
        printf("\n");
    } else {
        printf("Nenhum livro emprestado.\n\n");
    }
}

void listarUsuarios(Usuario usuarios[], int qtdeUsuarios) {
    if (qtdeUsuarios < 1) {
        printf("Nenhum usuario cadastrado.\n\n");
    } else {
        printf("Usuarios cadastrados:\n");
        for (int i = 0; i < qtdeUsuarios; i++) {
            getUsuario(usuarios[i]);
        }
    }
}

void emprestarLivro(Livro *L, Usuario *U) {
    if (L->quantidadeDisponivel <= 0) {
        printf("Livro indisponivel!\n\n");
    } else if (U->numeroLivros < 10) {
        U->livrosEmprestados[U->numeroLivros] = *L;
        L->quantidadeDisponivel--;
        U->numeroLivros++;
        printf("Livro emprestado com sucesso!\n\n");
    } else {
        printf("Devolva um livro antes de pegar outro!\n\n");
    }
}

void devolverLivro(Livro *L, Usuario *U) {
    int posicao = -1;
    for (int i = 0; i < U->numeroLivros; i++) {
        if (U->livrosEmprestados[i].id == L->id) {
            posicao = i;
            break;
        }
    }
    if (posicao != -1) {
        for (int i = posicao; i < U->numeroLivros - 1; i++) {
            U->livrosEmprestados[i] = U->livrosEmprestados[i + 1];
        }

        //printf("\n --- Antes: %d\n\n", L->quantidadeDisponivel);
        L->quantidadeDisponivel++; 
        //printf("\n --- Depois: %d\n\n", L->quantidadeDisponivel);

        U->numeroLivros--;
        printf("Livro devolvido com sucesso!\n");
    } else {
        printf("Livro nao encontrado.\n");
    }
}


int menu() {
    int resposta = -1;
    while (resposta < 0 || resposta > 6) {
        printf("\nOla, o que deseja fazer?\n");
        printf("1 - Cadastrar um livro.\n");
        printf("2 - Cadastrar um usuario.\n");
        printf("3 - Listar livros cadastrados.\n");
        printf("4 - Listar usuarios cadastrados.\n");
        printf("5 - Pegar um livro emprestado.\n");
        printf("6 - Devolver um livro.\n");
        printf("0 - Sair\n");
        scanf("%d", &resposta);
    }

    return resposta;
}
