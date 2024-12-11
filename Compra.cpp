#include "Compra.h"
#include <iostream>

using namespace std;

Compra::Compra(Cliente *_cliente,Producto *_producto,int _cantidad,string _fecha) {
	cantidad=_cantidad , fecha=_fecha;
	montoTotal=_producto->obtenerPrecio()*cantidad;
	cliente=_cliente;
	producto=_producto;
}

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

int Compra::obtenerIDVenta() {
	return idVenta;
}

float Compra::obtenerMontoTotal() {
	return montoTotal;
}

void Compra::asignarIDVenta(int _idVenta) {
	idVenta=_idVenta;
}

void Compra::asignarMontoTotal(float _montoTotal) {
	montoTotal=_montoTotal;
}

void Compra::mostrarVenta() {
	cout<<endl;
	producto->mostrarProducto();
	cout<<endl;
	cout<<"ID de venta: "<<idVenta<<endl
		<<"Cantidad: "<<cantidad<<endl
		<<"Monto total a pagar: "<<montoTotal<<endl
		<<"Fecha de venta: "<<fecha<<endl;
}