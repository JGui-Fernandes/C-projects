#include <stdio.h>
#include <math.h>

int main()
{
    int linhas = 3, coluna = 3;

    for(int i = 1; i <= linhas; i++){
        for(int j = 1; j <= coluna; j++){
            printf("%d%d ", i, j);
        }
        printf("\n");
    }
    return 0;
}
