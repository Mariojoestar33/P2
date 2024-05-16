#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_caracter {
    char letra;
    int cantidad;
};

typedef struct s_caracter caracter;

int main() {
    // Declaraciones
    char* mensaje = "Los sistemas ditribuidos se definen como aquellos sistemas que se componen de multiples computadoras que se comunican entre si a traves de una red, con el objetivo de compartir recursos y trabajar de manera conjunta en la realizacion de una tarea comun.";
    caracter* ptr = (caracter*)malloc(sizeof(caracter)*256); // 256 para abarcar todos los caracteres ASCII posibles
    
    // Inicializar el arreglo de caracteres
    for (int i = 0; i < 256; i++) {
        ptr[i].letra = (char)i;
        ptr[i].cantidad = 0;
    }

    // Calcular la frecuencia de cada carácter en el mensaje
    int len = strlen(mensaje);
    for (int i = 0; i < len; i++) {
        ptr[(int)mensaje[i]].cantidad++;
    }

    // Imprimir el diccionario y la frecuencia de aparición
    printf("Diccionario y frecuencia de aparicion de cada simbolo:\n\ncaracter: frecuencia\n");
    for (int i = 0; i < 256; i++) {
        if (ptr[i].cantidad > 0) {
            printf("'%c': %d\n", ptr[i].letra, ptr[i].cantidad);
        }
    }

    // Liberar memoria
    free(ptr);

    return 0;
}