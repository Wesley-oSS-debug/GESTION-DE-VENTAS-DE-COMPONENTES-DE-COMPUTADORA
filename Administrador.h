#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "Persona.h"
#include "TiendaComponentes.h"


using namespace std;

class Administrador:public Persona{
	private:
		string usuario;
		string contrasenia;
	public:
		Administrador(string,string,string);
		void gestionarCliente(TiendaComponentes*,Cliente*);
		void gestionarProducto(TiendaComponentes*,Producto*);
		void mostrarAdministrador();	
};

#endif