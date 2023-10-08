#include <stdio.h>
#include "Pila.h"
#include "Cuenta.h"

typedef struct {
    int cliente; // Nombre del cliente
    char cajero[100]; // Nombre del cajero
    double monto; // Monto de la operación (positivo para depósitos, negativo para retiros)
} InformeOperacion;

void ingresarDinero(CuentaPtr cuenta, const char* cajero, PtrPila pilaTransacciones) {
    // Solicitar al usuario el monto a ingresar
    double monto;
    printf("Ingrese el monto a ingresar: ");
    scanf("%lf", &monto);

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

void retirarDinero(CuentaPtr cuenta, const char* cajero, PtrPila pilaTransacciones) {
    // Solicitar al usuario el monto a ingresar
    double monto;
    printf("Ingrese el monto a ingresar: ");
    scanf("%lf", &monto);
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

// Función para consultar el saldo de una cuenta
void consultarSaldo(CuentaPtr cuenta) {
    printf("Saldo disponible en la cuenta: %.2lf\n", getSaldo(cuenta));
}

// Estructura para registrar movimientos
typedef struct {
    char cajero[50]; // Nombre del cajero
    double monto;   // Monto involucrado en el movimiento
} Movimiento;

// Función para consultar los movimientos realizados en una cuenta
void consultarMovimientos(PtrPila pilaTransacciones) {
    if (estaVaciaPila(pilaTransacciones)) {
        printf("No hay movimientos registrados en esta cuenta.\n");
    } else {
        printf("Movimientos realizados en la cuenta:\n");

        // Utilizamos una pila temporal para imprimir los movimientos en orden
        PtrPila pilaTemporal = crearPila();

        // Mientras la pila original no esté vacía, copiamos sus elementos en la pila temporal
        while (!estaVaciaPila(pilaTransacciones)) {
            Movimiento *movimiento = (Movimiento *)cima(pilaTransacciones);
            apilar(pilaTemporal, movimiento);
            desapilar(pilaTransacciones);
        }

        // Ahora, desapilamos la pila temporal y mostramos los movimientos en orden
        while (!estaVaciaPila(pilaTemporal)) {
            Movimiento *movimiento = (Movimiento *)cima(pilaTemporal);
            printf("Cajero: %s, Monto: %.2lf\n", movimiento->cajero, movimiento->monto);
            apilar(pilaTransacciones, movimiento); // Devolvemos los elementos a la pila original
            desapilar(pilaTemporal);
        }

        destruirPila(pilaTemporal); // Liberamos la memoria de la pila temporal
    }
}

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
