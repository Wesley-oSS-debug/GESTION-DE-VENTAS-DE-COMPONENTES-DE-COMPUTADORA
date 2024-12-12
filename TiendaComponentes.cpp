#include "TiendaComponentes.h"
#include <vector>
#include <iostream>

using namespace std;

void TiendaComponentes::agregarCliente(Cliente* clien) {
	listaClientes.push_back(clien);
	clien->aumentarID();
}

void TiendaComponentes::agregarProducto(Producto* prod) {
	listaProducto.push_back(prod); //asignacion de referencia
	prod->aumentarID(); 
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
		cout<<listaClientes[i]->obtenerID()<<endl;
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

void TiendaComponentes::modificarCliente(string _dni,string _nombre,string _nuevoDni,string _telefono) {
	int indC=buscarCliente(_dni);
	listaClientes[indC]->asignarNombre(_nombre);
	listaClientes[indC]->asignarDNI(_nuevoDni);
	listaClientes[indC]->asignarTelefono(_telefono);
	
}

void TiendaComponentes::modificarProducto(string _nombre,string nuevoNombre,float _precio,int _stock) {
	int indP=buscarProducto(_nombre);
	listaProducto[indP]->asignarNombre(nuevoNombre);
	listaProducto[indP]->asignarPrecio(_precio);
	listaProducto[indP]->asignarStock(_stock);
}

void TiendaComponentes::eliminarCliente(string _dni) {
	int indC=buscarCliente(_dni);
	listaClientes.erase(listaClientes.begin()+indC);
}

void TiendaComponentes::eliminarProducto(string _nombre) {
	int indP=buscarProducto(_nombre);
	listaProducto.erase(listaProducto.begin()+indP);
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
	compra->aumentarID();
}

vector<Cliente*> TiendaComponentes::obtenerClientes() {
	return listaClientes;
}

vector<Producto*> TiendaComponentes::obtenerProductos() {
	return listaProducto;
}

