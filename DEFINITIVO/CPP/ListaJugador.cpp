#include "ListaJugador.h"
ListaJugador::ListaJugador() {//Constructor lista jugador
	ppio = NULL;
}
string ListaJugador::toString() {//Metodo to string 
	stringstream s;
	NodoJugador* p = ppio;
	while (p != NULL) {
		s << p->getJugador()->toString() << endl;
		p = p->getSiguiente();
	}
	return s.str();
}
void ListaJugador::insertaAlPrincipio(Jugador* ju) {//Inserta jugador al principio de la lista
	ppio = new NodoJugador(ppio, ju);
}
void ListaJugador::insertaAlFinal(Jugador* ju) {//Inserta jugador al final de la lista
	NodoJugador* p = ppio;
	NodoJugador* aux;
	if (listaVacia()) {
		this->insertaAlPrincipio(ju);
	}
	else {
		while (p->getSiguiente() != NULL) {
			p = p->getSiguiente();
		}
		aux = new NodoJugador(NULL, ju);
		p->setSiguiente(aux);
	}
}
ListaJugador::~ListaJugador() {//Destructor jugador 
	NodoJugador* p = ppio;
	NodoJugador* aux;
	while (p != NULL) {
		aux = p->getSiguiente();
		delete p;
		p = aux;
	}
	ppio = NULL;
}
bool ListaJugador::listaVacia() {//Verifica si la lista esta vacia
	return (ppio == NULL) ? true : false;
}
void ListaJugador::leerJugadores() {//Lee jugadores en archivo
	ifstream arch("../Jugadores.txt", ios::in);
	Jugador* jug;
	Jugador aux;
	jug = aux.leeJugador(arch);
	if (arch) {
		while (!arch.eof()) {
			this->insertaAlFinal(jug);
			jug = aux.leeJugador(arch);
		}
		arch.close();
	}
	else {
		cout << "No se pudo abrir" << endl;
	}
}
void ListaJugador::guardarJugadores() {//Guarda jugadores en archivo
	NodoJugador* p = ppio;
	ofstream arch("../Jugadores.txt", ios::in);
	if (arch) {
		while (p != NULL) {
			p->getJugador()->guardaJugador(arch);
			p = p->getSiguiente();
		}
		arch.close();
	}
	else {
		cout << "No se pudo abrir" << endl;
	}
}
int ListaJugador::cuentaNodos() {//Metodo cuenta jugadores de la lista
	NodoJugador* p = ppio;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->getSiguiente();
	}
	return i;
}
void ListaJugador::ordenaListaPorPuntaje() {//Ordena lista por puntaje
	NodoJugador* p = ppio;
	NodoJugador* aux = NULL;
	Jugador* jug;
	while (p->getSiguiente() != NULL) {
		aux = p->getSiguiente();
		while (aux != NULL) {
			if (p->getJugador()->getPuntaje() < aux->getJugador()->getPuntaje()) {
				jug = aux->getJugador();
				aux->setJugador(p->getJugador());
				p->setJugador(jug);
			}
			aux = aux->getSiguiente();
		}
		p = p->getSiguiente();
	}
}
bool ListaJugador::puntajeRecord(Jugador* ju) {//Verifica si jugador rompio record de puntaje
	return (ppio->getJugador()->getPuntaje() < ju->getPuntaje()) ? true : false;
}
string ListaJugador::muestraPuntajesAltos() {//Metodo muestra mejores puntajes
	stringstream s;
	int cont = 0;
	NodoJugador* p = ppio;
	while (p!=NULL&& cont != 6) {
		s << p->getJugador()->toString() << endl;
		cont++;
		p = p->getSiguiente();
	}
	return s.str();
}