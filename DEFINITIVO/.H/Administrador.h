#pragma once
#include "Persona.h"
class Administrador : public Persona {
public:
	Administrador(string = "", string = "");//Constructor de administrador
	virtual ~Administrador();//Destructor de administrador
	string toString();//Metodo toString de Administrador
	string getContrasena();//Metodo getContrasena
private:
	string contrasena;//atributo contrasena
};