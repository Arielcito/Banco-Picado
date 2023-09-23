#include <stdbool.h>
#include "Cola.h"
#include "Util.h"
const void* FinCola=NULL;
PtrCola crearCola()
{
    PtrCola cola=(PtrCola)obtenerMemoria(sizeof(Cola),"no se pudo obtener la memoria");
    cola->primero=FinCola;
    cola->ultimo=FinCola;
    return cola;
}
PtrCola destruirCola(PtrCola cola)
{
// desencolamos cada uno de los nodos y los eliminamos. Si había
// datos a eliminar, eso es responsabilidad del usuario
    while(!colaVacia(cola))
    {
        desencolar(cola);
    }
    free(cola);
    return NULL;
}
bool colaVacia(PtrCola cola)
{
    return (cola->primero==FinCola);
}
int longitudCola(PtrCola cola)
{
// la longitud es cuantos nodos hay en la pila. Para saberlo, hay    que recorrerla
    int longitud=0;
    PtrNodo nodo=cola->primero;
    while(nodo!=FinCola)
    {
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}
void encolar(PtrCola cola, PtrDato dato)
{
    if(cola!=NULL)
    {
        PtrNodo nodo=crearNodo(dato);
        setDato(nodo,dato);
        if(colaVacia(cola))
        {
            cola->primero=nodo;
            cola->ultimo=nodo;
        }
        else
        {
            setSiguiente(cola->ultimo,nodo);
            cola->ultimo=nodo;
        }
    }
}
PtrDato desencolar(PtrCola cola)
{
    PtrDato dato=NULL;
    if(!colaVacia(cola))
    {
        PtrNodo nodo=cola->primero;
        cola->primero=getSiguiente(nodo);
        dato=getDato(nodo);
        if(cola->primero==FinCola)
        {
            cola->ultimo=FinCola;
        }
        nodo=destruirNodo(nodo);
    }
    return dato;
}
PtrDato primeroCola(PtrCola cola)
{
// devuelve el dato de la primera posición de la cola
// pero sin desencolarlo
    PtrDato dato=NULL;
    if(!colaVacia(cola))
    {
        PtrNodo nodo=cola->primero;
        dato=getDato(nodo);
    }
    return dato;
}

