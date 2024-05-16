#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> // Para usar isdigit y isspace

struct s_caracter {
    char caracter;
    int frecuencia;
};
typedef struct s_caracter caracter;

int main() {

    // Declaraciones
    FILE *archivo;
    char c;
    int longitud = 0;
    int i = 0;
    caracter* punteroCaracter = (caracter*)malloc(sizeof(caracter) * 256); // Declaramos un puntero con 256 direcciones que componen el código ASCII

    // Inicialización de las estructuras de los 256 ASCII
    for (int i = 0; i < 256; i++) {
        punteroCaracter[i].caracter = (char)i;
        punteroCaracter[i].frecuencia = 0;
    }

    // Lectura del archivo
    archivo = fopen("textoEjercicio03.txt", "r");

    if (archivo == NULL) { // Verificación de apertura del archivo
        printf("Error al tratar de abrir el archivo");
        free(punteroCaracter); // Liberar memoria antes de salir
        exit(1);
    }

    // Se ingresa a un puntero el contenido del archivo
    while ((c = fgetc(archivo)) != EOF) {
        // Verificar si el carácter es un dígito, un espacio en blanco o un carácter especial
        if (isdigit((unsigned char)c) || isspace((unsigned char)c) || ispunct((unsigned char)c)) {
            punteroCaracter[(int)c].frecuencia++;
            longitud++;
        }
    }

    // Imprimir el diccionario y la frecuencia de aparición
    printf("Diccionario y frecuencia de aparicion de cada simbolo:\n\ncaracter: frecuencia\n");
    for (int i = 0; i < 256; i++) {
        if (punteroCaracter[i].frecuencia > 0) {
            printf("'%c': %d\n", punteroCaracter[i].caracter, punteroCaracter[i].frecuencia);
        }
    }

    printf("El archivo tiene %d caracteres que son digitos, espacios en blanco o caracteres especiales\n", longitud);

    fclose(archivo);
    free(punteroCaracter);

    return 0;
}