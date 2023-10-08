#include "Turno.h"
#include "Cola.h"
int obtenerNumeroCorrelativo();
// Función para solicitar un nuevo turno
void solicitarTurno(TurnoPtr colaTurnos, char tipoOperacion)
{
    int numeroCorrelativo = obtenerNumeroCorrelativo(); // Debes implementar esta función.
    // Crear un nuevo turno
    TurnoPtr nuevoTurno = crearTurno(tipoOperacion,numeroCorrelativo);

    // Encolar el nuevo turno
    encolar(colaTurnos, nuevoTurno);


    // Imprimir mensaje de confirmación
    printf("Turno %c%d solicitado con éxito.\n", nuevoTurno->tipoOperacion, nuevoTurno->numeroCorrelativo);
}

// Función para obtener el número correlativo (deberás implementar la lógica específica)
int obtenerNumeroCorrelativo()
{
    static int correlativo = 1;
    return correlativo++;
}

// Función para llamar al próximo turno
void llamarProximoTurno(TurnoPtr colaTurnos)
{
    // Verificar si la cola de turnos está vacía
    if (colaVacia(colaTurnos))
    {
        printf("No hay turnos en espera.\n");
        return;
    }

    // Desencolar el próximo turno
    TurnoPtr proximoTurno = desencolar(colaTurnos);

    // Imprimir el turno llamado
    printf("Llamando al turno %c%d.\n", proximoTurno->tipoOperacion, proximoTurno->numeroCorrelativo);

    // Liberar la memoria del turno llamado
    free(proximoTurno);
}
