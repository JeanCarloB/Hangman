#include "Jugador.h"
Jugador::Jugador(string nom, int pun, int inte, int intFal,int punPer) :Persona(nom), intentosFallidos(intFal), puntaje(pun), intentos(inte),puntosPerdidos(punPer) {
}//Contrustor Jugador
Jugador::~Jugador() {
}
string Jugador::toString() {//Metodo tostring
	stringstream s;
	s << Persona::toString() << endl
		<< "---JUGADOR---" << endl
		<< "Puntaje: " << puntaje << endl
		<< "Intentos: " << intentos << endl
		<< "Intentos Fallidos: " << intentosFallidos << endl
		<< "Puntos Perdidos: " << puntosPerdidos << endl;
	return s.str();
}
int Jugador::getIntentosFallidos() {//Metodo get intentos fallidos
	return intentosFallidos;
}
void Jugador::setPuntaje(int pun) { puntaje = pun; }//Metodo set puntaje
void Jugador::setIntentosFallidos(int inte) {//Metodo set intentos fallidos
		intentosFallidos = inte;
}
Jugador* Jugador::leeJugador(ifstream& ent) {//Auto lee jugador
	string nombreS;
	string puntajeS;
	string intentosFallidosS;
	string intentosS;
	string puntosPerdidosS;

	int puntajeI;
	int intentosFallidosI;
	int intentosI;
	int puntosPerdidosI;

	getline(ent,nombreS,'\n');
	getline(ent, puntajeS, '\n');
	getline(ent, intentosS, '\n');
	getline(ent, intentosFallidosS, '\n');
	getline(ent,puntosPerdidosS,'\n');

	puntajeI = atoi(puntajeS.c_str());
	intentosFallidosI = atoi(intentosFallidosS.c_str());
	intentosI = atoi(intentosS.c_str());
	puntosPerdidosI = atoi(puntosPerdidosS.c_str());

	return new Jugador(nombreS, puntajeI, intentosI, intentosFallidosI,puntosPerdidosI);
}
void Jugador::guardaJugador(ofstream& sal) {//Auto guarda un objeto jugador
	sal << Persona::getNombre() << "\n";
	sal << puntaje << "\n";
	sal << intentos << "\n";
	sal << intentosFallidos << "\n";
	sal << puntosPerdidos << "\n";
}
void Jugador::setIntentos(int inte) {//Metodo set intentos
	intentos = inte;
}
void Jugador::setPuntosPerdidos(int pp){//Metodo set puntos perdidos
	puntosPerdidos = pp;
}
int Jugador::getIntentos() { return intentos; }//Metodo get intentos
int Jugador::getPuntosPerdidos(){//Metodo get puntos perdidos
	return puntosPerdidos;
}
int Jugador::getPuntaje() { return puntaje; }//Metodo get puntaje