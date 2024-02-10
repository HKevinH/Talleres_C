#include <stdio.h>

int main(int argc, char *argv[])
{
    int Tam = 45;
    int Vector1[Tam], Vector2[Tam], Vector3[Tam], i, j, c, opcion;
    
    printf("Deseas Llenar Automaticamente el Vector Si = 1, No = 0:");
    scanf("%i", &opcion);
    
    if(opcion == 1){
        for (c = 0; c < Tam; c++) {
            Vector1[c] = c + 1; 
            Vector2[c] = 2 * c + 1; 
        }
    }
    else if(opcion == 0)
    {
        for(i = 0; i < Tam ; i++){
            printf("Introduce El Vector 1 [%i]: ", i);
            scanf("%i", &Vector1[i]);
            printf("Introduce El Vector 2 [%i]: ", i);
            scanf("%i", &Vector2[i]);
            Vector3[i] = Vector2[i] + Vector1[i];
        }
    }
    else {
        printf("Hubo Un Error");
        return 0;
    }
    
    printf("El Vector Resultante Es:");
    
    for(j = 0; j < Tam; j++)
    {
        printf("\nVector 3  Position[%i] [%i]", j+1, Vector3[j]);
    }
    
    return 0;
}

