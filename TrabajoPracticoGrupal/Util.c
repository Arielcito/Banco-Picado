#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void* obtenerMemoria(size_t tamanio, const char *mensajeError)
{
    void* ptr = malloc(tamanio);
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: No se ha podido obtener memoria. %s\n", mensajeError);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

char* obtenerFechaHoraActual() {
    static char fechaHoraActual[80]; // Variable estática para retener el resultado
    time_t rawtime;
    struct tm *info;

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(fechaHoraActual, sizeof(fechaHoraActual), "%Y-%m-%d %H:%M:%S", info);

    return fechaHoraActual;
}
