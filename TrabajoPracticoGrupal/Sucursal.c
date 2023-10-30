#include "sucursal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Sucursal* crearSucursal(int numeroSucursal, const char *domicilio)
{
    Sucursal *sucursal = (Sucursal*)obtenerMemoria(sizeof(Sucursal), "Error al crear una nueva sucursal");
    sucursal->numeroSucursal = numeroSucursal;
    strncpy(sucursal->domicilio, domicilio, sizeof(sucursal->domicilio));
    // Inicializar otros campos si es necesario
    return sucursal;
}

SucursalPtr destruirSucursal(SucursalPtr sucursal)
{
    free(sucursal);
}

// Getter para el número de sucursal
int getNumeroSucursal(SucursalPtr sucursal)
{
    return sucursal->numeroSucursal;
}

// Getter para el domicilio
const char* getDomicilio(SucursalPtr sucursal)
{
    return sucursal->domicilio;
}

// Getter para una caja en la sucursal (asumiendo que existe el TDA Caja)
Caja getCaja(SucursalPtr sucursal, int numeroCaja)
{
    return sucursal->cajas[numeroCaja];
}

// Setter para el número de sucursal
void setNumeroSucursal(SucursalPtr sucursal, int numeroSucursal)
{
    sucursal->numeroSucursal = numeroSucursal;
}

// Setter para el domicilio
void setDomicilio(SucursalPtr sucursal, char *domicilio)
{
    strncpy(sucursal->domicilio, domicilio, sizeof(sucursal->domicilio));
}

// Setter para una caja en la sucursal
void setCaja(SucursalPtr sucursal, int numeroCaja, Caja *caja)
{
    sucursal->cajas[numeroCaja] = *caja;
}

void cargarSucursalesDesdeArchivo(const char *nombreArchivo, SucursalPtr listaSucursales)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1);
    }

    char linea[100];
    Sucursal *sucursal;

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        int numeroSucursal;
        char domicilio[100];
        if (sscanf(linea, "%d %99[^\n]", &numeroSucursal, domicilio) == 2)
        {
            sucursal = crearSucursal(numeroSucursal, domicilio);
            // Agregar la sucursal a la lista
            agregarDatoLista(listaSucursales, sucursal);
        }
    }

    fclose(archivo);
}
