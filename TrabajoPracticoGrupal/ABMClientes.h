
#ifndef ABMCLIENTES_H
#define ABMCLIENTES_H

#include "cliente.h"

// Declaración de funciones para el ABM de clientes
void altaCliente(ClientePtr listaCajeros, int *numClientes);
void bajaCliente(ClientePtr listaCajeros, int *numClientes, long dni);
int modificarCliente(ClientePtr listaCajeros, int numClientes, long dni);
void mostrarClientes(ClientePtr listaCajeros, int numClientes);

void mostrarMenuClientes();
#endif // ABMCLIENTES_H
