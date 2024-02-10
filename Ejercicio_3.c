#include <stdio.h>
#include <math.h> 

int main() {
    int N, i;

    printf("Ingrese el Numero de elementos en el vector: ");
    scanf("%d", &N);

    int vectorOriginal[N];
    int vectorCuadrado[N];

    for (i = 0; i < N; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &vectorOriginal[i]);

        vectorCuadrado[i] = pow(vectorOriginal[i], 2);
    }

    printf("Vector Original: ");
    for (i = 0; i < N; i++) {
        printf("%d ", vectorOriginal[i]);
    }
    printf("\n");

    printf("Vector Resultante (Cuadrado): ");
    for (i = 0; i < N; i++) {
        printf("%d ", vectorCuadrado[i]);
    }
    printf("\n");

    return 0;
}

