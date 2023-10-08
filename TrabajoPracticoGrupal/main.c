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
#include "Cola.h"
#include "Menu.h"
#include <time.h> // Para trabajar con fechas y horas
#include <locale.h>
void* obtenerMemoria(size_t tamanio, const char *mensajeError);


int main()
{
    setlocale(LC_ALL, "");
    // Declarar una cola de turnos

    mostrarMenuPrincipal();

    return 0;
}

