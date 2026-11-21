#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define MAX_CODIGO 5

// Estructura que define un Contenedor
typedef struct {
    char codigo[MAX_CODIGO]; // Alfanumérico de 4 caracteres + '\0'
    float peso;              // Peso en toneladas
    char tipo_mercancia[30]; // Tipo de mercancía
} Contenedor;

// Prototipos de funciones para el manejo del contenedor
void mostrar_contenedor(Contenedor c);

#endif