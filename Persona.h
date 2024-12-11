#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona{
	protected:
		string nombre;
		string dni;
		string telefono;
	public:
		Persona(string,string,string);
		void mostrarPersona();
		string obtenerNombre();
		string obtenerDNI();
		string obtenerTelefono();	
};

#endif