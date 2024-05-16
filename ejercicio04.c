#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

float suma(float x, float y);
float resta(float x, float y);
float multiplicacion(float x, float y);
float division(float x, float y);
bool verificar(float x, float y);

int main() {
    float x, y;
    int opcion;
    while (opcion != 5)
    {
        opcion = 0;
        printf("Ingrese la operacion a realizar:\n\n");
        printf("1)Suma\n2)Resta\n3)Multiplicacion\n4)Division\n5)Salir\n\n");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion) {
        case (1): {
            printf("Ingrese el primer numero:\n");
            scanf("%f", &x);
            printf("Ingrese el segundo numero:\n");
            scanf("%f", &y);
            printf("El resultado es: %f\n", suma(x, y));
            break;
        }

        case (2): {
            printf("Ingrese el primer numero:\n");
            scanf("%f", &x);
            printf("Ingrese el segundo numero:\n");
            scanf("%f", &y);
            printf("El resultado es: %f\n", resta(x, y));
            break;
        }

        case (3): {
            printf("Ingrese el primer numero:\n");
            scanf("%f", &x);
            printf("Ingrese el segundo numero:\n");
            scanf("%f", &y);
            printf("El resultado es: %f\n", multiplicacion(x, y));
            break;
        }

        case(4): {
            printf("Ingrese el primer numero:\n");
            scanf("%f", &x);
            printf("Ingrese el segundo numero:\n");
            scanf("%f", &y);
            printf("El resultado es: %f\n", division(x, y));
            break;
        }

        case(5): {
            printf("\n\nHasta la proxima!!!\n\n");
            break;
        }
        
        default:
            printf("\nOpcion invalida\n\n");
            break;
        }
    }
    
    return 0;
}

float suma(float x, float y) {
    return (x + y);
}

float resta(float x, float y) {
    return (x - y);
}

float multiplicacion(float x, float y) {
    return (x * y);
}

float division(float x, float y) {
    return (x / y);
}

bool verificar(float num1, float num2) {
    char* cadena1 = NULL;
    char* cadena2 = NULL;
    sprintf(cadena1, "%f", num1); // Convertir el primer flotante a cadena
    sprintf(cadena2, "%f", num2); // Convertir el segundo flotante a cadena
    // Verificar el primer flotante
    for (int i = 0; cadena1[i] != '\0'; i++) {
        if (!isdigit(cadena1[i]) && cadena1[i] != '.' && cadena1[i] != '-') {
            return false;
        }
    }
    // Verificar el segundo flotante
    for (int i = 0; cadena2[i] != '\0'; i++) {
        if (!isdigit(cadena2[i]) && cadena2[i] != '.' && cadena2[i] != '-') {
            return false;
        }
    }
    return true;
}
