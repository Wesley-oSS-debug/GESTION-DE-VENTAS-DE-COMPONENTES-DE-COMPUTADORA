#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Administrador.h"
#include "TiendaComponentes.h"

void agregarCliente(Administrador&,TiendaComponentes&);
void realizarVenta(Administrador&,TiendaComponentes&);
void agregarProductos(Administrador&,TiendaComponentes&);
void mostrarVenta(TiendaComponentes);

#endif