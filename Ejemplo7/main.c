#include <stdio.h>
#include <stdbool.h>

#define MAX_FILAS 100
#define MAX_COLUMNAS 100

// Función para validar si un número está dentro del rango [50, 100]
bool dentroDeRango(int num) {
    return (num >= 50 && num <= 100);
}

// Función para buscar un número en la matriz
void buscarNumero(int matriz[][MAX_COLUMNAS], int filas, int columnas, int num) {
    bool encontrado = false;
    int filaEncontrado = -1, columnaEncontrado = -1;

    // Buscar el número en la matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == num) {
                encontrado = true;
                filaEncontrado = i;
                columnaEncontrado = j;
                break; // Salir del bucle interno si se encuentra el número
            }
        }
        if (encontrado) // Salir del bucle externo si se encuentra el número
            break;
    }

    // Mostrar el resultado de la búsqueda
    if (encontrado) {
        printf("El número %d se encuentra en la posición [%d, %d] de la matriz.\n", num, filaEncontrado, columnaEncontrado);
    } else {
        printf("El número %d no está en la matriz.\n", num);
    }
}

int main() {
    int filas, columnas;

    // Solicitar al usuario el tamaño de la matriz
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);

    // Validar los tamaños de la matriz
    if (filas <= 0 || filas > MAX_FILAS || columnas <= 0 || columnas > MAX_COLUMNAS) {
        printf("Tamaño de la matriz no válido.\n");
        return 1;
    }

    int matriz[MAX_FILAS][MAX_COLUMNAS];

    // Solicitar al usuario ingresar los elementos de la matriz
    printf("Ingrese los elementos de la matriz (%d filas x %d columnas):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            // Validar si el elemento está dentro del rango [50, 100]
            if (!dentroDeRango(matriz[i][j])) {
                printf("Error: El número debe estar en el rango de 50 a 100.\n");
                return 1;
            }
        }
    }

    int numeroBuscado;

    // Solicitar al usuario el número a buscar
    printf("Ingrese el número que desea buscar en la matriz: ");
    scanf("%d", &numeroBuscado);

    // Validar si el número a buscar está dentro del rango [50, 100]
    if (!dentroDeRango(numeroBuscado)) {
        printf("Error: El número debe estar en el rango de 50 a 100.\n");
        return 1;
    }

    // Buscar el número en la matriz
    buscarNumero(matriz, filas, columnas, numeroBuscado);

    return 0;
}
