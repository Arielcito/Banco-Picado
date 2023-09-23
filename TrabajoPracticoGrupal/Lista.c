#include <stdbool.h>
#include "Lista.h"
#include "Util.h"
#include "Nodo.h"
// definida en Lista.c
const void* FinLista=NULL;
// Declarada aqui porque no es parte de la interfaz
PtrDato getDatoLista(PtrLista lista, int posicion);
PtrLista crearLista()
{
    PtrLista lista=obtenerMemoria(sizeof(Lista),"");
    lista->primero=FinLista;
    return lista;
}
PtrLista destruirLista(PtrLista lista, bool remover)
{
    if(remover)
    {
        while(!listaVacia(lista))
        {
            removerDeLista(lista,0);
        }
        free(lista);
    }
}
bool listaVacia(PtrLista lista)
{
// Una lista está vacía cuando lista->Primero==FinLista
    return (lista->primero==FinLista);
}
PtrNodo getNodoLista(PtrLista lista, int posicion)
{
    PtrNodo nodo=lista->primero;
    int posicionActual=0;
    if(nodo!=FinLista)
    {
        while(posicionActual<posicion &&
                getSiguiente(nodo)!=FinLista)
        {
            posicionActual++;
            nodo=getSiguiente(nodo);
        }
    }
    return nodo;
}
PtrDato getDatoLista(PtrLista lista, int posicion)
{
// Utilizamos una funcion auxiliar, getNodo, que no es parte de la
// interfaz de Lista
    PtrDato dato=FinLista;
    PtrNodo nodo=getNodoLista(lista,posicion);
    if(nodo!=FinLista)
    {
        dato=getDato(nodo);
    }
    return dato;
}
PtrDato getCabecera(PtrLista lista)
{
    PtrDato dato=FinLista;
    if(lista->primero!=FinLista)
    {
        dato=getDato(lista->primero);
    }
    return dato;
}
PtrLista getResto(PtrLista lista)
{
    PtrLista resto=crearLista();
    if(lista->primero!=FinLista)
    {
        resto->primero=getSiguiente(lista->primero);
    }
    return resto;
}
int longitudLista(PtrLista lista)
{
// para obtener la longitud, debemos recorrer la lista.
    int longitud=0;
    PtrNodo nodo=lista->primero;
    while(nodo!=FinLista)
    {
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}
void agregarDatoLista(PtrLista lista, PtrDato dato)
{
// simplemente creamos el nodo, hacemos que el primero de la lista
// sea su siguiente y lo ponemos como primero de la lista
    PtrNodo nuevoNodo=crearNodo(dato);
    setSiguiente(nuevoNodo,lista->primero);
    lista->primero=nuevoNodo;
}
bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion)
{
// Como insertamos después de la posición, utilizamos getNodoLista
    PtrNodo nodo=getNodoLista(lista,posicion);
    bool resultado=false;
    if (nodo!=FinLista)  // insertamos
    {
        PtrNodo nuevoNodo=crearNodo(dato);
        setSiguiente(nuevoNodo,getSiguiente(nodo));
        setSiguiente(nodo,nuevoNodo);
        resultado=true;
    }
    return resultado;
}
void agregarLista(PtrLista estaLista, PtrLista otraLista)
{
// Establecemos como siguiente del ultimo nodo de estaLista
// al primero de otraLista
    if(estaLista->primero==FinLista)
    {
        estaLista->primero=otraLista->primero;
    }
    else
    {
        PtrNodo nodo=estaLista->primero;
        while(getSiguiente(nodo)!=FinLista)
        {
            nodo=getSiguiente(nodo);
        }
        setSiguiente(nodo,otraLista->primero);
    }
}
PtrDato removerDeLista(PtrLista lista, int posicion)
{
// si la posición es 0, solo hay que devolver el dato del primero y
// eliminarlo. En otro caso, hay que pararse en posicion-1 , sacar
// el dato del siguiente y poner el siguiente del nodo en posicion-1
// al sgte del sgte
    PtrDato dato=NULL;
    PtrDato nodoEliminar=NULL;
    if(lista->primero!=FinLista)
    {
        if (posicion==0)  // eliminamos la cabecera
        {
            nodoEliminar=lista->primero;
            dato=getDato(nodoEliminar);
            lista->primero=getSiguiente(lista->primero);
            destruirNodo(nodoEliminar);
        }
        else
        {
            PtrNodo nodo=getNodoLista(lista,posicion-1);
            if(nodo!=FinLista)
            {
                nodoEliminar=getSiguiente(nodo);
                if(nodoEliminar!=FinLista)
                {
                    dato=getDato(nodoEliminar);
                    setSiguiente(nodo,
                                 getSiguiente(nodoEliminar));
                    destruirNodo(nodoEliminar);
                }
            }
        }
    }
    return dato;
}

