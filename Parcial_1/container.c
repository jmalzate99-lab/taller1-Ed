#include <stdio.h>
#include <string.h>
#include "container.h"

void registrarContenedores(Contenedor *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Registrando Contenedor %d de %d ---\n", i + 1, n);
        printf("Código único alfanumérico: ");
        scanf("%s", (arr + i)->codigo);
        printf("Peso en toneladas: ");
        scanf("%f", &(arr + i)->peso);
        printf("Tipo de mercancía: ");
        scanf(" %[^\n]", (arr + i)->tipo);
        printf("Bahía de asignación: ");
        scanf(" %[^\n]", (arr + i)->bahia);
    }
}

void mostrarContenedores(const Contenedor *arr, int n) {
    printf("\n%-10s | %-10s | %-20s | %-15s\n", "CÓDIGO", "PESO (t)", "TIPO MERCANCÍA", "BAHÍA");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s | %-10.2f | %-20s | %-15s\n", 
               (arr + i)->codigo, (arr + i)->peso, (arr + i)->tipo, (arr + i)->bahia);
    }
    printf("------------------------------------------------------------------------\n");
}

void bubbleSort(Contenedor *arr, int n) {
    Contenedor temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->peso > (arr + j + 1)->peso) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void selectionSort(Contenedor *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->peso < (arr + minIndex)->peso) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Contenedor temp = *(arr + i);
            *(arr + i) = *(arr + minIndex);
            *(arr + minIndex) = temp;
        }
    }
}

void insertionSort(Contenedor *arr, int n) {
    for (int i = 1; i < n; i++) {
        Contenedor key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && (arr + j)->peso > key.peso) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}