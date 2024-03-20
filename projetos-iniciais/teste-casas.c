#include <stdio.h>
#include <stdlib.h>

int main(){

    float numero;
    numero = -2.5;

    printf("1234567890\n");
    printf("%-7f\n", numero);
    printf("%7f\n", numero);
    printf("%7.0f\n", numero);
    printf("%7.3f\n", numero);
    printf("%8.3f\n", numero);
    printf("%9.3f\n", numero);
    printf("\n");
    printf("%8.4f\n", numero);
    printf("%8.1f\n", numero);
    printf("%6.12f\n", numero);

    return 0;
 
    /*
    1234567890
    -2.500000
    -2.500000
        -3
    -2.500
    -2.500
    -2.500

    -2.5000
        -2.5
    -2.500000000000
    */
}