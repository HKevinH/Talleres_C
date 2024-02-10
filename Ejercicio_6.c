#include <stdio.h>

int main() {
    int Tam, i; 
    printf("Ingrese el número de elementos en los vectores: ");
    scanf("%d", &Tam);

    int vectorA[Tam];
    int vectorB[Tam];

    printf("Ingrese los elementos del vector A:\n");
    for (i = 0; i < Tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vectorA[i]);
    }

    printf("Ingrese los elementos del vector B:\n");
    for (i = 0; i < Tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vectorB[i]);
    }

    int iguales = 1; 

    for (i = 0; i < Tam; i++) {
        if (vectorA[i] != vectorB[i]) {
            iguales = 0; 
            break; 
        }
    }

    if (iguales) {
        printf("Iguales\n");
    } else {
        printf("Diferentes\n");
    }

    return 0;
}

