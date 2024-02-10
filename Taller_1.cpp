#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_PROPIEDADES 100
#define MAX_DIRECCION 100

typedef enum { Casa, Apartamento, Bodega } TipoInmueble;
typedef enum { Excelente, Buena, Regular, Mala } CalidadUbicacion;

typedef struct {
  int id;
  TipoInmueble tipoInmueble;
  float superficie;
  CalidadUbicacion ubicacion;
  float valorComercial;
  float precioAlquiler;
  bool disponible;
  char direccion[MAX_DIRECCION];
} Propiedad;

void mostrarPropiedadesDisponibles(Propiedad propiedades[], int size,
                                   TipoInmueble tipo, float minPrecio,
                                   float maxPrecio,
                                   CalidadUbicacion ubicacion) {
  printf("\nPropiedades Disponibles:\n");
  for (int i = 0; i < size; i++) {
    if (propiedades[i].tipoInmueble == tipo &&
        propiedades[i].precioAlquiler >= minPrecio &&
        propiedades[i].precioAlquiler <= maxPrecio &&
        propiedades[i].ubicacion == ubicacion && propiedades[i].disponible) {

      printf("ID: %d, Dirección: %s, Precio Alquiler: %.2f\n",
             propiedades[i].id, propiedades[i].direccion,
             propiedades[i].precioAlquiler);
    }
  }
}

void mostrarInmueblesPorSuperficieValor(Propiedad propiedades[], int size,
                                        float minSuperficie,
                                        float maxSuperficie, float minValor,
                                        float maxValor) {
  printf("\nInmuebles por Superficie y Valor Comercial:\n");
  for (int i = 0; i < size; i++) {
    if (propiedades[i].superficie >= minSuperficie &&
        propiedades[i].superficie <= maxSuperficie &&
        propiedades[i].valorComercial >= minValor &&
        propiedades[i].valorComercial <= maxValor) {

      printf("ID: %d, Superficie: %.2f, Valor Comercial: %.2f\n",
             propiedades[i].id, propiedades[i].superficie,
             propiedades[i].valorComercial);
    }
  }
}

void mostrarInmueblesNoDisponibles(Propiedad propiedades[], int size) {
  printf("\nInmuebles No Disponibles:\n");
  for (int i = 0; i < size; i++) {
    if (!propiedades[i].disponible) {
      printf("ID: %d, Dirección: %s\n", propiedades[i].id,
             propiedades[i].direccion);
    }
  }
}

void mostrarValorPromedioAlquiler(Propiedad propiedades[], int size,
                                  float minPrecio, float maxPrecio) {
  float suma = 0;
  int contador = 0;
  for (int i = 0; i < size; i++) {
    if (propiedades[i].precioAlquiler >= minPrecio &&
        propiedades[i].precioAlquiler <= maxPrecio) {
      suma += propiedades[i].precioAlquiler;
      contador++;
    }
  }
  if (contador > 0) {
    printf("\nValor promedio de alquiler: %.2f\n", suma / contador);
  } else {
    printf("\nNo hay propiedades en el rango de precio dado.\n");
  }
}

void inicializarPropiedad(Propiedad *propiedad, int id,
                          TipoInmueble tipoInmueble, float superficie,
                          CalidadUbicacion ubicacion, float valorComercial,
                          float precioAlquiler, bool disponible,
                          const char *direccion) {
  propiedad->id = id;
  propiedad->tipoInmueble = tipoInmueble;
  propiedad->superficie = superficie;
  propiedad->ubicacion = ubicacion;
  propiedad->valorComercial = valorComercial;
  propiedad->precioAlquiler = precioAlquiler;
  propiedad->disponible = disponible;
  strcpy(propiedad->direccion, direccion);
}

int main() {
  Propiedad propiedades[MAX_PROPIEDADES];
  int numPropiedades = 0;
  int opcion;

  inicializarPropiedad(&propiedades[numPropiedades++], 1, Casa, 120.0, Buena,
                       100000.0, 5000.0, true, "Calle 123");
  inicializarPropiedad(&propiedades[numPropiedades++], 2, Apartamento, 80.0,
                       Excelente, 150000.0, 7000.0, false, "Avenida 456");
  inicializarPropiedad(&propiedades[numPropiedades++], 3, Bodega, 300.0,
                       Regular, 200000.0, 10000.0, true, "Ruta 789");

  do {
    printf("\nMenu de Gestion de Inmobiliaria\n");
    printf("1. Mostrar propiedades disponibles\n");
    printf("2. Mostrar información de inmuebles por superficie y valor\n");
    printf("3. Mostrar inmuebles no disponibles\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      // Aquí debes obtener los parámetros necesarios para la función
      mostrarPropiedadesDisponibles(propiedades, numPropiedades, Casa, 4000.0,
                                    8000.0, Buena);
      break;
    case 2:
      // Igualmente, obtener parámetros necesarios para la función
      mostrarInmueblesPorSuperficieValor(propiedades, numPropiedades, 100.0,
                                         200.0, 100000.0, 200000.0);
      break;
    case 3:
      mostrarInmueblesNoDisponibles(propiedades, numPropiedades);
      break;
    case 0:
      printf("Saliendo del programa.\n");
      break;
    default:
      printf("Opción no válida.\n");
    }
  } while (opcion != 0);

  return 0;
}

