#include <stdio.h>
#include <stdlib.h>

//Primitiva de la funcion "mayor"
float mayor(float x, float y, float z);

int main() {
    //Declaraciones
    float x, y, z;
    printf("Ingrese el primer numero:\n");
    scanf("%f", &x);
    printf("Ingrese el segundo numero:\n");
    scanf("%f", &y);
    printf("Ingrese el tercer numero:\n");
    scanf("%f", &z);
    printf("El numero mayor es: %.2f\n", mayor(x, y, z));
    return 0;
}

//Funcion para valorar el numero mayor
float mayor(float x, float y, float z) {
    if (x > y && x > z) {
        return x;
    } else if (y > x && y > z) {
        return y;
    } else {
        return z;
    }
}