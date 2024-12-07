#include "funciones.h"
#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
#include "Administrador.h"
#include "TiendaComponentes.h"

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

void mostrarVenta(TiendaComponentes tienda) {
	tienda.mostrarDato();
}