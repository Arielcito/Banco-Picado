#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct
{
    long dni;
    char apellido[50];
    char nombre[50];
    char domicilio[100];
} Cliente;

typedef Cliente* ClientePtr;

// Liberar la memoria asociada con el cliente
ClientePtr destruirCliente(ClientePtr cliente);

Cliente* crearCliente(long dni, const char *apellido, const char *nombre, const char *domicilio);
// Getters & Setters
long getDniCliente(ClientePtr cliente);
char* getApellidoCliente(ClientePtr cliente);
char* getNombreCliente(ClientePtr cliente);
char* getDomicilioCliente(ClientePtr cliente);

void setDniCliente(ClientePtr cliente, long dni);
void setApellidoCliente(ClientePtr cliente,  char *apellido);
void setNombreCliente(ClientePtr cliente,  char *nombre);
void setDomicilioCliente(ClientePtr cliente,  char *domicilio);

#endif // CLIENTE_H
