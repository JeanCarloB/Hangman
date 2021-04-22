#include "NodoPalabra.h"
NodoPalabra::NodoPalabra(NodoPalabra* si, Palabra* pa)
    :sig(si), pal(pa) {}//Contructor nodo palabra
NodoPalabra::~NodoPalabra() {//Destructor nodo palabra
    if (pal != NULL)
        delete pal;
}
NodoPalabra* NodoPalabra::getSiguiente() { return sig; }//Metodo get siguiente
void NodoPalabra::setSiguiente(NodoPalabra* si) { sig = si; }//Metodo set siguiente
Palabra* NodoPalabra::getPalabra() { return pal; }//Metodo get palabra
void NodoPalabra::setPalabra(Palabra* pa) { pal = pa; }//Metodo set palabra
