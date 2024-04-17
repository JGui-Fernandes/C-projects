#include <stdio.h>

// Função que incrementa o valor de dois números
void incrementa (int *a, int *b) {
    (*a)++; // Incrementa o valor apontado por a
    (*b)++; // Incrementa o valor apontado por b
}

int main() {
    int x = 5;
    int y = 10;

    // Imprime os valores de x e y antes da chamada da função
    printf("Antes: x = %d, y = %d\n", x, y);

    // Chamando a função incrementa com os endereços de x e y
    incrementa (&x, &y);

    // Imprime os valores de x e y após a chamada da função
    printf("Depois: x = %d, y = %d\n", x, y);

    return 0;
}