#pragma once
#include "Juego.h"
class Controladora{
public:
	Controladora();//Contructor  controladora
	void control();//control de gestion de archivos y menu
	virtual ~Controladora();//Destructor de Controladora
	void mostrarPalabras();//Muestra las palabras 
	void ingresarPalabra();//Ingresa una palabra
	void modificarPalabra();//Modifica una palabra
	void eliminarPalabra();//Elimina una palabra 
	int menu();//Menu principal
	int menuGestionPalabras();//Menu de gestion de palabras
private:
	Juego* jue;//Atributo juego
};

