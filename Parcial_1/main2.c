#include <stdio.h>
#include <stdlib.h>
#include "container.h"

int main() {
    int n = 0;
    printf("====================================================\n");
    printf("   SISTEMA LOGISTICO - PUERTO DE BUENAVENTURA       \n");
    printf("====================================================\n");
    printf("Ingrese el numero de contenedores/buques a gestionar: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Cantidad no valida.\n");
        return 1;
    }

    Contenedor *inventario = (Contenedor *)malloc(n * sizeof(Contenedor));
    if (inventario == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    registrarContenedores(inventario, n);

    int opcion = 0;
    do {
        printf("\n--- MENU PRINCIPAL - PATIO DE CONTENEDORES ---\n");
        printf("1. Mostrar inventario actual\n");
        printf("2. Ordenar por Bubble Sort (Burbuja)\n");
        printf("3. Ordenar por Selection Sort (Seleccion)\n");
        printf("4. Ordenar por Insertion Sort (Insercion)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("Opcion invalida.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                printf("\n[Inventario Actual del Puerto]");
                mostrarContenedores(inventario, n);
                break;
            case 2:
                bubbleSort(inventario, n);
                printf("\n[Exito] Contenedores ordenados mediante Bubble Sort.");
                mostrarContenedores(inventario, n);
                break;
            case 3:
                selectionSort(inventario, n);
                printf("\n[Exito] Contenedores ordenados mediante Selection Sort.");
                mostrarContenedores(inventario, n);
                break;
            case 4:
                insertionSort(inventario, n);
                printf("\n[Exito] Contenedores ordenados mediante Insertion Sort.");
                mostrarContenedores(inventario, n);
                break;
            case 5:
                printf("\nSaliendo del sistema logistico...\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }
    } while (opcion != 5);

    free(inventario);
    return 0;
}