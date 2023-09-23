#include "caja.h"
#include <stdlib.h>

Caja* crearCaja(int numeroCaja, double montoInicial) {
    Caja *caja = (Caja*)obtenerMemoria(sizeof(Caja), "Error al crear una nueva caja");
    caja->numeroCaja = numeroCaja;
    caja->montoInicial = montoInicial;
    // Inicializar otros campos si es necesario
    return caja;
}

CajaPtr destruirCaja(CajaPtr caja) {
    free(caja);
}

int getNumeroCaja(CajaPtr caja) {
    return caja->numeroCaja;
}

// Getter para el monto inicial
double getMontoInicial(CajaPtr caja) {
    return caja->montoInicial;
}

// Setter para el número de caja
void setNumeroCaja(CajaPtr caja, int numeroCaja) {
    caja->numeroCaja = numeroCaja;
}

// Setter para el monto inicial
void setMontoInicial(CajaPtr caja, double montoInicial) {
    caja->montoInicial = montoInicial;
}
