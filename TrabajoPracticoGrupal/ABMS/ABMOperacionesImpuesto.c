#include <stdio.h>
#include "OperacionImpuestos.h"

#define MAX_OPERACIONES 100

// Implementación de las funciones de ABM de operaciones de impuestos
void altaOperacionImpuestos(OperacionImpuestosPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion, const char *impuesto, double monto)
{
    if (*numOperaciones < MAX_OPERACIONES)
    {
        // Crear la operación y agregarla al arreglo
        operaciones[*numOperaciones] = crearOperacionImpuestos(fechaHoraOperacion, impuesto, monto);
        (*numOperaciones)++;
        printf("Operación agregada con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más operaciones. La capacidad está llena.\n");
    }
}

void bajaOperacionImpuestos(OperacionImpuestosPtr operaciones[], int *numOperaciones, time_t fechaHoraOperacion)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numOperaciones; i++)
    {
        if (getFechaHoraOperacionImpuestos(operaciones[i]) == fechaHoraOperacion)
        {
            // Liberar la memoria de la operación y eliminarla del arreglo
            operaciones[i] = destruirOperacionImpuestos(operaciones[i]);

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

void modificarOperacionImpuestos(OperacionImpuestosPtr operaciones[], int numOperaciones, time_t fechaHoraOperacion, const char *impuesto, double monto)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numOperaciones; i++)
    {
        if (getFechaHoraOperacionImpuestos(operaciones[i]) == fechaHoraOperacion)
        {
            // Actualizar los datos de la operación
            setImpuesto(operaciones[i], impuesto);
            setMontoImpuestos(operaciones[i], monto);
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

void mostrarOperacionesImpuestos(OperacionImpuestosPtr operaciones[], int numOperaciones)
{
    printf("Lista de Operaciones de Impuestos:\n");
    for (int i = 0; i < numOperaciones; i++)
    {
        printf("Fecha y hora de la operación: %ld, Tipo de impuesto: %s, Monto de impuestos: %.2f\n",
               getFechaHoraOperacionImpuestos(operaciones[i]),
               getImpuesto(operaciones[i]),
               getMontoImpuestos(operaciones[i]));
    }
}