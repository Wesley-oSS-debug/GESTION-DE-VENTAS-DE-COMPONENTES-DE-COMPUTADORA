#include <iostream>
#include "gestionDatos.h"
#include "Producto.h"
#include "Cliente.h"
#include "Compra.h"

void gestionDatos::guardarClientes(TiendaComponentes* tienda) {
	ofstream archivoSalida;
	vector<Cliente*> clientes;
	clientes=tienda->obtenerClientes();
	archivoSalida.open("clientes.txt",ios::app);
	if (archivoSalida.is_open()) {
		for (int i=0;i<clientes.size();i++) {
			archivoSalida<<clientes[i]->obtenerID()<<" "
					<<clientes[i]->obtenerNombre()<<" "
					<<clientes[i]->obtenerDNI()<<" "
					<<clientes[i]->obtenerTelefono()<<endl;
		}
		archivoSalida.close();	
	} else {
		cout<<"ERROR: No se pudo abrir clientes.txt"<<endl;
		return;
	}
}

void gestionDatos::guardarProductos(TiendaComponentes* tienda) {
	ofstream archivoSalida;
	vector<Producto*> productos;
	productos=tienda->obtenerProductos();
	archivoSalida.open("productos.txt",ios::app);
	if (archivoSalida.is_open()) {
		for (int i=0;i<productos.size();i++) {
			archivoSalida<<productos[i]->obtenerID()<<" "
					<<productos[i]->obtenerNombreP()<<" "
					<<productos[i]->obtenerStock()<<" "
					<<productos[i]->obtenerPrecio()<<endl;
		}
		archivoSalida.close();
	} else {
		cout<<"ERROR: No se pudo abrir productos.txt"<<endl;
		return;
	}
}

void gestionDatos::guardarCompras(TiendaComponentes* tienda) {
	ofstream archivoSalida;
	vector<Cliente*> cliente;
	cliente=tienda->obtenerClientes();
	vector<Compra*> ventas;
	archivoSalida.open("ventas.txt",ios::app);
	if (archivoSalida.is_open()) {
		for (int j=0;j<cliente.size();j++) {
			ventas=cliente[j]->obtenerCompras();
			for (int i=0;i<ventas.size();i++) {
				archivoSalida<<ventas[i]->obtenerIDVenta()<<" "
							<<cliente[j]->obtenerNombre()<<" "
							<<cliente[j]->obtenerDNI()<<" "
							<<ventas[i]->obtenerProducto()->obtenerNombreP()<<" "
							<<ventas[i]->obtenerCantidad()<<" "
							<<ventas[i]->obtenerMontoTotal()<<" "
							<<ventas[i]->obtenerFecha()<<" "<<endl;
			}
		}
		archivoSalida.close();
	} else {
		cout<<"ERROR: No se pudo abrir ventas.txt"<<endl;
		return;
	}
	
}

void gestionDatos::cargarClientes(TiendaComponentes* tienda) {
	ifstream archivoEntrada;
	string nombre, dni, telefono;
	int id;
	archivoEntrada.open("clientes.txt");
	if (archivoEntrada.is_open()) {
	    while (archivoEntrada>>id>>nombre>>dni>>telefono) { //devuelve true si lee exitosamente
	        Cliente* cliente= new Cliente(nombre,dni,telefono); 
	        tienda->agregarCliente(cliente);
	        cliente->asignarIDCliente(id);
	    }
		archivoEntrada.close();
	} else {
		cout<<"ERROR: No se pudo abrir clientes.txt"<<endl;
		return;
	}
}

void gestionDatos::cargarProductos(TiendaComponentes* tienda) {
	ifstream archivoEntrada;
	int id,stock;
	float precio;
	string nombre;
	archivoEntrada.open("productos.txt");
	if (archivoEntrada.is_open()) {
	    while (archivoEntrada>>id>>nombre>>stock>>precio) { //devuelve true si lee exitosamente
	        Producto* producto= new Producto(stock,nombre,precio); 
	        producto->asignarID(id);
	        tienda->agregarProducto(producto);
	    }
		archivoEntrada.close();	
	} else {
		cout<<"ERROR: No se pudo abrir productos.txt"<<endl;
		return;
	}

}

void gestionDatos::cargarCompras(TiendaComponentes* tienda) {
	ifstream archivoEntrada;
	int idVenta,cantidad;
	string fecha,nombreC,nombreP,dni;
	float montoTotal;
	archivoEntrada.open("ventas.txt");
	if (archivoEntrada.is_open()) {
		while (archivoEntrada>>idVenta>>nombreC>>dni>>nombreP>>cantidad>>montoTotal>>fecha) {
			// Buscar Cliente y producto por nombre
	        int indCliente=tienda->buscarCliente(dni);
	        int indProducto=tienda->buscarProducto(nombreP);
	        //obtener cliente y producto encontrado por medio del indice
	        Cliente* cliente=tienda->obtenerClientes()[indCliente];
	        Producto* producto=tienda->obtenerProductos()[indProducto];
	    	Compra* compra=new Compra(cliente, producto, cantidad, fecha);
	    	compra->aumentarID();
	        compra->asignarIDVenta(idVenta); 
	        compra->asignarMontoTotal(montoTotal);
	        // Asigna la compra al cliente y al producto
	        cliente->asignarCompras(compra);
	        producto->asignarCompras(compra,false);
		}
		archivoEntrada.close();
	} else {
		cout<<"ERROR: No se pudo abrir ventas.txt"<<endl;
		return;
	}
}

void gestionDatos::actualizarDatos(TiendaComponentes* tienda) {
	remove("productos.txt");
	remove("clientes.txt");
	remove("ventas.txt");
	guardarProductos(tienda);
	guardarClientes(tienda);
	guardarCompras(tienda);
	
}