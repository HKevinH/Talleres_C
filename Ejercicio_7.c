#include <stdio.h>

int main() {
    int Tam, i; 
    printf("Ingrese el numero de elementos en el vector: ");
    scanf("%d", &Tam);

    int vectorA[Tam];

    printf("Ingrese los elementos del vector A:\n");
    for (i = 0; i < Tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vectorA[i]);
    }

    int ordenado = 1; 

    for (i = 1; i < Tam; i++) {
        if (vectorA[i - 1] > vectorA[i]) {
            ordenado = 0;
            break; 
        }
    }

    if (ordenado) {
        printf("SI\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

