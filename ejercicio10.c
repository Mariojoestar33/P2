#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {
    //Declaraciones
    int numero[MAX];
    for(int i = 0; i < MAX; i++) {
        printf("Ingrese el numero %d:\n", i + 1);
        scanf("%d", &numero[i]);
    }
    // Algoritmo de burbuja para ordenar las palabras por frecuencia
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (numero[j] > numero[j+1]) {
                int temp = numero[j];
                numero[j] = numero[j+1];
                numero[j+1] = temp;
            }
        }
    }
    //Impresion de la lista ordenada
    for(int i = 0; i < MAX; i++) {
        printf("%d\n", numero[i]);
    }
    return 0;
}