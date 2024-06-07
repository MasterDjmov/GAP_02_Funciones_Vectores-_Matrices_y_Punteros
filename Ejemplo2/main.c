#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONAS 100

//defino la estructura
typedef struct {
    char nombre[50];
    int edad;
    float estatura;
} Persona;

// Función para ingresar los datos de una persona
void ingresarPersona(Persona *persona, int index) {
    printf("\nIngrese los datos de la persona %d:\n", index + 1);
    printf("Nombre: ");
    scanf("%s", persona->nombre);
    printf("Edad: ");
    scanf("%d", &persona->edad);
    printf("Estatura (en metros): ");
    scanf("%f", &persona->estatura);
}

// Función para buscar la posición de una persona por nombre
int buscarPorNombre(Persona personas[], int numPersonas, char nombreBuscar[]) {
    for (int i = 0; i < numPersonas; i++) {
        if (strcmp(personas[i].nombre, nombreBuscar) == 0) {
            return i;
        }
    }
    return -1; // Si no se encuentra la persona
}

// Función para buscar la posición de una persona por edad
int buscarPorEdad(Persona personas[], int numPersonas, int edadBuscar) {
    for (int i = 0; i < numPersonas; i++) {
        if (personas[i].edad == edadBuscar) {
            return i;
        }
    }
    return -1; // Si no se encuentra la persona
}

// Función para buscar la posición de una persona por estatura
int buscarPorEstatura(Persona personas[], int numPersonas, float estaturaBuscar) {
    for (int i = 0; i < numPersonas; i++) {
        if (personas[i].estatura == estaturaBuscar) {
            return i;
        }
    }
    return -1; // Si no se encuentra la persona
}

// Función para calcular el promedio de edades
float calcularPromedioEdad(Persona personas[], int numPersonas) {
    int sum = 0;
    for (int i = 0; i < numPersonas; i++) {
        sum += personas[i].edad;
    }
    return (float)sum / numPersonas;
}

// Función para calcular el promedio de estaturas
float calcularPromedioEstatura(Persona personas[], int numPersonas) {
    float sum = 0;
    for (int i = 0; i < numPersonas; i++) {
        sum += personas[i].estatura;
    }
    return sum / numPersonas;
}

//defino el main principal
int main() {
    int numPersonas;

    printf("Ingrese el número de personas: ");
    scanf("%d", &numPersonas);

    if (numPersonas <= 0 || numPersonas > MAX_PERSONAS) {
        printf("Número de personas no válido.\n");
        return 1;
    }

    //creo un objeto persona pero de tipo vector, para poder guardar a la cantidad que yo defina
    Persona personas[MAX_PERSONAS];
    // Ingresar datos de cada persona
    for (int i = 0; i < numPersonas; i++) {
        ingresarPersona(&personas[i], i);
    }

    int opcion;
    char nombreBuscar[50];
    int edadBuscar;
    float estaturaBuscar;
    int posicion;

    //armo menu para ir mostrando un poco mas lindo
    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Buscar por nombre\n");
        printf("2. Buscar por edad\n");
        printf("3. Buscar por estatura\n");
        printf("4. Mostrar promedio de edades\n");
        printf("5. Mostrar promedio de estaturas\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nIngrese el nombre de la persona a buscar: ");
                scanf("%s", nombreBuscar);
                posicion = buscarPorNombre(personas, numPersonas, nombreBuscar);
                break;
            case 2:
                printf("\nIngrese la edad de la persona a buscar: ");
                scanf("%d", &edadBuscar);
                posicion = buscarPorEdad(personas, numPersonas, edadBuscar);
                break;
            case 3:
                printf("\nIngrese la estatura (en metros) de la persona a buscar: ");
                scanf("%f", &estaturaBuscar);
                posicion = buscarPorEstatura(personas, numPersonas, estaturaBuscar);
                break;
            case 4:
                printf("El promedio de edad del grupo es: %.2f\n", calcularPromedioEdad(personas, numPersonas));
                break;
            case 5:
                printf("El promedio de estatura del grupo es: %.2f metros\n", calcularPromedioEstatura(personas, numPersonas));
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }

        if (opcion != 0 && posicion != -1) {
            printf("La persona %s, de %d años y %.2f metros de estatura, se encuentra en la posición %d del vector.\n", personas[posicion].nombre, personas[posicion].edad, personas[posicion].estatura, posicion);
        } else if (opcion != 0) {
            printf("La persona no se encontró en el grupo.\n");
        }

    } while (opcion != 0);

    return 0;
}
