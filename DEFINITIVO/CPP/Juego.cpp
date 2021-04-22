#include "Juego.h"
Juego::Juego(){//Constructor juego
	lisPal = new ListaPalabra();
	lisJug = new ListaJugador();
	jug1 = NULL;
	jug2 = NULL;
	original = "";
	copia = "";
}
Juego::~Juego() {//Destructor juego
	if (lisPal!=NULL)
		delete lisPal;
	if(lisJug!=NULL) 
		delete lisJug;
	if (jug1 != NULL)
		delete jug1;
	if (jug2 != NULL)
		delete jug2;
}
string Juego::toString() {//Metodo to string
	stringstream s;
	if (lisPal != NULL)
		s<<lisPal->toString()<<endl;
	if (lisJug != NULL)
		s << lisJug->toString() << endl;
	if (jug1 != NULL)
		s << jug1->toString() << endl;
	if (jug2 != NULL)
		s << jug2->toString() << endl;
	return s.str();
}
void Juego::jugar() {//Metodo para jugar una partida
	iniciar();
	int opc;
	bool turno=true;
	string pal;
devolver:
	while (!estado()) {
		do {
			system("cls");
			if (jug1->getIntentosFallidos() == 0) {
				turno = false;
			}
			if (jug2->getIntentosFallidos() == 0) {
				turno = true;
			}
			if (jug1->getIntentosFallidos()<5&&jug1->getPuntaje()-jug1->getPuntosPerdidos()==30) {
				jug1->setIntentosFallidos(jug1->getIntentosFallidos()+1);
				
			}
			if (jug2->getIntentosFallidos() < 5 && jug1->getPuntaje() - jug2->getPuntosPerdidos() == 30) {
				jug2->setIntentosFallidos(jug2->getIntentosFallidos() + 1);

			}
			if (turno) {
				cout << ">>>	TURNO JUGADOR 1	>>>" << endl;
				cout << "1.Adivina letra" << endl;
				cout << "2.Adivina Palabra" << endl;
			}
			else {
				cout << ">>>	TURNO JUGADOR 2	>>>" << endl;
				cout << "1.Adivina letra" << endl;
				cout << "2.Adivina Palabra" << endl;
			}
			cin >> opc;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024,'\n');
			}
			switch (opc) {
			case 1:
				system("cls");
				if (turno) {
					this->muestraPalabra();
					char x;
					cout << "Digite la letra o caracter jugador 1" << endl;
					cin >> x;
					// system_error("clear");//system(*cls*)
					this->adivinarLetra(x, jug1);
					this->muestraPalabra();
					turno = false;
					system("pause");
				}
				else {
					this->muestraPalabra();
					char x;
					cout << "Digite la letra o caracter jugador 2" << endl;
					cin >> x;
					// system_error("clear");//system(*cls*)
					this->adivinarLetra(x, jug2);
					this->muestraPalabra();
					turno = true;
					system("pause");
				}
				break;
			case 2:
				system("cls");
				if (turno) {
					cout << "Digite la palabra jugador 1" << endl;
					cin >> pal;
					// system_error("clear");//system(*cls*)
					this->adivinaPalabra(pal, jug1);
					this->muestraPalabra();
					turno = false;
					system("pause");
				}
				else {
					cout << "Digite la palabra jugador 2" << endl;
					cin >> pal;
					// system_error("clear");//system(*cls*)
					this->adivinaPalabra(pal, jug2);
					this->muestraPalabra();
					turno = true;
					system("pause");
				}
				break;

			}
		} while (opc < 0 && opc>4);
	}

	lisJug->insertaAlFinal(jug1);
	lisJug->insertaAlFinal(jug2);
	
	lisJug->ordenaListaPorPuntaje();

	if (jug1->getIntentosFallidos() > 0&& jug1->getPuntaje()> jug2->getPuntaje()) {
		if (lisJug->puntajeRecord(jug1)) {
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
			cout << "************** FELICITACIONES ***********************" << endl;
			cout << "********************* A *****************************" << endl;
			cout << "****************** SOBREPASADO **********************" << endl;
			cout << "************ EL PUNTAJE MAS ALTO!! ******************" << endl;
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
		}else{
			cout << "JUGADOR 1 GANO" << endl;
		}
	}
	if (jug2->getIntentosFallidos() > 0&& jug2->getPuntaje() > jug1->getPuntaje()) {
		if (lisJug->puntajeRecord(jug2)) {
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
			cout << "************** FELICITACIONES ***********************" << endl;
			cout << "********************* A *****************************" << endl;
			cout << "****************** SOBREPASADO **********************" << endl;
			cout << "************ EL PUNTAJE MAS ALTO!! ******************" << endl;
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
			cout << "*****************************************************" << endl;
		}
		else {
			cout << " JUGADOR 2 GANO" << endl;
		}
		}
		if (jug2->getIntentosFallidos() == 0 && jug1->getIntentosFallidos()==0) {
			cout << "Mejor suerte la proxima la palabra era: " << original << endl;
		}
		system("pause");
		system("cls");
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "******************** RANKING  ***********************" << endl;
		cout << "********************** DE ***************************" << endl;
		cout << "****************** PUNTAJES *************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl<<endl;
		cout<<lisJug->muestraPuntajesAltos()<<endl;
		system("pause");
		system("cls");
		int opcion;
		do {
			cout << ">>>Juego terminado>>>" << endl;
			cout << "1.Volver a jugar" << endl;
			cout << "2.Salir" << endl;
			cout << "Volver a jugar" << endl;
			cin >> opcion;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
			}
			switch (opcion) {
			case 1:
				system("cls");
				this->reiniciaTodo(jug1, jug2);
				goto devolver;
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "*****************************" << endl;
				cout << "*****************************" << endl;
				cout << "*** Gracias por jugar  :D ***" << endl;
				cout << "*****************************" << endl;
				cout << "*****************************" << endl;
				system("pause");
				break;
			}
		} while (opcion<0&&opcion>2);
}

void Juego::adivinaPalabra(string pa, Jugador* jug) {//Adivinar palabra

	int cont = 0;
	string minus;
	for (unsigned int i = 0; i < pa.length(); i++) {
		minus += tolower(pa[i]);
	}
	if (original==minus) {
		for (unsigned int i = 0; i < copia.length(); i++) {
			if (copia[i] == '_')
				cont++;
		}
		jug->setPuntaje(jug->getPuntaje()+cont*2);
		jug->setIntentos(jug->getIntentos() + 1);
		copia = original;
	}
	else {
		jug->setIntentos(jug->getIntentos() + 1);
		jug->setPuntosPerdidos(jug->getPuntosPerdidos() + cont * 2);
		jug->setIntentosFallidos(jug->getIntentosFallidos() -1 );
	}

}
void Juego::adivinarLetra(char ca, Jugador* jug) {//Adivinar letra

	bool perdiVidas = true;

	for (unsigned int i = 0; i < original.length(); i++) {
		if (tolower(ca) == original[i]&&copia[i]=='_') {
			perdiVidas = false;
			jug->setPuntaje(jug->getPuntaje() + 2);
			copia[i] = ca;
		}
	}
		if (perdiVidas) {
			jug->setPuntosPerdidos(jug->getPuntosPerdidos()+2);
			jug->setIntentos(jug->getIntentos() + 1);
			jug->setIntentosFallidos(jug->getIntentosFallidos() - 1);
		}
		else {
			jug->setIntentos(jug->getIntentos() + 1);
		}
}
ListaPalabra* Juego::getListaPalabra() {//Devuelve lista de palabras
	return lisPal;
}
ListaJugador* Juego::getListaJugador() {//Devuelve lista de jugadores
	return lisJug;
}
void Juego::muestraPalabra() {//Muestra palabra copia
	cout << copia << endl;
}
void Juego::iniciar() {//Inicializa atributos

	original = lisPal->seleccionaAlAzar()->getLetras();
	jug1 = Interfaz::creaJugador();
	jug2 = Interfaz::creaJugador();

	cout<<jug1->toString()<<endl;
	cout<<jug2->toString()<<endl;
	
	system("pause");

	for (unsigned int i = 0; i < original.length(); i++) {
		original[i] = tolower(original[i]);
	}
	for (unsigned int i = 0; i < original.length(); i++) {
		if (original[i] >= 'a' && original[i] <= 'z') {
			copia += '_';
		}
		else {
			copia += original[i];
		}
	}
}
void Juego::reiniciaTodo(Jugador* juga1,Jugador* juga2) {//Reinicia atributos
	juga1->setIntentos(0);
	juga1->setIntentosFallidos(3);
	juga1->setPuntaje(0);
	juga1->setPuntosPerdidos(0);
	juga2->setIntentos(0);
	juga2->setIntentosFallidos(3);
	juga2->setPuntaje(0);
	juga2->setPuntosPerdidos(0);
	
	original = lisPal->seleccionaAlAzar()->getLetras();
	copia = "";
	for (unsigned int i = 0; i < original.length(); i++) {
		if (original[i] >= 'A' && original[i] <= 'Z') {
			original[i] += 32;
		}
	}
	for (unsigned int i = 0; i < original.length(); i++) {
		if (original[i] >= 'a' && original[i] <= 'z') {
			copia += '_';
		}
		else {
			copia += original[i];
		}
	}
}
bool Juego::estado() {//Verifica el estado del juego
	if (copia == original || (jug1->getIntentosFallidos() == 0 && jug2->getIntentosFallidos() == 0))
		return true;
	else
		return false;
}