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

// Prototipos de las funciones del menú
void mostrarMenu();
void gestionarBanco();
void gestionarCaja();
void gestionarCajero();
void gestionarCliente();
void gestionarOperacionCuenta();
void gestionarOperacionImpuestos();
void gestionarCheque();
void gestionarTurno();
void limpiarPantalla();

int main() {
    int opcion;

    do {
        mostrarMenu();
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case '1':
                seleccionarSucursal();
                break;
            case '2':
                operacionCajero();
                break;
            case '3':
                operacionCliente();
                break;
            case '4':
                generarInforme();
                break;
            case '5':
                configurarUsuarios();
                break;
            case '0':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        limpiarPantalla();
    } while (opcion != 8);
    printf("Saliendo del programa. ¡Hasta luego!\n");
    return 0;
}

void mostrarMenu() {
    printf("****** Menú Principal ******\n");
    printf("1. Seleccionar sucursal\n");
    printf("2. Operacion cajero\n");
    printf("3. Operacion cliente\n");
    printf("4. Informes\n");
    printf("5. ABM usuarios\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

// Function for selecting a branch
void seleccionarSucursal() {
    printf("You selected 'Seleccionar sucursal'\n");
    // Add your code for selecting a branch here
}

// Function for cashier operation
void operacionCajero() {
    printf("You selected 'Operacion cajero'\n");
    // Add your code for cashier operation here
}

// Function for client operation
void operacionCliente() {
    printf("You selected 'Operacion cliente'\n");
    // Add your code for client operation here
}

// Function for generating reports
void generarInforme() {
    printf("You selected 'Informes'\n");
    // Add your code for generating reports here
}

// Function for user management
void configurarUsuarios() {
    printf("You selected 'ABM usuarios'\n");
    // Add your code for user management here
}

void limpiarPantalla() {
    // Limpia la pantalla (función específica del sistema operativo)
    //system("clear"); // Para sistemas Unix/Linux
    system("cls"); // Para sistemas Windows
}
