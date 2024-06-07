#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAXIMO_DE_INTENTOS 6
#define NUMERO_DE_PALABRAS 5
#define MAXIMO_LONGITUD_PALABRA 20
//armo un vector para contener las palabras
char palabras[NUMERO_DE_PALABRAS][MAXIMO_LONGITUD_PALABRA] = {
    "gato",
    "perro",
    "casa",
    "ordenador",
    "programacion"
};

// Función para imprimir el ahorcado
void imprimirAhorcado(int intentos) {
    printf(" _______\n");
    printf(" |     |\n");
    printf(" |     %s\n", intentos < 6 ? "O" : " ");
    printf(" |    %s%s%s\n", intentos < 4 ? "/" : " ", intentos < 5 ? "|" : " ", intentos < 3 ? "\\" : " ");
    printf(" |    %s %s\n", intentos < 2 ? "/" : " ", intentos < 1 ? "\\" : " ");
    printf("_|_\n\n");
}

// Función para ocultar la palabra mostrando solo las letras adivinadas
void mostrarPalabra(char palabra[], char letrasAdivinadas[]) {
    int longitud = strlen(palabra);
    for (int i = 0; i < longitud; i++) {
        if (strchr(letrasAdivinadas, palabra[i]) != NULL) {
            printf("%c ", palabra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Seleccionar una palabra aleatoria de la lista
    int indicePalabra = rand() % NUMERO_DE_PALABRAS;
    char palabra[MAXIMO_LONGITUD_PALABRA];
    strcpy(palabra, palabras[indicePalabra]);

    char letrasAdivinadas[MAXIMO_LONGITUD_PALABRA] = "";
    int intentosRestantes = MAXIMO_DE_INTENTOS;

    printf("Bienvenido al juego del ahorcado!\n");

    while (intentosRestantes > 0) {
        // Mostrar el ahorcado actual
        imprimirAhorcado(intentosRestantes);

        // Mostrar las letras adivinadas y la palabra oculta
        printf("Letras usadas: %s\n", letrasAdivinadas);
        printf("Palabra: ");
        mostrarPalabra(palabra, letrasAdivinadas);

        // Verificar si se ha adivinado la palabra completa
        if (strspn(palabra, letrasAdivinadas) == strlen(palabra)) {
            printf("¡Felicidades! Has adivinado la palabra: %s\n", palabra);
            break;
        }

        // Solicitar al usuario que ingrese una letra
        char letra;
        printf("Ingrese una letra: ");
        scanf(" %c", &letra);

        // Validar que la entrada sea una letra
        if (!isalpha(letra)) {
            printf("Error: Por favor ingrese una letra válida.\n");
            continue;
        }

        // Convertir la letra a minúscula
        letra = tolower(letra);

        // Verificar si la letra ya ha sido usada
        if (strchr(letrasAdivinadas, letra) != NULL) {
            printf("Error: La letra ya ha sido usada.\n");
            continue;
        }

        // Agregar la letra a las letras adivinadas
        letrasAdivinadas[strlen(letrasAdivinadas)] = letra;
        letrasAdivinadas[strlen(letrasAdivinadas)] = '\0';

        // Verificar si la letra está en la palabra
        if (strchr(palabra, letra) == NULL) {
            printf("La letra %c no está en la palabra.\n", letra);
            intentosRestantes--;
        } else {
            printf("¡Correcto! La letra %c está en la palabra.\n", letra);
        }
    }

    // Si se quedó sin intentos
    if (intentosRestantes == 0) {
        printf("¡Lo siento! Te has quedado sin intentos. La palabra era: %s\n", palabra);
        imprimirAhorcado(intentosRestantes);
    }

    return 0;
}
