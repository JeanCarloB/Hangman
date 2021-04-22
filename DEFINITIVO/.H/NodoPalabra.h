#pragma once
#include "Palabra.h"
class NodoPalabra{
private:
	NodoPalabra* sig;//Atributo nodo palabra
	Palabra* pal;//Atributo palabra
public:
	NodoPalabra(NodoPalabra* = NULL,Palabra* = NULL);//Constructor nodo palabra
	virtual ~NodoPalabra();//Destructor nodo palabra
	NodoPalabra* getSiguiente();//Metodo get siguiente
	void setSiguiente(NodoPalabra*);//Metodo set siguiente
	Palabra* getPalabra();//Metodo get palabra
	void setPalabra(Palabra*);//Metodo set palabra
};

