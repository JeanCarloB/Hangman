#pragma once
#include "NodoJugador.h"
class ListaJugador {
private:
	NodoJugador* ppio;//Atributo nodo jugador
public:
	ListaJugador();//Constructor lista jugador
	virtual ~ListaJugador();//Destructor lista jugador
	void insertaAlFinal(Jugador*);//Inserta jugador al final de la lista
	void insertaAlPrincipio(Jugador*);//Inserta jugador al principio de la lista
	string toString();//Metodo toString
	bool listaVacia();//Combrueba si la lista esta vacia
	void ordenaListaPorPuntaje();//Ordena lista por puntaje
	bool puntajeRecord(Jugador*);//Comprueba si jugador rompio record
	int cuentaNodos();//Metodo cuenta Jugadores
	void leerJugadores();//Lee jugadores
	void guardarJugadores();//Guarda jugadores
	string muestraPuntajesAltos();//Muestra 6 mejores puntajes
};

