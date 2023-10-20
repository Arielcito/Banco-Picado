#ifndef ABMCAJEROS_H
#define ABMCAJEROS_H

#include "cajero.h"

// Declaraci�n de funciones para el ABM de cajeros
void altaCajero(CajeroPtr listaCajeros, int *numCajeros);
void bajaCajero(CajeroPtr listaCajeros, int *numCajeros, long cuil);
void modificarCajero(CajeroPtr listaCajeros, int numCajeros, long cuil);
void mostrarCajeros(CajeroPtr listaCajeros, int numCajeros);

void mostrarMenuCajero();
#endif // ABMCAJEROS_H

