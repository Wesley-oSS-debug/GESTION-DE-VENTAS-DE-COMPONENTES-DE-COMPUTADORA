#include "Administrador.h"
#include <iostream>

using namespace std;

Administrador::Administrador(string _nombre,string _dni,string _telefono) : Persona(_nombre,_dni,_telefono) {}

void Administrador::mostrarAdministrador() {
	mostrarPersona();
}

void Administrador::gestionarCliente(TiendaComponentes* tienda,Cliente* clien) {
	tienda->agregarCliente(clien);
}

void Administrador::gestionarProducto(TiendaComponentes* tienda,Producto* prod) {
	tienda->agregarProducto(prod);
}