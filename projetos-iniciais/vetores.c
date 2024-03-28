#include <stdio.h>
#include <math.h>

int main(){

    int vetor[5] = {10, 20, 30, 40, 50};

    for(int i = 0; i < 5; i++){
        printf("Termo %d: %d\n", i + 1, vetor[i]);
    }
    return 0;
}