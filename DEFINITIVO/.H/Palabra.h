#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <ctime>
#include <string>
#include <wchar.h>
#include <locale.h>
using namespace std;
class Palabra{
private:
	string letras;//Atributo letras
public:
	Palabra(string="");//Constructor palabra
	virtual ~Palabra();//Destructor palabra
	string toString();//Metodo toString
	string getLetras();//Metodo get letras
	void setLetras(string);//Metodo set letras
	void guardaPalabra(ofstream&);//Metodo auto guarda palabra
	Palabra* leePalabra(ifstream&);//Metodo guarda palabra
};

