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
    FILE* file;
    char* mensaje;
    long tamaño;
    file = fopen("unmanual.txt", "r");

    if(file == NULL) {
            printf("No se pudo abrir el archivo\n");
            return 1;
    }

// Determinar el tamaño del archivo
    fseek(file, 0, SEEK_END);
    tamaño = ftell(file);
    rewind(file);
    
    // Asignar memoria dinámica para almacenar el contenido del archivo
    mensaje = (char *)malloc((tamaño + 1) * sizeof(char));
    if (mensaje == NULL) {
        fprintf(stderr, "No se pudo asignar memoria.\n");
        return 1;
    }

    // Leer el contenido del archivo en el espacio de memoria asignado
    if (fread(mensaje, sizeof(char), tamaño, file) != tamaño) {
        fprintf(stderr, "Error al leer el archivo.\n");
        return 1;
    }
    mensaje[tamaño] = '\0'; // Añadir el carácter nulo al final del contenido

    // Cerrar el archivo
    fclose(file);

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