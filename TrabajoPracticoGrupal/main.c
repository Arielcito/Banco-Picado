#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "caja.h"
#include "cajero.h"
#include "cliente.h"
#include "OperacionCuenta.h"
#include "OperacionImpuestos.h"
#include "turno.h"
#include "cheque.h"
#include <time.h> // Para trabajar con fechas y horas
#include "Menu.c"
void* obtenerMemoria(size_t tamanio, const char *mensajeError);


int main()
{
    Sucursal* sucursal1 = crearSucursal(1, "Sucursal Plaza de Mayo");
    printf("Contenido de sucursal1: %s\n", sucursal1->domicilio);

    Caja* caja1 = crearCaja(1, 1000.00);
    printf("Contenido de caja1: ID: %d, Saldo: %.2lf\n", caja1->numeroCaja, caja1->montoInicial);
    Caja* caja2 = crearCaja(2, 1000.00);
    printf("Contenido de caja2: ID: %d, Saldo: %.2lf\n", caja2->numeroCaja, caja2->montoInicial);

    Cajero* cajero1 = crearCajero("Lo Nigro", "Matias", 2, 2);
    printf("Contenido de cajero1:\n");
    printf("Apellido: %s\n", cajero1->apellido);
    printf("Nombre: %s\n", cajero1->nombre);
    printf("ID: %d\n", cajero1->cuil);
    printf("ID de Caja: %d\n", cajero1->numeroLegajo);

    Cajero* cajero2 = crearCajero("Serato", "Ariel", 1, 1);
    printf("Contenido de cajero2:\n");
    printf("Apellido: %s\n", cajero2->apellido);
    printf("Nombre: %s\n", cajero2->nombre);
    printf("ID: %d\n", cajero2->cuil);
    printf("ID de Caja: %d\n", cajero2->numeroLegajo);

    Cliente* cliente1 = crearCliente(123456789, "López", "Juan", "Calle 123");
    Cliente* cliente2 = crearCliente(987654321, "Gómez", "María", "Avenida 456");

    Cuenta* cuenta1 = crearCuenta(1, *cliente1, 1000.0);
    Cuenta* cuenta2 = crearCuenta(2, *cliente2, 2000.0);

// Imprime la información de la cuenta 1
    printf("Información de la cuenta 1:\n");
    printf("Número de cuenta: %d\n", getNumeroCuenta(cuenta1));
    printf("Saldo: %.2lf\n", getSaldo(cuenta1));

// Imprime la información de la cuenta 2
    printf("\nInformación de la cuenta 2:\n");
    printf("Número de cuenta: %d\n", getNumeroCuenta(cuenta2));
    printf("Saldo: %.2lf\n", getSaldo(cuenta2));

// Imprime la información del titular de la cuenta 1
    printf("\nInformación del titular de la cuenta 1:\n");
    printf("DNI: %ld\n", getDniCliente(&cuenta1->titular));
    printf("Apellido: %s\n", getApellidoCliente(&cuenta1->titular));
    printf("Nombre: %s\n", getNombreCliente(&cuenta1->titular));
    printf("Domicilio: %s\n", getDomicilioCliente(&cuenta1->titular));

// Imprime la información del titular de la cuenta 2
    printf("\nInformación del titular de la cuenta 2:\n");
    printf("DNI: %ld\n", getDniCliente(&cuenta2->titular));
    printf("Apellido: %s\n", getApellidoCliente(&cuenta2->titular));
    printf("Nombre: %s\n", getNombreCliente(&cuenta2->titular));
    printf("Domicilio: %s\n", getDomicilioCliente(&cuenta2->titular));

    // Obtener la fecha y hora actual
    time_t fechaHoraActual;
    time(&fechaHoraActual);

    // Crear una operación en cuenta
    OperacionCuenta* operacion = crearOperacionCuenta(fechaHoraActual, 500.0, 300.0, cuenta1);

    // Realizar la operación en la cuenta
    double montoTotal = getMontoCheques(operacion) + getMontoEfectivo(operacion);
    double saldoAnterior = getSaldo(cuenta1);
    double nuevoSaldo = saldoAnterior + montoTotal;
    setSaldo(&cuenta1, nuevoSaldo);

    // Imprimir el resultado
    printf("\nOperación realizada en cuenta:\n");
    printf("Fecha y hora: %s", ctime(&fechaHoraActual));
    printf("Monto total: %.2lf\n", montoTotal);
    printf("Saldo anterior: %.2lf\n", saldoAnterior);
    printf("Nuevo saldo: %.2lf\n", nuevoSaldo);
    printf("Saldo: %.2lf\n", getSaldo(cuenta1));
    // Finalmente, destruir la operación si ya no se necesita
    operacion = destruirOperacionCuenta(operacion);
// Finalmente, destruye los objetos que creaste
    cliente1 = destruirCliente(cliente1);
    cliente2 = destruirCliente(cliente2);
    cuenta1 = destruirCuenta(cuenta1);
    cuenta2 = destruirCuenta(cuenta2);

    mostarMenu();

    return 0;
}

