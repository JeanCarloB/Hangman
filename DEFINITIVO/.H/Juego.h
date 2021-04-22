#pragma once
#include "ListaPalabra.h"
#include "ListaJugador.h"
#include "Interfaz.h"
class Juego{
private:
	Jugador* jug1;//Atributo jugador n°1
	Jugador* jug2;//Atributo jugador n°1
	string original;//Atributo para guardar palabra original 
	string copia;//Atributo para guardar copia de la palabra original 
	ListaPalabra* lisPal;//Atributo lista de palabras
	ListaJugador* lisJug;//Atributo lista de jugadores
public:
	Juego();//Constructor de juego
	virtual ~Juego();//Destructor de juego
	string toString();//Metodo toString 
	void jugar();//Metodo para jugar
	void adivinaPalabra(string,Jugador*);
	void iniciar();//Inicializa los atributos necesarios para jugar
	void adivinarLetra(char,Jugador*);//Metodo para adivinar un caracter de la palabra
	void muestraPalabra();//Muestra palabra copia
	void reiniciaTodo(Jugador*,Jugador*);//Reinicia en caso de que los usuarios quieran volver a jugar una partida
	bool estado();//Verifica estado de la partida
	ListaPalabra* getListaPalabra();//Deevuelve lista de palabras
	ListaJugador* getListaJugador();//devulve lista de jugadores
};

