#include <cstdlib>
#include <iostream>
#include "RazaPerro.h"
#include "DtPerro.h"

using namespace std;

DtPerro::DtPerro () {
	this->raza = otro;
	this->vacunaCachorro = false;
}

DtPerro::DtPerro (string nombre,Genero genero,float peso,float racionDiaria,RazaPerro raza,bool vacunaCachorro):DtMascota(nombre,genero,peso,racionDiaria){
	this->raza = raza;
	this->vacunaCachorro = vacunaCachorro;
}
