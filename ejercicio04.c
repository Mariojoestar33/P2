#include <stdio.h>
#include <stdlib.h>

float suma(float arr[], int n);
float resta(float arr[], int n);
float multiplicacion(float arr[], int n);
float division(float arr[], int n);

int main() {
    // Declaraciones
    int n;
    int opcion;
    while (1) {
        opcion = 0;
        printf("Ingrese la operacion a realizar:\n\n");
        printf("1) Suma\n2) Resta\n3) Multiplicacion\n4) Division\n5) Salir\n\n");
        scanf("%d", &opcion);
        printf("\n");
        if (opcion == 5) {
            printf("\n\nHasta la proxima!!!\n\n");
            break;
        }

        if (opcion < 1 || opcion > 5) {
            printf("\nOpcion invalida\n\n");
            continue;
        }

        printf("Ingrese el numero de elementos:\n");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Numero de elementos invalido\n");
            continue;
        }

        float arr[n];
        for (int i = 0; i < n; i++) {
            printf("Ingrese el elemento %d:\n", i + 1);
            scanf("%f", &arr[i]);
        }

        switch (opcion) {
        case 1:
            printf("El resultado es: %f\n", suma(arr, n));
            break;
        case 2:
            printf("El resultado es: %f\n", resta(arr, n));
            break;
        case 3:
            printf("El resultado es: %f\n", multiplicacion(arr, n));
            break;
        case 4:
            printf("El resultado es: %f\n", division(arr, n));
            break;
        }
    }

    return 0;
}

float suma(float arr[], int n) {
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}

float resta(float arr[], int n) {
    float result = arr[0];
    for (int i = 1; i < n; i++) {
        result -= arr[i];
    }
    return result;
}

float multiplicacion(float arr[], int n) {
    float result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= arr[i];
    }
    return result;
}

float division(float arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    float result = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            printf("Error: Division por cero\n");
            exit(1);
        }
        result /= arr[i];
    }
    return result;
}