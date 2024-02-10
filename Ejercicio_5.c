#include <stdio.h>

int main() {
    int Tam, i; 
    printf("Ingrese el numero de elementos en el vector: ");
    scanf("%d", &Tam);

    int vectorOriginal[Tam];
    int vectorInverso[Tam];

    printf("Ingrese los elementos del vector:\n");
    for ( i = 0; i < Tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vectorOriginal[i]);
    }

    for ( i = 0; i < Tam; i++) {
        vectorInverso[Tam - 1 - i] = vectorOriginal[i];
    }

    printf("Vector inverso:\n");
    for ( i = 0; i < Tam; i++) {
        printf("%d ", vectorInverso[i]);
    }
    printf("\n");

    return 0;
}

