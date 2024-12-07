#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Persona.h"

using namespace std;

class Cliente:public Persona{
	private:
		int idCliente;
	public:
		Cliente(string,string,string);
		void mostrarDatos();	
};

#endif