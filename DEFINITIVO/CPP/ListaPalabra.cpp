#include "ListaPalabra.h"
ListaPalabra::ListaPalabra() :ppio(NULL){}//Constructor lista palabra
ListaPalabra::~ListaPalabra() {
	NodoPalabra* p = ppio;
	NodoPalabra* aux=new NodoPalabra();
	while (p != NULL) {
		aux=p->getSiguiente();
		delete p;
		p = aux;
	}
	ppio = NULL;
}
string ListaPalabra::toString() {//Metodo to string
	stringstream s;
	NodoPalabra* p = ppio;
	while (p != NULL) {
		s << p->getPalabra()->toString() << endl;
		p = p->getSiguiente();
	}
	return s.str();
}
Palabra* ListaPalabra::existePalabra(string le) {//Verifica si la palabra existe
	Palabra* aux;
	NodoPalabra* p = ppio;
	while (p != NULL) {
		if (p->getPalabra()->getLetras() == le) {
			aux=p->getPalabra();
			return aux;
		}
		p = p->getSiguiente();
	}
	return NULL;
}
void ListaPalabra::insertaAlPricipio(Palabra* pa) {//Inserta palabra al principio
	ppio = new NodoPalabra(ppio,pa);
}
void ListaPalabra::insertaAlFinal(Palabra* pa) {//Inserta palabra al final
	NodoPalabra* p = ppio;
	NodoPalabra* aux;
	if (listaVacia()) {
		insertaAlPricipio(pa);
	}
	else {
		while (p->getSiguiente() != NULL) {
			p = p->getSiguiente();
		}
		aux = new NodoPalabra(NULL,pa);
		p->setSiguiente(aux);
	}
}
int ListaPalabra::cuentaNodos() {//Metodo cuenta palabras existentes
	int i = 0;
	NodoPalabra* p = ppio;
	while (p != NULL) {
		i++;
		p = p->getSiguiente();
	}
	return i;
}
bool ListaPalabra::listaVacia() { return (ppio==NULL) ? true : false; }//Verifica si la lista esta vacia
Palabra* ListaPalabra::seleccionaAlAzar() {//Selecciona una de las palabras existentes al azar
	int num = rand() % cuentaNodos();
	int i = 0;
	NodoPalabra* p = ppio;
	Palabra* pal=new Palabra();
	while (p != NULL) {
		if (i == num) {
			pal = p->getPalabra();
		}
		i++;
		p = p->getSiguiente();
	}
	return pal;
}
void ListaPalabra::leerPalabras() {//Lee palabras
	ifstream arch("../Palabras.txt",ios::in);
	Palabra* pal;
	Palabra aux;
	pal = aux.leePalabra(arch);
	if (arch) {
		while (!arch.eof()) {
			insertaAlFinal(pal);
			pal = aux.leePalabra(arch);
		}
		arch.close();
	}
	else {
		cout << "No se pudo abrir" << endl;
	}
}
void ListaPalabra::guardarPalabras() {//Guarda palabras
	NodoPalabra* p = ppio;
	Palabra* pal;
	ofstream arch("../Palabras.txt", ios::out);
	if (arch) {
		while (p!=NULL) {
			pal = p->getPalabra();
			pal->guardaPalabra(arch);
			p = p->getSiguiente();
		}
		arch.close();
	}
	else {
		cout << "No se pudo abrir" << endl;
	}
}
Palabra* ListaPalabra::elimina(string carac) {//Devuelve una palabra o bien un valor NULL y de esa manera se elimina
	NodoPalabra* p = ppio;
	NodoPalabra* aux=NULL;
	bool encontrado = false;
	Palabra* pal;

	while (p != NULL && !encontrado) {
		if (p->getPalabra()->getLetras() == carac) {
			pal = p->getPalabra();
			encontrado = true;
			eliminaNodo(aux,p);
			return pal;
		}
		aux = p;
		p = p->getSiguiente();
	}
	return NULL;
}
void ListaPalabra::eliminaNodo(NodoPalabra* aux, NodoPalabra* p) {//Elimina nodo de la palabra que se va a eliminar por medio de los parametros enviados
	if (aux==NULL) {
		ppio = p->getSiguiente();
	}
	else {
		aux->setSiguiente(p->getSiguiente());
	}
	delete p;
}