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

// Prototipos de las funciones del menœ
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
CuentaPtr buscarCuentaPorDNI(CuentaPtr* listaCuentas, int *dni );

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

    CajeroPtr listaCajeros = crearLista(); // Inicializa la lista de clientes
    int *numCajeros = 0;

    TurnoPtr colaTurnos = crearCola();
    TurnoPtr colaTurnosPrioridad = crearCola();

    cargarSucursalesDesdeArchivo("sucursales.txt",listaSucursales);

    ClientePtr clienteMock = crearCliente(1, "Serato", "Ariel","jorge miles",22);
    altaCuenta(&listaCuentas, &numCuentas, clienteMock);
    ClientePtr clienteMock2 = crearCliente(2, "Serato", "Ariel","jorge miles",70);
    altaCuenta(&listaCuentas, &numCuentas, clienteMock2);
    ClientePtr clienteMock3 = crearCliente(3, "Serato", "Ariel","jorge miles",71);
    altaCuenta(&listaCuentas, &numCuentas, clienteMock3);

    CuentaPtr cuenta = getCabecera(&listaCuentas);
    CuentaPtr cuenta2 = getDatoLista(&listaCuentas,2);

    solicitarTurno(colaTurnos,colaTurnosPrioridad,"C",cuenta);
    solicitarTurno(colaTurnos,colaTurnosPrioridad,"I",cuenta2);

    do
    {
        SucursalPtr sucursalSeleccionada = seleccionarSucursal(listaSucursales);

        menuPrincipal(sucursalActual);
        printf("Sucursal Actual: %s \n", getDomicilio(sucursalSeleccionada));
        printf("Ingrese su opción: ");
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
                mostrarMenuCajero(opcion,colaTurnos,colaTurnosPrioridad,pilaTransacciones);
            }
            while (opcion != 0);
            opcion = ' ';
            break;
        case 3:
            operatoriaCliente(listaCuentas,colaTurnosPrioridad,&numClientes,colaTurnos);
            break;
        case 4:
            generarInforme(pilaTransacciones);
            break;
        case 5:
            // Opción para ABM Caja
            menuABMCuenta(listaClientes,listaCuentas,numClientes, numCuentas);
            break;
        case 6:
            // Opción para ABM Cajero
            menuABMSucursal(listaSucursales);
            break;
        case 7:
            // Opción para ABM Turno
            menuABMCajero();
            break;
        case 8:
            // Opción para ABM Cheque
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


void mostrarMenuCajero(int opcion, TurnoPtr colaTurnos,TurnoPtr colaTurnosPrioridad ,OperacionCuentaPtr pilaTransacciones)
{
    CuentaPtr cuentaActual = NULL;
    CajeroPtr cajero = crearCajero("serato", "Ariel",  123,  1);

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
        printf("Impuestos\n");
        break;
    case 3:

        if(&cuentaActual == NULL)
        {
            printf("Primero tiene que llamar un turno\n");
            break;
        }
        menuMovimientosDeCuenta(&cuentaActual,cajero, pilaTransacciones);
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
    printf("** Menú Principal **\n");
    printf("-------------------------\n\n");
    printf("1. Seleccionar sucursal\n");
    printf("2. Operación cajero\n");
    printf("3. Operación cliente\n");
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
    printf("** Operación Cajero **\n");
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
        printf("Ingrese su opción: ");
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

            // Verificar si el número de cliente es válido
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
                printf("Número de cliente no válido.\n");
            }

            break;
        }
        case 4:
            if(listaVacia(listaCuentas))
            {
                printf("La lista esta vacia!\n");
                break;
            }
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
void menuABMSucursal(SucursalPtr listaSucursales, int *numSucursales)
{
    int opcion;

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
            mostrarSucursales(&listaSucursales);
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
SucursalPtr seleccionarSucursal(SucursalPtr listaSucursales)
{
    int opcion = 0;
    for(int i = 0; i <3;i++){
        SucursalPtr sucursal = getDatoLista(listaSucursales,i);
        printf("%d. %s \n",i+1,getDomicilio(sucursal));
    }

    printf("Ingrese el número de sucursal: \n");
    scanf("%d", &opcion);

    SucursalPtr sucursal = getDatoLista(listaSucursales,opcion+1);
    printf("Ha seleccionado la sucursal %d. %s\n", opcion,getDomicilio(sucursal));
    return sucursal;
}
void operacionCajero()
{
    printf("Operacion cajero'\n");
}
static void mostrarMenuOperacionCliente()
{
    printf("\n** Menú de Operación Cliente **\n");
    printf("1. Solicitar turno\n");
    printf("2. Volver al menú principal\n");
}
void operatoriaCliente(CuentaPtr listaCuentas,TurnoPtr colaTurnosPriodidad ,int numClientes,TurnoPtr colaTurnos)
{
    int opcion;
    int opcionOperacion;
    CuentaPtr cuenta;

    int nroDni = 0;

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

    cuenta = buscarCuentaPorDNI(&listaCuentas,nroDni);

    char tipoOperacion;

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
        printf("Opción no válida. Inténtelo de nuevo.\n");
        break;
    }
    }
    do
    {
        mostrarMenuOperacionCliente();

        printf("Ingrese su opción: ");
        scanf("%d", &opcion);



        switch (opcion)
        {
        case 1:
        {
            solicitarTurno(colaTurnos, colaTurnosPriodidad,&tipoOperacion,cuenta);
            printf("Espere y será llamado a la brevedad\n");
            break;
        }
        case 2:
        {
            // Opción para volver al menú principal
            printf("Volviendo al menú principal...\n");
            break;
        }
        default:
        {
            printf("Opción no válida. Inténtelo de nuevo.\n");
            break;
        }
        }
    }
    while (opcion != 2);
}
CuentaPtr buscarCuentaPorDNI(CuentaPtr* listaCuentas, int *dni)
{
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,listaCuentas);

    while(!listaVacia(listaAux))
    {
        ClientePtr actualClient = getCabecera(listaAux);
        mostrarCuenta(actualClient);
        if (getDniCliente(getTitular(actualClient)) == dni)
        {
            printf("Encontrado!\n");
            return actualClient;
        }
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    printf("No se encontro el numero.\n");
    destruirLista(listaAux,false);
    printf("\n");


    return NULL;
}
void menuMovimientosDeCuenta(CuentaPtr cuenta, const char* cajero, PtrPila pilaTransacciones)
{
    int opcion;

    do
    {
        printf("\n** Movimientos de Cuenta **\n");
        printf("1. Ingresar dinero\n");
        printf("2. Retirar dinero\n");
        printf("3. Mostrar Saldo\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
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
            printf("Saliendo del menú de movimientos de cuenta.\n");
            break;
        default:
            printf("Opción no válida. Intente nuevamente.\n");
            break;
        }
    }
    while (opcion != 4);
}
// Función para generar el informe de operaciones por sucursal, cliente y cajero
void generarInforme(OperacionCuentaPtr pila) {
    /*
     // Estructura para mantener las estadísticas por sucursal
    typedef struct {
        char nombre[50];   // Nombre de la sucursal
        double total;      // Total operado por la sucursal
    } EstadisticaSucursal;

    const int MAX_SUCURSALES = 3;
    EstadisticaSucursal* listaEstadisticas = crearLista();
    int numSucursales = 0;

    // Inicializar las estadísticas
    for (int i = 0; i < MAX_SUCURSALES; i++) {
        listaEstadisticas = 0.0;
    }

    // Procesar las operaciones y calcular totales por sucursal
    while (pilaVacia(pila)) {
        OperacionCuentaPtr operacion = desapilar(pila);

        // Buscar si ya se ha registrado esta sucursal
        int indiceSucursal = -1;
        for (int i = 0; i < numSucursales; i++) {
            if (strcmp(estadisticas[i]->nombre, operacion->sucursal) == 0) {
                indiceSucursal = i;
                break;
            }
        }

        // Si no se ha registrado, agregarla a las estadísticas
        if (indiceSucursal == -1) {
            strncpy(estadisticas[numSucursales].nombre, operacion.sucursal, sizeof(estadisticas[numSucursales].nombre));
            numSucursales++;
            indiceSucursal = numSucursales - 1;
        }

        // Actualizar el total operado por la sucursal
        estadisticas[indiceSucursal].total += operacion.monto;
    }

    // Imprimir el informe
    printf("Informe de Total Operado por Sucursal:\n");
    for (int i = 0; i < numSucursales; i++) {
        printf("Sucursal: %s, Total Operado: %.2lf\n", estadisticas[i].nombre, estadisticas[i].total);
    }

    // Calcular y mostrar el total general
    double totalGeneral = 0.0;
    for (int i = 0; i < numSucursales; i++) {
        totalGeneral += estadisticas[i].total;
    }
    printf("Total General Operado en Todas las Sucursales: %.2lf\n", totalGeneral);
    */
}

void menuABMCajero()
{
    int opcion;
    CajeroPtr listaCajas = NULL; // Inicializa la lista de clientes
    int numCajas = 0;
    do
    {
        printf("** Menú ABM Cajero **\n");
        printf("1. Alta de Cajero\n");
        printf("2. Baja de Cajero\n");
        printf("3. Modificación de Cajero\n");
        printf("4. Mostrar Cajeros\n");
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

void limpiarPantalla()
{
    // Limpia la pantalla (funci—n espec’fica del sistema operativo)
    //system("clear"); // Para sistemas Unix/Linux
    system("cls"); // Para sistemas Windows
}
