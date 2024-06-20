#include <stdio.h>
#include <string.h>

int main (){
    
    char string1[50], string2[50], caractere;
    int cont = 0;

    printf("Digite a primeira string:\n");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Digite a segunda string:\n");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';

    if(strcmp(string1, string2) == 0){
        printf("Strings iguais\n");
    }

    strcat(string1, string2);

    printf("%s\n", string1);

    printf("Escolha um caractere para ser procurado: ");
    scanf("%c", &caractere);

    for(int i = 0; i < strlen(string1); i++){
        if(string1[i] == caractere){
            cont++;
        }
    }

    printf("%d caracteres\n", cont);

    printf("%d", strlen(string1));
    return 0;
}