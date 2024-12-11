#include <iostream>
#include "gestionDatos.h"
#include "Producto.h"
#include "Cliente.h"
#include "Compra.h"

void gestionDatos::guardarClientes(TiendaComponentes* tienda) {
	ofstream archivoSalida;
	vector<Cliente*> clientes;
	archivoSalida.open("clientes.txt",ios::app);
	clientes=tienda->obtenerClientes();
	
	for (int i=0;i<clientes.size();i++) {
		archivoSalida<<clientes[i]->obtenerID()<<" "
				<<clientes[i]->obtenerNombre()<<" "
				<<clientes[i]->obtenerDNI()<<" "
				<<clientes[i]->obtenerTelefono()<<endl;
	}
	archivoSalida.close();
}

void gestionDatos::guardarProductos(TiendaComponentes* tienda) {
	ofstream archivoSalida;
	vector<Producto*> productos;
	archivoSalida.open("productos.txt",ios::app);
	productos=tienda->obtenerProductos();
	
	for (int i=0;i<productos.size();i++) {
		archivoSalida<<productos[i]->obtenerID()<<" "
				<<productos[i]->obtenerNombreP()<<" "
				<<productos[i]->obtenerStock()<<" "
				<<productos[i]->obtenerPrecio()<<endl;
	}
	archivoSalida.close();
}

void gestionDatos::guardarCompras(TiendaComponentes* tienda) {
	ofstream archivoSalida;
	archivoSalida.open("ventas.txt",ios::app);
	
	vector<Cliente*> cliente;
	cliente=tienda->obtenerClientes();
	
	vector<Producto*> producto;
	producto=tienda->obtenerProductos();
	
	vector<Compra*> ventas;
	

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
}

void gestionDatos::cargarClientes(TiendaComponentes* tienda) {
	ifstream archivoEntrada;
	archivoEntrada.open("clientes.txt");
	string nombre, dni, telefono;
	int id;
    while (archivoEntrada>>id>>nombre>>dni>>telefono) { //devuelve true si lee exitosamente
        Cliente* cliente= new Cliente(nombre,dni,telefono); 
        tienda->agregarCliente(cliente);
        cliente->asignarIDCliente(id);
    }
	archivoEntrada.close();
}

void gestionDatos::cargarProductos(TiendaComponentes* tienda) {
	ifstream archivoEntrada;
	archivoEntrada.open("productos.txt");
	
	int id,stock;
	float precio;
	string nombre;

    while (archivoEntrada>>id>>nombre>>stock>>precio) { //devuelve true si lee exitosamente
        Producto* producto= new Producto(stock,nombre,precio); 
        producto->asignarID(id);
        tienda->agregarProducto(producto);
    }
	archivoEntrada.close();
}

void gestionDatos::cargarCompras(TiendaComponentes* tienda) {
	ifstream archivoEntrada;
	archivoEntrada.open("ventas.txt");
	
	int idVenta,cantidad;
	string fecha,nombreC,nombreP,dni;
	float montoTotal;
	
	
	while (archivoEntrada>>idVenta>>nombreC>>dni>>nombreP>>cantidad>>montoTotal>>fecha) {
		// Buscar Cliente y producto por nombre
        int indCliente = tienda->buscarCliente(dni);
        int indProducto = tienda->buscarProducto(nombreP);
        //obtener cliente y producto encontrado por medio del indice
        Cliente* cliente = tienda->obtenerClientes()[indCliente];
        Producto* producto = tienda->obtenerProductos()[indProducto];
    	Compra* compra = new Compra(cliente, producto, cantidad, fecha);
        compra->asignarIDVenta(idVenta); 
        compra->asignarMontoTotal(montoTotal);
        // Asigna la compra al cliente y al producto
        cliente->asignarCompras(compra);
        producto->asignarCompras(compra,false);
	}
	archivoEntrada.close();
}

void gestionDatos::actualizarDatos(TiendaComponentes* tienda) {
	
	remove("productos.txt");
	remove("clientes.txt");
	remove("ventas.txt");
	guardarProductos(tienda);
	guardarClientes(tienda);
	guardarCompras(tienda);
	
}