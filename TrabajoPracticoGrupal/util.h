
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
// Función de obtención de memoria
// Precondición: Ninguna
// Postcondición: Se reserva la memoria solicitada o se detiene el programa con un mensaje de error si no se pudo.
// Parámetros:
// tamanio: Tamaño de la memoria a reservar en size_t
// mensajeError: Mensaje personalizado para mostrar en caso de error.
// Devuelve void* apuntando a la memoria reservada.
void* obtenerMemoria(size_t tamanio, const char *mensajeError);
#endif // UTIL_H_INCLUDED
