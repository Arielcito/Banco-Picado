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
// Operación de construccion (constructor)
// Precondicion: la cola no debe haber sido creada.
// Postcondición: cola queda creada vacía y preparada para ser usada.
// Parámetros:
// Ninguno
// Devuelve puntero a la cola creada
PtrCola crearCola();
// Operación de destruccion (destructor)
// Precondicion: la cola debe haber sido creada.
// Postcondición: la cola queda vacía y la memoria que ocupaba se libera
// Parámetros:
// Ninguna
// Devuelve NULL
PtrCola destruirCola(PtrCola cola);
// Operación de verificación de estado
// Precondicion: la cola debe haber sido creada.
// Postcondición: ninguna
// Parámetros:
// cola: Puntero a la cola que se desea saber si se encuentra vacía
// Devuelve true si la cola se encuentra vacía (primero=FinCola), false deotro modo
bool colaVacia(PtrCola cola);
// Operación de obtención de la longitud de la cola
// Precondicion: la cola debe haber sido creada.
// Postcondición: Se obtiene la longitud de la cola (si vacía =0)
// Parámetros:
// cola: puntero a la cola
// Devuelve longitud de la cola
int longitudCola(PtrCola cola);
// Operación de agregado a cola
// Precondicion: la cola debe haber sido creada.
// Postcondición: Se inserta el dato luego de la última posición
// Parámetros:
// cola: puntero a la cola
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insertó el dato
void encolar(PtrCola cola, PtrDato dato);
// Operación de agregado antes de la cabecera
// Precondicion: la cola debe haber sido creada.
// Postcondición: Se inserta el dato antes de la cabecera de la cola
// Parámetros:
// cola: puntero a la cola
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insertó el dato
PtrDato desencolar(PtrCola cola);
// Operación de obtención del primero de la cola
// Precondicion: la cola debe haber sido creada.
// Postcondición: Se obtiene el dato del primer nodo sin desenconlarlo
// Parámetros:
// cola: puntero a la cola
// Devuelve puntero al dato de la primera posición
PtrDato primeroCola(PtrCola cola);
#endif // COLA_H_INCLUDED
