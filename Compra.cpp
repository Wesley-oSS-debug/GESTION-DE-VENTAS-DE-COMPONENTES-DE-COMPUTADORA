#include "Compra.h"
#include <iostream>

using namespace std;

Compra::Compra(Cliente *_cliente,Producto *_producto,int _cantidad,string _fecha) {
	cantidad=_cantidad , fecha=_fecha;
	montoTotal=_producto->obtenerPrecio()*cantidad;
	cliente=_cliente;
	producto=_producto;
}

int Compra::contadorID=0;

Cliente* Compra::obtenerCliente() {
	return cliente;
}

Producto* Compra::obtenerProducto() {
	return producto;
}

int Compra::obtenerCantidad() {
	return cantidad;
}

string Compra::obtenerFecha() {
	return fecha;
}

void Compra::aumentarID() {
	contadorID++;
	idVenta=contadorID;
}

int Compra::obtenerIDVenta() {
	return idVenta;
}
void Compra::asignarIDVenta(int _idVenta) {
	idVenta=_idVenta;
}


float Compra::obtenerMontoTotal() {
	return montoTotal;
}


void Compra::asignarMontoTotal(float _montoTotal) {
	montoTotal=_montoTotal;
}

void Compra::mostrarVenta() {
	cout<<"ID de venta: "<<idVenta<<endl
		<<"Cantidad: "<<cantidad<<endl
		<<"Monto total a pagar: "<<montoTotal<<endl
		<<"Fecha de venta: "<<fecha<<endl;
	cout<<endl;
	producto->mostrarProducto();
}