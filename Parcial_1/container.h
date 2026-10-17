#ifndef CONTAINER_H
#define CONTAINER_H

#define MAX_CODIGO 20
#define MAX_TIPO 30
#define MAX_BAHIA 20

typedef struct {
    char codigo[MAX_CODIGO];
    float peso;
    char tipo[MAX_TIPO];
    char bahia[MAX_BAHIA];
} Contenedor;

void registrarContenedores(Contenedor *arr, int n);
void mostrarContenedores(const Contenedor *arr, int n);

void bubbleSort(Contenedor *arr, int n);
void selectionSort(Contenedor *arr, int n);
void insertionSort(Contenedor *arr, int n);

#endif