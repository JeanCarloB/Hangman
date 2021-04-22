#pragma once
#include "NodoPalabra.h"
class ListaPalabra{
public:
    ListaPalabra();//Contructor lista palabra
    virtual ~ListaPalabra();//Destructor lista palabra
    string toString();//Metodo toString
    Palabra* existePalabra(string);//Comprueba si existe palabra
    void insertaAlPricipio(Palabra*);//Metodo inserta palabra al principio
    void insertaAlFinal(Palabra*);//Metodo inserta palabra al final
    int cuentaNodos();//Metodo cuenta palabras
    bool listaVacia();//Combrueba si la lista esta vacia
    Palabra* seleccionaAlAzar();//Selecciona palabra al azar
    Palabra* elimina(string);//Elimina una palabra 
    void eliminaNodo(NodoPalabra*,NodoPalabra*);//Elimina nodo por medio de parametros enviados de metodo elimina
    void leerPalabras();//Leer palabras  
    void guardarPalabras();//Guarda palabras
private:
    NodoPalabra* ppio;//Atributo nodo palabra

};

