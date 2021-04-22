#include "Persona.h"
Persona::Persona(string nom) :nombre(nom) {}//Constructor persona
Persona::~Persona() {}//Destructor persona
string Persona::getNombre() { return nombre; }//Metodo get nombre
string Persona::toString() {//Metodo to string
	stringstream s;
	s << ">>>PERSONA>>>" << endl
		<< "Nombre: " << nombre << endl;
	return s.str();
}
