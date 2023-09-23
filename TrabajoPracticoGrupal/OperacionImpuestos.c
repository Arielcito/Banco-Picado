#include "OperacionImpuestos.h"
#include <stdlib.h>
#include <string.h>

OperacionImpuestos* crearOperacionImpuestos(time_t fechaHoraOperacion, const char *impuesto, double monto) {
    OperacionImpuestos *operacion = (OperacionImpuestos*)obtenerMemoria(sizeof(OperacionImpuestos), "Error al crear una nueva operaci�n de impuestos");
    operacion->fechaHoraOperacion = fechaHoraOperacion;
    strncpy(operacion->impuesto, impuesto, sizeof(operacion->impuesto));
    operacion->monto = monto;
    // Inicializar otros campos si es necesario
    return operacion;
}

OperacionImpuestosPtr destruirOperacionImpuestos(OperacionImpuestosPtr operacion) {
    free(operacion);
    return operacion;
}

// Getter para la fecha y hora de la operaci�n de impuestos
time_t getFechaHoraOperacionImpuestos(OperacionImpuestosPtr operacion) {
    return operacion->fechaHoraOperacion;
}

// Getter para el tipo de impuesto de la operaci�n
const char* getImpuesto(OperacionImpuestosPtr operacion) {
    return operacion->impuesto;
}

// Getter para el monto de impuestos de la operaci�n
double getMontoImpuestos(OperacionImpuestosPtr operacion) {
    return operacion->monto;
}

// Setter para la fecha y hora de la operaci�n de impuestos
void setFechaHoraOperacionImpuestos(OperacionImpuestosPtr operacion, time_t fechaHoraOperacion) {
    operacion->fechaHoraOperacion = fechaHoraOperacion;
}

// Setter para el tipo de impuesto de la operaci�n
void setImpuesto(OperacionImpuestosPtr operacion, char *impuesto) {
    free(operacion->impuesto);
    strcpy(operacion->impuesto, impuesto);
}

// Setter para el monto de impuestos de la operaci�n
void setMontoImpuestos(OperacionImpuestosPtr operacion, double monto) {
    operacion->monto = monto;
}
