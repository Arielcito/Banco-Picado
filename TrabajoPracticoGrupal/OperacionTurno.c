#include "Turno.h"
#include "Cola.h"

// Función para solicitar un nuevo turno
void solicitarTurno(PtrCola colaTurnos, char tipoOperacion)
{
    // Crear un nuevo turno
    Turno nuevoTurno;
    nuevoTurno.tipoOperacion = tipoOperacion;
    // nuevoTurno.numeroCorrelativo = obtenerNumeroCorrelativo(); // Debes implementar esta función.

    // Encolar el nuevo turno
    encolar(colaTurnos, &nuevoTurno);

    // Imprimir mensaje de confirmación
    printf("Turno %c%d solicitado con éxito.\n", nuevoTurno.tipoOperacion, nuevoTurno.numeroCorrelativo);
}

// Función para llamar al próximo turno
void llamarProximoTurno(PtrCola colaTurnos)
{
    // Verificar si la cola de turnos está vacía
    if (colaVacia(colaTurnos))
    {
        printf("No hay turnos en espera.\n");
        return;
    }

    // Desencolar el próximo turno
    Turno *proximoTurno = (Turno *)desencolar(colaTurnos);

    // Imprimir el turno llamado
    printf("Llamando al turno %c%d.\n", proximoTurno->tipoOperacion, proximoTurno->numeroCorrelativo);

    // Liberar la memoria del turno llamado
    free(proximoTurno);
}
