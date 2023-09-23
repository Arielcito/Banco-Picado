#ifndef CUENTA_H
#define CUENTA_H

#include "cliente.h"
typedef struct
{
    int numeroCuenta;
    Cliente titular; // El cliente titular de la cuenta
    double saldo;   // Saldo disponible en pesos
} Cuenta;

typedef Cuenta* CuentaPtr;

// Liberar la memoria asociada con la cuenta
CuentaPtr destruirCuenta(CuentaPtr cuenta);

CuentaPtr crearCuenta(int numeroCuenta, Cliente titular, double saldo);
// Getters & Setters
int getNumeroCuenta(CuentaPtr cuenta);
Cliente getTitular(CuentaPtr cuenta);
double getSaldo(CuentaPtr cuenta);

void setNumeroCuenta(CuentaPtr cuenta, int numeroCuenta);
void setTitular(CuentaPtr cuenta, Cliente titular);
void setSaldo(CuentaPtr cuenta, double saldo);

#endif // CUENTA_H
