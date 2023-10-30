#include "Turno.h"
#include "Cola.h"
#include "Cuenta.h"
#include "Cliente.h"
int obtenerNumeroCorrelativo();
// Función para solicitar un nuevo turno
void solicitarTurno(TurnoPtr colaTurnos, TurnoPtr colaTurnosPrioridad,char* tipoOperacion,CuentaPtr cuenta)
{
    int numeroCorrelativo = obtenerNumeroCorrelativo(); // Debes implementar esta función.
    // Crear un nuevo turno
    TurnoPtr nuevoTurno = crearTurno(tipoOperacion,numeroCorrelativo,cuenta);

    int edadCliente = getEdadCliente(getTitular(cuenta));

    if (edadCliente >= 70)
    {
        // Encolar el turno en la cola de prioridad
        encolar(colaTurnosPrioridad, nuevoTurno);
    }
    else
    {
        // Encolar el turno en la cola normal
        encolar(colaTurnos, nuevoTurno);
    }

    // Imprimir mensaje de confirmación
    printf("Turno %s%d solicitado con éxito.\n", getTipoOperacion(nuevoTurno), getNumeroCorrelativo(nuevoTurno));
}

// Función para obtener el número correlativo (deberás implementar la lógica específica)
int obtenerNumeroCorrelativo()
{
    static int correlativo = 1;
    return correlativo++;
}

// Función para llamar al próximo turno
CuentaPtr llamarProximoTurno(TurnoPtr colaTurnos, TurnoPtr colaTurnosPrioridad)
{
   // Verificar si la cola de turnos está vacía
    if (colaVacia(colaTurnos))
    {
        printf("No hay turnos en espera.\n");
        return;
    }

    // Verificar si la cola de prioridad no está vacía
    if (!colaVacia(colaTurnosPrioridad))
    {
        // Desencolar el turno de la cola de prioridad
        TurnoPtr proximoTurno = desencolar(colaTurnosPrioridad);
        int edadCliente = getEdadCliente(getTitular(getCuentaAAtender(proximoTurno)));
        printf("%d",edadCliente);

        printf("Llamando al turno con prioridad: %s%d.\n", getTipoOperacion(proximoTurno), proximoTurno->numeroCorrelativo);

        return proximoTurno->cuenta;
    }
    else
    {
        // Desencolar el turno de la cola normal
        TurnoPtr proximoTurno = desencolar(colaTurnos);
        char* tipoOp = getTipoOperacion(proximoTurno);
        printf("Llamando al turno %s%d.\n", getTipoOperacion(proximoTurno), proximoTurno->numeroCorrelativo);

        return proximoTurno->cuenta;
    }
}
