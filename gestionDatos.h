#ifndef GESTION_H
#define GESTION_H

#include <fstream>
#include "TiendaComponentes.h"

class gestionDatos{
	public:
		void guardarClientes(TiendaComponentes*);
		void guardarProductos(TiendaComponentes*);
		void guardarCompras(TiendaComponentes*);
		void cargarClientes(TiendaComponentes*);
		void cargarProductos(TiendaComponentes*);
		void cargarCompras(TiendaComponentes*);
		void actualizarDatos(TiendaComponentes*);
};

#endif