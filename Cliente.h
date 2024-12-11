#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Persona.h"
#include "Compra.h"
#include <vector>

using namespace std;

class Compra;

class Cliente:public Persona{
	private:
		int idCliente;
		static int contadorID;
		vector<Compra*> compras;
	public:
		Cliente(string,string,string);
		void mostrarDatos();
		void asignarCompras(Compra*);
		void asignarIDCliente(int);
		void aumentarID();
		int obtenerID();
		vector<Compra*> obtenerCompras();	
};

#endif