#ifndef BANCO_H
#define BANCO_H

#include "caja.h"

typedef struct
{
    int numeroSucursal;
    char domicilio[100];
    Caja cajas[2]; // Dos cajas para atención al público
} Sucursal;

typedef Sucursal* SucursalPtr;

// Liberar la memoria asociada con la sucursal
SucursalPtr destruirSucursal(SucursalPtr sucursal);

Sucursal* crearSucursal(int numeroSucursal, const char *domicilio);
// Getters & Setters
int getNumeroSucursal(SucursalPtr sucursal);
const char* getDomicilio(SucursalPtr sucursal);
Caja getCaja(SucursalPtr sucursal, int numeroCaja);
void setNumeroSucursal(SucursalPtr sucursal, int numeroSucursal);
void setDomicilio(SucursalPtr sucursal, char *domicilio);
void setCaja(SucursalPtr sucursal, int numeroCaja, Caja *caja);
void cargarSucursalesDesdeArchivo(const char *nombreArchivo, SucursalPtr listaSucursales);

#endif // BANCO_H
