#include <stdio.h>
#include <math.h>

int main(){

    printf("Digite o numero desejado:\n");
    int n = 0;
    scanf("%d", &n);
    printf("\n");

    for (int i = n; i > 1; i--)
    {
        if(i % 2 == 0){
            printf("%d\n", i);
        }
    }
    
    return 0;
}