#include "InformeOperaciones.h"
#include "Cliente.h"
#include "Cajero.h"
#include "cliente.h"
// Función para crear un nuevo informe de operación
InformeOperacionPtr crearInformeOperacion(CuentaPtr titular,CajeroPtr cajero,double monto,char *tipoOperacion)
{
    // Asignar los valores a los miembros del informe de operación
    InformeOperacionPtr informeOperacion = malloc(sizeof(InformeOperacion));
    informeOperacion->cliente = titular;
    informeOperacion->cajero = cajero;
    informeOperacion->monto = monto;
    strncpy(informeOperacion->tipoOperacion, tipoOperacion, sizeof(informeOperacion->tipoOperacion));
    // Devolver el informe de operación
    return informeOperacion;
}

// Función para destruir un informe de operación
InformeOperacionPtr destruirInformeOperacion(InformeOperacionPtr cuenta)
{
    // Liberar la memoria del informe de operación
    free(cuenta);

    // Devolver NULL
    return cuenta;
}

// Función para obtener el cliente del informe de operación
CuentaPtr getCliente(InformeOperacionPtr cuenta)
{
    // Devolver el cliente del informe de operación
    return cuenta->cliente;
}

// Función para obtener el cajero del informe de operación
CajeroPtr getCajeroInforme(InformeOperacionPtr cuenta)
{
    // Devolver el cajero del informe de operación
    return cuenta->cajero;
}

// Función para obtener el saldo del informe de operación
double getSaldoOperacion(InformeOperacionPtr cuenta)
{
    // Devolver el saldo del informe de operación
    return cuenta->monto;
}

char getTipoOperacionInforme(InformeOperacionPtr cuenta){
    return cuenta->tipoOperacion;
}
