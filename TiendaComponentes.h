#ifndef TIENDACOMPONENTES_H
#define TIENDACOMPONENTES_H
#include <vector>
#include "Cliente.h"
#include "Producto.h"
#include "Compra.h"

using namespace std;

class TiendaComponentes{
	private:
		vector<Cliente*> listaClientes; //variable de agregacion
		vector<Producto*> listaProducto; //variable de agregacion
	public:
		void agregarCliente(Cliente*);
		void agregarProducto(Producto*);
		void mostrarDato();
		void crearCompra(int,string,string,string);
		void mostrarProductos();
		int buscarCliente(string);
		int buscarProducto(string);
};

#endif