#include "Compra.h"
#include <iostream>

using namespace std;

Compra::Compra(int _cantidad,string _fecha) {
	cantidad=_cantidad, fecha=_fecha;
}

void Compra::mostrarVenta() {
	cout<<"ID de venta: "<<idVenta<<endl
		<<"Monto total a pagar: "<<montoTotal<<endl
		<<"Fecha de venta: "<<fecha<<endl;
}