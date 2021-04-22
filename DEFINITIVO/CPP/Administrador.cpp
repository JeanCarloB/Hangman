#include "Administrador.h"
Administrador::Administrador(string nom, string con) : Persona(nom), contrasena(con) {}//Constructor administrador
Administrador::~Administrador() {}//Destructor administrador
string Administrador::toString() {//Metodo to string
	stringstream s;
	s << Persona::toString() << endl
		<< "---ADMINISTRADOR---" << endl
		<< "Contrasena: " << endl;
	for (unsigned int i = 0; i < contrasena.length(); i++) {
		s << "*";//Oculta contrasena
	}
	return s.str();
}
string Administrador::getContrasena() {//Metodo get contrasena
	return contrasena;
}