#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Administrador.h"
#include "TiendaComponentes.h"
#include "Producto.h"

void agregarCliente(Administrador&,TiendaComponentes&);
void realizarVenta(Administrador&,TiendaComponentes&);
void agregarProductos(Administrador&,TiendaComponentes&);
void mostrarVenta(TiendaComponentes);
void mostrarProducto(TiendaComponentes);
void mostrarCliente(TiendaComponentes);
void modificarCliente(Administrador&,TiendaComponentes&);
void modificarProducto(Administrador&,TiendaComponentes&);
void mostrarClienAlf(TiendaComponentes);
void mostrarMaxVent(TiendaComponentes);

#endif