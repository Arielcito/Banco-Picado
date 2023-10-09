#include <stdio.h>
#include "cuenta.h"
#include "cliente.h"
#include "lista.h"

#define MAX_CUENTAS 100

// Implementación de las funciones de ABM de cuentas
void altaCuenta(CuentaPtr* listaCuentas, int *numCuentas, ClientePtr titular)
{
    if (*numCuentas < MAX_CUENTAS)
    {
        // Crear la cuenta y agregarla al arreglo
        (*numCuentas)++;
        CuentaPtr nuevaCuenta = crearCuenta(titular,*numCuentas);
        agregarDatoLista(listaCuentas,nuevaCuenta);

        printf("Cuenta agregada con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más cuentas. La capacidad está llena.\n");
    }
}

void bajaCuenta(CuentaPtr* listaCuentas, int *numCuentas, int numeroCuenta)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numCuentas; i++)
    {
        CuentaPtr cuentaActual = getDatoLista(listaCuentas,i);
        if (getNumeroCuenta(cuentaActual) == numeroCuenta)
        {
            listaCuentas = removerDeLista(listaCuentas,i);
            // Liberar la memoria de la cuenta y eliminarla del arreglo
            cuentaActual = destruirCuenta(cuentaActual);

            (*numCuentas)--;
            printf("Cuenta eliminada con éxito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado la cuenta
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cuenta no encontrada.\n");
    }
}

void modificarCuenta(CuentaPtr* listaCuentas, int *numCuentas, int numeroCuenta, ClientePtr titular, double saldo)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numCuentas; i++)
    {

        CuentaPtr cuentaActual = getDatoLista(listaCuentas,i);
        if (getNumeroCuenta(cuentaActual) == numeroCuenta)
        {
            // Actualizar los datos de la cuenta
            setTitular(cuentaActual, titular);
            setSaldo(cuentaActual, saldo);
            printf("Cuenta modificada con éxito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado la cuenta
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Cuenta no encontrada.\n");
    }
}

void mostrarCuentas(CuentaPtr** listaCuentas, int *numCuentas)
{
    CuentaPtr listaAux=crearLista();
    agregarLista(listaAux,listaCuentas);

    printf("Lista de Cuentas:\n");
    while(!listaVacia(listaAux))
    {
        CuentaPtr actualClient = getCabecera(listaAux);
        mostrarCuenta(actualClient);

        CuentaPtr listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");

}

void mostrarCuenta(CuentaPtr actualClient)
{
    printf("Número de cuenta: %d, Titular: %s %s, DNI: %d , Saldo: %.2f\n",
           getNumeroCuenta(actualClient),
           getNombreCliente(getTitular(actualClient)),
           getApellidoCliente(getTitular(actualClient)),
           getDniCliente(getTitular(actualClient)),
           getSaldo(actualClient));
}
void mostrarMenuCuentas()
{
    printf("Menu de Cuenta:\n");
    printf("-------------------------\n\n");
    printf("1. Alta de Cuenta\n");
    printf("2. Baja de Cuenta\n");
    printf("3. Modificaci�n de Cuenta\n");
    printf("4. Mostrar Cuenta\n");
    printf("5. Salir\n");
}
