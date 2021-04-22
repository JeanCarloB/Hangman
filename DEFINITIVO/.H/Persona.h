#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
class Persona {
public:
	Persona(string = "");//Constructor persona
	virtual ~Persona();//Destructor persona
	virtual string toString();//Metodo toString
	string getNombre();//Metdodo get nombre
protected:
	string nombre;//Atributo nombre
};


