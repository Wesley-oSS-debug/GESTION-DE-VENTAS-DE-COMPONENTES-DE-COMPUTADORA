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

// funcion para dar color a los caracteres
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
		cout<<"\tINICIAR SESIÓN\n"<<endl;
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
		system("cls");
			setConsoleColor(11);
		cout<<"\n\n----------MENÚ PRINCIPAL---------\n\n";
		cout<<"1. Agregar cliente"<<endl
			<<"2. Mostrar Clientes"<<endl
			<<"3. Realizar venta"<<endl
			<<"4. Mostrar datos de venta"<<endl
			<<"5. Mostrar Productos"<<endl
			<<"6. Modificar Cliente"<<endl
			<<"7. Modificar Producto"<<endl
			<<"8. Agregar Productos"<<endl
			<<"9. Mostrar Maxima venta"<<endl
			<<"10. Ordenar clientes por orden alfabetico"<<endl
			<<"0.  GUARDAR Y SALIR"<<endl;
		while (true) {
        cout << "\nSelecione una opción: "; cin >> op;
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de std::cin
            cin.ignore(10000, '\n'); // Descartar la entrada inválida
            cout << "\nEntrada no válida. Por favor, ingrese un número.\n";
            cout<<"\n";
        } else {
            break;
        }
    }
		switch (op) {
			case 1:
				setConsoleColor(12); // rojo
				agregarCliente(admin,tienda);
				tienda.mostrarNombreCliente();
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 2:
				setConsoleColor(13); // purpura
				mostrarCliente(tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 3:
				setConsoleColor(2); // verde
				realizarVenta(admin,tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 4: // observacion
				setConsoleColor(9); // azul
				mostrarVenta(tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 5:
				setConsoleColor(14); // amarillo
				mostrarProducto(tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 6:
				setConsoleColor(15); // blanco
				modificarCliente(admin,tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 7:
				setConsoleColor(1 | (8 << 4));  // texto negro , fondo gris
				//modificarCliente(admin,tienda);
				modificarProducto(admin,tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
			case 8:
				setConsoleColor(7 | (12 << 4)); // texto blanco, fondo rojo
				agregarProductos(admin,tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				break;
	        case 9:
	        	setConsoleColor(2 | (1 << 4)); // texto rojo, fondo azul
		        mostrarMaxVent(tienda);
		        setConsoleColor(7); // color por defecto(blanco/gris)
		        break;
			case 10:
				setConsoleColor(7 | (1 << 4)); // texto blanco, fondo azul
				mostrarClienAlf(tienda);
				setConsoleColor(7); // color por defecto(blanco/gris)
				
				break;
			
		}
	} while(op!=0);
	
	gestion.actualizarDatos(&tienda);
	//system("pause");
	return 0;
}