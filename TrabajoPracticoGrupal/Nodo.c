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
// Operaci�n de destruccion (desstructor)
// Precondicion: El nodo debe haberse creado
// Postcondici�n: Se Libera la memoria del nodo eliminado
// Par�metros:
// puntero al nodo a eliminar
// Devuelve NULL
PtrNodo destruirNodo(PtrNodo nodo)
{
// la destrucci�n del dato queda por cuenta del usuario
    free(nodo);
    return SinNodoSgte;
}
// Operaci�n de establecimiento de datos
// Precondicion: nodo creado con crearNodo()
// Postcondici�n: almacena el dato proporcionado en el nodo apuntado porptrNodo.
// Par�metros:
// ptrNodo: puntero al nodo
// PtrDato: Puntero al dato a almacenar
// No devuelve valor
void setDato(PtrNodo nodo, PtrDato dato)
{
    nodo->dato=dato;
}
// Operaci�n de obtenci�n de datos
// Precondicion: nodo creado con crearNodo()
// Postcondici�n: obtiene el dato almacenado en el nodo apuntado porptrNodo.
// Par�metros:
// ptrNodo: puntero al nodo
// Devuelve puntero al dato almacenado
PtrDato getDato(PtrNodo nodo)
{
    return nodo->dato;
}
// Operaci�n de establecimiento del siguiente nodo
// Precondicion: esteNodo creado con crearNodo()
// Postcondici�n: se establece el nodo siguiente al actual
// Par�metros:
// esteNodo: puntero al nodo
// No devuelve valor
void setSiguiente(PtrNodo esteNodo, PtrNodo siguienteNodo)
{
    esteNodo->sgte=siguienteNodo;
}
// Operaci�n de obtenci�n del siguiente nodo
// Precondicion: esteNodo creado con crearNodo()
// Postcondici�n: se obtiene el nodo siguiente al actual
// Par�metros:
// nodo: puntero al nodo
// No devuelve valor
PtrNodo getSiguiente(PtrNodo nodo)
{
    return nodo->sgte;
}
