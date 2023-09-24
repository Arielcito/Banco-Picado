#include <stdio.h>
#include "Pila.h"
#include "Cuenta.h"

typedef struct {
    int cliente; // Nombre del cliente
    char cajero[100]; // Nombre del cajero
    double monto; // Monto de la operación (positivo para depósitos, negativo para retiros)
} InformeOperacion;

void ingresarDinero(CuentaPtr cuenta, double monto, const char* cajero, PtrPila pilaTransacciones) {
    // Verificar que el monto a ingresar sea positivo
    if (monto <= 0) {
        printf("El monto a ingresar debe ser mayor que cero.\n");
        return;
    }

    // Actualizar el saldo disponible en la cuenta
    cuenta->saldo += monto;

    // Registra la operación en la pila de transacciones
    InformeOperacion informe;
    informe.cliente = cuenta->numeroCuenta;
    strcpy(informe.cajero, cajero);
    informe.monto = monto;
    apilar(pilaTransacciones, &informe);

    // Imprimir un mensaje de confirmación
    printf("Se ingresaron %.2lf pesos a la cuenta de %d. Nuevo saldo: %.2lf\n", monto, cuenta->numeroCuenta, cuenta->saldo);
}

void retirarDinero(CuentaPtr cuenta, double monto, const char* cajero, PtrPila pilaTransacciones) {
    // Verificar que el monto a retirar sea positivo
    if (monto <= 0) {
        printf("El monto a retirar debe ser mayor que cero.\n");
        return;
    }

    // Verificar si el saldo es suficiente para el retiro
    if (monto > cuenta->saldo) {
        printf("Saldo insuficiente para realizar el retiro.\n");
        return;
    }

    // Realizar el retiro y actualizar el saldo disponible
    cuenta->saldo -= monto;

    // Registra la operación en la pila de transacciones
    InformeOperacion informe;
    informe.cliente = cuenta->numeroCuenta;
    strcpy(informe.cajero, cajero);
    informe.monto = -monto; // Monto negativo para indicar retiro
    apilar(pilaTransacciones, &informe);

    // Imprimir un mensaje de confirmación
    printf("Se retiraron %.2lf pesos de la cuenta de %d. Nuevo saldo: %.2lf\n", monto, cuenta->numeroCuenta, cuenta->saldo);
}

void mostrarInformes(PtrPila pila) {
    printf("Informe de operaciones:\n");

    // Creamos una pila auxiliar para invertir el orden de los informes
    PtrPila pilaAuxiliar = crearPila();

    // Desapilamos los elementos de la pila original y los apilamos en la auxiliar
    while (!pilaVacia(pila)) {
        InformeOperacion* informe = (InformeOperacion*)desapilar(pila);
        apilar(pilaAuxiliar, informe);
    }

    // Iteramos sobre la pila auxiliar para mostrar los informes
    while (!pilaVacia(pilaAuxiliar)) {
        InformeOperacion* informe = (InformeOperacion*)desapilar(pilaAuxiliar);
        // Suponiendo que InformeOperacion tiene campos nombreCliente, monto, etc.
        printf("Cliente: %d\n", informe->cliente);
        printf("Cajero: %s\n", informe->cajero);
        printf("Monto: %.2f\n", informe->monto);
        // Aquí muestra otros campos del informe según sea necesario
    }

    // Destruimos la pila auxiliar
    destruirPila(pilaAuxiliar);
}
