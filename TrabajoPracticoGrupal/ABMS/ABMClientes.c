#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

#define MAX_CLIENTES 100

// Declaración de funciones auxiliares
static void mostrarMenuClientes();

// Implementación de las funciones de ABM de clientes
void altaCliente(ClientePtr clientes[], int *numClientes)
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
        scanf("%ld", &dni);

        // Crear el cliente y agregarlo al arreglo
        clientes[*numClientes] = crearCliente(dni, apellido, nombre, domicilio);
        (*numClientes)++;
        printf("Cliente agregado con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más clientes. La capacidad está llena.\n");
    }
}

void bajaCliente(ClientePtr clientes[], int *numClientes, long dni)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numClientes; i++)
    {
        if (getDniCliente(clientes[i]) == dni)
        {
            // Liberar la memoria del cliente y eliminarlo del arreglo
            clientes[i] = destruirCliente(clientes[i]);

            // Mover los clientes posteriores hacia atrás
            for (int j = i; j < (*numClientes - 1); j++)
            {
                clientes[j] = clientes[j + 1];
            }

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

void modificarCliente(ClientePtr clientes[], int numClientes, long dni)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numClientes; i++)
    {
        if (getDniCliente(clientes[i]) == dni)
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
            setApellidoCliente(clientes[i], nuevoApellido);
            setNombreCliente(clientes[i], nuevoNombre);
            setDomicilioCliente(clientes[i], nuevoDomicilio);
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

void mostrarClientes(ClientePtr clientes[], int numClientes)
{
    printf("Lista de Clientes:\n");
    for (int i = 0; i < numClientes; i++)
    {
        printf("DNI: %ld, Apellido: %s, Nombre: %s, Domicilio: %s\n",
               getDniCliente(clientes[i]),
               getApellidoCliente(clientes[i]),
               getNombreCliente(clientes[i]),
               getDomicilioCliente(clientes[i]));
    }
}

static void mostrarMenuClientes()
{
    printf("Menu de Clientes:\n");
    printf("1. Alta de cliente\n");
    printf("2. Baja de cliente\n");
    printf("3. Modificación de cliente\n");
    printf("4. Mostrar clientes\n");
    printf("5. Salir\n");
}