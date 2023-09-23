#ifndef TURNO_H
#define TURNO_H

typedef struct
{
    char tipoOperacion; // 'C' para operaciones en cuenta, 'I' para pago de impuestos
    int numeroCorrelativo;
} Turno;

typedef Turno* TurnoPtr;

// Liberar la memoria asociada con el turno
TurnoPtr destruirTurno(TurnoPtr turno);

TurnoPtr crearTurno(char tipoOperacion, int numeroCorrelativo);
// Getters & Setters
char getTipoOperacion(TurnoPtr turno);
int getNumeroCorrelativo(TurnoPtr turno);

void setTipoOperacion(TurnoPtr turno, char tipoOperacion);
void setNumeroCorrelativo(TurnoPtr turno, int numeroCorrelativo);

#endif // TURNO_H
