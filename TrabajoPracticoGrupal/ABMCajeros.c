#include <stdio.h>
#include <stdlib.h>
#include "ABMCajeros.h"

#define MAX_CAJEROS 100

// Implementaci�n de las funciones de ABM de cajeros
void altaCajero(CajeroPtr cajeros[], int *numCajeros)
{
    if (*numCajeros < MAX_CAJEROS)
    {
        char apellido[50];
        char nombre[50];
        long cuil;
        int numeroLegajo;

        printf("Ingrese el apellido del cajero: ");
        scanf("%s", apellido);

        printf("Ingrese el nombre del cajero: ");
        scanf("%s", nombre);

        printf("Ingrese el CUIL del cajero: ");
        scanf("%ld", &cuil);

        printf("Ingrese el n�mero de legajo del cajero: ");
        scanf("%d", &numeroLegajo);

        // Crear el cajero y agregarlo al arreglo
        cajeros[*numCajeros] = crearCajero(apellido, nombre, cuil, numeroLegajo);
        (*numCajeros)++;
        printf("Cajero agregado con �xito.\n");
    }
    else
    {
        printf("No se pueden agregar m�s cajeros. La capacidad est� llena.\n");
    }
}

void bajaCajero(CajeroPtr cajeros[], int *numCajeros, long cuil)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numCajeros; i++)
    {
        if (getCuilCajero(cajeros[i]) == cuil)
        {
            // Liberar la memoria del cajero y eliminarlo del arreglo
            cajeros[i] = destruirCajero(cajeros[i]);

            // Mover los cajeros posteriores hacia atr�s
            for (int j = i; j < (*numCajeros - 1); j++)
            {
                cajeros[j] = cajeros[j + 1];
            }

            indiceEncontrado = i;
            (*numCajeros)--;
            printf("Cajero eliminado con �xito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado el cajero
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cajero no encontrado.\n");
    }
}

void modificarCajero(CajeroPtr cajeros[], int numCajeros, long cuil)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numCajeros; i++)
    {
        if (getCuilCajero(cajeros[i]) == cuil)
        {
            // Solicitar los nuevos datos al usuario
            char nuevoApellido[50];
            char nuevoNombre[50];
            int nuevoNumeroLegajo;

            printf("Ingrese el nuevo apellido del cajero: ");
            scanf("%s", nuevoApellido);

            printf("Ingrese el nuevo nombre del cajero: ");
            scanf("%s", nuevoNombre);

            printf("Ingrese el nuevo n�mero de legajo del cajero: ");
            scanf("%d", &nuevoNumeroLegajo);

            // Actualizar los datos del cajero
            setApellidoCajero(cajeros[i], nuevoApellido);
            setNombreCajero(cajeros[i], nuevoNombre);
            setNumeroLegajoCajero(cajeros[i], nuevoNumeroLegajo);
            printf("Cajero modificado con �xito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado el cajero
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cajero no encontrado.\n");
    }
}

void mostrarCajeros(CajeroPtr cajeros[], int numCajeros)
{
    printf("Lista de Cajeros:\n");
    for (int i = 0; i < numCajeros; i++)
    {
        printf("CUIL: %ld, Apellido: %s, Nombre: %s, N�mero de Legajo: %d\n",
               getCuilCajero(cajeros[i]),
               getApellidoCajero(cajeros[i]),
               getNombreCajero(cajeros[i]),
               getNumeroLegajoCajero(cajeros[i]));
    }
}

void mostrarMenuCajeros()
{
    printf("Menu de Cajeros:\n");
    printf("1. Alta de cajero\n");
    printf("2. Baja de cajero\n");
    printf("3. Modificaci�n de cajero\n");
    printf("4. Mostrar cajeros\n");
    printf("5. Salir\n");
}

