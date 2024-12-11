#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
#include "Administrador.h"
#include "TiendaComponentes.h"
#include "funciones.h"
using namespace std;

int main() {
	TiendaComponentes tienda;
	Administrador admin("Oscar","63147610","934323253");
	gestionDatos gestion;
	gestion.cargarClientes(&tienda);
	gestion.cargarProductos(&tienda);
	gestion.cargarCompras(&tienda);

	//PRODUCTOS
	int op;
	do {

		cout<<"1. Agregar cliente"<<endl
			<<"2. Agregar productos"<<endl
			<<"3. Realizar venta"<<endl
			<<"4. Mostrar datos de venta"<<endl
			<<"5. Mostrar Productos"<<endl
			<<"Ingrese una opcion: "; cin>>op;
		switch (op) {
			case 1:
				agregarCliente(admin,tienda,gestion);
				tienda.mostrarNombreCliente();
				break;
			case 2:
				agregarProductos(admin,tienda,gestion);
				break;
			case 3:
				realizarVenta(admin,tienda,gestion);
				break;
			case 4:
				mostrarVenta(tienda);
				break;
			case 5:
				mostrarProducto(tienda);
		}
	} while(op!=0);
	
	gestion.actualizarDatos(&tienda);
	return 0;
}