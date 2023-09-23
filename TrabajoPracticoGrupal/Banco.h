#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#include "sucursal.h"

#define MAX_SUCURSALES 3

typedef struct
{
    SucursalPtr sucursales[MAX_SUCURSALES];
} Banco;

typedef Banco* BancoPtr;

// Crear un nuevo banco con las sucursales proporcionadas
BancoPtr crearBanco(SucursalPtr sucursales[]);

// Liberar la memoria asociada con el banco
void destruirBanco(BancoPtr banco);

#endif // BANCO_H_INCLUDED
