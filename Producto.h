#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

using namespace std;

class Producto{
	private:
		int id;
		int stock;
		string nombre;
		float precio;
	public:
		Producto(int,string,float);
		void mostrarProducto();	
};

#endif