#include "cajero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cajero* crearCajero(const char *apellido, const char *nombre, long cuil, int numeroLegajo) {
    Cajero *cajero = (Cajero*)obtenerMemoria(sizeof(Cajero), "Error al crear un nuevo cajero");
    strncpy(cajero->apellido, apellido, sizeof(cajero->apellido));
    strncpy(cajero->nombre, nombre, sizeof(cajero->nombre));
    cajero->cuil = cuil;
    cajero->numeroLegajo = numeroLegajo;
    // Inicializar otros campos si es necesario
    return cajero;
}

CajeroPtr destruirCajero(CajeroPtr cajero) {
    free(cajero->apellido);
    free(cajero->nombre);
    free(cajero);
    return cajero;
}

// Getter para el apellido del cajero
 char* getApellidoCajero(CajeroPtr cajero) {
    return cajero->apellido;
}

// Getter para el nombre del cajero
 char* getNombreCajero(CajeroPtr cajero) {
    return cajero->nombre;
}

// Getter para el CUIL del cajero
long getCuilCajero(CajeroPtr cajero) {
    return cajero->cuil;
}

// Getter para el número de legajo del cajero
int getNumeroLegajoCajero(CajeroPtr cajero) {
    return cajero->numeroLegajo;
}

// Setter para el apellido del cajero
void setApellidoCajero(CajeroPtr cajero, const char *apellido) {
    strncpy(cajero->apellido, apellido, sizeof(cajero->apellido));
}

// Setter para el nombre del cajero
void setNombreCajero(CajeroPtr cajero, const char *nombre) {
    strncpy(cajero->nombre, nombre, sizeof(cajero->nombre));
}

// Setter para el CUIL del cajero
void setCuilCajero(CajeroPtr cajero, long cuil) {
    cajero->cuil = cuil;
}

// Setter para el número de legajo del cajero
void setNumeroLegajoCajero(CajeroPtr cajero, int numeroLegajo) {
    cajero->numeroLegajo = numeroLegajo;
}

void cargarCajerosDesdeArchivo(const char *nombreArchivo, CajeroPtr listaCajeros)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1);
    }

    char linea[100];
    Cajero *cajero;

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        char apellido[100];
        char nombre[100];
        long cuil;
        int numeroLegajo;

        if (sscanf(linea, "%99s %99s %ld %d", apellido, nombre, &cuil, &numeroLegajo) == 4)
        {
            cajero = crearCajero(apellido, nombre, cuil, numeroLegajo);
            // Agregar el cajero a la lista
            agregarDatoLista(listaCajeros, cajero);
        }
    }

    fclose(archivo);
}
