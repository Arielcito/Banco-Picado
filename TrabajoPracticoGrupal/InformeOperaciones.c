#include "InformeOperaciones.h"
#include "Cliente.h"
#include "Cajero.h"
#include "cliente.h"
// Funci�n para crear un nuevo informe de operaci�n
InformeOperacionPtr crearInformeOperacion(CuentaPtr titular,CajeroPtr cajero,double monto,char *tipoOperacion)
{
    // Asignar los valores a los miembros del informe de operaci�n
    InformeOperacionPtr informeOperacion = malloc(sizeof(InformeOperacion));
    informeOperacion->cliente = titular;
    informeOperacion->cajero = cajero;
    informeOperacion->monto = monto;
    strncpy(informeOperacion->tipoOperacion, tipoOperacion, sizeof(informeOperacion->tipoOperacion));
    // Devolver el informe de operaci�n
    return informeOperacion;
}

// Funci�n para destruir un informe de operaci�n
InformeOperacionPtr destruirInformeOperacion(InformeOperacionPtr cuenta)
{
    // Liberar la memoria del informe de operaci�n
    free(cuenta);

    // Devolver NULL
    return cuenta;
}

// Funci�n para obtener el cliente del informe de operaci�n
CuentaPtr getCliente(InformeOperacionPtr cuenta)
{
    // Devolver el cliente del informe de operaci�n
    return cuenta->cliente;
}

// Funci�n para obtener el cajero del informe de operaci�n
CajeroPtr getCajeroInforme(InformeOperacionPtr cuenta)
{
    // Devolver el cajero del informe de operaci�n
    return cuenta->cajero;
}

// Funci�n para obtener el saldo del informe de operaci�n
double getSaldoOperacion(InformeOperacionPtr cuenta)
{
    // Devolver el saldo del informe de operaci�n
    return cuenta->monto;
}

char getTipoOperacionInforme(InformeOperacionPtr cuenta){
    return cuenta->tipoOperacion;
}
