#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    //Declaraciones
    char mensaje[100];
    int opcion = 0;
    printf("Introdusca un mensaje:\n\n");
    gets(mensaje);
    char* puntero = (char*)malloc(sizeof(char*)*(strlen(mensaje) + 1)); //Declaracion del puntero donde se almacena el mensaje
    strcpy(puntero, mensaje);
    //Menu con las diferentes opciones despegables
    while(opcion != 3) {
        opcion = 0;
        printf("El mensaje es: %s\n\n", puntero);
        printf("Que deseas hacer?\n\n1)Mayusculas\n2)Minusculas\n3)Salir\n\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case (1): {
                for (int i = 0; i < strlen(puntero); i++) {
                    puntero[i] = toupper(puntero[i]);
                }
                break;
            }
            case (2): {
                for (int i = 0; i < strlen(puntero); i++) {
                    puntero[i] = tolower(puntero[i]);
                }
                break;
            }
            case (3): {
                printf("Hasta la proxima!!!\n\n");
                exit(1);
            }
            default: {
                printf("Opcion no valida\n");
                break;
            }
        }
    }
    //libracion de la memoria
    free(puntero);
    return 0;
}