#include "TiendaComponentes.h"
#include "Cliente.h"
#include <vector>
#include <iostream>

using namespace std;

void TiendaComponentes::agregarCliente(Cliente* clien) {
	listaClientes.push_back(clien);
}

void TiendaComponentes::mostrarDato() {
	for (int i=0;i<listaClientes.size();i++) {
		listaClientes[i]-> mostrarDatos();
		cout<<endl;
	}
}