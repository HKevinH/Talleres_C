#include <stdio.h>

int main() {
    int Tam, i;

    // Solicitar al usuario el número de elementos en el vector
    printf("Ingrese el numero de elementos en el vector: ");
    scanf("%d", &Tam);

    int vector[Tam];
    int ceros = 0, negativos = 0, positivos = 0;
    int sumaNegativos = 0, sumaPositivos = 0;

    // Leer los elementos del vector y realizar conteos y sumas
    for (i = 0; i < Tam; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &vector[i]);

        if (vector[i] == 0) {
            ceros++;
        } else if (vector[i] < 0) {
            negativos++;
            sumaNegativos += vector[i];
        } else {
            positivos++;
            sumaPositivos += vector[i];
        }
    }

    // Imprimir resultados
    printf("Cantidad de ceros: %d\n", ceros);
    printf("Cantidad de numeros negativos: %d\n", negativos);
    printf("Cantidad de numeros positivos: %d\n", positivos);
    printf("Suma de numeros negativos: %d\n", sumaNegativos);
    printf("Suma de numeros positivos: %d\n", sumaPositivos);

    return 0;
}

