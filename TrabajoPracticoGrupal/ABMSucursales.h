#ifndef ABMSUCURSALES_H
#define ABMSUCURSALES_H

#include "sucursal.h"

// Declaración de funciones para el ABM de sucursales
void altaSucursal(SucursalPtr listaSucursales, int *numSucursales);
void bajaSucursal(SucursalPtr listaSucursales, int *numSucursales, int numeroSucursal);
void modificarSucursal(SucursalPtr listaSucursales, int numSucursales, int numeroSucursal);
void mostrarSucursales(SucursalPtr listaSucursales);

void mostrarMenuSucursales();
#endif // ABMSUCURSALES_H
