#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CEDULA 20
#define MAX_NOMBRE 100
#define MAX_SEXO 10
#define MAX_DOMICILIO 100
#define MAX_TELEFONO 20
#define MAX_PACIENTES 5

typedef enum { Masculino, Femenino } Genero;

typedef struct {
  char cedula[MAX_CEDULA];
  char nombre[MAX_NOMBRE];
  int edad;
  Genero sexo;
  char domicilio[MAX_DOMICILIO];
  bool asegurado;
  char telefono[MAX_TELEFONO];
} Paciente;

void mostrarPaciente(Paciente p, int size) {
  if (size > 0) {
    printf("\nCédula: %s\n", p.cedula);
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
    printf("Sexo: %s\n", p.sexo == Masculino ? "Masculino" : "Femenino");
    printf("Domicilio: %s\n", p.domicilio);
    printf("Asegurado: %s\n", p.asegurado ? "Sí" : "No");
    printf("Teléfono: %s\n", p.telefono);
    printf("-------------------------------------------------\n");
  } else {
    printf("\nNo Hay Ningun Paciente Agregado");
  }
}

void inicializarPaciente(Paciente *p, const char *cedula, const char *nombre,
                         int edad, Genero sexo, const char *domicilio,
                         bool asegurado, const char *telefono) {
  strcpy(p->cedula, cedula);
  strcpy(p->nombre, nombre);
  p->edad = edad;
  p->sexo = sexo;
  strcpy(p->domicilio, domicilio);
  p->asegurado = asegurado;
  strcpy(p->telefono, telefono);
}

void listarNombresPacientes(Paciente pacientes[], int size) {
  printf("\nNombres de los pacientes hospitalizados:\n");
  for (int i = 0; i < size; i++) {
    printf("%s\n", pacientes[i].nombre);
  }
  printf("-------------------------------------------------\n");
}

void mostrarPacientesPorCategoria(Paciente pacientes[], int size) {
  printf("\nPacientes hospitalizados por categoria de edad:\n");
  for (int i = 0; i < size; i++) {
    printf("%s: \n", pacientes[i].edad <= 15 ? "Niño"
                     : (pacientes[i].edad > 15 && pacientes[i].edad < 30)
                         ? "Joven"
                     : (pacientes[i].edad >= 31 && pacientes[i].edad <= 65)
                         ? "Adulto"
                         : "Adulto Mayor");
    mostrarPaciente(pacientes[i], size);
  }
}

void ingresarPaciente(Paciente *pacientes, int *numPacientes) {
  if (*numPacientes >= MAX_PACIENTES) {
    printf("\nLimite de pacientes alcanzado.\n");
    return;
  }

  Paciente p;
  printf("\nIngrese cedula: ");
  scanf("%s", p.cedula);
  printf("Ingrese nombre: ");
  scanf("%s", p.nombre);
  printf("Ingrese edad: ");
  scanf("%d", &p.edad);
  printf("Ingrese sexo (0 para Masculino, 1 para Femenino): ");
  int sexo;
  scanf("%d", &sexo);
  p.sexo = sexo == 0 ? Masculino : Femenino;
  printf("Ingrese domicilio: ");
  scanf("%s", p.domicilio);
  printf("¿Esta asegurado? (1 para Si, 0 para No): ");
  scanf("%d", &p.asegurado);
  printf("Ingrese telefono: ");
  scanf("%s", p.telefono);

  pacientes[*numPacientes] = p;
  (*numPacientes)++;
}

// Modificar calcularPorcentaje para manejar rangos de edad
double calcularPorcentaje(Paciente pacientes[], int totalPacientes,
                          Genero sexoBuscado, int edadMin, int edadMax) {
  int contador = 0;
  for (int i = 0; i < totalPacientes; i++) {
    if (pacientes[i].sexo == sexoBuscado && pacientes[i].edad >= edadMin &&
        pacientes[i].edad <= edadMax) {
      contador++;
    }
  }
  return totalPacientes > 0 ? (double)contador / totalPacientes * 100 : 0.0;
}
void calcularSexoEdad(Paciente pacientes[], int totalPacientes) {
  int edad, edadMax;
  printf("\nIngresa la edad: ");
  scanf("%d", &edad);
  printf("Ingresa la edad Max:");
  scanf("%d", &edadMax);
  printf("Ingrese sexo (0 para Masculino, 1 para Femenino): ");
  int sexoInput;
  scanf("%d", &sexoInput);
  Genero sexo = sexoInput == 0 ? Masculino : Femenino;

  double porcentaje =
      calcularPorcentaje(pacientes, totalPacientes, sexo, edad, edadMax);
  printf("Porcentaje de pacientes de sexo %s y edad %d: %f%%\n",
         sexo == Masculino ? "Masculino" : "Femenino", edad, porcentaje);
}

double calcularPorcentajeSeguroEdad(Paciente pacientes[], int totalPacientes,
                                    bool asegurado, Genero sexoBuscado,
                                    int edadMin, int edadMax) {
  int contador = 0;
  for (int i = 0; i < totalPacientes; i++) {
    if (pacientes[i].asegurado == asegurado &&
        pacientes[i].sexo == sexoBuscado && pacientes[i].edad >= edadMin &&
        pacientes[i].edad <= edadMax) {
      contador++;
    }
  }
  return totalPacientes > 0 ? (double)contador / totalPacientes * 100 : 0.0;
}

void calcularPorcentajeSeguroEdadUsuario(Paciente pacientes[],
                                         int totalPacientes, bool asegurado) {
  int edadMin, edadMax;
  printf("\nIngresa la edad minima: ");
  scanf("%d", &edadMin);
  printf("Ingresa la edad maxima: ");
  scanf("%d", &edadMax);

  printf("Ingrese sexo (0 para Masculino, 1 para Femenino): ");
  int sexoInput;
  scanf("%d", &sexoInput);
  Genero sexo = sexoInput == 0 ? Masculino : Femenino;

  double porcentaje = calcularPorcentajeSeguroEdad(
      pacientes, totalPacientes, asegurado, sexo, edadMin, edadMax);
  printf("Porcentaje de pacientes %s de sexo %s y rango de edad %d-%d: %f%%\n",
         asegurado ? "con seguro" : "sin seguro",
         sexo == Masculino ? "Masculino" : "Femenino", edadMin, edadMax,
         porcentaje);
}

int main() {
  Paciente pacientes[MAX_PACIENTES];
  int numPacientes = 0;
  int opcion;

  inicializarPaciente(&pacientes[numPacientes++], "12345678", "Juan Perez", 25,
                      Masculino, "Calle Falsa 123", true, "555-1234");
  inicializarPaciente(&pacientes[numPacientes++], "87654321", "Ana Gomez", 40,
                      Femenino, "Avenida Siempre Viva 456", false, "555-5678");
  inicializarPaciente(&pacientes[numPacientes++], "12348765", "Carlos López",
                      70, Masculino, "Calle de la Amargura 789", true,
                      "555-9012");
  do {

    printf("\nMenu de Gestion de Pacientes\n");
    printf("1. Ingresar nuevo paciente\n");
    printf("2. Listar nombres de pacientes\n");
    printf("3. Mostrar pacientes por categoria de edad\n");
    printf("4. Calcular porcentaje de pacientes por sexo y edad\n");
    printf("5. Calcular porcentaje de pacientes con seguro por sexo y edad\n");
    printf("6. Calcular porcentaje de pacientes sin seguro por sexo y edad\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      ingresarPaciente(pacientes, &numPacientes);
      break;
    case 2:
      listarNombresPacientes(pacientes, numPacientes);
      break;
    case 3:
      mostrarPacientesPorCategoria(pacientes, numPacientes);
      break;
    case 4:
      calcularSexoEdad(pacientes, numPacientes);
      break;
    case 5:
      calcularPorcentajeSeguroEdadUsuario(pacientes, numPacientes, true);
      break;
    case 6:
      calcularPorcentajeSeguroEdadUsuario(pacientes, numPacientes, false);
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
