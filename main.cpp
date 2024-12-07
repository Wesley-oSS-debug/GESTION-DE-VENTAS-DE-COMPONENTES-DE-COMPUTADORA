#include <iostream>
#include "Persona.h"
#include "Cliente.h"
#include "Producto.h"
using namespace std;

int main() {
	//Prueba
	Cliente obj("oscar","6314442","986408779");
	Producto p(2,"rtx2060",550.5);
	
	obj.mostrarPersona();
	p.mostrarProducto();
	return 0;
}