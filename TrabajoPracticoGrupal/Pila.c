#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "Util.h"
const void* FinPila=NULL;
PtrPila crearPila()
{
    PtrPila pila=(PtrPila)obtenerMemoria(sizeof(Pila),"no se pudo obtener la memoria");
    pila->primero=FinPila;
    return pila;
}
PtrPila destruirPila(PtrPila pila)
{
// desapilamos cada uno de los nodos y para eliminamos. Si haba    datos a eliminar,
// eso es responsabilidad del usuario
          while(!pilaVacia(pila))
    {
        desapilar(pila);
    }
    free(pila);
    return NULL;
}
bool pilaVacia(PtrPila pila)
{
    return (pila->primero==FinPila);
}
int longitudPila(PtrPila pila)
{
// la longitud es cuantos nodos hay en la pila. Para saberlo, hay    que recorrerla
    int longitud=0;
    PtrNodo nodo=pila->primero;
    while(nodo!=FinPila)
    {
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}
// Otra versión, recursiva
int longitudPilaRecur(PtrPila pila)
{
    int longitud=longitudPilaAyudante(pila->primero,0);
    return longitud;
}
int longitudPilaAyudante(PtrNodo nodo, int longitud)
{
// la longitud es cuantos nodos hay en la pila. Para saberlo, hay    que recorrerla
    if(nodo==FinPila)
    {
        return longitud;
    }
    else
    {
        longitudPilaAyudante(getSiguiente(nodo), longitud++);
    }
}
void apilar(PtrPila pila, PtrDato dato)
{
// creamos un nodo, le asignamos el dato y lo ponemos al frente de    la pila
    if(pila!=NULL)
    {
        PtrNodo nodo=crearNodo(dato);
        setDato(nodo,dato);
        setSiguiente(nodo,pila->primero);
        pila->primero=nodo;
    }
}
PtrDato desapilar(PtrPila pila)
{
    PtrDato dato=NULL;
    if(!pilaVacia(pila))
    {
        PtrNodo nodo=pila->primero;
        pila->primero=getSiguiente(nodo);
        dato=getDato(nodo);
        nodo=destruirNodo(nodo);
    }
    return dato;
}
PtrDato primeroPila(PtrPila pila)
{
// devuelve el dato de la primera posición de la pila
// pero sin desapilarlo
    PtrDato dato=NULL;
    if(!pilaVacia(pila))
    {
        PtrNodo nodo=pila->primero;
        dato=getDato(nodo);
    }
    return dato;
}

