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
		static int contadorID;
		int cantidad;
		float montoTotal;
		string fecha;
		Cliente *cliente;
		Producto *producto;
	public:
		Compra(Cliente*,Producto*,int,string);
		void mostrarVenta();
		int obtenerIDVenta();
		void aumentarID();
		float obtenerMontoTotal();
		string obtenerFecha();
		int obtenerCantidad();	
		Cliente* obtenerCliente();
		Producto* obtenerProducto();
		void asignarMontoTotal(float);
		void asignarIDVenta(int);
};

#endif