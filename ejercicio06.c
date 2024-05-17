#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 121

struct s_caracteres {
    char caracter;
    int frecuencia;
};

typedef struct s_caracteres caracter;

int main() {
    //Declaraciones
    char c;
    char buffer[MAX];
    caracter* puntero = (caracter*)malloc(sizeof(caracter*)*256);
    //Inicializar el ptro con los caracteres
    for (int i = 0; i < 256; i++) {
        puntero[i].caracter = (char)i;
        puntero[i].frecuencia = 0;
    }
    //Lectura del mensaje
    printf("Ingrese el mensaje a analizar:\n");
    gets(buffer);   
    char* mensaje = (char*)malloc(sizeof(char)*(strlen(buffer) + 1)); //Hacemos un puntero con el mensaje del tamaño del buffer
    strcpy(mensaje, buffer); //Se copia el buffer en el puntero del mensaje
    //Calcular la frecuencia de cada caracter en el mensaje
    for(int i = 0; i < strlen(mensaje); i++) {
        puntero[(int)mensaje[i]].frecuencia++;
    }
    //Algoritmo de burbuja
    printf("\n\nAlgoritmo de burbuja:\n\n");
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 256; j++) {
            if(puntero[i].frecuencia > puntero[j].frecuencia) {
                caracter aux = puntero[i];
                puntero[i] = puntero[j];
                puntero[j] = aux;
            }
        }
    }
     //Imprimir el diccionario y la frecuencia de aparicion
    printf("Diccionario y frecuencia de aparicion de cada simbolo:\n\ncaracter: frecuencia\n");
    for(int i = 0; i < 256; i++) {
        if (puntero[i].frecuencia > 0) {
            printf("'%c': %d\n", puntero[i].caracter, puntero[i].frecuencia);
        }
    }
    return 0;
}