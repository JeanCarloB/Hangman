#include "Controladora.h"
Controladora::Controladora() {//Constructor controladora
	jue = new Juego();
}
Controladora::~Controladora() {//Destructor controladora
	if (jue!=NULL) {
		delete jue;
	}
}
int Controladora::menu() {//Menu principal
	int opc=0;
	do {
		system("cls");
		cout << "**************************" << endl;
		cout << "**************************" << endl;
		cout << "---------- MENU ----------" << endl;
		cout << "**************************" << endl;
		cout << "**************************" << endl<<endl;
		cout << "1.Ingresar gestion palabras"<<endl;
		cout << "2.Ingresar para jugar"<<endl;
		cout << "3.Salir" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opc;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024,'\n');
			opc = menu();
		}
			switch (opc) {
			case 1:
				this->menuGestionPalabras();
				break;
			case 2:
				jue->jugar();
				break;
			case 3:
				system("cls");
				cout << "****************************************" << endl;
				cout << "****************************************" << endl;
				cout << "----- GRACIAS POR UTILIZAR NUESTRO -----" << endl;
				cout << "------------ PRODUCTO!!! :D ------------" << endl;
				cout << "****************************************" << endl;
				cout << "****************************************" << endl;
				system("pause");
				break;
			}
	} while (opc!=3);
	return opc;
}
int Controladora::menuGestionPalabras() {//Menu gestion de palabras
	int opc=0;
	Administrador* admin=Interfaz::creaAdministrador();//Crea administrador
	if (admin == NULL) {
		cout << "Contrasena incorrecta, digite una contrasena valida" << endl;
		Sleep(2000);
		opc = menu();
	}
	do {
		system("cls");
		cout << "***********************************************" << endl;
		cout << "***********************************************" << endl;
		cout << "---------- MENU - GESTION - PALABRAS ----------" << endl;
		cout << "***********************************************" << endl;
		cout << "***********************************************" << endl<<endl;
		cout << "1.Ingresar palabra" << endl;
		cout << "2.Visualizar palabras" << endl;
		cout << "3.Modificar palabra" << endl;
		cout << "4.Eliminar palabra" << endl;
		cout << "5.Salir" << endl;
		cout << "\nDigite una opcion: ";
		cin >> opc;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		switch (opc) {
		case 1:this->ingresarPalabra();break;
		case 2:this->mostrarPalabras();break;
		case 3:this->modificarPalabra();break;
		case 4:this->eliminarPalabra();break;
		case 5:cout << "Volviendo al menu principal..." << endl; Sleep(2000);
		}
	} while (opc != 5);
	return opc;
}
void Controladora::mostrarPalabras() {//Mostrar palabras que existen
	system("cls");
	cout<<jue->getListaPalabra()->toString()<<endl;
	system("pause");
}
void Controladora::ingresarPalabra() {//Ingresa palabra en caso de no existir
	system("cls");
	Palabra* pala;
	string pal;
	string rem;
	cout << "Digite la palabra  aingresar" << endl;
	cin >> pal;
	for (unsigned int i = 0;i<pal.length();i++) {
		rem += tolower(pal[i]);
	}
	pala = jue->getListaPalabra()->existePalabra(rem);
	if (pala == NULL){
		jue->getListaPalabra()->insertaAlFinal(new Palabra(rem));
		cout << "Se ingreso correctamente" << endl;
	}else{
		cout << "Ya se encuentra en lista" << endl;
	}
	system("pause");
}
void Controladora::eliminarPalabra() {//Elimina palabra si existe 
	system("cls");
	string carac;
	string rem;
	Palabra* pala;
	cout<<jue->getListaPalabra()->toString()<<endl;
	cout << "Digite la palabra que desea eliminar" << endl;
	cin >> carac;
	for (unsigned int i = 0; i < carac.length(); i++) {
		rem += tolower(carac[i]);
	}
	pala = jue->getListaPalabra()->elimina(rem);
	if (pala != NULL) {
		cout << "Palabra eliminada de la lista" << endl;
	}
	else {
		cout << "No se encuentra la palabra en la lista" << endl;
	}
	system("pause");
}
void Controladora::modificarPalabra() {//Modifica palabra si existe
	system("cls");
	Palabra* pala;
	string pal;
	string rem;
	string nueva;
	string nue;
	cout << "Digite la palabra  a modificar" << endl;
	cin >> pal;
	for (unsigned int i = 0; i < pal.length(); i++) {
		rem += tolower(pal[i]);
	}
	pala = jue->getListaPalabra()->existePalabra(rem);
	if (pala != NULL) {
		cout << "Digite la nueva palabra" << endl;
		cin >> nueva;
		for (unsigned int i = 0; i < nueva.length(); i++) {
			nue += tolower(nueva[i]);
		}
		pala->setLetras(nue);
		cout << "Se modifico correctamente" << endl;
	}
	else {
		cout << "No se encuentra en la lista" << endl;
	}
	system("pause");
}
void Controladora::control() {//Controla todo el sistema de gestion de palabras y jugadores, así como el menu
	jue->getListaPalabra()->leerPalabras();
	jue->getListaJugador()->leerJugadores();
	this->menu();
	jue->getListaPalabra()->guardarPalabras();
	jue->getListaJugador()->guardarJugadores();
}