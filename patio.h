#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define CAPACIDAD_PATIO 5

// Estructura para la Pila del Patio de Contenedores (LIFO)
typedef struct {
    Contenedor elementos[CAPACIDAD_PATIO];
    int tope;
} PatioContenedores;

// Prototipos de funciones del patio
void inicializar_patio(PatioContenedores *patio);
int patio_esta_lleno(PatioContenedores *patio);
int patio_esta_vacio(PatioContenedores *patio);
int ingresar_contenedor(PatioContenedores *patio, Contenedor c);
int retirar_contenedor(PatioContenedores *patio, Contenedor *c_retirado);
void consultar_patio(PatioContenedores *patio);

#endif