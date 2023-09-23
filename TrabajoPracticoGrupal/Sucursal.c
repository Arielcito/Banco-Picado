#include "sucursal.h"
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
    // Implementa la lógica para obtener la caja específica aquí
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

