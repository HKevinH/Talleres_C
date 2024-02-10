#include <stdio.h>

int main() {
    int Tam; 
    printf("Ingrese el numero de elementos en el vector: ");
    scanf("%d", &Tam);
    int i;

    int vectorX[Tam];

    printf("Ingrese los elementos del vector X:\n");
    for (i = 0; i < Tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vectorX[i]);
    }

    int numero;
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &numero);

    int encontrado = 0;
    int posicion = -1; 

    for (i = 0; i < Tam; i++) {
        if (vectorX[i] == numero) {
            encontrado = 1; 
            posicion = i;
            break; 
        }
    }

    if (encontrado) {
        printf("El numero %d se encuentra en la posicion %d del vector X.\n", numero, posicion);
    } else {
        printf("NO\n"); 
    }

    return 0;
}

