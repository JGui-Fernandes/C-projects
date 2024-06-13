#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int *v;

    v = (int*)malloc(sizeof(int)*3);

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;

    for(int i = 0; i < 3; i++){
        printf("%d\n", v[i]);
    }
    return 0;
}