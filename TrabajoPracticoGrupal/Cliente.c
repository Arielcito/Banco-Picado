#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* crearCliente(long dni, const char *apellido, const char *nombre, const char *domicilio, int edad) {
    Cliente *cliente = (Cliente*)obtenerMemoria(sizeof(Cliente), "Error al crear un nuevo cliente");
    cliente->dni = dni;
    cliente->edad = edad;
    strncpy(cliente->apellido, apellido, sizeof(cliente->apellido));
    strncpy(cliente->nombre, nombre, sizeof(cliente->nombre));
    strncpy(cliente->domicilio, domicilio, sizeof(cliente->domicilio));
    // Inicializar otros campos si es necesario
    return cliente;
}

ClientePtr destruirCliente(ClientePtr cliente) {
    free(cliente);
    return cliente;
}

// Getter para el DNI del cliente
long getDniCliente(ClientePtr cliente) {
    return cliente->dni;
}

// Getter para el apellido del cliente
 char* getApellidoCliente(ClientePtr cliente) {
    return cliente->apellido;
}

// Getter para el nombre del cliente
 char* getNombreCliente(ClientePtr cliente) {
    return cliente->nombre;
}

// Getter para el domicilio del cliente
char* getDomicilioCliente(ClientePtr cliente) {
    return cliente->domicilio;
}

int getEdadCliente(ClientePtr cliente){
    return cliente->edad;
}

// Setter para el DNI del cliente
void setDniCliente(ClientePtr cliente, long dni) {
    cliente->dni = dni;
}

// Setter para el apellido del cliente
void setApellidoCliente(ClientePtr cliente, char *apellido) {
    strncpy(cliente->apellido, apellido, sizeof(cliente->apellido));
}

// Setter para el nombre del cliente
void setNombreCliente(ClientePtr cliente, char *nombre) {
    strncpy(cliente->nombre, nombre, sizeof(cliente->nombre));
}

// Setter para el domicilio del cliente
void setDomicilioCliente(ClientePtr cliente, char *domicilio) {
    strncpy(cliente->domicilio, domicilio, sizeof(cliente->domicilio));
}


void setEdadCliente(ClientePtr cliente, int edad){
     cliente->edad;
}

void cargarClientesDesdeArchivo(const char *nombreArchivo, ClientePtr listaClientes)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        exit(1);
    }

    char linea[100];
    Cliente *cliente;

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        long dni;
        char apellido[100];
        char nombre[100];
        char domicilio[100];
        int edad;

        if (sscanf(linea, "%ld %99s %99s %99s %d", &dni, apellido, nombre, domicilio, &edad) == 5)
        {
            cliente = crearCliente(dni, apellido, nombre, domicilio, edad);
            // Agregar el cliente a la lista
            agregarDatoLista(listaClientes, cliente);
        }
    }

    fclose(archivo);
}
