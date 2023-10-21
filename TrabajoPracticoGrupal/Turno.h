#ifndef TURNO_H
#define TURNO_H

#include "Cuenta.h"
typedef struct
{
    char tipoOperacion[50]; // 'C' para operaciones en cuenta, 'I' para pago de impuestos
    CuentaPtr cuenta;
    int numeroCorrelativo;
} Turno;

typedef Turno* TurnoPtr;

// Liberar la memoria asociada con el turno
TurnoPtr destruirTurno(TurnoPtr turno);

TurnoPtr crearTurno(const char *tipoOperacion, int numeroCorrelativo,CuentaPtr cuenta);
// Getters & Setters
char* getTipoOperacion(TurnoPtr turno);
int getNumeroCorrelativo(TurnoPtr turno);
CuentaPtr getCuentaAAtender(TurnoPtr turno);

void setTipoOperacion(TurnoPtr turno, char* tipoOperacion);
void setNumeroCorrelativo(TurnoPtr turno, int numeroCorrelativo);

#endif // TURNO_H
