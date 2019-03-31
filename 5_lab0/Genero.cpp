#include <cstdlib>
#include <iostream>
#include "Genero.h"

using namespace std;


Genero::Genero () {
	this->nombre = Macho;
}
Genero::Genero (genero nombre){
	this->nombre = nombre;
}

genero Genero::getGenero (){
	return this->nombre;
}
