#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void leVetor(char vetor[], int tamanho);
void comparaVetores(char vetor1[], char vetor2[], int posicao1, int posicao2);

int main() {
    int tamanho1, tamanho2, numeroComparacoes, posicao1, posicao2;
    char *vetor1, *vetor2;

    printf("Digite o numero de caracteres da primeira cadeia: ");
    scanf("%d", &tamanho1);

    printf("Digite o numero de caracteres da segunda cadeia: ");
    scanf("%d", &tamanho2);

    vetor1 = (char *)malloc((tamanho1 + 1) * sizeof(char));
    vetor2 = (char *)malloc((tamanho2 + 1) * sizeof(char));

    leVetor(vetor1, tamanho1);
    leVetor(vetor2, tamanho2);

    printf("Digite a quantidade de comparacoes desejadas: ");
    scanf("%d", &numeroComparacoes);

    for (int i = 0; i < numeroComparacoes; i++) {
        printf("Digite a posicao inicial desejada: ");
        scanf("%d", &posicao1);
        printf("Digite a posicao final desejada: ");
        scanf("%d", &posicao2);

        comparaVetores(vetor1, vetor2, posicao1, posicao2);
    }

    free(vetor1);
    free(vetor2);

    return 0;
}

void leVetor(char vetor[], int tamanho) {
    printf("Digite a sequencia desejada: ");
    for (int i = 0; i < tamanho; i++) {
        scanf(" %c", &vetor[i]);
    }
    vetor[tamanho] = '\0';
}

void comparaVetores(char vetor1[], char vetor2[], int posicao1, int posicao2) {
    int tamanhoSubString = posicao2 - posicao1 + 1;
    char subString[tamanhoSubString];
    int tamanhoVetor = strlen(vetor1);
    int contagemRepeticoes = 0;
    int j = 0;

    for (int i = posicao1 - 1; i < posicao2; i++) {
        subString[j] = vetor2[i];
        j++;
    }
    subString[j] = '\0';

    for (int i = 0; i <= tamanhoVetor - tamanhoSubString; i++) {
        char temp[tamanhoSubString + 1]; 
        strncpy(temp, &vetor1[i], tamanhoSubString);
        temp[tamanhoSubString] = '\0';

        if (strcmp(temp, subString) == 0) {
            contagemRepeticoes++;
        }
    }

    printf("%d\n", contagemRepeticoes);
}
