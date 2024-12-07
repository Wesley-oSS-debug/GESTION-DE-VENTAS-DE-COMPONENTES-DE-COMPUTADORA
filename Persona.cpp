#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona(string _nombre,string _dni,string _telefono) {
	nombre=_nombre, dni=_dni, telefono=_telefono;
}

void Persona::mostrarPersona() {
	cout<<"Nombre: "<<nombre<<endl
		<<"DNI: "<<dni<<endl
		<<"telefono: "<<telefono<<endl;
}

string Persona::obtenerDNI() {
	return dni;
}

string Persona::obtenerNombre() {
	return nombre;
}