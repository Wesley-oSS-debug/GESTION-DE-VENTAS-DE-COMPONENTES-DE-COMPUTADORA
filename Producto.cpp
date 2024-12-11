#include "Producto.h"
#include <iostream>

using namespace std;

Producto::Producto(int _stock,string _nombre,float _precio) {
	stock=_stock, nombre=_nombre, precio=_precio;
}

int Producto::contadorID=0;

void Producto::mostrarProducto() {
	cout<<endl;
	cout<<"ID del producto: "<<id<<endl
		<<"Stock del producto: "<<stock<<endl
		<<"Nombre del producto: "<<nombre<<endl
		<<"Precio del producto: "<<precio<<endl;
}

float Producto::obtenerPrecio() {
	return precio;
}

int Producto::obtenerID() {
	return id;
}

void Producto::aumentarID() {
	contadorID++;
	id=contadorID;
}

int Producto::obtenerStock() {
	return stock;
}
void Producto::asignarCompras(Compra* com, bool cen) {
	if (cen==true) { //si cen es true entonces disminuye stock al asignar una compra
		compras.push_back(com);
		stock-=com->obtenerCantidad();
	} else { // si no solo carga los datos de compras
		compras.push_back(com);
	}
} 

string Producto::obtenerNombreP() {
	return nombre;
}

void Producto::asignarID(int _id) {
	id=_id;
}

