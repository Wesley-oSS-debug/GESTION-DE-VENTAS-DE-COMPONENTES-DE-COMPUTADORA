#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>


using namespace std;

class Compra;


class Producto{
	private:
		int id;
		int stock;
		string nombre;
		float precio;
		vector<Compra*> compras;
	public:
		Producto(int,string,float);
		float obtenerPrecio();
		string obtenerNombreP();
		void mostrarProducto();
		void asignarCompras(Compra*);	
};

#endif