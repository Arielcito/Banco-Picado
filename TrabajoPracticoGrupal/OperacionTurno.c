#include "Turno.h"
#include "Cola.h"
#include "Cuenta.h"
#include "Cliente.h"
int obtenerNumeroCorrelativo();
// Funci�n para solicitar un nuevo turno
void solicitarTurno(TurnoPtr colaTurnos, TurnoPtr colaTurnosPrioridad,char* tipoOperacion,CuentaPtr cuenta)
{
    int numeroCorrelativo = obtenerNumeroCorrelativo(); // Debes implementar esta funci�n.
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

    // Imprimir mensaje de confirmaci�n
    printf("Turno %s%d solicitado con �xito.\n", getTipoOperacion(nuevoTurno), getNumeroCorrelativo(nuevoTurno));
}

// Funci�n para obtener el n�mero correlativo (deber�s implementar la l�gica espec�fica)
int obtenerNumeroCorrelativo()
{
    static int correlativo = 1;
    return correlativo++;
}

// Funci�n para llamar al pr�ximo turno
CuentaPtr llamarProximoTurno(TurnoPtr colaTurnos, TurnoPtr colaTurnosPrioridad)
{
   // Verificar si la cola de turnos est� vac�a
    if (colaVacia(colaTurnos))
    {
        printf("No hay turnos en espera.\n");
        return;
    }

    // Verificar si la cola de prioridad no est� vac�a
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
