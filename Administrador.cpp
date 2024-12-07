#include "Administrador.h"
#include <iostream>

using namespace std;

Administrador::Administrador(string _nombre,string _dni,string _telefono) : Persona(_nombre,_dni,_telefono) {}

void Administrador::mostrarAdministrador() {
	mostrarPersona();
}

void Administrador::gestionarCliente(string _nombre,string _dni,string _telefono) {
}