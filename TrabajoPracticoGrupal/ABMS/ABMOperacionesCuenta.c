#include <stdio.h>
#include "OperacionCuenta.h"

#define MAX_OPERACIONES 100

// Implementación de las funciones de ABM de operaciones en cuenta
void altaOperacionCuenta(OperacionCuentaPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion, double montoCheques, double montoEfectivo, Cuenta cuentaAfectada)
{
    if (*numOperaciones < MAX_OPERACIONES)
    {
        // Crear la operación y agregarla al arreglo
        operaciones[*numOperaciones] = crearOperacionCuenta(fechaHoraOperacion, montoCheques, montoEfectivo, cuentaAfectada);
        (*numOperaciones)++;
        printf("Operación agregada con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más operaciones. La capacidad está llena.\n");
    }
}

void bajaOperacionCuenta(OperacionCuentaPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numOperaciones; i++)
    {
        if (getFechaHoraOperacion(operaciones[i]) == fechaHoraOperacion)
        {
            // Liberar la memoria de la operación y eliminarla del arreglo
            operaciones[i] = destruirOperacionCuenta(operaciones[i]);

            // Mover las operaciones posteriores hacia atrás
            for (int j = i; j < (*numOperaciones - 1); j++)
            {
                operaciones[j] = operaciones[j + 1];
            }

            indiceEncontrado = i;
            (*numOperaciones)--;
            printf("Operación eliminada con éxito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado la operación
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Operación no encontrada.\n");
    }
}

void modificarOperacionCuenta(OperacionCuentaPtr operaciones[], int numOperaciones, time_t fechaHoraOperacion, double montoCheques, double montoEfectivo, Cuenta cuentaAfectada)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numOperaciones; i++)
    {
        if (getFechaHoraOperacion(operaciones[i]) == fechaHoraOperacion)
        {
            // Actualizar los datos de la operación
            setMontoCheques(operaciones[i], montoCheques);
            setMontoEfectivo(operaciones[i], montoEfectivo);
            setCuentaAfectada(operaciones[i], cuentaAfectada);
            printf("Operación modificada con éxito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado la operación
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Operación no encontrada.\n");
    }
}

void mostrarOperacionesCuenta(OperacionCuentaPtr operaciones[], int numOperaciones)
{
    printf("Lista de Operaciones en Cuenta:\n");
    for (int i = 0; i < numOperaciones; i++)
    {
        printf("Fecha y hora de la operación: %ld, Monto de cheques: %.2f, Monto en efectivo: %.2f, Cuenta afectada: %d\n",
               getFechaHoraOperacion(operaciones[i]),
               getMontoCheques(operaciones[i]),
               getMontoEfectivo(operaciones[i]),
               getCuentaAfectada(operaciones[i]));
    }
}