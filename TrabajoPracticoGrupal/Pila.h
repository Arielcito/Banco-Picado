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
// Operación de construccion (constructor)
// Precondicion: la pila no debe haber sido creada.
// Postcondición: píla queda creada vacía y preparada para ser usada.
// Parámetros:
// Ninguno
// Devuelve puntero a la pila creada
PtrPila crearPila();
// Operación de destruccion (destructor)
// Precondicion: la pila debe haber sido creada.
// Postcondición: la pila queda vacía y la memoria que ocupaba se libera
// Parámetros:
// Ninguna
// Devuelve NULL
PtrPila destruirPila(PtrPila pila);
// Operación de verificación de estado
// Precondicion: la pila debe haber sido creada.
// Postcondición: ninguna
// Parámetros:
// pila: Puntero a la pila que se desea saber si se encuentra vacía
// Devuelve true si la pila se encuentra vacía (primero=FinPila), false deotro modo
bool pilaVacia(PtrPila pila);
// Operación de obtención de la longitud de la pila
// Precondicion: la pila debe haber sido creada.
// Postcondición: Se obtiene la longitud de la pila (si vacía =0)
// Parámetros:
// pila: puntero a la pila
// Devuelve longitud de la pila
int longitudPila(PtrPila pila);
// Operación de agregado a pila
// Precondicion: la pila debe haber sido creada.
// Postcondición: Se inserta el dato antes de la primra posición
// Parámetros:
// pila: puntero a la pila
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insertó el dato
void apilar(PtrPila pila, PtrDato dato);
// Operación de agregado antes de la cabecera
// Precondicion: la pila debe haber sido creada.
// Postcondición: Se inserta el dato antes de la cabecera de la pila
// Parámetros:
// pila: puntero a la pila
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insertó el dato
PtrDato desapilar(PtrPila pila);
// Operación de agregado al final de la pila
// Precondicion: la pila debe haber sido creada.
// Postcondición: Se agrega el dato luego del ultimo nodo
// Parámetros:
// pila: puntero a la pila
// dato: puntero al dato a insertar
// Devuelve puntero al nodo en que se insertó el dato
PtrDato primeroPila(PtrPila pila);
#endif // PILA_H_INCLUDED
