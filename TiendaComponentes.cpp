#include "TiendaComponentes.h"
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
		listaClientes[i] -> mostrarDatos();
		cout<<endl;
	}
}

void TiendaComponentes::mostrarNombreCliente() {
	for (int i=0;i<listaClientes.size();i++) {
		cout<<listaClientes[i]->obtenerNombre()<<endl;
		cout<<endl;
	}
}

void TiendaComponentes::mostrarProductos() {
	for (int i=0;i<listaProducto.size();i++) {
		listaProducto[i] -> mostrarProducto();
		cout<<endl;
	}
}

int TiendaComponentes::buscarCliente(string _dni) {
	for (int i=0;i<listaClientes.size();i++) {
		if (listaClientes[i] -> obtenerDNI() == _dni) {
			return i;
		}
	}
	return -1;
} 

int TiendaComponentes::buscarProducto(string nombreP) {
	for (int i=0;i<listaProducto.size();i++) {
		if (listaProducto[i] -> obtenerNombreP() == nombreP) {
			return i;
		}
	}
	return -1;
}

void TiendaComponentes::crearCompra(int _cantidad,string _fecha, string nombreP,string _dni) {
	Compra* compra;
	Cliente* cliente;
	int indP,indC;
	indC=buscarCliente(_dni);
	indP=buscarProducto(nombreP);
	
	cliente = listaClientes[indC];
	compra = new Compra(cliente,listaProducto[indP],_cantidad,_fecha);
	listaProducto[indP]-> asignarCompras(compra,true);
	cliente->asignarCompras(compra);
}

vector<Cliente*> TiendaComponentes::obtenerClientes() {
	return listaClientes;
}

vector<Producto*> TiendaComponentes::obtenerProductos() {
	return listaProducto;
}

