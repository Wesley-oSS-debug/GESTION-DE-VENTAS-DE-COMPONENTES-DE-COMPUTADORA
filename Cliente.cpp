#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(string _nombre,string _dni,string _telefono) : Persona(_nombre,_dni,_telefono) {
}

void Cliente::asignarCompras(Compra* com) {
	compras.push_back(com);
}

void Cliente::mostrarDatos() {
	mostrarPersona();
	for (int i=0;i<compras.size();i++) {
		compras[i]->mostrarVenta();
		cout<<endl;
	}
}

void Cliente::asignarIDCliente(int _id) {
	idCliente=_id;
}

int Cliente::obtenerID() {
	return idCliente;
}

vector<Compra*> Cliente::obtenerCompras() {
	return compras;
}
