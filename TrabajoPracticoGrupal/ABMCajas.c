
#include <stdio.h>
#include "Caja.h"
#include "lista.h"

#define MAX_CAJAS 100

// Implementación de las funciones de ABM de cajas
void altaCaja(Caja** listaCajas,int* numCajas, int numeroCaja, double montoInicial)
{
    if (*numCajas < MAX_CAJAS)
    {
        // Crear la caja y agregarla al arreglo
        Caja* nuevaCaja = crearCaja(numeroCaja, montoInicial);

        agregarDatoLista(listaCajas,nuevaCaja);
        (*numCajas)++;

        printf("Caja agregada con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más cajas. La capacidad está llena.\n");
    }
}

void bajaCaja(CajaPtr cajas[], int *numCajas, int numeroCaja)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numCajas; i++)
    {
        if (getNumeroCaja(cajas[i]) == numeroCaja)
        {
            // Liberar la memoria de la caja y eliminarla del arreglo
            cajas[i] = destruirCaja(cajas[i]);

            // Mover las cajas posteriores hacia atrás
            for (int j = i; j < (*numCajas - 1); j++)
            {
                cajas[j] = cajas[j + 1];
            }

            indiceEncontrado = i;
            (*numCajas)--;
            printf("Caja eliminada con éxito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado la caja
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Caja no encontrada.\n");
    }
}

void modificarCaja(CajaPtr cajas[], int numCajas, int numeroCaja, double montoInicial)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numCajas; i++)
    {
        if (getNumeroCaja(cajas[i]) == numeroCaja)
        {
            // Actualizar los datos de la caja
            setMontoInicial(cajas[i], montoInicial);
            printf("Caja modificada con éxito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado la caja
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Caja no encontrada.\n");
    }
}

void mostrarCajas(CajaPtr cajas[], int numCajas)
{
    printf("Lista de Cajas:\n");
    for (int i = 0; i < numCajas; i++)
    {
        printf("Número de caja: %d, Monto inicial: %.2f\n",
               getNumeroCaja(cajas[i]),
               getMontoInicial(cajas[i]));
    }
}
