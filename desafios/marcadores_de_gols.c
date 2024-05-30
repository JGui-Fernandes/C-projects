#include <math.h>
#include <stdio.h>

int main()
{
    int jogadores, jogos, golEmTodos = 0;
    printf("Digite o numero de jogadores:\n");
    scanf("%d", &jogadores);
    printf("Digite o numero de jogos:\n");
    scanf("%d", &jogos);
    int matriz[jogadores][jogos];
    

    for(int i = 0; i < jogadores; i++){
        printf("Gols nos jogos do jogador %d: ", i + 1);
        for(int j = 0; j < jogos; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < jogadores; i++){
        int jogosComGols = 0;
        for(int j = 0; j < jogos; j++){
            if(matriz[i][j] > 0){
                jogosComGols++;
            }
        }
        if(jogosComGols == jogos){
            golEmTodos++;
        }
    }

    printf("%d", golEmTodos);
    return 0;
}
