#ifndef TIENDACOMPONENTES_H
#define TIENDACOMPONENTES_H
#include <vector>
#include "Cliente.h"
#include "Producto.h"

using namespace std;

class TiendaComponentes{
	private:
		vector<Cliente*> listaClientes; //variable de agregacion
		vector<Producto*> listaProducto; //variable de agregacion
	public:
		void agregarCliente(Cliente*);
		void mostrarDato();
};

#endif