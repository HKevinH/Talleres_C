#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int Tam = 0, i = 0, posMayor = 0;

    printf("Ingresa el número de elementos del vector:");
    scanf("%i", &Tam);

    // Declarar un puntero a int
    int *Vector;

    // Asignar memoria para el vector de tamaño Tam
    Vector = (int *)malloc(Tam * sizeof(int));

    if (Vector == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (i = 0; i < Tam; i++)
    {
        printf("Vector[%i]:", i);
        scanf("%i", &Vector[i]);

        if (Vector[i] > Vector[posMayor])
        {
            posMayor = i;
        }
    }

    printf("El elemento del vector mayor es Vector[%i] = %i\n", posMayor, Vector[posMayor]);

    free(Vector);

    return 0;
}

