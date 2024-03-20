#include <stdio.h>
#include <math.h>

int main(){

    int a, b, c;
    float delta, resposta1, resposta2, raiz;
    float calculo1, calculo2;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    delta = pow(b, 2) - (4 * a * c);

    if (delta > 0)
    {
        // 2 respostas;
        calculo1 = (b * -1) + sqrt(delta); 
        resposta1 = calculo1 / (2 * a);

        calculo2 = (b * -1) - sqrt(delta); 
        resposta2 = calculo2 / (2 * a);

        printf("Respostas: %.2f e %.2f", resposta1, resposta2);
    }
    else if(delta == 0)
    {
        // 1 resposta
        calculo1 = (b * -1); 
        resposta1 = calculo1 / (2 * a);

        printf("Resposta: %.2f", resposta1);
    }
    else
    {
        // 0 respostas
        printf("Não existem respostas reais.");
    }

    
    
    return 0;
}