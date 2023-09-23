#include "cheque.h"
#include <stdlib.h>
#include <string.h>

Cheque* crearCheque(const char *banco, long numeroCheque, double monto) {
    Cheque *cheque = (Cheque*)obtenerMemoria(sizeof(Cheque), "Error al crear un nuevo cheque");
    strncpy(cheque->banco, banco, sizeof(cheque->banco));
    cheque->numeroCheque = numeroCheque;
    cheque->monto = monto;
    // Inicializar otros campos si es necesario
    return cheque;
}

ChequePtr destruirCheque(ChequePtr cheque) {
    free(cheque);
    return cheque;
}

// Getter para el nombre del banco en el cheque
char* getNombreBanco(ChequePtr cheque) {
    return cheque->banco;
}

// Getter para el número de cheque
long getNumeroCheque(ChequePtr cheque) {
    return cheque->numeroCheque;
}

// Getter para el monto del cheque
double getMonto(ChequePtr cheque) {
    return cheque->monto;
}

// Setter para el nombre del banco en el cheque
void setNombreBanco(ChequePtr cheque, char *banco) {
    strncpy(cheque->banco, banco, sizeof(cheque->banco));
}

// Setter para el número de cheque
void setNumeroCheque(ChequePtr cheque, long numeroCheque) {
    cheque->numeroCheque = numeroCheque;
}

// Setter para el monto del cheque
void setMonto(ChequePtr cheque, double monto) {
    cheque->monto = monto;
}
