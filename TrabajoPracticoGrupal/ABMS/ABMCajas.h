#ifndef ABMCAJAS_H
#define ABMCAJAS_H

#include "caja.h"

// Declaración de funciones para el ABM de cajas
void altaCaja(CajaPtr cajas[], int *numCajas, int numeroCaja, double montoInicial);
void bajaCaja(CajaPtr cajas[], int *numCajas, int numeroCaja);
void modificarCaja(CajaPtr cajas[], int numCajas, int numeroCaja, double montoInicial);
void mostrarCajas(CajaPtr cajas[], int numCajas);

#endif // ABMCAJAS_H