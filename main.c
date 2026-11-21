
#include <stdio.h>
#include "contenedor.h"

int main() {

    Contenedor *inicio = NULL;
    Contenedor *fin = NULL;

    int siguienteId = 1;
    int opcion;
    int id;

    do {

        printf("\n====================================\n");
        printf(" SISTEMA DE GESTION DE CONTENEDORES\n");
        printf("====================================\n");

        printf("1. Registrar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Mostrar de inicio a fin\n");
        printf("6. Mostrar de fin a inicio\n");
        printf("0. Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                insertarContenedor(
                    &inicio, &fin, &siguienteId
                );
                break;

            case 2:
                printf("Ingrese el ID: ");
                scanf("%d", &id);

                Contenedor *encontrado =
                    buscarContenedor(inicio, id);

                if (encontrado != NULL) {
                    printf("\nContenedor encontrado:\n");

                    printf("ID: %d\n", encontrado->id);
                    printf("Tara: %.2f\n", encontrado->tara);
                    printf("Peso de carga: %.2f\n",
                           encontrado->pesoCarga);
                    printf("Peso total: %.2f\n",
                           encontrado->pesoTotal);
                    printf("Costo: %.2f\n",
                           encontrado->costo);
                } else {
                    printf("Contenedor no encontrado.\n");
                }
                break;

            case 3:
                actualizarContenedor(inicio);
                break;

            case 4:
                eliminarContenedor(&inicio, &fin);
                break;

            case 5:
                mostrarAdelante(inicio);
                break;

            case 6:
                mostrarAtras(fin);
                break;

            case 0:
                liberarMemoria(&inicio, &fin);
                printf("Memoria liberada correctamente.\n");
                printf("Gracias por utilizar el sistema.\n");
                break;

            default:
                printf("Opcion incorrecta.\n");
        }

    } while (opcion != 0);

    return 0;
}
