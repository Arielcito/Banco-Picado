#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Nodo.h"
typedef struct Pila
{
    PtrNodo primero; // puntero al primer nodo de la pila
} Pila;
typedef Pila* PtrPila;
// Terminador de pila. En Pila.c se define como NULL;
const void* FinPila;
/*************************************************************************
*****/
/* Definicion de Primitivas */
/*--------------------------*/
// Operaci�n de construccion (constructor)
// Precondicion: la pila no debe haber sido creada.
// Postcondici�n: p�la queda creada vac�a y preparada para ser usada.
// Par�metros:
// Ninguno
// Devuelve puntero a la pila creada
PtrPila crearPila();
// Operaci�n de destruccion (destructor)
// Precondicion: la pila debe haber sido creada.
// Postcondici�n: la pila queda vac�a y la memoria que ocupaba se libera
// Par�metros:
// Ninguna
// Devuelve NULL
PtrPila destruirPila(PtrPila pila);
// Operaci�n de verificaci�n de estado
// Precondicion: la pila debe haber sido creada.
// Postcondici�n: ninguna
// Par�metros:
// pila: Puntero a la pila que se desea saber si se encuentra vac�a
// Devuelve true si la pila se encuentra vac�a (primero=FinPila), false deotro modo
bool pilaVacia(PtrPila pila);
// Operaci�n de obtenci�n de la longitud de la pila
// Precondicion: la pila debe haber sido creada.
// Postcondici�n: Se obtiene la longitud de la pila (si vac�a =0)
// Par�metros:
// pila: puntero a la pila
// Devuelve longitud de la pila
int longitudPila(PtrPila pila);
// Operaci�n de agregado a pila
// Precondicion: la pila debe haber sido creada.
// Postcondici�n: Se inserta el dato antes de la primra posici�n
// Par�metros:
// pila: puntero a la pila
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insert� el dato
void apilar(PtrPila pila, PtrDato dato);
// Operaci�n de agregado antes de la cabecera
// Precondicion: la pila debe haber sido creada.
// Postcondici�n: Se inserta el dato antes de la cabecera de la pila
// Par�metros:
// pila: puntero a la pila
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insert� el dato
PtrDato desapilar(PtrPila pila);
// Operaci�n de agregado al final de la pila
// Precondicion: la pila debe haber sido creada.
// Postcondici�n: Se agrega el dato luego del ultimo nodo
// Par�metros:
// pila: puntero a la pila
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insert� el dato
PtrDato primeroPila(PtrPila pila);
#endif // PILA_H_INCLUDED
