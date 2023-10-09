#include "Turno.h"
#include "Cola.h"
int obtenerNumeroCorrelativo();
// Funci�n para solicitar un nuevo turno
void solicitarTurno(TurnoPtr colaTurnos, char tipoOperacion,CuentaPtr cuenta)
{
    int numeroCorrelativo = obtenerNumeroCorrelativo(); // Debes implementar esta funci�n.
    // Crear un nuevo turno
    TurnoPtr nuevoTurno = crearTurno(tipoOperacion,numeroCorrelativo,cuenta);

    // Encolar el nuevo turno
    encolar(colaTurnos, nuevoTurno);

    // Imprimir mensaje de confirmaci�n
    printf("Turno %c%d solicitado con �xito.\n", nuevoTurno->tipoOperacion, nuevoTurno->numeroCorrelativo);
}

// Funci�n para obtener el n�mero correlativo (deber�s implementar la l�gica espec�fica)
int obtenerNumeroCorrelativo()
{
    static int correlativo = 1;
    return correlativo++;
}

// Funci�n para llamar al pr�ximo turno
CuentaPtr llamarProximoTurno(TurnoPtr colaTurnos)
{
    // Verificar si la cola de turnos est� vac�a
    if (colaVacia(colaTurnos))
    {
        printf("No hay turnos en espera.\n");
        return;
    }

    // Desencolar el pr�ximo turno
    TurnoPtr proximoTurno = desencolar(colaTurnos);

    printf("Llamando al turno %c%d.\n", proximoTurno->tipoOperacion, proximoTurno->numeroCorrelativo);

    return proximoTurno->cuenta;
}
