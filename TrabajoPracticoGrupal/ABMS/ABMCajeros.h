#ifndef ABMCAJEROS_H
#define ABMCAJEROS_H

#include "cajero.h"

// Declaraci�n de funciones para el ABM de cajeros
void altaCajero(CajeroPtr cajeros[], int *numCajeros);
void bajaCajero(CajeroPtr cajeros[], int *numCajeros, long cuil);
void modificarCajero(CajeroPtr cajeros[], int numCajeros, long cuil);
void mostrarCajeros(CajeroPtr cajeros[], int numCajeros);

#endif // ABMCAJEROS_H
