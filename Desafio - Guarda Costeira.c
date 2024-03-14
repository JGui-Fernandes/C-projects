#include <stdio.h>
#include <math.h>

int main()
{
    float velLadrao, velPolicia, distancia, tempoLadrao, tempoPolicia, hipotenusa;

    printf("Digite a distancia entre o policial e o ladrão:\n");
    scanf("%f", &distancia);

    fflush(stdin);
    
    printf("Digite a velocidade do ladrão:\n");
    scanf("%f", &velLadrao);
    
    fflush(stdin);

    printf("Digite a velocidade do policial:\n");
    scanf("%f", &velPolicia);

    hipotenusa = sqrt((distancia * distancia) + (12 * 12));

    tempoLadrao = 12 / velLadrao;
    tempoPolicia = hipotenusa / velPolicia;

    if(tempoLadrao < tempoPolicia){
        printf("N");
    } else{
        printf("S");
    }
    return 0;
}
