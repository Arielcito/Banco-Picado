#ifndef ABMOPERACIONESCUENTA_H
#define ABMOPERACIONESCUENTA_H

#include "OperacionCuenta.h"

// Declaración de funciones para el ABM de operaciones en cuenta
void altaOperacionCuenta(OperacionCuentaPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion, double montoCheques, double montoEfectivo, Cuenta cuentaAfectada);
void bajaOperacionCuenta(OperacionCuentaPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion);
void modificarOperacionCuenta(OperacionCuentaPtr operaciones[], int numOperaciones, time_t fechaHoraOperacion, double montoCheques, double montoEfectivo, Cuenta cuentaAfectada);
void mostrarOperacionesCuenta(OperacionCuentaPtr operaciones[], int numOperaciones);

#endif // ABMOPERACIONESCUENTA_H