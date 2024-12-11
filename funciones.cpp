#include "funciones.h"
#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
#include "Administrador.h"
#include "TiendaComponentes.h"
#include "gestionDatos.h"

using namespace std;

void agregarCliente(Administrador& admin,TiendaComponentes& tienda, gestionDatos gestion) {

	string nombre,dni,numero;
	cout<<"Ingrese nombre: "; cin>>nombre;
	cout<<"Ingrese dni: "; cin>>dni;
	cout<<"Ingrese telefono: "; cin>>numero;
	cout<<"Agregado Correctamente"<<endl;
	Cliente* nuevoCliente= new Cliente(nombre,dni,numero);
	admin.gestionarCliente(&tienda,nuevoCliente);
	gestion.guardarClientes(&tienda);

}

void realizarVenta(Administrador& admin,TiendaComponentes& tienda, gestionDatos gestion) {
	int cantidad;
	string nombre,dni,fecha;
	tienda.mostrarProductos();
	cout<<"Ingrese nombre producto: "; cin>>nombre;
	cout<<"Ingrese la cantidad comprada: "; cin>>cantidad;
	cout<<"Ingrese dni de la persona: "; cin>>dni;
	cout<<"Ingrese la fecha de compra: "; cin>>fecha;
	cout<<"Agregado Correctamente"<<endl;
	admin.gestionarCompra(&tienda,cantidad,fecha,dni,nombre);
	gestion.guardarCompras(&tienda);
}

void agregarProductos(Administrador& admin,TiendaComponentes& tienda, gestionDatos gestion) {
	int stock;
	string nombre;
	float precio;
	cout<<"Ingrese nombre producto: "; cin>>nombre;
	cout<<"Ingrese la cantidad a agregar: "; cin>>stock;
	cout<<"Ingrese el precio del producto: "; cin>>precio;
	cout<<"Agregado Correctamente"<<endl;
	Producto* nuevoProducto=new Producto(stock,nombre,precio);
	admin.gestionarProducto(&tienda,nuevoProducto);
	gestion.guardarProductos(&tienda);
	
}
void mostrarVenta(TiendaComponentes tienda) {
	tienda.mostrarDato();
}

void mostrarProducto(TiendaComponentes tienda) {
	tienda.mostrarProductos();
}

