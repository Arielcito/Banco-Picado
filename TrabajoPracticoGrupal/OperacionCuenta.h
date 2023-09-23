#ifndef OPERACION_CUENTA_H
#define OPERACION_CUENTA_H

#include "cuenta.h"
#include <time.h>

typedef struct
{
    time_t fechaHoraOperacion;
    double montoCheques;
    double montoEfectivo;
    Cuenta cuentaAfectada; // La cuenta en la que se realizó la operación
} OperacionCuenta;

typedef OperacionCuenta* OperacionCuentaPtr;

// Liberar la memoria asociada con la operación de cuenta
OperacionCuentaPtr destruirOperacionCuenta(OperacionCuentaPtr operacionCuenta);

// Getters & Setters
time_t getFechaHoraOperacion(OperacionCuentaPtr operacion);
double getMontoCheques(OperacionCuentaPtr operacion);
double getMontoEfectivo(OperacionCuentaPtr operacion);
Cuenta getCuentaAfectada(OperacionCuentaPtr operacion);

void setFechaHoraOperacion(OperacionCuentaPtr operacion, time_t fechaHora);
void setMontoCheques(OperacionCuentaPtr operacion, double montoCheques);
void setMontoEfectivo(OperacionCuentaPtr operacion, double montoEfectivo);
void setCuentaAfectada(OperacionCuentaPtr operacion, Cuenta cuenta);

#endif // OPERACION_CUENTA_H
