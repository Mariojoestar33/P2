#include <stdio.h>
#include <stdbool.h>

// Función para verificar si un año es bisiesto
bool es_bisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

// Función para convertir mes y día a día del año
int convertir_a_dia_del_anio(int dia, int mes, int anio) {
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (es_bisiesto(anio)) {
        dias_por_mes[1] = 29; // Febrero tiene 29 días en un año bisiesto
    }

    int dia_del_anio = 0;
    for (int i = 0; i < mes - 1; i++) {
        dia_del_anio += dias_por_mes[i];
    }
    dia_del_anio += dia;
    
    return dia_del_anio;
}

// Función para convertir día del año a mes y día
void convertir_a_mes_y_dia(int dia_del_anio, int anio, int *mes, int *dia) {
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (es_bisiesto(anio)) {
        dias_por_mes[1] = 29; // Febrero tiene 29 días en un año bisiesto
    }

    *mes = 0;
    while (dia_del_anio > dias_por_mes[*mes]) {
        dia_del_anio -= dias_por_mes[*mes];
        (*mes)++;
    }
    *dia = dia_del_anio;
    (*mes)++; // Ajustamos el mes porque el array empieza en 0
}

int main() {
    int opcion, dia, mes, anio, dia_del_anio;
    
    printf("Seleccione una opcion:\n");
    printf("1. Convertir mes y dia a dia del anio\n");
    printf("2. Convertir dia del anio a mes y dia\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el dia: ");
        scanf("%d", &dia);
        printf("Ingrese el mes: ");
        scanf("%d", &mes);
        printf("Ingrese el anio: ");
        scanf("%d", &anio);
        
        dia_del_anio = convertir_a_dia_del_anio(dia, mes, anio);
        printf("El dia %d/%d corresponde al dia %d del anio %d.\n", dia, mes, dia_del_anio, anio);
    } else if (opcion == 2) {
        printf("Ingrese el dia del anio: ");
        scanf("%d", &dia_del_anio);
        printf("Ingrese el anio: ");
        scanf("%d", &anio);
        
        convertir_a_mes_y_dia(dia_del_anio, anio, &mes, &dia);
        printf("El dia %d del anio %d corresponde al %d/%d.\n", dia_del_anio, anio, dia, mes);
    } else {
        printf("Opcion no valida.\n");
    }
    return 0;
}