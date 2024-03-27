#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int escolha = 0;



    while(escolha != 3)
    {
        printf("\nMenu: \n");
        printf("1: opcao 1\n");
        printf("2: opcao 2\n");
        printf("3: sair do menu\n\n");
   
        printf("Digite uma das opcoes: ");
        scanf("%d", &escolha);
    
        switch (escolha)
        {
        case 1:
            printf("\nOpcao 1!\n");
            break;
        case 2:
            printf("\nOpcao 2!\n");
            break;
        case 3:
            printf("\nSaindo do menu!\n");
            break;
        default:
            printf("\nDigite uma opcao valida!\n");
            break;
        }

    } 
    

    return 0;
}
