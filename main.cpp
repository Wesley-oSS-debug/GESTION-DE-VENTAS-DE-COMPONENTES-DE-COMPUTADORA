#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
#include "Administrador.h"
#include "TiendaComponentes.h"
using namespace std;

int main() {
	//Prueba
	TiendaComponentes tienda;
	Administrador admin("Oscar","63147610","934323253");
	//CLIENTES
	//Cliente cliente1("wesley","75353535","922424524");
	Cliente cliente2("yair","71112233","9423423241");
	//admin.gestionarCliente(&tienda,&cliente1);
	admin.gestionarCliente(&tienda,&cliente2);
	
	//PRODUCTOS
	Producto producto1(20,"rtx2060",650);
	Producto producto2(10,"i5-12400",550.5);
	Producto producto3(5,"ram32gb",440);
	admin.gestionarProducto(&tienda,&producto1);
	admin.gestionarProducto(&tienda,&producto2);
	admin.gestionarProducto(&tienda,&producto3);
	
	admin.gestionarCompra(&tienda,4,"07/12/2024","71112233","i5-12400");
	tienda.mostrarDato();
	
	return 0;
}