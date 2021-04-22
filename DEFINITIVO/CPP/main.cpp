#include "Controladora.h"
int main() {
	srand((unsigned)time(NULL));//Sead para seleccionar palabra al azar
	SetConsoleOutputCP(65001);//Setea salida de consola para mostrar caracteres especiales
	Controladora* con=new Controladora();//Instancia controladora
	con->control();//Metodo control
	delete con;//Elimina instancia controladora
	return 0;
}