#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de las funciones
void mostrarMenu();
void cargarDimensionVector(int *tam, int **vector);
void generarVector(int *vector, int tam);
void calcularPromedio(int *vector, int tam, double *promedio);
void encontrarMaxMin(int *vector, int tam, int *max, int *min, int *posMax, int *posMin);
void ordenarDescendente(int *vector, int tam);
void ordenarAscendente(int *vector, int tam);
int busquedaBinaria(int *vector, int tam, int valor);
void limpiarConsola();
void mostrarVector(int *vector, int tam);

int main() {
    int *vector = NULL; // Puntero para almacenar el vector dinámico
    int tam = 0;        // Tamaño del vector
    double promedio = 0.0; // Variable para almacenar el promedio
    int max, min, posMax, posMin; // Variables para almacenar el valor y posición del máximo y mínimo
    int opcion; // Variable para almacenar la opción del menú
    int valor, posicion; // Variables para la búsqueda binaria

    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios

    // Ciclo principal del programa que muestra el menú y ejecuta la opción seleccionada
    do {
        limpiarConsola(); // Limpiar la consola antes de mostrar el menú
        mostrarMenu();
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                cargarDimensionVector(&tam, &vector); // Cargar la dimensión del vector y asignar memoria
                //para cada accion, llamo a ver el estado del vector
                mostrarVector(vector, tam);
                break;
            case 2:
                if (tam > 0 && vector != NULL) {
                    generarVector(vector, tam); // Generar los números aleatorios en el vector
                    //para cada accion, llamo a ver el estado del vector
                    mostrarVector(vector, tam);

                } else {
                    printf("Debe cargar la dimensión del vector primero.\n");
                }
                break;
            case 3:
                if (tam > 0 && vector != NULL) {
                    //para cada accion, llamo a ver el estado del vector
                    mostrarVector(vector, tam);
                    //calculo el promedio
                    calcularPromedio(vector, tam, &promedio); // Calcular el promedio de los valores en el vector
                    printf("El valor promedio es: %.2f\n", promedio);
                } else {
                    printf("Debe generar el vector primero.\n");
                }
                break;
            case 4:
                if (tam > 0 && vector != NULL) {
                    //para cada accion, llamo a ver el estado del vector
                    mostrarVector(vector, tam);
                    //busco el maximo y minimo
                    encontrarMaxMin(vector, tam, &max, &min, &posMax, &posMin); // Encontrar el valor máximo y mínimo
                    printf("Valor máximo: %d en la posición %d\n", max, posMax);
                    printf("Valor mínimo: %d en la posición %d\n", min, posMin);
                } else {
                    printf("Debe generar el vector primero.\n");
                }
                break;
            case 5:
                if (tam > 0 && vector != NULL) {
                    //para cada accion, llamo a ver el estado del vector
                    mostrarVector(vector, tam);
                    //ordeno
                    ordenarDescendente(vector, tam); // Ordenar el vector de mayor a menor
                    printf("Vector ordenado de mayor a menor.\n");
                    mostrarVector(vector, tam);
                } else {
                    printf("Debe generar el vector primero.\n");
                }
                break;
            case 6:
                if (tam > 0 && vector != NULL) {
                    //para cada accion, llamo a ver el estado del vector
                    mostrarVector(vector, tam);
                    //ordenar
                    ordenarAscendente(vector, tam); // Ordenar el vector de menor a mayor
                    printf("Vector ordenado de menor a mayor.\n");
                    mostrarVector(vector, tam);
                } else {
                    printf("Debe generar el vector primero.\n");
                }
                break;
            case 7:
                if (tam > 0 && vector != NULL) {
                    //para cada accion, llamo a ver el estado del vector
                    mostrarVector(vector, tam);

                    printf("Ingrese el valor a buscar: ");
                    scanf("%d", &valor);
                    posicion = busquedaBinaria(vector, tam, valor); // Buscar un valor en el vector usando búsqueda binaria
                    if (posicion != -1) {
                        printf("Recuerde que el vector comienza siempre en CERO.\n");
                        printf("Valor encontrado en la posición %d\n", posicion);
                    } else {
                        printf("Valor no encontrado.\n");
                    }
                } else {
                    printf("Debe generar el vector primero.\n");
                }
                break;
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }

        if (opcion != 8) {
            printf("\nPresione cualquier tecla para continuar");
            getchar(); // Captura el Enter después de la opción
            getchar(); // Captura el Enter antes de limpiar la consola
        }

    } while(opcion != 8);

    if (vector != NULL) {
        free(vector); // Liberar la memoria asignada al vector
    }

    return 0;
}

// Función para limpiar la consola según el sistema operativo
void limpiarConsola() {
#ifdef _WIN32
    system("cls"); // Comando para limpiar consola en Windows
#else
    system("clear"); // Comando para limpiar consola en Unix/Linux
#endif
}

// Función que muestra el menú de opciones
void mostrarMenu() {
    printf("\nMenú:\n");
    printf("1. Cargar Dimensión del Vector\n");
    printf("2. Generar Vector\n");
    printf("3. Calcular el valor promedio\n");
    printf("4. Mostrar valores máximo y mínimo y su posición correspondiente\n");
    printf("5. Ordenar de mayor a menor\n");
    printf("6. Ordenar de menor a mayor\n");
    printf("7. Buscar un valor determinado\n");
    printf("8. Salir\n");
    printf("Seleccione una opción: ");
}

// Función para cargar la dimensión del vector y asignar memoria
void cargarDimensionVector(int *tam, int **vector) {
    do {
        printf("Ingrese la dimensión del vector (2 a 9999): ");
        scanf("%d", tam);
    } while (*tam < 2 || *tam > 9999); // Validación del tamaño

    // Liberar memoria previamente asignada si es necesario
    if (*vector != NULL) {
        free(*vector);
    }

    // Asignar memoria dinámica para el vector
    *vector = (int *)malloc(*tam * sizeof(int));
    if (*vector == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1); // Terminar el programa si la asignación falla
    }
}

// Función para generar el vector con números aleatorios
void generarVector(int *vector, int tam) {
    for (int i = 0; i < tam; i++) {
        vector[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }
    printf("Vector generado.\n");
}

// Función para calcular el promedio de los valores en el vector
void calcularPromedio(int *vector, int tam, double *promedio) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += vector[i]; // Sumar todos los elementos del vector
    }
    *promedio = (double)suma / tam; // Calcular el promedio
}

// Función para encontrar el valor máximo y mínimo y sus posiciones
void encontrarMaxMin(int *vector, int tam, int *max, int *min, int *posMax, int *posMin) {
    *max = *min = vector[0];
    *posMax = *posMin = 0;
    for (int i = 1; i < tam; i++) {
        if (vector[i] > *max) {
            *max = vector[i];
            *posMax = i;
        }
        if (vector[i] < *min) {
            *min = vector[i];
            *posMin = i;
        }
    }
}

// Función para ordenar el vector de mayor a menor usando el método de burbuja
void ordenarDescendente(int *vector, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (vector[j] < vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

// Función para ordenar el vector de menor a mayor usando el método de burbuja
void ordenarAscendente(int *vector, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

// Función para realizar una búsqueda binaria en el vector
int busquedaBinaria(int *vector, int tam, int valor) {
    int izquierda = 0, derecha = tam - 1, medio;
    while (izquierda <= derecha) {
        medio = izquierda + (derecha - izquierda) / 2;
        if (vector[medio] == valor) {
            return medio; // Valor encontrado
        } else if (vector[medio] < valor) {
            izquierda = medio + 1; // Buscar en la mitad derecha
        } else {
            derecha = medio - 1; // Buscar en la mitad izquierda
        }
    }
    return -1; // Valor no encontrado
}

// Función para mostrar el vector
void mostrarVector(int *vector, int tam) {
    printf("Vector actual: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}
