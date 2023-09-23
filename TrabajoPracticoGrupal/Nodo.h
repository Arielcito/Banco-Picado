#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef void* PtrDato;
/* Tipo de Estructura de los Nodos de la Lista. */
typedef struct Nodo
{
    PtrDato dato; // dato almacenado
    struct Nodo *sgte; // puntero al siguiente
} Nodo;
// puntero a nodo
typedef Nodo* PtrNodo;
// Terminador de nodo. En Nodo.c se asigna NULL
const void* SinNodoSgte;
// Operación de construccion (constructor)
// Precondicion: El nodo no debe haberse creado
// Postcondición: Se crea el nodo con null en PtrDato y SinNodoSgte ensgte
// Parámetros:
// dato: Puntero al dato a almacenar
// Devuelve puntero al nodo creado
PtrNodo crearNodo(PtrDato dato);
// Operación de destruccion (destructor)
// Precondicion: El nodo debe haberse creado
// Postcondición: Se Libera la memoria del nodo eliminado
// Parámetros:
// puntero al nodo a eliminar
// Devuelve NULL
PtrNodo destruirNodo(PtrNodo nodo);
// Operación de establecimiento de datos
// Precondicion: nodo creado con crearNodo()
// Postcondición: almacena el puntero al dato proporcionado en dato
// en el nodo apuntado por ptrNodo.
// Parámetros:
// ptrNodo: puntero al nodo
// PtrDato: Puntero al dato a almacenar
// No devuelve valor
void setDato(PtrNodo nodo, PtrDato dato);
// Operación de obtención de datos
// Precondicion: nodo creado con crearNodo()
// Postcondición: obtiene el dato almacenado en el nodo apuntado porptrNodo.
// Parámetros:
// ptrNodo: puntero al nodo
// Devuelve puntero al dato almacenado
PtrDato getDato(PtrNodo nodo);
// Operación de establecimiento del siguiente nodo
// Precondicion: esteNodo creado con crearNodo()
// Postcondición: se establece el nodo siguiente al actual
// Parámetros:
// esteNodo: puntero al nodo
// No devuelve valor
void setSiguiente(PtrNodo esteNodo, PtrNodo siguienteNodo);
// Operación de obtención del siguiente nodo
// Precondicion: esteNodo creado con crearNodo()
// Postcondición: se obtiene el nodo siguiente al actual
// Parámetros:
// nodo: puntero al nodo
// No devuelve valor
PtrNodo getSiguiente(PtrNodo nodo);
#endif // NODO_H_INCLUDED

