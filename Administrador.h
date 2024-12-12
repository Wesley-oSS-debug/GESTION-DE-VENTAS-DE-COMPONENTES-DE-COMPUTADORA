#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "Cliente.h"
#include "Producto.h"
#include "TiendaComponentes.h"
#include "Compra.h"


using namespace std;

class Administrador:public Persona{
	private:
		string usuario;
		string contrasenia;
	public:
		Administrador(string,string,string);
		void gestionarCliente(TiendaComponentes*,Cliente*);
		void gestionarProducto(TiendaComponentes*,Producto*);
		void gestionarCompra(TiendaComponentes*,int,string,string,string);
		void editarCliente(TiendaComponentes*,string,string,string,string);
		void editarProducto(TiendaComponentes*,string,int,string,float);
		void mostrarAdministrador();	
};

#endif