#include <stdio.h>

// Función para dibujar un cuadrado de tamaño n
void drawSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Función para dibujar un óvalo de ancho width y alto height
void drawOval(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i == 0 || i == height - 1) && (j > 0 && j < width - 1)) {
                printf("*");
            } else if ((i > 0 && i < height - 1) && (j == 0 || j == width - 1)) {
                printf("*");
            } else if ((i == 1 || i == height - 2) && (j == 1 || j == width - 2)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Función para dibujar una flecha de longitud n
void drawArrow(int length) {
    int mid = length / 2;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i == mid || (i < mid && j == mid) || (i > mid && j == mid)) {
                printf("*");
            } else if (i < mid && (j == mid - i || j == mid + i)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Función para dibujar un diamante de tamaño n
void drawDiamond(int size) {
    int n = size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Función para dibujar un triángulo de base base
void drawTriangle(int base) {
    int height = base / 2 + 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < base; j++) {
            if (j == height - i - 1 || j == height + i - 1 || i == height - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Función para imprimir el menú de opciones
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Dibujar Cuadrado\n");
    printf("2. Dibujar Ovalo\n");
    printf("3. Dibujar Flecha\n");
    printf("4. Dibujar Diamante\n");
    printf("5. Dibujar Triangulo\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        int size, width, height, length, base;
        switch(choice) {
            case 1:
                printf("Ingrese el tamanio del cuadrado: ");
                scanf("%d", &size);
                drawSquare(size);
                break;
            case 2:
                printf("Ingrese el ancho del ovalo: ");
                scanf("%d", &width);
                printf("Ingrese la altura del ovalo: ");
                scanf("%d", &height);
                drawOval(width, height);
                break;
            case 3:
                printf("Ingrese la longitud de la flecha: ");
                scanf("%d", &length);
                drawArrow(length);
                break;
            case 4:
                printf("Ingrese el tamanio del diamante: ");
                scanf("%d", &size);
                drawDiamond(size);
                break;
            case 5:
                printf("Ingrese la base del triangulo: ");
                scanf("%d", &base);
                drawTriangle(base);
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intentelo de nuevo.\n");
        }
    } while (choice != 6);
    return 0;
}