#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "Compra.h"
#include <string>
#include <vector>

using namespace std;

class Compra;


class Producto{
	private:
		int id;
		static int contadorID;
		int stock;
		string nombre;
		float precio;
		vector<Compra*> compras;
	public:
		Producto(int,string,float);
		int obtenerID();
		void aumentarID();
		int obtenerStock();
		string obtenerNombreP();
		float obtenerPrecio();
		void mostrarProducto();
		void asignarID(int);
		void asignarNombre(string);
		void asignarStock(int);
		void asignarPrecio(float);
		void asignarCompras(Compra*,bool);	
};

#endif