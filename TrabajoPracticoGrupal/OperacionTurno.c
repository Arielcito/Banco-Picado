#include "Turno.h"
#include "Cola.h"

// Funci�n para solicitar un nuevo turno
void solicitarTurno(PtrCola colaTurnos, char tipoOperacion)
{
    // Crear un nuevo turno
    Turno nuevoTurno;
    nuevoTurno.tipoOperacion = tipoOperacion;
    // nuevoTurno.numeroCorrelativo = obtenerNumeroCorrelativo(); // Debes implementar esta funci�n.

    // Encolar el nuevo turno
    encolar(colaTurnos, &nuevoTurno);

    // Imprimir mensaje de confirmaci�n
    printf("Turno %c%d solicitado con �xito.\n", nuevoTurno.tipoOperacion, nuevoTurno.numeroCorrelativo);
}

// Funci�n para llamar al pr�ximo turno
void llamarProximoTurno(PtrCola colaTurnos)
{
    // Verificar si la cola de turnos est� vac�a
    if (colaVacia(colaTurnos))
    {
        printf("No hay turnos en espera.\n");
        return;
    }

    // Desencolar el pr�ximo turno
    Turno *proximoTurno = (Turno *)desencolar(colaTurnos);

    // Imprimir el turno llamado
    printf("Llamando al turno %c%d.\n", proximoTurno->tipoOperacion, proximoTurno->numeroCorrelativo);

    // Liberar la memoria del turno llamado
    free(proximoTurno);
}
