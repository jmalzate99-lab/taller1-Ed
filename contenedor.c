#include <stdio.h>
#include "contenedor.h"

// Función auxiliar para mostrar los datos de un contenedor
void mostrar_contenedor(Contenedor c) {
    printf("----------------------------------------\n");
    printf(" Codigo: %s\n", c.codigo);
    printf(" Peso: %.2f toneladas\n", c.peso);
    printf(" Mercancia: %s\n", c.tipo_mercancia);
    printf("----------------------------------------\n");
}