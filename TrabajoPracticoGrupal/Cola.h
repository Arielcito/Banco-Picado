#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Nodo.h"
typedef struct Cola
{
    PtrNodo primero; // puntero al primer nodo de la cola
    PtrNodo ultimo; // puntero al ultimo nodo de la cola
} Cola;
typedef Cola* PtrCola;
// Terminador de Cola. En Cola.c se define como NULL;
const void* FinCola;
/*************************************************************************
*****/
/* Definicion de Primitivas */
/*--------------------------*/
// Operaci�n de construccion (constructor)
// Precondicion: la cola no debe haber sido creada.
// Postcondici�n: cola queda creada vac�a y preparada para ser usada.
// Par�metros:
// Ninguno
// Devuelve puntero a la cola creada
PtrCola crearCola();
// Operaci�n de destruccion (destructor)
// Precondicion: la cola debe haber sido creada.
// Postcondici�n: la cola queda vac�a y la memoria que ocupaba se libera
// Par�metros:
// Ninguna
// Devuelve NULL
PtrCola destruirCola(PtrCola cola);
// Operaci�n de verificaci�n de estado
// Precondicion: la cola debe haber sido creada.
// Postcondici�n: ninguna
// Par�metros:
// cola: Puntero a la cola que se desea saber si se encuentra vac�a
// Devuelve true si la cola se encuentra vac�a (primero=FinCola), false deotro modo
bool colaVacia(PtrCola cola);
// Operaci�n de obtenci�n de la longitud de la cola
// Precondicion: la cola debe haber sido creada.
// Postcondici�n: Se obtiene la longitud de la cola (si vac�a =0)
// Par�metros:
// cola: puntero a la cola
// Devuelve longitud de la cola
int longitudCola(PtrCola cola);
// Operaci�n de agregado a cola
// Precondicion: la cola debe haber sido creada.
// Postcondici�n: Se inserta el dato luego de la �ltima posici�n
// Par�metros:
// cola: puntero a la cola
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insert� el dato
void encolar(PtrCola cola, PtrDato dato);
// Operaci�n de agregado antes de la cabecera
// Precondicion: la cola debe haber sido creada.
// Postcondici�n: Se inserta el dato antes de la cabecera de la cola
// Par�metros:
// cola: puntero a la cola
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insert� el dato
PtrDato desencolar(PtrCola cola);
// Operaci�n de obtenci�n del primero de la cola
// Precondicion: la cola debe haber sido creada.
// Postcondici�n: Se obtiene el dato del primer nodo sin desenconlarlo
// Par�metros:
// cola: puntero a la cola
// Devuelve puntero al dato de la primera posici�n
PtrDato primeroCola(PtrCola cola);
#endif // COLA_H_INCLUDED
