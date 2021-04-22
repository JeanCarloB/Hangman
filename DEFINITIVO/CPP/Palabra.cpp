#include "Palabra.h"
Palabra::Palabra(string let) :letras(let){}//Constructor palabra
Palabra::~Palabra() {}//Destructor palabra
string Palabra::toString() {
	stringstream s;
	s << ">>Palabra>>" << endl
	<< letras << endl;
	return s.str();
}
string Palabra::getLetras() { return letras; }//Metodo get letras
void Palabra::setLetras(string let){//Metodo set letras
	letras = let;
}
void Palabra::guardaPalabra(ofstream& sal) {//Guarda palabra
	sal << letras<<'\n';
}
Palabra* Palabra::leePalabra(ifstream& ent) {//Lee palabra
	string letrasS;
	getline(ent, letrasS, '\n');
	return new Palabra(letrasS);
}