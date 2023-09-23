#include "banco.h"
#include <stdlib.h>

BancoPtr crearBanco(SucursalPtr sucursales[]) {
    BancoPtr banco = (BancoPtr)obtenerMemoria(sizeof(Banco), "Error al crear un nuevo banco");

    for (int i = 0; i < MAX_SUCURSALES; i++) {
        banco->sucursales[i] = sucursales[i];
    }

    // Otras inicializaciones del banco si es necesario

    return banco;
}

void destruirBanco(BancoPtr banco) {
    free(banco);
}
