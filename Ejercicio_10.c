#include <stdio.h>

int main() {
    long long int FIB[100]; // Utilizamos "long long int" para manejar números grandes
    int i;

    FIB[0] = 0;
    FIB[1] = 1;

    for (i = 2; i < 100; i++) {
        FIB[i] = FIB[i - 1] + FIB[i - 2];
    }

    printf("Los primeros 100 Numeros de la serie Fibonacci son:\n");
    for (i = 0; i < 100; i++) {
        printf("\n%lld", FIB[i]);
        if (i < 99) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}

