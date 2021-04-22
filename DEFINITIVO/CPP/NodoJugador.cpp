#include "NodoJugador.h"
NodoJugador::NodoJugador(NodoJugador* si, Jugador* ju) :sig(si), jug(ju) {}//Constructor nodo  jugador
NodoJugador* NodoJugador::getSiguiente() { return sig; }//Metodo get siguiente
void NodoJugador::setSiguiente(NodoJugador* si) { sig = si; }//Metodo set siguiente
Jugador* NodoJugador::getJugador() { return jug; }//Metodo get jugador
void NodoJugador::setJugador(Jugador* ju) { jug = ju; }//Metodo set jugador
NodoJugador::~NodoJugador() {//Destructor nodo jugador
	if (jug != NULL)
		delete jug;
}
