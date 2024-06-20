#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    FILE *arq;
    float mat, fis, qui, media;

    printf("Digite a nota de matematica: ");
    scanf("%f", &mat);

    printf("Digite a nota de fisica: ");
    scanf("%f", &fis);
        
    printf("Digite a nota de quimica: ");
    scanf("%f", &qui);

    media = (mat + fis + qui) / 3;

    arq = fopen("./output/media-notas.txt", "wt");

    if(arq == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
        return 1;
    }

    char linha1[50], linha2[50], cat[50]; 
    strcpy(linha1, "Matematica     Fisica    Quimica    Media"); 

    strcpy(linha2, "%f   %f   %f   %f", mat, fis, qui, media);

    int result = fputs(linha1, arq);

    if(result == EOF){
        printf("Erro na Gravacao\n");
    }


    return 0;
}