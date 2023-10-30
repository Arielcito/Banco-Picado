#ifndef INFORMEOPERACIONES_H
#define INFORMEOPERACIONES_H
#include "cuenta.h"
#include "cajero.h"
typedef struct {
    CuentaPtr cliente; // Nombre del cliente
    CajeroPtr cajero; // Nombre del cajero
    double monto; // Monto de la operación (positivo para depósitos, negativo para retiros)
} InformeOperacion;

typedef InformeOperacion* InformeOperacionPtr;

InformeOperacionPtr destruirInformeOperacion(InformeOperacionPtr cuenta);

InformeOperacionPtr crearInformeOperacion(CuentaPtr titular,CajeroPtr cajero,double monto);
// Getters & Setters
CuentaPtr getCliente(InformeOperacionPtr cuenta);
CajeroPtr getCajeroInforme(InformeOperacionPtr cuenta);
double getSaldoOperacion(InformeOperacionPtr cuenta);

#endif // INFORMEOPERACIONES_H
