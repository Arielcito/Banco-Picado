#include "cuenta.h"
#include <stdlib.h>

Cuenta* crearCuenta(int numeroCuenta, Cliente titular, double saldo) {
    Cuenta *cuenta = (Cuenta*)obtenerMemoria(sizeof(Cuenta), "Error al crear una nueva cuenta");
    cuenta->numeroCuenta = numeroCuenta;
    cuenta->titular = titular;
    cuenta->saldo = saldo;
    // Inicializar otros campos si es necesario
    return cuenta;
}

CuentaPtr destruirCuenta(CuentaPtr cuenta) {
    free(cuenta);
    return cuenta;
}

// Getter para el número de cuenta
int getNumeroCuenta(CuentaPtr cuenta) {
    return cuenta->numeroCuenta;
}

// Getter para el titular de la cuenta
Cliente getTitular(CuentaPtr cuenta) {
    return cuenta->titular;
}

// Getter para el saldo de la cuenta
double getSaldo(CuentaPtr cuenta) {
    return cuenta->saldo;
}

// Setter para el número de cuenta
void setNumeroCuenta(CuentaPtr cuenta, int numero) {
    cuenta->numeroCuenta = numero;
}

// Setter para el titular de la cuenta
void setTitular(CuentaPtr cuenta, Cliente titular) {
    cuenta->titular = titular;
}

// Setter para el saldo de la cuenta
void setSaldo(CuentaPtr cuenta, double saldo) {
    cuenta->saldo = saldo;
}
