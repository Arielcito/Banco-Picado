#ifndef ABMSUCURSALES_H
#define ABMSUCURSALES_H

#include "sucursal.h"

// Declaración de funciones para el ABM de sucursales
void altaSucursal(SucursalPtr sucursales[], int *numSucursales);
void bajaSucursal(SucursalPtr sucursales[], int *numSucursales, int numeroSucursal);
void modificarSucursal(SucursalPtr sucursales[], int numSucursales, int numeroSucursal);
void mostrarSucursales(SucursalPtr sucursales[], int numSucursales);

#endif // ABMSUCURSALES_H