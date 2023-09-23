
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
// Operación de construccion (constructor)
// Precondicion: la lista no debe haber sido creada.
// Postcondición: lista queda creada vacía y preparada para ser usada.
// Parámetros:
// Ninguna
// Devuelve puntero a la lista creada
PtrLista crearLista();
// Operación de destruccion (destructor)
// Precondicion: la lista debe haber sido creada y sus nodos eliminados.
// Postcondición: se reclama la memoria de lista.
// Parámetros:
// lista: puntero a la lista a destruir
// remover: indica si se deben remover los nodos antes de reclamar
// Devuelve FinLista
PtrLista destruirLista(PtrLista lista, bool remover);
// Operación de verificación de estado
// Precondicion: la lista debe haber sido creada.
// Postcondición: ninguna
// Parámetros:
// Puntero a la lista que se desea saber si se encuentra vacía
// Devuelve true si la lista se encuentra vacía (PtrLista=FinLista), falsede otro modo
bool listaVacia(PtrLista lista);
// Operación de obtención del dato
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se obitiene el dato en la posicion solicitada
// Parámetros:
// lista: puntero a la lista
// posicion: Entero indicando la posición solicitada. 0 la primera
// Si la posición no existe, devuelve FinLista
// Devuelve puntero al dato obtenido o FinLista
PtrDato getDatoLista(PtrLista lista, int posicion);
// Operación de obtención del dato de la primera posición
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se obitiene el dato en la primera posicion. Si la listaesta vacía
// devuelve FinLista
// Parámetros:
// lista: puntero a la lista
// Devuelve puntero al dato de la cabecera
PtrDato getCabecera(PtrLista lista);
// Operación de obtención de la cola de la lista (sin el primer nodo)
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se obtiene el resto de la lista
// Parámetros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
PtrLista getResto(PtrLista lista);
// Operación de obtención de la longitud de la lista
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se obtiene la longitud de la lista
// Parámetros:
// lista: puntero a la lista
// Devuelve puntero al resto de la lista
int longitudLista(PtrLista lista);
// Operación de agregado antes de la cabecera
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se agrega el dato antes de la cabecera de la lista
// Parámetros:
// lista: puntero a la lista
// dato: puntero al dato a insertar
// Devuelve true si pudo agregar, false de lo contrario
void agregarDatoLista(PtrLista lista, PtrDato dato);
// Operación de inserción en lista
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se inserta el dato despues de la posición indicada
// Parámetros:
// lista: puntero a la lista
// dato: puntero al dato a insertar
// posición: posición luego de la que se desea insertar el dato. Si laposición no
// existe, devuelve false
// Devuelve true si pudo insertar, false de lo contrario
bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion);
// Operación de agregado de una lista al final de otra
// Precondicion: estaLista y otraLista deben haber sido creadas.
// Postcondición: Se agrega otraLista luego del ultimo nodo de estaLista
// Parámetros:
// estaLista: puntero a la lista a la que se agregará
// otraLista: puntero a la lista que se agregará
// No devuelve valores
void agregarLista(PtrLista estaLista, PtrLista otraLista);
// Operación de remoción
// Precondicion: la lista debe haber sido creada.
// Postcondición: Se remueve el nodo de posición
// Parámetros:
// lista: puntero a la lista
// posicion: posición del nodo a remover. Si no existe, no se remueve
// y devuelve FinLista
// Devuelve puntero al dato removido de la lista
PtrDato removerDeLista(PtrLista lista, int posicion);
#endif // LISTA_H_INCLUDED
