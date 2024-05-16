#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void invertir(char* puntero);

int main() {
    char cadena[MAX];
    char* puntero;
    printf("Introduce una cadena de caracteres: (MAX 120 caracteres)\n");
    gets(cadena);
    puntero = (char*)malloc((strlen(cadena) + 1) * sizeof(char)); // +1 para el carácter nulo al final
    strcpy(puntero, cadena);
    printf("Cadena original: %s\n", cadena);
    
    // Imprimir la cadena invertida con el puntero
    printf("Cadena invertida con puntero: ");
    invertir(puntero);

    free(puntero);
    return 0;
}

void invertir(char* puntero) {
    for(int i = strlen(puntero) - 1; i >= 0; i--) {
        printf("%c", puntero[i]);
    }
    printf("\n");
}