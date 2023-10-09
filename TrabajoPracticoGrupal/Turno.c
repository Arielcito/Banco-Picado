#include "turno.h"
#include <stdlib.h>

Turno* crearTurno(char tipoOperacion, int numeroCorrelativo, CuentaPtr cuenta) {
    Turno *turno = (Turno*)obtenerMemoria(sizeof(Turno), "Error al crear un nuevo turno");
    turno->tipoOperacion = tipoOperacion;
    turno->cuenta = cuenta;
    turno->numeroCorrelativo = numeroCorrelativo;
    // Inicializar otros campos si es necesario
    return turno;
}

TurnoPtr destruirTurno(TurnoPtr turno) {
    free(turno);
    return turno;
}

// Getter para el tipo de operación del turno
char getTipoOperacion(TurnoPtr turno) {
    return turno->tipoOperacion;
}

// Getter para el número correlativo del turno
int getNumeroCorrelativo(TurnoPtr turno) {
    return turno->numeroCorrelativo;
}

// Getter para el número correlativo del turno
CuentaPtr getCuentaAAtender(TurnoPtr turno) {
    return turno->cuenta;
}
// Setter para el tipo de operación del turno
void setTipoOperacion(TurnoPtr turno, char tipoOperacion) {
    turno->tipoOperacion = tipoOperacion;
}

// Setter para el número correlativo del turno
void setNumeroCorrelativo(TurnoPtr turno, int numeroCorrelativo) {
    turno->numeroCorrelativo = numeroCorrelativo;
}
