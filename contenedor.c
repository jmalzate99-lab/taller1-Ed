
#include <stdio.h>
#include <stdlib.h>
#include "contenedor.h"

// Funcion para mostrar los datos
void mostrarDatos(Contenedor *c) {
    printf("\n-----------------------------\n");
    printf("ID: %d\n", c->id);
    printf("Tara: %.2f\n", c->tara);
    printf("Peso de carga: %.2f\n", c->pesoCarga);
    printf("Peso total: %.2f\n", c->pesoTotal);
    printf("Costo: $%.2f\n", c->costo);
    printf("-----------------------------\n");
}

// Funcion para insertar un contenedor
void insertarContenedor(Contenedor **inicio, Contenedor **fin, int *siguienteId) {

    Contenedor *nuevo = (Contenedor *)malloc(sizeof(Contenedor));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    nuevo->id = *siguienteId;

    printf("Ingrese la tara: ");
    scanf("%f", &nuevo->tara);

    printf("Ingrese el peso de carga: ");
    scanf("%f", &nuevo->pesoCarga);

    printf("Ingrese el costo: ");
    scanf("%f", &nuevo->costo);

    nuevo->pesoTotal = nuevo->tara + nuevo->pesoCarga;

    nuevo->anterior = *fin;
    nuevo->siguiente = NULL;

    if (*inicio == NULL) {
        *inicio = nuevo;
        *fin = nuevo;
    } else {
        (*fin)->siguiente = nuevo;
        *fin = nuevo;
    }

    (*siguienteId)++;

    printf("\nContenedor registrado correctamente.\n");
    printf("ID asignado: %d\n", nuevo->id);
    printf("Peso total: %.2f\n", nuevo->pesoTotal);
}

// Funcion para buscar un contenedor
Contenedor *buscarContenedor(Contenedor *inicio, int id) {

    Contenedor *actual = inicio;

    while (actual != NULL) {

        if (actual->id == id) {
            return actual;
        }

        actual = actual->siguiente;
    }

    return NULL;
}

// Funcion para actualizar un contenedor
void actualizarContenedor(Contenedor *inicio) {

    int id;

    printf("Ingrese el ID del contenedor: ");
    scanf("%d", &id);

    Contenedor *encontrado = buscarContenedor(inicio, id);

    if (encontrado == NULL) {
        printf("Contenedor no encontrado.\n");
        return;
    }

    printf("Ingrese la nueva tara: ");
    scanf("%f", &encontrado->tara);

    printf("Ingrese el nuevo peso de carga: ");
    scanf("%f", &encontrado->pesoCarga);

    printf("Ingrese el nuevo costo: ");
    scanf("%f", &encontrado->costo);

    encontrado->pesoTotal =
        encontrado->tara + encontrado->pesoCarga;

    printf("Contenedor actualizado correctamente.\n");
}

// Funcion para eliminar un contenedor
void eliminarContenedor(Contenedor **inicio, Contenedor **fin) {

    int id;

    printf("Ingrese el ID del contenedor: ");
    scanf("%d", &id);

    Contenedor *encontrado = buscarContenedor(*inicio, id);

    if (encontrado == NULL) {
        printf("Contenedor no encontrado.\n");
        return;
    }

    if (encontrado->anterior != NULL) {
        encontrado->anterior->siguiente =
            encontrado->siguiente;
    } else {
        *inicio = encontrado->siguiente;
    }

    if (encontrado->siguiente != NULL) {
        encontrado->siguiente->anterior =
            encontrado->anterior;
    } else {
        *fin = encontrado->anterior;
    }

    free(encontrado);

    printf("Contenedor eliminado correctamente.\n");
}

// Mostrar desde el inicio hasta el final
void mostrarAdelante(Contenedor *inicio) {

    Contenedor *actual = inicio;

    if (actual == NULL) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    while (actual != NULL) {
        mostrarDatos(actual);
        actual = actual->siguiente;
    }
}

// Mostrar desde el final hasta el inicio
void mostrarAtras(Contenedor *fin) {

    Contenedor *actual = fin;

    if (actual == NULL) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    while (actual != NULL) {
        mostrarDatos(actual);
        actual = actual->anterior;
    }
}

// Liberar toda la memoria utilizada
void liberarMemoria(Contenedor **inicio, Contenedor **fin) {

    Contenedor *actual = *inicio;

    while (actual != NULL) {

        Contenedor *temporal = actual;

        actual = actual->siguiente;

        free(temporal);
    }

    *inicio = NULL;
    *fin = NULL;
}
