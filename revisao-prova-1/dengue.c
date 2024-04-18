#include <stdio.h>

int main(){
    int dias, valor1 = 0, valor2 = 0, valor3 = 0;

    printf("Tempo da doenca em dias\n");
    scanf("%d", &dias);

    if(dias >= 6){
        while(valor1 == 0){
            printf("Resultado do teste NS1. (1 ou -1)\n");
            scanf("%d", &valor1);
        }
        while(valor2 == 0){
            printf("Resultado do teste IgM. (1 ou -1)\n");
            scanf("%d", &valor2);
        }
        while(valor3 == 0){
            printf("Resultado do teste IgG. (1 ou -1)\n");
            scanf("%d", &valor3);   
        }

        if(valor1 < 0 && valor2 < 0 && valor3 > 0){
            printf("Provavel infeccao previa");
        }
        if(valor1 > 0 && valor2 < 0 && valor3 < 0){
            printf("Infeccao aguda");
        }
        if(valor1 > 0 && valor2 > 0 && valor3 < 0){
            printf("Infeccao aguda");
        }
        if(valor1 < 0 && valor2 < 0 && valor3 < 0){
            printf("Dengue improvavel");
        }
        if(valor1 > 0 && valor2 < 0 && valor3 > 0){
            printf("Infeccao aguda e provavel infeccao previa");
        }
    }
    if(dias < 6){
         while(valor1 == 0){
            printf("Resultado do teste IgM. (+ ou -)\n");
            scanf("%d", &valor1);
        }
        while(valor2 == 0){
            printf("Resultado do teste IgG. (+ ou -)\n");
            scanf("%d", &valor2);
        }
        
        if(valor1 < 0 && valor2 > 0){
            printf("Provavel infeccao previa");
        }
        if(valor1 > 0 && valor2 < 0){
            printf("Infeccao aguda");
        }
        if(valor1 < 0 && valor2 < 0){
            printf("Dengue improvavel");
        }
        if(valor1 > 0 && valor2 > 0){
            printf("Infeccao aguda e provavel infeccao previa");
        }
    }
    return 0;
}