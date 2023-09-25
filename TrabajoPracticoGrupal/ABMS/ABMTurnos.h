#ifndef ABMTURNOS_H
#define ABMTURNOS_H

#include "turno.h"

// Declaración de funciones para el ABM de turnos
void altaTurno(TurnoPtr turnos[], int *numTurnos, char tipoOperacion);
void bajaTurno(TurnoPtr turnos[], int *numTurnos, int numeroCorrelativo);
void modificarTurno(TurnoPtr turnos[], int numTurnos, int numeroCorrelativo, char tipoOperacion);
void mostrarTurnos(TurnoPtr turnos[], int numTurnos);

#endif // ABMTURNOS_H