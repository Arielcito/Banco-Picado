
#ifndef ABMCAJAS_H
#define ABMCAJAS_H

#include "caja.h"

// Declaraci�n de funciones para el ABM de cajas
void altaCaja(CajaPtr listaCajas, int *numCajas, int numeroCaja, double montoInicial);
void bajaCaja(CajaPtr listaCajas, int *numCajas, int numeroCaja);
void modificarCaja(CajaPtr listaCajas, int *numCajas, int numeroCaja, double montoInicial);
void mostrarCajas(CajaPtr listaCajas, int *numCajas);

void mostrarMenuCajas();
#endif // ABMCAJAS_H
