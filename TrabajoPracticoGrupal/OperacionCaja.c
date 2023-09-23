#include <stdio.h>
#include <time.h>

Cliente obtenerSiguienteCliente(Cola *cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía. No hay clientes para atender.\n");
        Cliente clienteVacio = {"", 0};
        return clienteVacio;
    }

    return cola->elementos[cola->frente];
}

void atenderTurno(Cola *cola) {
    Cliente siguienteCliente = obtenerSiguienteCliente(cola);

    if (siguienteCliente == 0) {
        printf("No hay clientes para atender.\n");
    } else {
        printf("Atendiendo al cliente: %s, %d años\n", siguienteCliente.nombre, siguienteCliente.edad);
        desencolar(cola);
    }
}

void pagarImpuestos(float taxPaid, float amount) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // Check if the payment is for taxes
    // Assuming the taxPaid value is 1 for tax payments
    if (taxPaid == 1) {
        // Check if the payment is made at the correct cashier (cashier 2)
        // Assuming the cashier value is 2 for cashier 2
        if (cashier == 2) {
            // Extract the current date and time components
            int year = tm->tm_year + 1900;
            int month = tm->tm_mon + 1;
            int day = tm->tm_mday;
            int hour = tm->tm_hour;
            int minute = tm->tm_min;
            int second = tm->tm_sec;

            // Perform the necessary operations to record the payment
            // For example, you can print the details of the payment
            printf("Payment Date and Time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
            printf("Tax Paid: %.2f\n", amount);
        } else {
            printf("Taxes can only be paid at cashier 2.\n");
        }
    } else {
        printf("Invalid payment type.\n");
    }
}

void transferirDinero(CuentaBancaria* origen, CuentaBancaria* destino, double monto) {
    if (origen == NULL || destino == NULL) {
        printf("Error: Las cuentas no existen.\n");
        return;
    }

    if (origen->saldo < monto) {
        printf("Error: Saldo insuficiente en la cuenta de origen.\n");
        return;
    }

    origen->saldo -= monto;
    destino->saldo += monto;

    // Registra la operación en cuenta
    OperacionCuenta operacion;
    operacion.fechaHora = time(NULL);
    operacion.cheques = NULL; // Puede ser NULL ya que no se usan cheques en esta operación
    operacion.numCheques = 0;
    operacion.efectivo = monto;
    operacion.cuenta = *origen;
    realizarOperacionCuenta(operacion);

    printf("Transferencia exitosa de %.2lf pesos desde la cuenta %d a la cuenta %d.\n", monto, origen->numero, destino->numero);
}
