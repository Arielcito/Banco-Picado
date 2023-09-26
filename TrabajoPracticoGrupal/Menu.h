#ifndef MENU_H
#define MENU_H

// Prototipos de las funciones
void* obtenerMemoria(size_t tamanio, const char *mensajeError);
int mostrarMenuPrincipal();
void submenuABS();
void submenuCajero();
void mostarMenuCajero(int opcion);
void mostrarMenuABS(int opcion);
void limpiarPantalla();
void submenuAltas();
void seleccionarSucursal();
void operacionCajero();
void operacionCliente();
void generarInforme();
void configurarUsuarios();

#endif // MENU_H
