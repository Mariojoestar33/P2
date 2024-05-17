#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024 // Aumentar el tamaño del buffer para leer mensajes más largos
#define MAX_WORD_LENGTH 100 // Longitud máxima de una palabra
#define INITIAL_WORD_COUNT 50 // Número inicial de palabras a almacenar

struct s_palabra {
    char palabra[MAX_WORD_LENGTH];
    int frecuencia;
};

typedef struct s_palabra palabra;

int main() {
    // Declaraciones
    char buffer[MAX];
    printf("Ingrese el mensaje a analizar:\n");
    fgets(buffer, MAX, stdin); // Usar fgets en lugar de gets para evitar desbordamientos de buffer

    // Quitar el salto de línea si existe
    buffer[strcspn(buffer, "\n")] = '\0';

    // Crear un arreglo dinámico para almacenar las palabras
    int capacidad = INITIAL_WORD_COUNT;
    palabra* puntero = (palabra*)malloc(sizeof(palabra) * capacidad);

    if (!puntero) {
        fprintf(stderr, "Error de asignación de memoria\n");
        return 1;
    }

    int num_palabras = 0;

    // Tokenizar la cadena de entrada en palabras
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        // Verificar si la palabra ya está en el arreglo
        int encontrada = 0;
        for (int i = 0; i < num_palabras; i++) {
            if (strcmp(puntero[i].palabra, token) == 0) {
                puntero[i].frecuencia++;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            // Agregar nueva palabra al arreglo
            if (num_palabras >= capacidad) {
                capacidad *= 2;
                puntero = (palabra*)realloc(puntero, sizeof(palabra) * capacidad);
                if (!puntero) {
                    fprintf(stderr, "Error de asignación de memoria\n");
                    return 1;
                }
            }
            strcpy(puntero[num_palabras].palabra, token);
            puntero[num_palabras].frecuencia = 1;
            num_palabras++;
        }
        token = strtok(NULL, " ");
    }

    // Algoritmo de burbuja para ordenar las palabras por frecuencia
    for (int i = 0; i < num_palabras - 1; i++) {
        for (int j = 0; j < num_palabras - i - 1; j++) {
            if (puntero[j].frecuencia < puntero[j + 1].frecuencia) {
                palabra aux = puntero[j];
                puntero[j] = puntero[j + 1];
                puntero[j + 1] = aux;
            }
        }
    }

    // Imprimir el diccionario y la frecuencia de aparición
    printf("\nDiccionario y frecuencia de aparición de cada palabra:\n\npalabra: frecuencia\n");
    for (int i = 0; i < num_palabras; i++) {
        printf("'%s': %d\n", puntero[i].palabra, puntero[i].frecuencia);
    }

    // Liberación de memoria
    free(puntero);
    return 0; // Fin del programa
}