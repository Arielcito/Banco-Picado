#include <stdio.h>
#include "turno.h"

#define MAX_TURNOS 100

// Implementación de las funciones de ABM de turnos
void altaTurno(TurnoPtr turnos[], int *numTurnos, char tipoOperacion)
{
    if (*numTurnos < MAX_TURNOS)
    {
        // Crear el turno y agregarlo al arreglo
        turnos[*numTurnos] = crearTurno(tipoOperacion, (*numTurnos + 1));
        (*numTurnos)++;
        printf("Turno agregado con éxito.\n");
    }
    else
    {
        printf("No se pueden agregar más turnos. La capacidad está llena.\n");
    }
}

void bajaTurno(TurnoPtr turnos[], int *numTurnos, int numeroCorrelativo)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < *numTurnos; i++)
    {
        if (getNumeroCorrelativo(turnos[i]) == numeroCorrelativo)
        {
            // Liberar la memoria del turno y eliminarlo del arreglo
            turnos[i] = destruirTurno(turnos[i]);

            // Mover los turnos posteriores hacia atrás
            for (int j = i; j < (*numTurnos - 1); j++)
            {
                turnos[j] = turnos[j + 1];
            }

            indiceEncontrado = i;
            (*numTurnos)--;
            printf("Turno eliminado con éxito.\n");
            break; // Salir del bucle una vez que se ha encontrado y eliminado el turno
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Turno no encontrado.\n");
    }
}

void modificarTurno(TurnoPtr turnos[], int numTurnos, int numeroCorrelativo, char tipoOperacion)
{
    int indiceEncontrado = -1;

    for (int i = 0; i < numTurnos; i++)
    {
        if (getNumeroCorrelativo(turnos[i]) == numeroCorrelativo)
        {
            // Actualizar el tipo de operación del turno
            setTipoOperacion(turnos[i], tipoOperacion);
            printf("Turno modificado con éxito.\n");

            indiceEncontrado = i;
            break; // Salir del bucle una vez que se ha encontrado y modificado el turno
        }
    }

    if (indiceEncontrado == -1)
    {
        printf("Turno no encontrado.\n");
    }
}

void mostrarTurnos(TurnoPtr turnos[], int numTurnos)
{
    printf("Lista de Turnos:\n");
    for (int i = 0; i < numTurnos; i++)
    {
        printf("Número correlativo: %d, Tipo de operación: %c\n",
               getNumeroCorrelativo(turnos[i]),
               getTipoOperacion(turnos[i]));
    }
}