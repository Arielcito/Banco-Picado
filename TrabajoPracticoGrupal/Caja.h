#ifndef CAJA_H
#define CAJA_H

#include "turno.h"
#include "cajero.h"

typedef struct
{
    int numeroCaja;
    double montoInicial;
    CajeroPtr cajero;
} Caja;

typedef Caja* CajaPtr;

// Liberar la memoria asociada con la caja
CajaPtr destruirCaja(CajaPtr caja);

CajaPtr crearCaja(int numeroCaja, double montoInicial);

// Getters & Setters
int getNumeroCaja(CajaPtr caja);
double getMontoInicial(CajaPtr caja);
CajeroPtr getCajero(CajaPtr caja);

void setNumeroCaja(CajaPtr caja, int numeroCaja);
void setMontoInicial(CajaPtr caja, double montoInicial);
void setCajero(CajaPtr caja, CajeroPtr cajero);

#endif // CAJA_H
