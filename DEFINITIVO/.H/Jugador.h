#pragma once
#include "Persona.h"
class Jugador :public Persona {
private:
	int intentosFallidos;//Atributo intentos fallidos
	int puntaje;//Atributo puntaje
	int intentos;//Atributo intentos
	int puntosPerdidos;//Atributo puntos perdidos
public:
	Jugador(string = "", int = 0, int = 0, int = 3, int = 0);//Constructor jugador
	virtual ~Jugador();//Destructor de jugador
	string toString();//Metodo toString
	int getIntentosFallidos();//Metodo get intentos fallidos
	void setPuntaje(int);//Metodo set puntaje
	void setIntentos(int);//Metodo set intentos
	void setPuntosPerdidos(int);//Metodo set puntos perdidos
	int getIntentos();//Metodo get intentos
	int getPuntosPerdidos();//Metodo puntos perdidos
	int getPuntaje();//Metodo get puntaje
	void setIntentosFallidos(int);//Metodo set intentos fallidos
	void guardaJugador(ofstream&);//Metodo auto guarda jugador
	Jugador* leeJugador(ifstream&);//Metodo auto lee jugador
};