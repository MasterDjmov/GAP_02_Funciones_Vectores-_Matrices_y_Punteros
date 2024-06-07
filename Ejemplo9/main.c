#include <stdio.h>
//defino variables globales
#define MAXIMO_FILAS 10
#define MAXIMO_COLUMNAS 10

// Función para validar que las dimensiones de la matriz estén dentro de los límites
int validarDimension(int dim) {
    if (dim < 1 || dim > 10) {
        printf("Error: El tamaño de la matriz debe estar entre 1 y 10.\n");
        return 0;
    }
    return 1;
}

// Función para tomar la matriz como entrada del usuario
void tomarMatriz(int matriz[][MAXIMO_COLUMNAS], int filas, int columnas) {
    printf("Ingrese los elementos de la matriz (%d filas x %d columnas):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para calcular y mostrar la matriz traspuesta
void matrizTraspuesta(int matriz[][MAXIMO_COLUMNAS], int filas, int columnas) {
    printf("La matriz traspuesta es:\n");
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;

    // Solicitar al usuario el número de filas de la matriz
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);

    // Validar el número de filas
    if (!validarDimension(filas)) {
        return 1;
    }

    // Solicitar al usuario el número de columnas de la matriz
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);

    // Validar el número de columnas
    if (!validarDimension(columnas)) {
        return 1;
    }

    int matriz[MAXIMO_FILAS][MAXIMO_COLUMNAS];

    // Tomar la matriz como entrada del usuario
    tomarMatriz(matriz, filas, columnas);

    // Calcular y mostrar la matriz traspuesta
    matrizTraspuesta(matriz, filas, columnas);

    return 0;
}
