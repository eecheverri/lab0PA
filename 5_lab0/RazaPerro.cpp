#include <cstdlib>
#include <iostream>
#include "RazaPerro.h"

using namespace std;


RazaPerro::RazaPerro () {
	this->nombre = otro;
}
RazaPerro::RazaPerro (razaPerro nombre){
	this->nombre = nombre;
}

razaPerro RazaPerro::getRazaPerro(){
	return this->nombre;
}
