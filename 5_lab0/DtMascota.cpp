#include <cstdlib>
#include <iostream>
#include "DtMascota.h"


using namespace std;


DtMascota::DtMascota () {
	nombre = "";
	genero = Macho;
    peso = 0;
 	racionDiaria = 0;
}

DtMascota::DtMascota (string nombre,Genero genero,float peso,float racionDiaria) {
	this->nombre = nombre;
	this->genero = genero;
	this->peso = peso;
	this->racionDiaria = racionDiaria;        
}


