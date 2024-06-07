#include <stdio.h>
#include <stdbool.h>

// Función para ordenar el vector usando el algoritmo de ordenamiento de burbuja
void ordenarBurbuja(int vector[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                // Intercambiar los elementos
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

// Función para eliminar elementos duplicados en un vector ordenado
int eliminarDuplicados(int vector[], int n) {
    //verifico que realmente se pase un limite valido
    if (n == 0 || n == 1)
        return n;

    int j = 0;
    //no olvidar siempre ir a n-1 para no tocar memoria extrania
    for (int i = 0; i < n - 1; i++) {
        if (vector[i] != vector[i + 1]) {
            vector[j++] = vector[i];
        }
    }

    vector[j++] = vector[n - 1];

    return j;
}

int main() {
    //creo variables necesarias
    int n;

    // Solicitar al usuario el tamaño del vector
    printf("Ingrese el tamaño del vector (entre 1 y 100): ");
    scanf("%d", &n);

    //con n ya puedo crear el vector
    int vector[n];
    // Validar el tamaño del vector
    if (n < 1 || n > 100) {
        printf("El tamaño del vector debe estar entre 1 y 100.\n");
        return 1;
    }


    // Solicitar al usuario los números enteros para llenar el vector
    printf("Ingrese %d números enteros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    // Ordenar el vector usando el algoritmo de ordenamiento de burbuja
    ordenarBurbuja(vector, n);

    // Eliminar elementos duplicados
    int nuevoTamanio = eliminarDuplicados(vector, n);

    // Mostrar el vector resultante sin duplicados
    printf("\nVector ordenado sin duplicados:\n");
    for (int i = 0; i < nuevoTamanio; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
