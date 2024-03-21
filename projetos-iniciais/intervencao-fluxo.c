#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    /*for(int i = 0; i <= 20; i++){
        if(i % 2 != 0){
            continue;
        }
        printf("%d\n", i);
    }
    */
    int cont = 1;

    while(1){
        int quadrado = cont * cont;

        if(quadrado > 50){
            break;
        }
        printf("%d\n", quadrado);

        cont++;
    }
    return 0;
}
