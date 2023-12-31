#include <stdio.h>
#include <stdlib.h>
#include "ABMCajeros.h"
#include "lista.h"

#define MAX_CAJEROS 100

// Implementaci�n de las funciones de ABM de cajeros
void altaCajero(CajeroPtr listaCajeros, int *numCajeros)
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
        CajeroPtr nuevoCajero = crearCajero(apellido, nombre, cuil, numeroLegajo);
        agregarDatoLista(listaCajeros,nuevoCajero);
        (*numCajeros)++;
        printf("Cajero agregado con �xito.\n");
    }
    else
    {
        printf("No se pueden agregar m�s cajeros. La capacidad est� llena.\n");
    }
}

void bajaCajero(CajeroPtr listaCajeros, int *numCajeros, long cuil)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numCajeros; i++)
    {
        CajeroPtr actualCajero = getDatoLista(listaCajeros,i);
        if (getCuilCajero(actualCajero) == cuil)
        {
            listaCajeros = removerDeLista(listaCajeros,i);
            // Liberar la memoria del cliente y eliminarlo del arreglo
            listaCajeros = destruirCliente(actualCajero);

            indiceEncontrado = i;
            (*numCajeros)--;
            printf("Cliente eliminado con �xito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado el cliente
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cajero no encontrado.\n");
    }
}

void modificarCajero(CajeroPtr listaCajeros, int numCajeros, long cuil)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numCajeros; i++)
    {
        if (getCuilCajero(listaCajeros) == cuil)
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
            setApellidoCajero(listaCajeros, nuevoApellido);
            setNombreCajero(listaCajeros, nuevoNombre);
            setNumeroLegajoCajero(listaCajeros, nuevoNumeroLegajo);
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

void mostrarCajeros(CajeroPtr listaCajeros, int numCajeros)
{
    CajeroPtr listaAux=crearLista();
    agregarLista(listaAux,listaCajeros);

    printf("Lista de Cajeros:\n");
    while(!listaVacia(listaAux))
    {
        CajeroPtr actualCajero = getCabecera(listaAux);
        printf("Apellido: %s, Nombre: %s, Cuil: %d, Numero de legajo: %d\n",
               getApellidoCajero(actualCajero),
               getNombreCajero(actualCajero),
               getCuilCajero(actualCajero),
               getNumeroLegajoCajero(actualCajero));

        CajeroPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
        printf("\n");
}

void mostrarMenuCajeros()
{
    printf("Menu de Cajeros:\n");
    printf("-------------------------\n\n");
    printf("1. Alta de cajero\n");
    printf("2. Baja de cajero\n");
    printf("3. Modificaci�n de cajero\n");
    printf("4. Mostrar cajeros\n");
    printf("5. Salir\n");
}

