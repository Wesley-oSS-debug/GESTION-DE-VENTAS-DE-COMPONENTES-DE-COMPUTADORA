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
	
	//PRODUCTOS
	Producto producto1(20,"rtx2060",650);
	Producto producto2(10,"i5-12400",550.5);
	Producto producto3(5,"ram32gb",440);
	admin.gestionarProducto(&tienda,&producto1);
	admin.gestionarProducto(&tienda,&producto2);
	admin.gestionarProducto(&tienda,&producto3);
	
	int op;
	do {
		cout<<"1. Agregar cliente"<<endl
			<<"2. Agregar productos"<<endl
			<<"3. Realizar venta"<<endl
			<<"4. Mostrar datos de venta"<<endl
			<<"Ingrese una opcion: "; cin>>op;
		switch (op) {
			case 1:
				agregarCliente(admin,tienda);
				tienda.mostrarNombreCliente();
				break;
			case 2:
				agregarProductos(admin,tienda);
				break;
			case 3:
				realizarVenta(admin,tienda);
				break;
			case 4:
				mostrarVenta(tienda);
				break;
		}
	} while(op!=0);
	
	return 0;
}