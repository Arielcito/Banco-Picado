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
SucursalPtr seleccionarSucursal();
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
void menuMovimientosDeCuenta();
int sucursalActual = -1;

CuentaPtr buscarCuentaPorNumero(CuentaPtr* listaCuentas, int numeroCuenta);
CuentaPtr buscarCuentaPorDNI(CuentaPtr* listaCuentas, int *dni, int *numCuentas,int *encontrado);

void mostrarMenuPrincipal()
{
    int opcion = 0;

    SucursalPtr listaSucursales = crearLista(); // Inicializa la lista de sucursales
    int numSucursales = 0;

    OperacionCuentaPtr pilaTransacciones = crearPila();

    Cliente* listaClientes = crearLista(); // Inicializa la lista de clientes
    int *numClientes = 0;

    CuentaPtr listaCuentas = crearLista(); // Inicializa la lista de clientes
    int *numCuentas = 0;

    TurnoPtr colaTurnos = crearCola();
    TurnoPtr colaTurnosPrioridad = crearCola();

    cargarSucursalesDesdeArchivo("sucursales.txt",listaSucursales);

    cargarClientesDesdeArchivo("clientes.txt",listaClientes);

    for (int i = 0; i < longitudLista(listaClientes); i++)
    {
        ClientePtr cliente = (ClientePtr)getDatoLista(listaClientes, i);
        altaCuenta(&listaCuentas, &numCuentas, cliente);
    }

    CuentaPtr cuenta = getCabecera(&listaCuentas);
    CuentaPtr cuenta2 = getDatoLista(&listaCuentas,2);

    solicitarTurno(colaTurnos,colaTurnosPrioridad,"C",cuenta);
    solicitarTurno(colaTurnos,colaTurnosPrioridad,"I",cuenta2);
    limpiarPantalla();

    do
    {
        SucursalPtr sucursalSeleccionada = NULL;
        do
        {
            sucursalSeleccionada = seleccionarSucursal(listaSucursales);
        }
        while(sucursalSeleccionada == NULL);

        menuPrincipal(sucursalActual);

        printf("Sucursal Actual: %s \n", getDomicilio(sucursalSeleccionada));
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
                mostrarMenuCajero(opcion,colaTurnos,colaTurnosPrioridad,pilaTransacciones,numClientes);
            }
            while (opcion != 0);
            opcion = ' ';
            break;
        case 3:

            operatoriaCliente(listaCuentas,colaTurnosPrioridad,numCuentas,colaTurnos);
            break;
        case 4:
            generarInforme(pilaTransacciones);
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
            limpiarPantalla();
            break;
        default:
            printf("\n");
            break;
        }
    }
    while (opcion != 0);
    printf("Saliendo del programa. Hasta luego!\n");
}

static void mostrarMenuOperacionCliente()
{
    printf("-------------------------\n\n");
    printf("\n** Men� de Operaci�n Cliente **\n");
    printf("-------------------------\n\n");
    printf("1. Solicitar turno\n");
    printf("2. Volver al men� principal\n");
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

void mostrarMenuCajero(int opcion, TurnoPtr colaTurnos,TurnoPtr colaTurnosPrioridad,OperacionCuentaPtr pilaTransacciones, int numClientes)
{
    CuentaPtr cuentaActual = NULL;

    CajeroPtr listaCajeros = crearLista();
    int *numCajeros = 0;

    cargarCajerosDesdeArchivo("cajeros.txt",listaCajeros);

    CajeroPtr cajeroMovimientos = (CajeroPtr)getDatoLista(listaCajeros, 0);
    CajeroPtr cajeroImpuestos = (CajeroPtr)getDatoLista(listaCajeros, 1);

    switch(opcion)
    {
    case 1:
        //Llamar turno
        cuentaActual = llamarProximoTurno(colaTurnos,colaTurnosPrioridad);

        break;
    case 2:
        //Impuestos

        if(&cuentaActual == NULL)
        {
            printf("Primero tiene que llamar un turno\n");
            break;
        }
        menuImpuestos(&cuentaActual,cajeroImpuestos,pilaTransacciones);
        break;
    case 3:

        if(&cuentaActual == NULL)
        {
            printf("Primero tiene que llamar un turno\n");
            break;
        }
        menuMovimientosDeCuenta(&cuentaActual,cajeroMovimientos, pilaTransacciones);
        break;
    case 4:
        //Informe del cajero
        mostrarInformes(pilaTransacciones);
        break;
    case 0:
        printf("Volviendo al menu principal...");
        limpiarPantalla();
        break;
    default:
        printf("La opcion ingresada no es correcta, intentelo nuevamente\n");
        break;
    }
}

void menuABMCuenta(ClientePtr* listaClientes, CuentaPtr listaCuentas, int *numClientes, int *numCuentas)
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
            int indiceEncontrado = -1;
            double saldo;

            printf("Ingrese el n�mero de cuenta a modificar: ");
            scanf("%d", &numeroCuenta);

            // Verificar si el n�mero de cliente es v�lido
            if (numeroCuenta >= 0 && numeroCuenta < 100)
            {
                printf("%d",numCuentas);
                for (int i = 1; i <= numCuentas; i++)
                {
                    CuentaPtr cuentaActual = getDatoLista(&listaCuentas,i);

                    if (getNumeroCuenta(cuentaActual) == numeroCuenta)
                    {
                        indiceEncontrado = modificarCliente(&listaCuentas, &numCuentas, getTitular(cuentaActual));
                        break; // Salir del bucle una vez que se ha encontrado y eliminado la cuenta
                    }
                }
                if(indiceEncontrado == -1){
                    printf("No se encontro el numero.\n");
                }
            }
            else
            {
                printf("N�mero de cliente no v�lido.\n");
            }

            break;
        }
        case 4:
            if(listaVacia(listaCuentas))
            {
                printf("La lista esta vacia!\n");
                break;
            }

            mostrarCuentas(&listaCuentas,numCuentas);

            break;
        case 5:
            printf("Volviendo al men� principal...\n");
            limpiarPantalla();
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
            limpiarPantalla();
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
    CajaPtr listaCajas = NULL;
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
            limpiarPantalla();
            break;
        default:
            printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
            break;
        }
    }
    while (opcion != 0);
}
SucursalPtr seleccionarSucursal(SucursalPtr listaSucursales)
{
    int opcion = 0;
    for(int i = 0; i <3; i++)
    {
        SucursalPtr sucursal = getDatoLista(listaSucursales,i);
        printf("%d. %s \n",i,getDomicilio(sucursal));
    }

    printf("Ingrese el n�mero de sucursal: \n");
    scanf("%d", &opcion);
    if(opcion > 2)
    {
        printf("Opcion incorrecta!!\n");
        return NULL;

    }
    SucursalPtr sucursal = getDatoLista(listaSucursales,opcion);
    printf("Ha seleccionado la sucursal %d. %s\n", opcion,getDomicilio(sucursal));
    return sucursal;
}


void operatoriaCliente(CuentaPtr listaCuentas,TurnoPtr colaTurnosPriodidad,int numClientes,TurnoPtr colaTurnos)
{
    int opcion;
    int opcionOperacion;
    CuentaPtr cuenta = NULL;

    int nroDni = 0;

    int encontrado = 0; // Variable para almacenar la bandera
    do
    {
        printf("\nIngrese su numero de DNI: ");
        scanf("%d", &nroDni);
        if(nroDni < 0)
        {
            printf("Numero cuenta invalido! ");
        }

        if(listaVacia(listaCuentas))
        {
            printf("No hay cuentas registradas con ese dni! ");
        }

        cuenta = buscarCuentaPorDNI(&listaCuentas,nroDni,numClientes,&encontrado);

        if(encontrado == 1){
            break;
        }
    }
    while(encontrado == 0);

    char* tipoOperacion;

    printf("1. Impuestos\n");
    printf("2. Movimientos\n");

    printf("Ingrese la operacion que desea realizar: \n");
    scanf("%d", &opcionOperacion);

    switch (opcionOperacion)
    {
    case 1:
    {
        tipoOperacion = "I";
        break;
    }
    case 2:
    {
        tipoOperacion = "C";
        break;
    }
    default:
    {
        printf("Opci�n no v�lida. Int�ntelo de nuevo.\n");
        break;
    }
    }
    do
    {
        mostrarMenuOperacionCliente();

        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            solicitarTurno(colaTurnos, colaTurnosPriodidad,tipoOperacion,cuenta);
            printf("Espere y ser� llamado a la brevedad\n");
            break;
        }
        case 2:
        {
            // Opci�n para volver al men� principal
            printf("Volviendo al men� principal...\n");
            limpiarPantalla();
            break;
        }

        }
    }
    while (opcion != 2);
}
CuentaPtr buscarCuentaPorDNI(CuentaPtr* listaCuentas, int *dni, int *numCuentas, int *encontrado)
{
    CuentaPtr actualClient = NULL;

    for (int i = 0; i < numCuentas; i++)
    {
        actualClient = getDatoLista(listaCuentas, i);

        if (getDniCliente(getTitular(actualClient)) == dni)
        {
            printf("Hola %s %s!\n", getApellidoCliente(getTitular(actualClient)), getNombreCliente(getTitular(actualClient)));
            *encontrado = 1; // Establece la bandera en 1 (encontrado)
            return actualClient;
        }
    }

    printf("No se encontr� el n�mero.\n");
    *encontrado = 0; // Establece la bandera en 0 (no encontrado)

    return actualClient;
}


void menuMovimientosDeCuenta(CuentaPtr cuenta, CajeroPtr cajero, PtrPila pilaTransacciones)
{
    int opcion;

    do
    {
        printf("\n** Movimientos de Cuenta **\n");
        printf("1. Ingresar dinero\n");
        printf("2. Retirar dinero\n");
        printf("3. Mostrar Saldo\n");
        printf("4. Mostrar Informes\n");
        printf("5. Salir\n");
        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            ingresarDinero(cuenta,cajero,pilaTransacciones);
            break;
        case 2:
            retirarDinero(cuenta,cajero,pilaTransacciones);
            break;
        case 3:
            consultarSaldo(cuenta);

            break;
        case 4:
            mostrarInformes(pilaTransacciones);
            break;
        case 5:
            printf("Saliendo del men� de movimientos de cuenta.\n");
            limpiarPantalla();
            break;
        default:
            printf("Opci�n no v�lida. Intente nuevamente.\n");
            break;
        }
    }
    while (opcion != 5);
}
// Funci�n para generar el informe de operaciones por sucursal, cliente y cajero
void generarInforme(OperacionCuentaPtr pila)
{

}

void menuABMCajero()
{
    int opcion;
    CajeroPtr listaCajas = NULL; // Inicializa la lista de clientes
    int numCajas = 0;
    do
    {
        printf("** Men� ABM Cajero **\n");
        printf("1. Alta de Cajero\n");
        printf("2. Baja de Cajero\n");
        printf("3. Modificaci�n de Cajero\n");
        printf("4. Mostrar Cajeros\n");
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

void limpiarPantalla()
{
    // Limpia la pantalla (funci�n espec�fica del sistema operativo)
    //system("clear"); // Para sistemas Unix/Linux
    system("cls"); // Para sistemas Windows
}
