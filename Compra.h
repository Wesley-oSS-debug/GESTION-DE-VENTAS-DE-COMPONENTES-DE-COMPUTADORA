#ifndef COMPRA_H
#define COMPRA_H
#include <string>
#include "Cliente.h"
#include "Producto.h"

using namespace std;

class Producto;
class Cliente;

class Compra{
	private:
		int idVenta;
		int cantidad;
		float montoTotal;
		string fecha;
		Cliente *cliente;
		Producto *producto;
	public:
		Compra(Cliente*,Producto*,int,string);
		void mostrarVenta();
		string obtenerIDVenta();
		string obtenerMontoTotal();
		int obtenerCantidad();	
		Cliente* obtenerCliente();
		Producto* obtenerProducto();
};

#endif