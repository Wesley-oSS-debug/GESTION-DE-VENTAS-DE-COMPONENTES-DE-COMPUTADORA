#include "Producto.h"
#include <iostream>

using namespace std;

Producto::Producto(int _stock,string _nombre,float _precio) {
	stock=_stock, nombre=_nombre, precio=_precio;
}

void Producto::mostrarProducto() {
	cout<<"ID del producto: "<<id<<endl
		<<"Stock del producto: "<<stock<<endl
		<<"Nombre del producto: "<<nombre<<endl
		<<"Precio del producto: "<<precio<<endl;
}