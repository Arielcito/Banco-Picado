#include <stdio.h>
#include "cuenta.h"

#define MAX_CUENTAS 100

// Implementación de las funciones de ABM de cuentas
void altaCuenta(CuentaPtr cuentas[], int *numCuentas, int numeroCuenta, Cliente titular, double saldo)
{
    if (*numCuentas < MAX_CUENTAS)
    {
        // Crear la cuenta y agregarla al arreglo
        cuentas[*numCuentas] = crearCuenta(numeroCuenta, titular, saldo);
        (*numCuentas)++;
        printf("Cuenta agregada con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más cuentas. La capacidad está llena.\n");
    }
}

void bajaCuenta(CuentaPtr cuentas[], int *numCuentas, int numeroCuenta)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numCuentas; i++)
    {
        if (getNumeroCuenta(cuentas[i]) == numeroCuenta)
        {
            // Liberar la memoria de la cuenta y eliminarla del arreglo
            cuentas[i] = destruirCuenta(cuentas[i]);

            // Mover las cuentas posteriores hacia atrás
            for (int j = i; j < (*numCuentas - 1); j++)
            {
                cuentas[j] = cuentas[j + 1];
            }

            indiceEncontrado = i;
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

void modificarCuenta(CuentaPtr cuentas[], int numCuentas, int numeroCuenta, Cliente titular, double saldo)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numCuentas; i++)
    {
        if (getNumeroCuenta(cuentas[i]) == numeroCuenta)
        {
            // Actualizar los datos de la cuenta
            setTitular(cuentas[i], titular);
            setSaldo(cuentas[i], saldo);
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

void mostrarCuentas(CuentaPtr cuentas[], int numCuentas)
{
    printf("Lista de Cuentas:\n");
    for (int i = 0; i < numCuentas; i++)
    {
        printf("Número de cuenta: %d, Titular: %s %s, Saldo: %.2f\n",
               getNumeroCuenta(cuentas[i]),
               getNombre(getTitular(cuentas[i])),
               getApellido(getTitular(cuentas[i])),
               getSaldo(cuentas[i]));
    }
}