#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
#include "Administrador.h"
#include "TiendaComponentes.h"
#include "funciones.h"
#include <windows.h>
#include "gestionDatos.h"

using namespace std;

void setConsoleColor( int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,color);
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	TiendaComponentes tienda;
	Administrador admin("Wesley","63147610","934323253");
	admin.asignarUsuario("admin");
	admin.asignarContrasenia("1234");
	
	string usuario,contrasenia;
	
	for (int i=0;i<3;i++) {
		system("cls");
		cout<<"\tIniciar Sesion"<<endl;
		cout<<"Ingrese su usuario: "; cin>>usuario;
		cout<<"Ingrese su contrasenia: "; cin>>contrasenia;
		
		if(admin.verificarCredenciales(usuario,contrasenia)) {
			cout<<"Sesion iniciada correctamente"<<endl;
			break;
		} else {
			if (i==2) {
				cout<<"Demasiados intentos"<<endl;
				return 0;
			}
			cout<<"Usuario o contrasenia incorrecta Intente de nuevo"<<endl;
			system("pause");
		}
	}
	//cargar datos de archivo
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
			<<"6. Mostrar Clientes"<<endl
			<<"7. Modificar Cliente"<<endl
			<<"8. Modificar Producto"<<endl
			<<"9. Mostrar Maxima venta"<<endl
			<<"10. Ordenar clientes por orden alfabetico"<<endl
			<<"0. Cerrar programa"<<endl
			<<"Ingrese una opcion: "; cin>>op;
		switch (op) {
			case 1:
				setConsoleColor(12); // rojo
				agregarCliente(admin,tienda);
				tienda.mostrarNombreCliente();
				setConsoleColor(7); // color por defecto(blanco/gris)
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
			case 5:
				mostrarProducto(tienda);
				break;
			case 6:
				mostrarCliente(tienda);
				break;
			case 7:
				modificarCliente(admin,tienda);
				break;
			case 8:
				modificarProducto(admin,tienda);
				break;
      case 9:
        mostrarMaxVent(tienda);
        break;
			case 10:
				mostrarClienAlf(tienda);
				break;
			
		}
	} while(op!=0);
	
	gestion.actualizarDatos(&tienda);
	return 0;
}