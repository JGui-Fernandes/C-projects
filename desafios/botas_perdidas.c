#include <stdio.h>
#include <math.h>


int main()
{
    printf("Digite a quantidade de botas: ");
    int qtdeBotas = 0, contPares = 0;
    scanf("%d", &qtdeBotas);
    
    int esquerdo[qtdeBotas], contEsquerdo = 0;
    int direito[qtdeBotas], contDireito = 0;

    for(int i = 0; i < qtdeBotas; i++){
        char lado;
        int tamanho;
        printf("Digite o tamanho e o lado (TT L): ");
        scanf("%d %c", &tamanho, &lado);

        if(lado == 'E' || lado == 'e'){
            esquerdo[contEsquerdo] = tamanho;
            contEsquerdo++;
        } else if(lado == 'D' || lado == 'd'){
            direito[contDireito] = tamanho;
            contDireito++;
        } else{
            printf("Lado invalido, por favor escreva novamente.\n");
            i--;
        }
    }

    for(int i = 0; i < contEsquerdo; i++){
        for(int j = 0; j < contDireito; j++){
            int tamanhoEsq = esquerdo[i];
            int tamanhoDir = direito[j];

            if(tamanhoDir != 0 && tamanhoEsq != 0){
                if(tamanhoDir == tamanhoEsq){
                    contPares++;
                    esquerdo[i] = 0;
                    direito[j] = 0;
                }
            }
        }
    }

    printf("Numero de pares:  %d ", contPares);
    return 0;
}