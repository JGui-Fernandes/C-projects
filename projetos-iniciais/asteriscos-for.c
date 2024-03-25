#include <stdio.h>
#include <math.h>

int main()
{
    int numeroLinhas;
    printf("Escreva o numero de linhas desejadas: ");
    scanf("%d", &numeroLinhas);

    char texto = '*';
    

    /*
    for(int i = 0; i < numeroLinhas; i++){
        for(int j = 1; j <= (i*2)+1; j++){
            printf("%c ", texto);
        }
        printf("\n");
    }
    */
   for(int i = 0; i < numeroLinhas; i++){
        for(int k = 0; k < numeroLinhas - i; k++){
            printf("  ");
        }
        for(int j = 1; j <= (i*2)+1; j++){
            printf("%c ", texto);
        }
        printf("\n");
    }
   


    return 0;
}
