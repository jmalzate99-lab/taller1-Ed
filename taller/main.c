#include <stdio.h>
#include <string.h>
#include "contenedor.h"
#include "patio.h"

void mostrar_menu() {
    printf("\n========================================\n");
    printf(" PUERTO DE BUENAVENTURA - CONTROL PATIO\n");
    printf("========================================\n");
    printf("1. Ingresar contenedor\n");
    printf("2. Retirar contenedor (Despacho)\n");
    printf("3. Consultar estado del patio\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    PatioContenedores patio;
    inicializar_patio(&patio);
    int opcion;

    do {
        mostrar_menu();
        if (scanf("%d", &opcion) != 1) {
            printf("Por favor, ingrese un numero valido.\n");
            while(getchar() != '\n'); // Limpiar buffer
            continue;
        }
        while(getchar() != '\n'); // Limpiar buffer de salto de linea

        switch (opcion) {
            case 1: {
                Contenedor nuevo;
                printf("\n--- REGISTRAR NUEVO CONTENEDOR ---\n");
                printf("Ingrese codigo alfanumerico (exactamente 4 caracteres): ");
                fgets(nuevo.codigo, sizeof(nuevo.codigo), stdin);
                nuevo.codigo[strcspn(nuevo.codigo, "\n")] = 0; // Quitar salto de línea

                if (strlen(nuevo.codigo) != 4) {
                    printf("Error: El codigo debe tener exactamente 4 caracteres.\n");
                    break;
                }

                printf("Ingrese peso en toneladas: ");
                if (scanf("%f", &nuevo.peso) != 1) {
                    printf("Peso invalido.\n");
                    while(getchar() != '\n');
                    break;
                }
                while(getchar() != '\n');

                printf("Ingrese tipo de mercancía: ");
                fgets(nuevo.tipo_mercancia, sizeof(nuevo.tipo_mercancia), stdin);
                nuevo.tipo_mercancia[strcspn(nuevo.tipo_mercancia, "\n")] = 0;

                if (ingresar_contenedor(&patio, nuevo)) {
                    printf("Contenedor registrado e ingresado al patio exitosamente.\n");
                } else {
                    printf("¡PATIO LLENO! Capacidad maxima de 5 contenedores alcanzada. Se ha notificado bloqueo operativo.\n");
                }
                break;
            }
            case 2: {
                Contenedor retirado;
                if (retirar_contenedor(&patio, &retirado)) {
                    printf("\nContenedor retirado con exito para despacho:\n");
                    mostrar_contenedor(retirado);
                } else {
                    printf("El patio esta vacio. No hay contenedores para retirar.\n");
                }
                break;
            }
            case 3:
                consultar_patio(&patio);
                break;
            case 4:
                printf("\nSaliendo del sistema del Terminal Maritimo...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}