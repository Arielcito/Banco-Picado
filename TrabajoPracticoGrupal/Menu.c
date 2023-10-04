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
#include "ABMCajas.h"
#include "ABMCajeros.h"
#include "ABMClientes.h"
#include "ABMCuentas.h"
#include "ABMSucursales.h"
void* obtenerMemoria(size_t tamanio, const char *mensajeError);

// Prototipos de las funciones del menœ
void menuPrincipal();
void submenuABS();
void submenuCajero();
void mostarMenuCajero();
void mostrarMenuABS();
void limpiarPantalla();
void submenuCajero();
void seleccionarSucursal();
void operacionCajero();
void operacionCliente();
void generarInforme();
void configurarUsuarios();
void menuABMBanco();
void menuABMCaja();
void menuABMCajero();
void menuABMCliente();
void menuABMOperacionCuenta();
void menuABMOperacionImpuestos();
void menuABMTurno();
void menuABMCheque();
void mostrarMenuPrincipal()
{
    int opcion = 0;

    do
    {
        menuPrincipal();
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            seleccionarSucursal();
            break;
        case 2:
            do
            {
                submenuCajero();
                scanf("%d", &opcion);
                mostrarMenuCajero(opcion);
            }
            while (opcion != 0);
            opcion = ' ';
            break;
        case 3:
            operacionCliente();
            break;
        case 4:
            generarInforme();
            break;
        case 5:
            // Opción para ABM Caja
            menuABMCaja();
            break;
        case 6:
            // Opción para ABM Cajero
            menuABMCajero();
            break;
        case 7:
            // Opción para ABM Cliente
            menuABMCliente();
            break;
        case 8:
            // Opción para ABM OperacionCuenta
            menuABMOperacionCuenta();
            break;
        case 9:
            // Opción para ABM OperacionImpuestos
            menuABMOperacionImpuestos();
            break;
        case 10:
            // Opción para ABM Turno
            menuABMTurno();
            break;
        case 11:
            // Opción para ABM Cheque
            menuABMCuenta();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("\n");
            break;
        }
    }
    while (opcion != 0);
    printf("Saliendo del programa. Hasta luego!\n");
}


void mostrarMenuCajero(int opcion)
{
    switch(opcion)
    {
    case 1:
        //Llamar turno
        printf("LLamar turno\n");
        break;
    case 2:
        //Impuestos
        printf("Impuestos\n");
        break;
    case 3:
        //Movimientos de cuenta
        printf("Movimientos de cuenta\n");
        break;
    case 4:
        //Informe del cajero
        printf("Informe del cajero\n");
        break;
    case 0:
        printf("Volviendo al menu principal...");
        break;
    default:
        printf("La opcion ingresada no es correcta, intentelo nuevamente\n");
        break;
    }
}

void menuPrincipal()
{
    printf("** Menœ Principal **\n");
    printf("1. Seleccionar sucursal\n");
    printf("2. Operacion cajero\n");
    printf("3. Operacion cliente\n");
    printf("4. Informes\n");
    printf("5. ABM Cajas\n");
    printf("6. ABM Cajero\n");
    printf("7. ABM Clientes\n");
    printf("8. ABM OperacionCuenta\n");       // Add option for ABM of OperacionCuenta
    printf("9. ABM OperacionImpuestos\n");    // Add option for ABM of OperacionImpuestos
    printf("10. ABM Turno\n");                 // Add option for ABM of Turno
    printf("11. ABM Cuenta\n");              // Add option for ABM of Cheque
    printf("0. Salir\n");
}



void submenuCajero()
{
    printf("** Operacion Cajero **\n");
    printf("1. Llamar Turno\n");
    printf("2. Impuestos\n");
    printf("3. Movimientos de cuenta\n");
    printf("4. Informe del Cajero\n");
    printf("0. Volver al menu principal\n");
}


void menuABMCliente()
{
}
void menuABMCuenta()
{
    int opcion;
    Cliente* listaClientes = NULL; // Inicializa la lista de clientes
    int numClientes = 0;
    CuentaPtr listaCuentas = NULL; // Inicializa la lista de clientes
    int numCuentas = 0;
    do
    {
        mostrarMenuCuentas();
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int numeroCuenta;
            int numeroCliente;
            double saldo;

            printf("Ingrese el número de cuenta: ");
            scanf("%d", &numeroCuenta);

            altaCliente(&listaClientes, &numClientes);
            ClientePtr titular = getCabecera(&listaClientes);
            printf("Ingrese el saldo inicial de la cuenta: ");
            scanf("%lf", &saldo);

            altaCuenta(&listaCuentas, &numCuentas, numeroCuenta, *titular, saldo);

            break;
        }
        case 2:
        {
            int numeroCuenta;
            printf("Ingrese el número de cuenta a dar de baja: ");
            scanf("%d", &numeroCuenta);
            bajaCuenta(&listaCuentas, &numCuentas, numeroCuenta);
            break;
        }
        case 3:
        {
            int numeroCuenta;
            int numeroCliente;
            double saldo;

            printf("Ingrese el número de cuenta a modificar: ");
            scanf("%d", &numeroCuenta);

            printf("Ingrese el nuevo número de cliente titular de la cuenta: ");
            scanf("%d", &numeroCliente);

            // Verificar si el número de cliente es válido
            if (numeroCliente >= 0 && numeroCliente < numClientes)
            {
                ClientePtr titular = clientes[numeroCliente];

                printf("Ingrese el nuevo saldo de la cuenta: ");
                scanf("%lf", &saldo);

                modificarCuenta(&listaCuentas, &numCuentas, numeroCuenta, *titular, saldo);
            }
            else
            {
                printf("Número de cliente no válido.\n");
            }

            break;
        }
        case 4:
            mostrarCuentas(&listaCuentas, &numCuentas);
            break;
        case 5:
            printf("Volviendo al menú principal...\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            break;
        }
    }
    while (opcion != 5);
}
void menuABMSucursal()
{
    int opcion;
    SucursalPtr listaSucursales = NULL; // Inicializa la lista de clientes
    int numSucursales = 0;
    do
    {
        mostrarMenuSucursales();
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            altaSucursal(&listaSucursales, &numSucursales);
            break;
        }
        case 2:
        {
            int numeroSucursal;
            printf("Ingrese el número de sucursal a dar de baja: ");
            scanf("%d", &numeroSucursal);
            bajaSucursal(&listaSucursales, &numSucursales, numeroSucursal);
            break;
        }
        case 3:
        {
            int numeroSucursal;
            printf("Ingrese el número de sucursal a modificar: ");
            scanf("%d", &numeroSucursal);
            modificarSucursal(&listaSucursales, &numSucursales, numeroSucursal);
            break;
        }
        case 4:
            mostrarSucursales(&listaSucursales, &numSucursales);
            break;
        case 5:
            printf("Volviendo al menú principal...\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            break;
        }
    }
    while (opcion != 5);
}
void menuABMCaja()
{
    int opcion;
    CajaPtr listaCajas = NULL; // Inicializa la lista de clientes
    int numCajas = 0;
    do
    {
        printf("** Menú ABM Caja **\n");
        printf("1. Alta de caja\n");
        printf("2. Baja de caja\n");
        printf("3. Modificación de caja\n");
        printf("4. Mostrar cajas\n");
        printf("0. Volver al menú principal\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int numeroCaja;
            double montoInicial;
            printf("Ingrese el número de caja: ");
            scanf("%d", &numeroCaja);
            printf("Ingrese el monto inicial: ");
            scanf("%lf", &montoInicial);
            altaCaja(&listaCajas, &numCajas, numeroCaja, montoInicial);
            break;
        }
        case 2:
        {
            int numeroCaja;
            printf("Ingrese el número de caja a dar de baja: ");
            scanf("%d", &numeroCaja);
            bajaCaja(&listaCajas, &numCajas, numeroCaja);
            break;
        }
        case 3:
        {
            int numeroCaja;
            double nuevoMonto;
            printf("Ingrese el número de caja a modificar: ");
            scanf("%d", &numeroCaja);
            printf("Ingrese el nuevo monto inicial: ");
            scanf("%lf", &nuevoMonto);
            modificarCaja(&listaCajas, &numCajas, numeroCaja, nuevoMonto);
            break;
        }
        case 4:
            mostrarCajas(&listaCajas, &numCajas);
            break;
        case 0:
            printf("Volviendo al menú principal...\n");
            break;
        default:
            printf("Opción no válida. Inténtelo de nuevo.\n");
            break;
        }
    }
    while (opcion != 0);
}

void seleccionarSucursal()
{
    printf("Seleccionar sucursal\n");
}

void operacionCajero()
{
    printf("Operacion cajero'\n");
}

void operacionCliente()
{
    printf("You selected 'Operacion cliente'\n");
}

// Function for generating reports
void generarInforme()
{
    printf("You selected 'Informes'\n");
    // Add your code for generating reports here
}

void configurarUsuarios()
{
    printf("You selected 'ABM usuarios'\n");
}
void menuABMBanco()
{
    printf("You selected ABMBanco\n");
}


void menuABMCajero()
{
    printf("You selected ABMCajero\n");
}



void menuABMOperacionCuenta()
{
    printf("You selected ABMOperacionCuent\n");
}

void menuABMOperacionImpuestos()
{
    printf("You selected ABMOperacionImpuestos\n");
}

void menuABMTurno()
{
    printf("You selected ABMTurno\n");
}

void menuABMCheque()
{
    printf("You selected ABMCheque\n");
}
void limpiarPantalla()
{
    // Limpia la pantalla (funci—n espec’fica del sistema operativo)
    //system("clear"); // Para sistemas Unix/Linux
    system("cls"); // Para sistemas Windows
}
