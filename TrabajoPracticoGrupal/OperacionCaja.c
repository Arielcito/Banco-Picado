#include <stdio.h>
#include "Pila.h"
#include "Cuenta.h"
#include "InformeOperaciones.h"

void ingresarDinero(CuentaPtr cuenta,  CajeroPtr cajero, InformeOperacionPtr pilaTransacciones) {
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
    InformeOperacionPtr informe = crearInformeOperacion(cuenta,cajero,monto);

    apilar(pilaTransacciones, informe);

    // Imprimir un mensaje de confirmación
    printf("Se ingresaron %.2lf pesos a la cuenta de %d. Nuevo saldo: %.2lf\n", informe->monto, cuenta->numeroCuenta, cuenta->saldo);
}

void ingresarCheque(CuentaPtr cuenta,  CajeroPtr cajero, InformeOperacionPtr pilaTransacciones) {
    // Solicitar al usuario el monto a ingresar
    double monto;
    printf("Ingrese el monto del cheque: ");
    scanf("%lf", &monto);

    // Verificar que el monto a ingresar sea positivo
    if (monto <= 0) {
        printf("El monto a ingresar debe ser mayor que cero.\n");
        return;
    }

    // Actualizar el saldo disponible en la cuenta
    cuenta->saldo += monto;

    // Registra la operación en la pila de transacciones
    InformeOperacionPtr informe = crearInformeOperacion(cuenta,cajero,monto);

    apilar(pilaTransacciones, informe);

    // Imprimir un mensaje de confirmación
    printf("Se ingresaron %.2lf pesos a la cuenta de %d. Nuevo saldo: %.2lf\n", informe->monto, cuenta->numeroCuenta, cuenta->saldo);
}

void retirarDinero(CuentaPtr cuenta, CajeroPtr cajero, InformeOperacionPtr pilaTransacciones) {
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
    InformeOperacionPtr informe = crearInformeOperacion(cuenta,cajero,-monto);

    apilar(pilaTransacciones, informe);

    // Imprimir un mensaje de confirmación
    printf("Se retiraron %.2lf pesos de la cuenta de %d. Nuevo saldo: %.2lf\n", monto, cuenta->numeroCuenta, cuenta->saldo);
}

// Función para consultar el saldo de una cuenta
void consultarSaldo(CuentaPtr cuenta) {
    printf("Saldo disponible en la cuenta: %.2lf\n", getSaldo(cuenta));
}

// Función para consultar los movimientos realizados en una cuenta

void mostrarInformes(InformeOperacionPtr pila) {

    printf("Operaciones realizadas:\n");

    // Creamos una pila auxiliar para invertir el orden de los informes
    InformeOperacionPtr pilaAuxiliar = crearPila();

    // Desapilamos los elementos de la pila original y los apilamos en la auxiliar
    while (!pilaVacia(pila)) {
        InformeOperacion* informe = (InformeOperacion*)desapilar(pila);
        apilar(pilaAuxiliar, informe);
    }

    // Iteramos sobre la pila auxiliar para mostrar los informes
    while (!pilaVacia(pilaAuxiliar)) {
        InformeOperacion* informe = (InformeOperacion*)desapilar(pilaAuxiliar);
        // Suponiendo que InformeOperacion tiene campos nombreCliente, monto, etc.
        printf("Cliente: %1d\n", getDniCliente(getCliente(informe)));
        printf("Cajero: %s\n", getNombreCajero(getCajero(informe)));
        printf("Monto: %.2f\n", getSaldoOperacion(informe));
        // Aquí muestra otros campos del informe según sea necesario
    }

    // Destruimos la pila auxiliar
    destruirPila(pilaAuxiliar);
}

void menuImpuestos(CuentaPtr cuenta,  CajeroPtr cajero, InformeOperacionPtr pilaTransacciones){
    int montoImpuesto=1000;
    int opcion;

    printf("1. Si\n");
    printf("2. No\n");

    printf("Desea pagar los impuestos por un valor de %d",montoImpuesto);
    scanf("%d",&opcion);

    switch(opcion){
    case 1:
        //Informe del cajero
        crearImpuestos(cuenta,cajero,pilaTransacciones,montoImpuesto);
        break;
    case 2:
        break;
    }
}

void crearImpuestos(CuentaPtr cuenta,  CajeroPtr cajero, InformeOperacionPtr pilaTransacciones, int montoImpuesto){
// Verificar si el saldo es suficiente para el retiro
    if (montoImpuesto > cuenta->saldo) {
        printf("Saldo insuficiente para realizar el retiro.\n");
        return;
    }

    // Realizar el retiro y actualizar el saldo disponible
    cuenta->saldo -= montoImpuesto;

    // Registra la operación en la pila de transacciones
    InformeOperacionPtr informe = crearInformeOperacion(cuenta,cajero,-montoImpuesto);

    apilar(pilaTransacciones, informe);

    // Imprimir un mensaje de confirmación
    printf("Se retiraron %.2lf pesos de la cuenta de %d. Nuevo saldo: %.2lf\n", montoImpuesto, cuenta->numeroCuenta, cuenta->saldo);
}
