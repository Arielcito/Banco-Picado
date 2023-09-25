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

int mostarMenu()
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
            while(opcion!=0);
            break;
        case 3:
            operacionCliente();
            break;
        case 4:
            generarInforme();
            break;
        case 5:
            do{
                submenuABS();
                scanf("%d", &opcion);
                mostrarMenuABS();
            }while(opcion!=0);
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
    printf("Saliendo del programa. ÁHasta luego!\n");
    return 0;
}

void menuPrincipal()
{
    printf("** Menœ Principal **\n");
    printf("1. Seleccionar sucursal\n");
    printf("2. Operacion cajero\n");
    printf("3. Operacion cliente\n");
    printf("4. Informes\n");
    printf("5. ABM usuarios\n");
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

void submenuABS()
{
    printf("** Menu ABS **");
    printf("1. Altas\n");
    printf("2. Bajas\n");
    printf("3. Modificaciones\n");
    printf("0. Volver al menu principal\n");
}

void mostarMenuCajero(int opcion)
{
    switch(opcion){
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

void mostrarMenuABS(int opcion){
    switch(opcion){
    case 1:
        //Altas
        printf("Altas");
        break;
    case 2:
        //Bajas
        printf("Bajas");
        break;
    case 3:
        //Modificaciones
        printf("Modificaciones");
        break;
    case 0:
        printf("Volviendo al menu principal");
        break;
    default:
        printf("La opcion ingresada no es correcta, intentelo nuevamente");
        break;
    }
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

void limpiarPantalla()
{
    // Limpia la pantalla (funci—n espec’fica del sistema operativo)
    //system("clear"); // Para sistemas Unix/Linux
    system("cls"); // Para sistemas Windows
}

