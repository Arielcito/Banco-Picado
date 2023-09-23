#ifndef CAJERO_H
#define CAJERO_H

typedef struct
{
    char apellido[50];
    char nombre[50];
    long cuil;
    int numeroLegajo;
} Cajero;

typedef Cajero* CajeroPtr;

// Liberar la memoria asociada con el cajero
CajeroPtr destruirCajero(CajeroPtr cajero);

Cajero* crearCajero(const char *apellido, const char *nombre, long cuil, int numeroLegajo);
// Getters & Setters
char* getApellidoCajero(CajeroPtr cajero);
char* getNombreCajero(CajeroPtr cajero);
long getCuilCajero(CajeroPtr cajero);
int getNumeroLegajoCajero(CajeroPtr cajero);

void setApellidoCajero(CajeroPtr cajero, const char *apellido);
void setNombreCajero(CajeroPtr cajero, const char *nombre);
void setCuilCajero(CajeroPtr cajero, long cuil);
void setNumeroLegajoCajero(CajeroPtr cajero, int numeroLegajo);

#endif // CAJERO_H
