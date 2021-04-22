#pragma once
#include "Jugador.h"
class NodoJugador {
private:
	Jugador* jug;//Atributo jugador
	NodoJugador* sig;//Atributo nodo jugador
public:
	NodoJugador(NodoJugador*, Jugador*);//Constructor nodo jugador
	NodoJugador* getSiguiente();//Metodo get siguiente
	void setSiguiente(NodoJugador*);//Metodo set siguiente
	Jugador* getJugador();//Metodo getJugador
	void setJugador(Jugador*);//Metodo set jugador
	virtual ~NodoJugador();//Destructor nodo jugador
};
