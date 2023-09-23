#include <stdio.h>
#include "Lista.h"
#include "Cuenta.h"

typedef struct {
    int cliente; // Nombre del cliente
    char cajero[100]; // Nombre del cajero
    double monto; // Monto de la operación (positivo para depósitos, negativo para retiros)
} InformeOperacion;

PtrLista inicializarLista(){
    PtrLista lista=crearLista();
    return lista;
}

void ingresarDinero(CuentaPtr cuenta, double monto, const char* cajero, PtrLista listaTransacciones) {
    // Verificar que el monto a ingresar sea positivo
    if (monto <= 0) {
        printf("El monto a ingresar debe ser mayor que cero.\n");
        return;
    }

    // Actualizar el saldo disponible en la cuenta
    cuenta->saldo += monto;

    // Registra la operación en la lista de transacciones
    InformeOperacion informe;
    strcpy(informe.cliente, cuenta->numeroCuenta);
    strcpy(informe.cajero, cajero);
    informe.monto = monto;
    agregarDatoLista(listaTransacciones, &informe);

    // Imprimir un mensaje de confirmación
    printf("Se ingresaron %.2lf pesos a la cuenta de %s. Nuevo saldo: %.2lf\n", monto, cuenta->numeroCuenta, cuenta->saldo);
}

// Función para retirar dinero de una cuenta y registrar la operación
void retirarDinero(CuentaPtr cuenta, double monto, const char* cajero, PtrLista listaTransacciones) {
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

    // Registra la operación en la lista de transacciones
    InformeOperacion informe;
    strcpy(informe.cliente, cuenta->numeroCuenta);
    strcpy(informe.cajero, cajero);
    informe.monto = -monto; // Monto negativo para indicar retiro
    agregarDatoLista(listaTransacciones, &informe);

    // Imprimir un mensaje de confirmación
    printf("Se retiraron %.2lf pesos de la cuenta de %s. Nuevo saldo: %.2lf\n", monto, cuenta->numeroCuenta, cuenta->saldo);
}

void mostrarInformes(PtrLista lista) {
    printf("Informe de operaciones:\n");

    // Iteramos sobre la lista usando longitudLista para saber cuántos informes hay
    int longitud = longitudLista(lista);

    for (int i = 0; i < longitud; i++) {
        // Obtenemos el informe en la posición i de la lista
        InformeOperacion* informe = (InformeOperacion*)getDatoLista(lista, i);


        // Suponiendo que InformeOperacion tiene campos nombreCliente, monto, etc.
        printf("Cliente: %d\n", informe->cliente);
        printf("Cajero: %s\n", informe->cajero);
        printf("Monto: %.2f\n", informe->monto);
        // Aquí muestra otros campos del informe según sea necesario
    }
}
