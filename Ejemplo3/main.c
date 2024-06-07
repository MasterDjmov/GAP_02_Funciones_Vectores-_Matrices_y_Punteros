#include <stdio.h>
#include <string.h>
//funcion que se encarga de buscar y comparar
int buscar(char s1[], char s2[]) {
    int i, j;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (i = 0; i <= len1 - len2; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j])
                break;
        }
        if (j == len2)
            return i;
    }
    return -1;
}

int main() {
    //defino dos cadenas, no menciona el tamanio, pero yo las creeo de 100
    char s1[100], s2[100];

    printf("Ingrese la cadena principal: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    printf("Ingrese la subcadena a buscar: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    int posicion = buscar(s1, s2);

    if (posicion != -1) {
        printf("La subcadena \"%s\" se encuentra en la posición %d de la cadena principal \"%s\".\n", s2, posicion, s1);
    } else {
        printf("La subcadena \"%s\" no se encontró en la cadena principal \"%s\".\n", s2, s1);
    }

    return 0;
}
