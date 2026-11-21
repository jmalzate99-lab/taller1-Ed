
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

typedef struct Contenedor {
    int id;
    float tara;
    float pesoCarga;
    float pesoTotal;
    float costo;

    struct Contenedor *anterior;
    struct Contenedor *siguiente;

} Contenedor;

// Declaracion de funciones
void insertarContenedor(Contenedor **inicio, Contenedor **fin, int *siguienteId);
Contenedor *buscarContenedor(Contenedor *inicio, int id);
void actualizarContenedor(Contenedor *inicio);
void eliminarContenedor(Contenedor **inicio, Contenedor **fin);
void mostrarAdelante(Contenedor *inicio);
void mostrarAtras(Contenedor *fin);
void liberarMemoria(Contenedor **inicio, Contenedor **fin);

#endif

