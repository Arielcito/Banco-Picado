#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Util.h"
const void* SinNodoSgte=NULL;
PtrNodo crearNodo(PtrDato dato)
{
    PtrNodo nodo=(PtrNodo)obtenerMemoria(sizeof(Nodo),"no se pudo obtener la memoria");
    nodo->dato=dato;
    nodo->sgte=SinNodoSgte;
    return nodo;
}
// Operación de destruccion (desstructor)
// Precondicion: El nodo debe haberse creado
// Postcondición: Se Libera la memoria del nodo eliminado
// Parámetros:
// puntero al nodo a eliminar
// Devuelve NULL
PtrNodo destruirNodo(PtrNodo nodo)
{
// la destrucción del dato queda por cuenta del usuario
    free(nodo);
    return SinNodoSgte;
}
// Operación de establecimiento de datos
// Precondicion: nodo creado con crearNodo()
// Postcondición: almacena el dato proporcionado en el nodo apuntado porptrNodo.
// Parámetros:
// ptrNodo: puntero al nodo
// PtrDato: Puntero al dato a almacenar
// No devuelve valor
void setDato(PtrNodo nodo, PtrDato dato)
{
    nodo->dato=dato;
}
// Operación de obtención de datos
// Precondicion: nodo creado con crearNodo()
// Postcondición: obtiene el dato almacenado en el nodo apuntado porptrNodo.
// Parámetros:
// ptrNodo: puntero al nodo
// Devuelve puntero al dato almacenado
PtrDato getDato(PtrNodo nodo)
{
    return nodo->dato;
}
// Operación de establecimiento del siguiente nodo
// Precondicion: esteNodo creado con crearNodo()
// Postcondición: se establece el nodo siguiente al actual
// Parámetros:
// esteNodo: puntero al nodo
// No devuelve valor
void setSiguiente(PtrNodo esteNodo, PtrNodo siguienteNodo)
{
    esteNodo->sgte=siguienteNodo;
}
// Operación de obtención del siguiente nodo
// Precondicion: esteNodo creado con crearNodo()
// Postcondición: se obtiene el nodo siguiente al actual
// Parámetros:
// nodo: puntero al nodo
// No devuelve valor
PtrNodo getSiguiente(PtrNodo nodo)
{
    return nodo->sgte;
}
