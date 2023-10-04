
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "lista.h"

#define MAX_CLIENTES 100

// Implementación de las funciones de ABM de clientes
void    altaCliente(Cliente** listaClientes, int* numClientes)
{
    if (*numClientes < MAX_CLIENTES)
    {

        char apellido[50];
        char nombre[50];
        char domicilio[100];
        long dni;

        printf("Ingrese el apellido del cliente: ");
        scanf("%s", apellido);

        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombre);

        printf("Ingrese el domicilio del cliente: ");
        scanf("%s", domicilio);

        printf("Ingrese el DNI del cliente: ");
        scanf("%ld", &dni); // Corregido el formato a %ld

        Cliente* nuevoCliente = crearCliente(dni, apellido, nombre, domicilio);

        agregarDatoLista(listaClientes,nuevoCliente);
        (*numClientes)++;

        printf("Cliente agregado con éxito.\n");

    }
    else
    {
        printf("No se pueden agregar más clientes. La capacidad está llena.\n");

    }
}

// Modificación de la función bajaCliente
void bajaCliente(Cliente** listaClientes, int *numClientes, long dni)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numClientes; i++)
    {
        ClientePtr actualClient = getDatoLista(listaClientes,i);
        if (getDniCliente(actualClient) == dni)
        {
            listaClientes = removerDeLista(listaClientes,i);
            // Liberar la memoria del cliente y eliminarlo del arreglo
            listaClientes = destruirCliente(actualClient);

            indiceEncontrado = i;
            (*numClientes)--;
            printf("Cliente eliminado con éxito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado el cliente
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cliente no encontrado.\n");
    }
}

void modificarCliente(Cliente** listaClientes, int *numClientes, long dni)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numClientes; i++)
    {
        ClientePtr actualClient = getDatoLista(listaClientes,i);
        if (getDniCliente(actualClient) == dni)
        {
            // Solicitar los nuevos datos al usuario
            char nuevoApellido[50];
            char nuevoNombre[50];
            char nuevoDomicilio[100];

            printf("Ingrese el nuevo apellido del cliente: ");
            scanf("%s", nuevoApellido);

            printf("Ingrese el nuevo nombre del cliente: ");
            scanf("%s", nuevoNombre);

            printf("Ingrese el nuevo domicilio del cliente: ");
            scanf("%s", nuevoDomicilio);

            // Actualizar los datos del cliente
            setApellidoCliente(actualClient, nuevoApellido);
            setNombreCliente(actualClient, nuevoNombre);
            setDomicilioCliente(actualClient, nuevoDomicilio);
            printf("Cliente modificado con éxito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado el cliente
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cliente no encontrado.\n");
    }
}

void mostrarClientes(Cliente** listaClientes, int *numClientes)
{
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,listaClientes);
    printf("Lista de Clientes:\n");
    while(!listaVacia(listaAux))
    {
        ClientePtr actualClient = getCabecera(listaAux);
            printf("DNI: %ld, Apellido: %s, Nombre: %s, Domicilio: %s\n",
                   getDniCliente(actualClient),
                   getApellidoCliente(actualClient),
                   getNombreCliente(actualClient),
                   getDomicilioCliente(actualClient));
            PtrLista listaADestruir=listaAux;
            listaAux=getResto(listaAux);
            destruirLista(listaADestruir,false);


        destruirLista(listaAux,false);
        printf("\n");
    }
}
    void mostrarMenuClientes()
    {
        printf("Menu de Clientes:\n");
        printf("1. Alta de cliente\n");
        printf("2. Baja de cliente\n");
        printf("3. Modificación de cliente\n");
        printf("4. Mostrar clientes\n");
        printf("5. Salir\n");
    }
