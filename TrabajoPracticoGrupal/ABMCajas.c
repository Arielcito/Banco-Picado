
#include <stdio.h>
#include "Caja.h"
#include "lista.h"
#include "Cajero.h"

#define MAX_CAJAS 100

// Implementaci�n de las funciones de ABM de cajas
void altaCaja(Caja** listaCajas,int* numCajas, int numeroCaja, double montoInicial)
{
    if (*numCajas < MAX_CAJAS)
    {
        // Crear la caja y agregarla al arreglo
        Caja* nuevaCaja = crearCaja(numeroCaja, montoInicial);

        agregarDatoLista(listaCajas,nuevaCaja);
        (*numCajas)++;

        printf("Caja agregada con �xito.\n");
    }
    else
    {
        printf("No se pueden agregar m�s cajas. La capacidad est� llena.\n");
    }
}

void bajaCaja(CajaPtr* listaCajas, int *numCajas, int numeroCaja)
{
    int indiceEncontrado = -1;

     for (int i = 0; i < *numCajas; i++)
    {
        CajaPtr actualCaja = getDatoLista(listaCajas,i);
        if (getNumeroCaja(actualCaja) == numeroCaja)
        {
            listaCajas = removerDeLista(listaCajas,i);
            // Liberar la memoria del cliente y eliminarlo del arreglo
            listaCajas = destruirCliente(actualCaja);

            indiceEncontrado = i;
            (*numCajas)--;
            printf("Cliente eliminado con �xito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado el cliente
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Caja no encontrada.\n");
    }
}

void modificarCaja(CajaPtr listaCajas, int numCajas, int numeroCaja, double montoInicial)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numCajas; i++)
    {
        CajaPtr actualCaja = getDatoLista(listaCajas,i);
        if (getNumeroCaja(actualCaja) == numeroCaja)
        {
            // Actualizar los datos de la caja
            setMontoInicial(actualCaja, montoInicial);
            printf("Caja modificada con �xito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado la caja
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Caja no encontrada.\n");
    }
}

void mostrarCajas(CajaPtr listaCajas, int numCajas)
{
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,listaCajas);

    printf("-------------------------\n");
    printf("Lista de Cajas:\n");
    printf("-------------------------\n\n");
    while(!listaVacia(listaAux))
    {
        CajaPtr actualCaja = getCabecera(listaAux);
        printf("Numero Caja: %d, Monte inicial: %1d\n",
               getNumeroCaja(actualCaja),
               getMontoInicial(actualCaja)
               );

        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
        printf("\n");
}
