#include <stdio.h>

void trocaValores(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}

int main(){

    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);
    
    trocaValores(&x, &y);

    printf("X: %d  \nY: %d", x, y);
    return 0;
}