#include "TiendaComponentes.h"
#include "Cliente.h"
#include "Producto.h"
#include <vector>
#include <iostream>

using namespace std;

void TiendaComponentes::agregarCliente(Cliente* clien) {
	listaClientes.push_back(clien);
}

void TiendaComponentes::agregarProducto(Producto* prod) {
	listaProducto.push_back(prod); //asignacion de referencia
}

void TiendaComponentes::mostrarDato() {
	for (int i=0;i<listaClientes.size();i++) {
		listaClientes[i]-> mostrarDatos();
		cout<<endl;
	}
}

void TiendaComponentes::mostrarProductos() {
	for (int i=0;i<listaProducto.size();i++) {
		listaProducto[i] -> mostrarProducto();
		cout<<endl;
	}
}


