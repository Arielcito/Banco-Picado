#include "cliente.h"
#include <stdlib.h>
#include <string.h>

Cliente* crearCliente(long dni, const char *apellido, const char *nombre, const char *domicilio) {
    Cliente *cliente = (Cliente*)obtenerMemoria(sizeof(Cliente), "Error al crear un nuevo cliente");
    cliente->dni = dni;
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
