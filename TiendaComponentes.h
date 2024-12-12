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
		void mostrarNombreCliente();
		void crearCompra(int,string,string,string);
		void mostrarProductos();
		void modificarCliente(string,string,string,string);
		void modificarProducto(string,string,float,int);
		void eliminarCliente(string);
		void ordenarClienAlf();
		int buscarCliente(string);
		int buscarVenta(int);
		int buscarProducto(string);
		vector<Cliente*> obtenerClientes();
		vector<Producto*> obtenerProductos();
};

#endif