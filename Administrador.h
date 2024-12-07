#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "Persona.h"


using namespace std;

class Administrador:public Persona{
	private:
		string usuario;
		string contrasenia;
	public:
		Administrador(string,string,string);
		void gestionarCliente(string,string,string);
		void mostrarAdministrador();	
};

#endif