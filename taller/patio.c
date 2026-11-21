#include <stdio.h>
#include <string.h>
#include "patio.h"

// Inicializa el patio de contenedores
void inicializar_patio(PatioContenedores *patio) {
    patio->tope = -1;
}

// Verifica si el patio alcanzó su capacidad máxima de 5 contenedores
int patio_esta_lleno(PatioContenedores *patio) {
    return patio->tope == CAPACIDAD_PATIO - 1;
}

// Verifica si el patio se encuentra vacío
int patio_esta_vacio(PatioContenedores *patio) {
    return patio->tope == -1;
}

// Inserta un contenedor en la zona de despacho (Pila LIFO)
int ingresar_contenedor(PatioContenedores *patio, Contenedor c) {
    if (patio_esta_lleno(patio)) {
        return 0; // Error: Patio lleno (bloqueo)
    }
    patio->tope++;
    patio->elementos[patio->tope] = c;
    return 1; // Éxito
}

// Retira el contenedor superior del patio (último en entrar, primero en salir)
int retirar_contenedor(PatioContenedores *patio, Contenedor *c_retirado) {
    if (patio_esta_vacio(patio)) {
        return 0; // Error: Patio vacío
    }
    *c_retirado = patio->elementos[patio->tope];
    patio->tope--;
    return 1; // Éxito
}

// Muestra todos los contenedores actuales en el patio
void consultar_patio(PatioContenedores *patio) {
    if (patio_esta_vacio(patio)) {
        printf("\nEl patio de contenedores se encuentra vacio.\n");
        return;
    }
    printf("\n=== ESTADO ACTUAL DEL PATIO DE CONTENEDORES (Tope a Base) ===\n");
    for (int i = patio->tope; i >= 0; i--) {
        printf("Posicion %d:\n", i + 1);
        mostrar_contenedor(patio->elementos[i]);
    }
}