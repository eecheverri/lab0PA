#include <cstdlib>
#include <iostream>
#include "TipoPelo.h"

using namespace std;


TipoPelo::TipoPelo () {
	this->nombre = Corto;
}
TipoPelo::TipoPelo (tipoPelo nombre){
	this->nombre = nombre;
}

tipoPelo TipoPelo::getTipoPelo(){
	return this->nombre;
}

