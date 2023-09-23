#ifndef OPERACION_IMPUESTOS_H
#define OPERACION_IMPUESTOS_H

#include <time.h>

typedef struct
{
    time_t fechaHoraOperacion;
    char impuesto[50];
    double monto;
} OperacionImpuestos;

typedef OperacionImpuestos* OperacionImpuestosPtr;

// Liberar la memoria asociada con la operación de impuestos
OperacionImpuestosPtr destruirOperacionImpuestos(OperacionImpuestosPtr operacionImpuestos);

// Getters & Setters
time_t getFechaHoraOperacionImpuestos(OperacionImpuestosPtr operacion);
const char* getImpuesto(OperacionImpuestosPtr operacion);
double getMontoImpuestos(OperacionImpuestosPtr operacion);

void setFechaHoraOperacionImpuestos(OperacionImpuestos *operacion, time_t fechaHora);
void setImpuesto(OperacionImpuestosPtr operacion, char *impuesto);
void setMontoImpuestos(OperacionImpuestos *operacion, double monto);

#endif // OPERACION_IMPUESTOS_H
