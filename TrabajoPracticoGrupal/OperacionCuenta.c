#include "OperacionCuenta.h"
#include <stdlib.h>

OperacionCuenta* crearOperacionCuenta(time_t fechaHoraOperacion, double montoCheques, double montoEfectivo, Cuenta cuentaAfectada) {
    OperacionCuenta *operacion = (OperacionCuenta*)obtenerMemoria(sizeof(OperacionCuenta), "Error al crear una nueva operación en cuenta");
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

// Getter para la fecha y hora de la operación
time_t getFechaHoraOperacion(OperacionCuentaPtr operacion) {
    return operacion->fechaHoraOperacion;
}

// Getter para el monto de cheques de la operación
double getMontoCheques(OperacionCuentaPtr operacion) {
    return operacion->montoCheques;
}

// Getter para el monto en efectivo de la operación
double getMontoEfectivo(OperacionCuentaPtr operacion) {
    return operacion->montoEfectivo;
}

// Getter para la cuenta afectada por la operación
Cuenta getCuentaAfectada(OperacionCuentaPtr operacion) {
    return operacion->cuentaAfectada;
}

// Setter para la fecha y hora de la operación
void setFechaHoraOperacion(OperacionCuentaPtr operacion, time_t fechaHoraOperacion) {
    operacion->fechaHoraOperacion = fechaHoraOperacion;
}

// Setter para el monto de cheques de la operación
void setMontoCheques(OperacionCuentaPtr operacion, double montoCheques) {
    operacion->montoCheques = montoCheques;
}

// Setter para el monto en efectivo de la operación
void setMontoEfectivo(OperacionCuentaPtr operacion, double montoEfectivo) {
    operacion->montoEfectivo = montoEfectivo;
}

// Setter para la cuenta afectada por la operación
void setCuentaAfectada(OperacionCuentaPtr operacion, Cuenta cuenta) {
    operacion->cuentaAfectada = cuenta;
}
