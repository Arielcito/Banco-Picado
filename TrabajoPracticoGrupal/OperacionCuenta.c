#include "OperacionCuenta.h"
#include <stdlib.h>

OperacionCuenta* crearOperacionCuenta(time_t fechaHoraOperacion, double montoCheques, double montoEfectivo, Cuenta cuentaAfectada) {
    OperacionCuenta *operacion = (OperacionCuenta*)obtenerMemoria(sizeof(OperacionCuenta), "Error al crear una nueva operaci�n en cuenta");
    operacion->fechaHoraOperacion = fechaHoraOperacion;
    operacion->montoCheques = montoCheques;
    operacion->montoEfectivo = montoEfectivo;
    operacion->cuentaAfectada = cuentaAfectada;
    // Inicializar otros campos si es necesario
    return operacion;
}

OperacionCuentaPtr destruirOperacionCuenta(OperacionCuentaPtr operacion) {
    free(operacion);
    return operacion;
}

// Getter para la fecha y hora de la operaci�n
time_t getFechaHoraOperacion(OperacionCuentaPtr operacion) {
    return operacion->fechaHoraOperacion;
}

// Getter para el monto de cheques de la operaci�n
double getMontoCheques(OperacionCuentaPtr operacion) {
    return operacion->montoCheques;
}

// Getter para el monto en efectivo de la operaci�n
double getMontoEfectivo(OperacionCuentaPtr operacion) {
    return operacion->montoEfectivo;
}

// Getter para la cuenta afectada por la operaci�n
Cuenta getCuentaAfectada(OperacionCuentaPtr operacion) {
    return operacion->cuentaAfectada;
}

// Setter para la fecha y hora de la operaci�n
void setFechaHoraOperacion(OperacionCuentaPtr operacion, time_t fechaHoraOperacion) {
    operacion->fechaHoraOperacion = fechaHoraOperacion;
}

// Setter para el monto de cheques de la operaci�n
void setMontoCheques(OperacionCuentaPtr operacion, double montoCheques) {
    operacion->montoCheques = montoCheques;
}

// Setter para el monto en efectivo de la operaci�n
void setMontoEfectivo(OperacionCuentaPtr operacion, double montoEfectivo) {
    operacion->montoEfectivo = montoEfectivo;
}

// Setter para la cuenta afectada por la operaci�n
void setCuentaAfectada(OperacionCuentaPtr operacion, Cuenta cuenta) {
    operacion->cuentaAfectada = cuenta;
}
