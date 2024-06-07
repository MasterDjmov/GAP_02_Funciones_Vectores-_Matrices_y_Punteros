#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Función para verificar si una cadena es un palíndromo
bool esPalindromo(char cadena[]) {
    int i = 0, j = strlen(cadena) - 1;

    // Ignorar espacios y signos de puntuación al comparar los caracteres
    while (i < j) {
        // Ignorar espacios y signos de puntuación en el extremo izquierdo
        while (isspace(cadena[i]) || ispunct(cadena[i]))
            i++;
        // Ignorar espacios y signos de puntuación en el extremo derecho
        while (isspace(cadena[j]) || ispunct(cadena[j]))
            j--;

        // Convertir ambos caracteres a minúsculas antes de compararlos
        if (tolower(cadena[i]) != tolower(cadena[j]))
            return false;

        i++;
        j--;
    }
    return true;
}

int main() {
    char cadena[101];

    // Solicitar al usuario ingresar una palabra u oración
    printf("Ingrese una palabra u oracion (máximo 100 caracteres):\n");
    fgets(cadena, sizeof(cadena), stdin);

    // Eliminar el carácter de nueva línea del final de la cadena
    cadena[strcspn(cadena, "\n")] = '\0';

    // Verificar si la cadena es un palíndromo
    if (esPalindromo(cadena)) {
        printf("La palabra u oración ingresada es un palíndromo.\n");
    } else {
        printf("La palabra u oración ingresada no es un palíndromo.\n");
    }

    return 0;
}
