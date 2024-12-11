#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Administrador.h"
#include "TiendaComponentes.h"
#include "gestionDatos.h"
#include "Producto.h"

void agregarCliente(Administrador&,TiendaComponentes&,gestionDatos);
void realizarVenta(Administrador&,TiendaComponentes&,gestionDatos);
void agregarProductos(Administrador&,TiendaComponentes&,gestionDatos);
void mostrarVenta(TiendaComponentes);
void mostrarProducto(TiendaComponentes);

#endif