#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(string _nombre,string _dni,string _telefono) : Persona(_nombre,_dni,_telefono) {
}

void Cliente::mostrarDatos() {
	mostrarPersona();
}