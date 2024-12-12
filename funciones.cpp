#include "funciones.h"
#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
#include "Administrador.h"
#include "TiendaComponentes.h"
#include "gestionDatos.h"

using namespace std;

void agregarCliente(Administrador& admin,TiendaComponentes& tienda) {

	string nombre,dni,numero;
	cout<<"Ingrese nombre: "; cin>>nombre;
	cout<<"Ingrese dni: "; cin>>dni;
	cout<<"Ingrese telefono: "; cin>>numero;
	cout<<"Agregado Correctamente"<<endl;
	Cliente* nuevoCliente= new Cliente(nombre,dni,numero);
	admin.gestionarCliente(&tienda,nuevoCliente);

}

void realizarVenta(Administrador& admin,TiendaComponentes& tienda) {
	int cantidad;
	string nombre,dni,fecha;
	tienda.mostrarProductos();
	cout<<"Ingrese nombre producto: "; cin>>nombre;
	cout<<"Ingrese la cantidad comprada: "; cin>>cantidad;
	cout<<"Ingrese dni de la persona: "; cin>>dni;
	cout<<"Ingrese la fecha de compra: "; cin>>fecha;
	cout<<"Agregado Correctamente"<<endl;
	admin.gestionarCompra(&tienda,cantidad,fecha,dni,nombre);
}

void agregarProductos(Administrador& admin,TiendaComponentes& tienda) {
	int stock;
	string nombre;
	float precio;
	cout<<"Ingrese nombre producto: "; cin>>nombre;
	cout<<"Ingrese la cantidad a agregar: "; cin>>stock;
	cout<<"Ingrese el precio del producto: "; cin>>precio;
	cout<<"Agregado Correctamente"<<endl;
	Producto* nuevoProducto=new Producto(stock,nombre,precio);
	admin.gestionarProducto(&tienda,nuevoProducto);
	
}
void mostrarVenta(TiendaComponentes tienda) {
	tienda.mostrarDato();
}

void mostrarProducto(TiendaComponentes tienda) {
	tienda.mostrarProductos();
}

void mostrarCliente(TiendaComponentes tienda) {
	tienda.mostrarNombreCliente();
}

void modificarCliente(Administrador& admin,TiendaComponentes& tienda) {
	string nombre,dni,nuevoDni,numero;
	tienda.mostrarNombreCliente();
	cout<<"Ingrese el DNI del cliente a modificar sus datos: "; cin>>dni;
	cout<<"Ingrese el nuevo nombre: "; cin>>nombre;
	cout<<"Ingrese el nuevo dni: "; cin>>nuevoDni;
	cout<<"Ingrese el nuevo telefono: "; cin>>numero;
	cout<<endl;
	admin.editarCliente(&tienda,dni,nombre,nuevoDni,numero);
}

void modificarProducto(Administrador& admin,TiendaComponentes& tienda) {
	int stock;
	string nombre,producto;
	float precio;
	cout<<"Ingrese el nombre del producto a modificar sus datos: "; cin>>producto;
	cout<<"Ingrese el nuevo nombre del producto: "; cin>>nombre;
	cout<<"Ingrese la nueva cantidad: "; cin>>stock;
	cout<<"Ingrese el nuevo precio del producto: "; cin>>precio;
	cout<<"Agregado Correctamente"<<endl;
	admin.editarProducto(&tienda,producto,stock,nombre,precio);
}

void eliminarCliente(Administrador& admin,TiendaComponentes& tienda) {
	string dni;
	cout<<"Ingrese el dni del cliente a eliminar: "; cin>>dni;
	cout<<"Eliminado"<<endl;
	admin.eliminarCliente(&tienda,dni);
}

void mostrarClienAlf(TiendaComponentes tienda) {
	tienda.ordenarClienAlf();
	tienda.mostrarNombreCliente();
}

void mostrarMaxVent(TiendaComponentes tienda) {
	tienda.mostrarMaxVenta();
}

