#ifndef COMPRA_H
#define COMPRA_H
#include <string>

using namespace std;

class Compra{
	private:
		int idVenta;
		int cantidad;
		float montoTotal;
		string fecha;
	public:
		Compra(int,string);
		void mostrarVenta();
		string obtenerIDVenta();
		string obtenerMontoTotal();	
};

#endif