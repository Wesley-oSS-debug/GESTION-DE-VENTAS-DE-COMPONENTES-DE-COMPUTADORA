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

void Administrador::gestionarCompra(TiendaComponentes* tienda,int _cantidad,string _fecha,string _dni,string nombreP) {
	tienda->crearCompra(_cantidad,_fecha,nombreP,_dni);
}

void Administrador::editarCliente(TiendaComponentes* tienda,string _dni,string _nombre,string _nuevoDni,string _telefono) {
	tienda->modificarCliente(_dni,_nombre,_nuevoDni,_telefono);
}

void Administrador::editarProducto(TiendaComponentes* tienda,string _nombre,int _stock,string nuevoNombre,float _precio) {
	tienda->modificarProducto(_nombre,nuevoNombre,_precio,_stock);
}

void Administrador::asignarUsuario(string user) {
	usuario=user;
}

void Administrador::asignarContrasenia(string password) {
	contrasenia=password;
}

bool Administrador::verificarCredenciales(string user,string password) {
	if (user==usuario && password==contrasenia) {
		return true;
	} else {
		return false;
	}
}