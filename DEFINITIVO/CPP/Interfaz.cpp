#include "Interfaz.h"
Jugador* Interfaz::creaJugador() {//Crea jugador
	string ini;
	string rem;
devolver:
	system("cls");
	cout << "Digite sus tres iniciales para el nombre" << endl;
	cin >> ini;
	for (unsigned int i = 0; i < ini.length(); i++) {
		rem += toupper(ini[i]);
	}
	if (rem.length() == 3) {
		return new Jugador(rem, 0, 0, 3,0);
	}
	else {
		cout << "Digite solamente tres iniciales" << endl;
		system("pause");
		goto devolver;
	}
	cout << "Registrado por favor espere jugador..." << endl;
	Sleep(3000);
}
Administrador* Interfaz::creaAdministrador() {//Crea administrador
	system("cls");
	cout << "Inicio de sesion administrador" << endl << endl;
	Administrador* adm = NULL;
	string nom;
	string contra;
	cout << "Digite el nombre" << endl;
	cin >> nom;
	cout << "Digite la contrasena" << endl;
	cin >> contra;
	if (contra == "admin") {
		adm = new Administrador(nom, contra);
	}
	return adm;
}