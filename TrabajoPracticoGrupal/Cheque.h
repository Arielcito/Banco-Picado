#ifndef CHEQUE_H
#define CHEQUE_H

typedef struct
{
    char banco[50];      // Nombre del banco emisor
    long numeroCheque;   // Número de cheque de 10 cifras
    double monto;        // Monto del cheque
} Cheque;

typedef Cheque* ChequePtr;

// Liberar la memoria asociada con el cheque
ChequePtr destruirCheque(ChequePtr cheque);

Cheque* crearCheque(const char *banco, long numeroCheque, double monto);
// Getters & Setters
char* getNombreBanco(ChequePtr cheque);
long getNumeroCheque(ChequePtr cheque);
double getMonto(ChequePtr cheque);
void setNombreBanco(ChequePtr cheque, char *banco);
void setNumeroCheque(ChequePtr cheque, long numeroCheque);
void setMonto(ChequePtr cheque, double monto);

#endif // CHEQUE_H
