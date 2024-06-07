#include <stdio.h>
#include <stdbool.h>

#define DIMENSION_MAXIMA 5 // Máxima dimensión permitida para la matriz

// Función para imprimir la matriz
void imprimirMatriz(int matriz[DIMENSION_MAXIMA][DIMENSION_MAXIMA], int dimension) {
    printf("Matriz ingresada:\n");
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular el determinante de una matriz cuadrada
int determinanteMatriz(int matriz[DIMENSION_MAXIMA][DIMENSION_MAXIMA], int dimension) {
    int det = 0;

    // Caso base: si la matriz es de 1x1
    if (dimension == 1) {
        return matriz[0][0];
    }

    // Caso base: si la matriz es de 2x2
    if (dimension == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    // Caso general: usar el método de Laplace para calcular el determinante
    for (int k = 0; k < dimension; k++) {
        int submatriz[DIMENSION_MAXIMA][DIMENSION_MAXIMA];
        int subfila = 0, subcolumna = 0;

        // Construir la submatriz eliminando la fila y la columna k
        for (int i = 1; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if (j != k) {
                    submatriz[subfila][subcolumna++] = matriz[i][j];
                    if (subcolumna == dimension - 1) {
                        subcolumna = 0;
                        subfila++;
                    }
                }
            }
        }

        // Calcular el determinante recursivamente
        det += matriz[0][k] * determinanteMatriz(submatriz, dimension - 1) * (k % 2 == 0 ? 1 : -1);
    }

    return det;
}

int main() {
    int dimension;

    // Solicitar al usuario el tamaño de la matriz cuadrada
    printf("Ingrese la dimensión de la matriz cuadrada (máximo %d): ", DIMENSION_MAXIMA);
    scanf("%d", &dimension);

    // Validar la dimensión de la matriz
    if (dimension < 1 || dimension > DIMENSION_MAXIMA) {
        printf("Error: La dimensión de la matriz debe estar entre 1 y %d.\n", DIMENSION_MAXIMA);
        return 1;
    }

    int matriz[DIMENSION_MAXIMA][DIMENSION_MAXIMA];

    // Solicitar al usuario ingresar los elementos de la matriz
    printf("Ingrese los elementos de la matriz %dx%d:\n", dimension, dimension);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir la matriz ingresada
    imprimirMatriz(matriz, dimension);

    // Calcular y mostrar el determinante de la matriz
    int determinante = determinanteMatriz(matriz, dimension);
    printf("El determinante de la matriz es: %d\n", determinante);

    return 0;
}
