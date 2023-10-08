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
#include "Pila.h"
#include "Lista.h"

void* obtenerMemoria(size_t tamanio, const char *mensajeError);

// Prototipos de las funciones del men�
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

int sucursalActual = -1;

CuentaPtr buscarCuentaPorNumero(CuentaPtr* listaCuentas, int numeroCuenta);
CuentaPtr buscarCuentaPorDNI(CuentaPtr listaCuentas, int dni);

void mostrarMenuPrincipal()
{
    int opcion = 0;

    SucursalPtr listaSucursales = crearLista(); // Inicializa la lista de clientes
    int numSucursales = 0;

    OperacionCuentaPtr pilaTransacciones = crearPila();

    Cliente* listaClientes = crearLista(); // Inicializa la lista de clientes
    int *numClientes = 0;

    CuentaPtr listaCuentas = crearLista(); // Inicializa la lista de clientes
    int *numCuentas = 0;

    TurnoPtr colaTurnos = crearCola();

    do
    {
        menuPrincipal();
        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            seleccionarSucursal(listaSucursales);
            break;
        case 2:
            do
            {
                submenuCajero();
                scanf("%d", &opcion);
                mostrarMenuCajero(opcion,colaTurnos);
            }
            while (opcion != 0);
            opcion = ' ';
            break;
        case 3:
            operatoriaCliente(listaCuentas);
            break;
        case 4:
            generarInforme();
            break;
        case 5:
            // Opci�n para ABM Caja
            menuABMCuenta(listaClientes,listaCuentas,numClientes, numCuentas);
            break;
        case 6:
            // Opci�n para ABM Cajero
            menuABMSucursal(listaSucursales);
            break;
        case 7:
            // Opci�n para ABM Turno
            menuABMCajero();
            break;
        case 8:
            // Opci�n para ABM Cheque
            menuABMCaja();
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("\n");
            break;
        }
    }
    while (opcion != 0);
    printf("Saliendo del programa. Hasta luego!\n");
}


void mostrarMenuCajero(int opcion, TurnoPtr colaTurnos)
{
    switch(opcion)
    {
    case 1:
        //Llamar turno
        llamarProximoTurno(colaTurnos);
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
    printf("\n-------------------------\n");
    printf("** Men� Principal **\n");
    printf("-------------------------\n\n");
    printf("1. Seleccionar sucursal\n");
    printf("2. Operaci�n cajero\n");
    printf("3. Operaci�n cliente\n");
    printf("4. Informes\n");
    printf("5. ABM Cuenta\n");
    printf("6. ABM Sucursal\n");
    printf("7. ABM Cajero\n");
    printf("8. ABM Cajas\n");
    printf("0. Salir\n");
}

void submenuCajero()
{
    printf("-------------------------\n");
    printf("** Operaci�n Cajero **\n");
    printf("-------------------------\n\n");
    printf("1. Llamar Turno\n");
    printf("2. Impuestos\n");
    printf("3. Movimientos de cuenta\n");
    printf("4. Informe del Cajero\n");
    printf("0. Volver al menu principal\n");
}

void menuABMCuenta(ClientePtr* listaClientes, CuentaPtr* listaCuentas, int *numClientes, int *numCuentas)
{
    int opcion;

    do
    {
        mostrarMenuCuentas();
        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int numeroCuenta;
            int numeroCliente;
            double saldo;

            altaCliente(&listaClientes, &numClientes);
            ClientePtr titular = getCabecera(&listaClientes);

            altaCuenta(&listaCuentas, &numCuentas, titular);

            break;
        }
        case 2:
        {
            int numeroCuenta;
            printf("Ingrese el n�mero de cuenta a dar de baja: ");
            scanf("%d", &numeroCuenta);
            bajaCuenta(&listaCuentas, &numCuentas, numeroCuenta);
            break;
        }
        case 3:
        {
            int numeroCuenta;
            int numeroCliente;
            double saldo;

            printf("Ingrese el n�mero de cuenta a modificar: ");
            scanf("%d", &numeroCuenta);

            // Verificar si el n�mero de cliente es v�lido
            if (numeroCuenta >= 0 && numeroCuenta < 100)
            {
                for (int i = 1; i <= numClientes; i++)
                {
                    CuentaPtr cuentaActual = getDatoLista(&listaCuentas,i);

                    if (getNumeroCuenta(cuentaActual) == numeroCuenta)
                    {
                        modificarCliente(&listaCuentas, &numCuentas, getTitular(cuentaActual));
                        break; // Salir del bucle una vez que se ha encontrado y eliminado la cuenta
                    }
                }
                printf("No se encontro el numero.\n");
            }
            else
            {
                printf("N�mero de cliente no v�lido.\n");
            }

            break;
        }
        case 4:
            mostrarCuentas(&listaCuentas, &numCuentas);
            break;
        case 5:
            printf("Volviendo al men� principal...\n");
            break;
        default:
            printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
            break;
        }
    }
    while (opcion != 5);
}
void menuABMSucursal(SucursalPtr listaSucursales, int *numSucursales)
{
    int opcion;

    do
    {
        mostrarMenuSucursales();
        printf("Ingrese su opci�n: ");
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
            printf("Ingrese el n�mero de sucursal a dar de baja: ");
            scanf("%d", &numeroSucursal);
            bajaSucursal(&listaSucursales, &numSucursales, numeroSucursal);
            break;
        }
        case 3:
        {
            int numeroSucursal;
            printf("Ingrese el n�mero de sucursal a modificar: ");
            scanf("%d", &numeroSucursal);
            modificarSucursal(&listaSucursales, &numSucursales, numeroSucursal);
            break;
        }
        case 4:
            mostrarSucursales(&listaSucursales);
            break;
        case 5:
            printf("Volviendo al men� principal...\n");
            break;
        default:
            printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
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
        printf("** Men� ABM Caja **\n");
        printf("1. Alta de caja\n");
        printf("2. Baja de caja\n");
        printf("3. Modificaci�n de caja\n");
        printf("4. Mostrar cajas\n");
        printf("0. Volver al men� principal\n");
        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int numeroCaja;
            double montoInicial;
            printf("Ingrese el n�mero de caja: ");
            scanf("%d", &numeroCaja);
            printf("Ingrese el monto inicial: ");
            scanf("%lf", &montoInicial);
            altaCaja(&listaCajas, &numCajas, numeroCaja, montoInicial);
            break;
        }
        case 2:
        {
            int numeroCaja;
            printf("Ingrese el n�mero de caja a dar de baja: ");
            scanf("%d", &numeroCaja);
            bajaCaja(&listaCajas, &numCajas, numeroCaja);
            break;
        }
        case 3:
        {
            int numeroCaja;
            double nuevoMonto;
            printf("Ingrese el n�mero de caja a modificar: ");
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
            printf("Volviendo al men� principal...\n");
            break;
        default:
            printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
            break;
        }
    }
    while (opcion != 0);
}

void seleccionarSucursal(SucursalPtr listaSucursales)
{
    mostrarSucursales(&listaSucursales);
    printf("Ingrese el n�mero de sucursal: ");
    scanf("%d", &sucursalActual);
    printf("Ha seleccionado la sucursal %d.\n", sucursalActual);
}

void operacionCajero()
{
    printf("Operacion cajero'\n");
}

/*static void mostrarMenuOperacionCliente()
{
    printf("\n** Men� de Operaci�n Cliente **\n");
    printf("1. Consultar saldo\n");
    printf("2. Realizar retiro\n");
    printf("3. Realizar dep�sito\n");
    printf("4. Consultar movimientos\n");
    printf("5. Volver al men� principal\n");
}
*/

static void mostrarMenuOperacionCliente()
{
    printf("\n** Men� de Operaci�n Cliente **\n");
    printf("1. Solicitar turno\n");
    printf("2. Volver al men� principal\n");
}
/*void operacionCliente(OperacionCuentaPtr pilaTransacciones, CuentaPtr listaCuentas)
{

    int opcion;

    do {
        CuentaPtr cuenta;
        CajeroPtr cajero;
        int *nroCuenta = 0;

        printf("Ingrese su nro de cuenta: ");
        scanf("%d", &nroCuenta);

        if(nroCuenta < 0 || nroCuenta > 100){
            printf("Numero cuenta invalido! ");
        }

        cuenta = buscarCuentaPorNumero(&listaCuentas,&nroCuenta);

        printf("Apellido: %s", getApellidoCliente(getTitular(cuenta)));

        mostrarMenuOperacionCliente();

        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                // Opci�n para consultar saldo
                // consultarSaldo(cuenta);
                printf("Numero cuenta invalido! ");
                break;
            }
            case 2: {
                // Opci�n para realizar un retiro
                retirarDinero(cuenta, cajero, pilaTransacciones);
                break;
            }
            case 3: {
                // Opci�n para ingresar dinero
                ingresarDinero(cuenta, cajero, pilaTransacciones);
                break;
            }
            case 4: {
                // Opci�n para consultar movimientos
                //consultarMovimientos(pilaTransacciones);
                 printf("Numero cuenta invalido! ");
                break;
            }
            case 5: {
                // Opci�n para volver al men� principal
                printf("Volviendo al men� principal...\n");
                break;
            }
            default: {
                printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
                break;
            }
        }
    } while (opcion != 5);

}
*/

void operatoriaCliente(CuentaPtr* listaCuentas){
    int opcion;

     do {
        CuentaPtr cuenta;

        int nroDni = 0;

        printf("Ingrese su numero de DNI: ");
        scanf("%d", &nroDni);
        cuenta = getDatoLista(listaCuentas,1);
        printf("%d", getNumeroCorrelativo(cuenta));

        if(nroDni < 0){
            printf("Numero cuenta invalido! ");
             break;
        }

        if(listaVacia(&listaCuentas)){
            printf("No hay cuentas registradas con ese dni! ");
            break;
        }

        cuenta = buscarCuentaPorDNI(&listaCuentas,nroDni);

        printf("Apellido: %s", getApellidoCliente(getTitular(cuenta)));

        mostrarMenuOperacionCliente();

        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                solicitarTurno();
                 printf("Espere y ser� llamado a la brevedad");
                break;
            }
            case 2: {
                // Opci�n para volver al men� principal
                printf("Volviendo al men� principal...\n");
                break;
            }
            default: {
                printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
                break;
            }
        }
    } while (opcion != 2);
}
/*
CuentaPtr buscarCuentaPorNumero(CuentaPtr* listaCuentas, int numeroCuenta) {
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,listaCuentas);

    while (!listaVacia(listaAux)) {
        CuentaPtr cuentaActual = getCabecera(listaAux);
        if (getNumeroCuenta(cuentaActual) == numeroCuenta) {
            printf("Encontrado.\n");
            return cuentaActual; // Devuelve la cuenta si se encuentra
        }

        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }

    destruirLista(listaAux,false);
    return NULL; // Devuelve NULL si no se encuentra la cuenta
}
*/
CuentaPtr buscarCuentaPorDNI(CuentaPtr listaCuentas, int dni) {
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,listaCuentas);

    while (!listaVacia(listaAux)) {
        CuentaPtr cuentaActual = getCabecera(listaAux);
         printf("%d",getDniCliente(getTitular(cuentaActual)));
        if (getDniCliente(getTitular(cuentaActual)) == dni) {
            printf("Encontrado.\n");
            return cuentaActual; // Devuelve la cuenta si se encuentra
        }

        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }

    printf("No se pudo encontrar un cuenta con ese DNI.\n");
    destruirLista(listaAux,false);
    return NULL; // Devuelve NULL si no se encuentra la cuenta
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
    // Limpia la pantalla (funci�n espec�fica del sistema operativo)
    //system("clear"); // Para sistemas Unix/Linux
    system("cls"); // Para sistemas Windows
}
