
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdbool.h>
#include "Nodo.h"
#include "Util.h"
typedef struct Lista{
PtrNodo primero;
} Lista;
typedef Lista* PtrLista;
const void* FinLista;
/*************************************************************************
*****/
/* Definicion de Primitivas */
/*--------------------------*/
// Operaci�n de construccion (constructor)
// Precondicion: la lista no debe haber sido creada.
// Postcondici�n: lista queda creada vac�a y preparada para ser usada.
// Par�metros:
// Ninguna
// Devuelve puntero a la lista creada
PtrLista crearLista();
// Operaci�n de destruccion (destructor)
// Precondicion: la lista debe haber sido creada y sus nodos eliminados.
// Postcondici�n: se reclama la memoria de lista.
// Par�metros:
// lista: puntero a la lista a destruir
// remover: indica si se deben remover los nodos antes de reclamar
// Devuelve FinLista
PtrLista destruirLista(PtrLista lista, bool remover);
// Operaci�n de verificaci�n de estado
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: ninguna
// Par�metros:
// Puntero a la lista que se desea saber si se encuentra vac�a
// Devuelve true si la lista se encuentra vac�a (PtrLista=FinLista), falsede otro modo
bool listaVacia(PtrLista lista);
// Operaci�n de obtenci�n del dato
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se obitiene el dato en la posicion solicitada
// Par�metros:
// lista: puntero a la lista
// posicion: Entero indicando la posici�n solicitada. 0 la primera
// Si la posici�n no existe, devuelve FinLista
// Devuelve puntero al dato obtenido o FinLista
PtrDato getDatoLista(PtrLista lista, int posicion);
// Operaci�n de obtenci�n del dato de la primera posici�n
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se obitiene el dato en la primera posicion. Si la listaesta vac�a
// devuelve FinLista
// Par�metros:
// lista: puntero a la lista
// Devuelve puntero al dato de la cabecera
PtrDato getCabecera(PtrLista lista);
// Operaci�n de obtenci�n de la cola de la lista (sin el primer nodo)
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se obtiene el resto de la lista
// Par�metros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
PtrLista getResto(PtrLista lista);
// Operaci�n de obtenci�n de la longitud de la lista
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se obtiene la longitud de la lista
// Par�metros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
int longitudLista(PtrLista lista);
// Operaci�n de agregado antes de la cabecera
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se agrega el dato antes de la cabecera de la lista
// Par�metros:
// lista: puntero a la lista
// dato: puntero al dato a insertar
// Devuelve true si pudo agregar, false de lo contrario
void agregarDatoLista(PtrLista lista, PtrDato dato);
// Operaci�n de inserci�n en lista
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se inserta el dato despues de la posici�n indicada
// Par�metros:
// lista: puntero a la lista
// dato: puntero al dato a insertar
// posici�n: posici�n luego de la que se desea insertar el dato. Si laposici�n no
// existe, devuelve false
// Devuelve true si pudo insertar, false de lo contrario
bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion);
// Operaci�n de agregado de una lista al final de otra
// Precondicion: estaLista y otraLista deben haber sido creadas.
// Postcondici�n: Se agrega otraLista luego del ultimo nodo de estaLista
// Par�metros:
// estaLista: puntero a la lista a la que se agregar�
// otraLista: puntero a la lista que se agregar�
// No devuelve valores
void agregarLista(PtrLista estaLista, PtrLista otraLista);
// Operaci�n de remoci�n
// Precondicion: la lista debe haber sido creada.
// Postcondici�n: Se remueve el nodo de posici�n
// Par�metros:
// lista: puntero a la lista
// posicion: posici�n del nodo a remover. Si no existe, no se remueve
// y devuelve FinLista
// Devuelve puntero al dato removido de la lista
PtrDato removerDeLista(PtrLista lista, int posicion);
#endif // LISTA_H_INCLUDED
