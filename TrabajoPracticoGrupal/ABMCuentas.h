#ifndef ABMCUENTAS_H
#define ABMCUENTAS_H

#include "cuenta.h"

// Declaración de funciones para el ABM de cuentas
void altaCuenta(CuentaPtr* listaCuentas, int *numCuentas, ClientePtr titular);
void bajaCuenta(CuentaPtr cuentas[], int *numCuentas, int numeroCuenta);
void modificarCuenta(CuentaPtr cuentas[], int numCuentas, int numeroCuenta, Cliente titular, double saldo);
void mostrarCuentas(CuentaPtr cuentas[], int numCuentas);

void mostrarMenuCuentas();
#endif // ABMCUENTAS_H
