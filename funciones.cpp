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
	system("cls");

	string nombre,dni,numero;
	cout<<"\n\n-------------AGREGAR DATOS DEL CLIENTE-------------\n\n";
	cout<<"Ingrese nombre: "; cin>>nombre;
	cout<<"Ingrese dni: "; cin>>dni;
	cout<<"Ingrese telefono: "; cin>>numero;
	cout<<"Agregado Correctamente"<<endl;
	Cliente* nuevoCliente= new Cliente(nombre,dni,numero);
	admin.gestionarCliente(&tienda,nuevoCliente);
	system("pause");
}

void realizarVenta(Administrador& admin,TiendaComponentes& tienda) {
	system("cls");
	int cantidad;
	int cantidadCaracteres;
	string nombre,dni,fecha;
	tienda.mostrarProductos();
	cout<<"Ingrese nombre producto: "; cin>>nombre;
	cout<<"Ingrese la cantidad comprada: "; cin>>cantidad;
	cout<<"Ingrese dni de la persona: "; cin>>dni;
//Este bucle es Validacion, permitira volver a preguntar la fecha al usuario.
	do{ 
		cout << "Ingrese la fecha (DD/MM/YYYY): ";
	    cin>>fecha;
		cantidadCaracteres = fecha.length();	
		//Esto valida que la fecha tenga / 
		if (fecha[2]!= '/' || fecha[5]!= '/'){ 
			cantidadCaracteres = 9; // se da 9 para volver al bucle
		}
		if(cantidadCaracteres != 10){  //Esto es para el error en el caso de que sea diferente de 10.
			cout << "\nError fecha inválida, INGRESE DE NUEVO.\n\n";
		}
	}while(cantidadCaracteres != 10); //El bucle finaliza cuando cantidaCaracteres es 10.
	
	cout<<"Agregado Correctamente"<<endl;
	system("pause");
	admin.gestionarCompra(&tienda,cantidad,fecha,dni,nombre);
}

void agregarProductos(Administrador& admin,TiendaComponentes& tienda) {
	system("cls");
	int stock;
	string nombre;
	float precio;
	cout<<"Ingrese nombre producto: "; cin>>nombre;
	cout<<"Ingrese la cantidad a agregar: "; cin>>stock;
	cout<<"Ingrese el precio del producto: "; cin>>precio;
	cout<<"Agregado Correctamente"<<endl;
	Producto* nuevoProducto=new Producto(stock,nombre,precio);
	system("pause");
	admin.gestionarProducto(&tienda,nuevoProducto);
}
void mostrarVenta(TiendaComponentes tienda) {
	system("cls");
	tienda.mostrarDato();
	system("pause");
}

void mostrarProducto(TiendaComponentes tienda) {
	system("cls");
	tienda.mostrarProductos();
	system("pause");
}

void mostrarCliente(TiendaComponentes tienda) {
	system("cls");
	tienda.mostrarNombreCliente();
	system("pause");
}

void modificarCliente(Administrador& admin,TiendaComponentes& tienda) {
	system("cls");
	string nombre,dni,nuevoDni,numero;
	tienda.mostrarNombreCliente();
	cout<<"Ingrese el DNI del cliente a modificar sus datos: "; cin>>dni;
	cout<<"Ingrese el nuevo nombre: "; cin>>nombre;
	cout<<"Ingrese el nuevo dni: "; cin>>nuevoDni;
	cout<<"Ingrese el nuevo telefono: "; cin>>numero;
	cout<<endl;
	system("pause");
	admin.editarCliente(&tienda,dni,nombre,nuevoDni,numero);
}

void modificarProducto(Administrador& admin,TiendaComponentes& tienda) {
	system("cls");
	int stock;
	string nombre,producto;
	float precio;
	cout<<"Ingrese el nombre del producto a modificar sus datos: "; cin>>producto;
	cout<<"Ingrese el nuevo nombre del producto: "; cin>>nombre;
	cout<<"Ingrese la nueva cantidad: "; cin>>stock;
	cout<<"Ingrese el nuevo precio del producto: "; cin>>precio;
	cout<<"Agregado Correctamente"<<endl;
	system("pause");
	admin.editarProducto(&tienda,producto,stock,nombre,precio);
}

void mostrarClienAlf(TiendaComponentes tienda) {
	system("cls");
	tienda.ordenarClienAlf();
	tienda.mostrarNombreCliente();
	system("pause");
}

void mostrarMaxVent(TiendaComponentes tienda) {
	system("cls");
	tienda.mostrarMaxVenta();
	system("pause");
}

