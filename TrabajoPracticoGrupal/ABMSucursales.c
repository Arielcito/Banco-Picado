
#include <stdio.h>
#include <stdlib.h>
#include "sucursal.h"
#include "lista.h"

#define MAX_SUCURSALES 2

// Implementación de las funciones de ABM de sucursales
void altaSucursal(SucursalPtr listaSucursales, int *numSucursales)
{
    if (*numSucursales < MAX_SUCURSALES)
    {
        int numeroSucursal;
        char domicilio[100];

        printf("Ingrese el número de la sucursal: ");
        scanf("%d", &numeroSucursal);

        printf("Ingrese el domicilio de la sucursal: ");
        scanf("%s", domicilio);

        // Crear la sucursal y agregarla al arreglo
        SucursalPtr nuevaSucursal = crearSucursal(numeroSucursal, domicilio);
        agregarDatoLista(listaSucursales,nuevaSucursal);
        (*numSucursales)++;
        printf("Sucursal agregada con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más sucursales. La capacidad está llena.\n");
    }
}

void bajaSucursal(SucursalPtr sucursales[], int *numSucursales, int numeroSucursal)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numSucursales; i++)
    {
        if (getNumeroSucursal(sucursales[i]) == numeroSucursal)
        {
            // Liberar la memoria de la sucursal y eliminarla del arreglo
            sucursales[i] = destruirSucursal(sucursales[i]);

            // Mover las sucursales posteriores hacia atrás
            for (int j = i; j < (*numSucursales - 1); j++)
            {
                sucursales[j] = sucursales[j + 1];
            }

            indiceEncontrado = i;
            (*numSucursales)--;
            printf("Sucursal eliminada con éxito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado la sucursal
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Sucursal no encontrada.\n");
    }
}

void modificarSucursal(SucursalPtr sucursales[], int numSucursales, int numeroSucursal)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numSucursales; i++)
    {
        if (getNumeroSucursal(sucursales[i]) == numeroSucursal)
        {
            // Solicitar los nuevos datos al usuario
            char nuevoDomicilio[100];

            printf("Ingrese el nuevo domicilio de la sucursal: ");
            scanf("%s", nuevoDomicilio);

            // Actualizar los datos de la sucursal
            setDomicilio(sucursales[i], nuevoDomicilio);
            printf("Sucursal modificada con éxito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado la sucursal
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Sucursal no encontrada.\n");
    }
}


void mostrarSucursales(SucursalPtr listaSucursal)
{
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,listaSucursal);
    printf("Lista de Sucursales:\n");
    while(!listaVacia(listaAux))
    {
        SucursalPtr actualSucursal = getCabecera(listaAux);
            printf("Número de sucursal: %d, Domicilio: %s \n",
               getNumeroSucursal(actualSucursal),
               getDomicilio(actualSucursal));

            PtrLista listaADestruir=listaAux;
            listaAux=getResto(listaAux);
            destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

 void mostrarMenuSucursales()
{
    printf("Menu de Sucursales:\n");
    printf("1. Alta de sucursal\n");
    printf("2. Baja de sucursal\n");
    printf("3. Modificación de sucursal\n");
    printf("4. Mostrar sucursales\n");
    printf("5. Salir\n");
}
