
#ifndef ABMCLIENTES_H
#define ABMCLIENTES_H

#include "cliente.h"

// Declaración de funciones para el ABM de clientes
void altaCliente(ClientePtr clientes[], int *numClientes);
void bajaCliente(ClientePtr clientes[], int *numClientes, long dni);
void modificarCliente(ClientePtr clientes[], int numClientes, long dni);
void mostrarClientes(ClientePtr clientes[], int numClientes);

void mostrarMenuClientes();
#endif // ABMCLIENTES_H
