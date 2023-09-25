#ifndef ABMOPERACIONESIMPUESTO_H
#define ABMOPERACIONESIMPUESTO_H

#include "OperacionImpuestos.h"

// Declaración de funciones para el ABM de operaciones de impuestos
void altaOperacionImpuestos(OperacionImpuestosPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion, const char *impuesto, double monto);
void bajaOperacionImpuestos(OperacionImpuestosPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion);
void modificarOperacionImpuestos(OperacionImpuestosPtr operaciones[], int numOperaciones, time_t fechaHoraOperacion, const char *impuesto, double monto);
void mostrarOperacionesImpuestos(OperacionImpuestosPtr operaciones[], int numOperaciones);

#endif // ABMOPERACIONESIMPUESTO_H