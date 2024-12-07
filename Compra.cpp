#include "Compra.h"
#include <iostream>

using namespace std;

Compra::Compra(Cliente *_cliente,Producto *_producto,int _cantidad,string _fecha) {
	cantidad=_cantidad , fecha=_fecha;
	montoTotal=_producto->obtenerPrecio()*cantidad;
	cliente=_cliente;
	producto=_producto;
}

int Compra::obtenerCantidad() {
	return cantidad;
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