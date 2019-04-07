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

DtMascota::DtMascota (const DtMascota& dtMascota){	
	this->nombre = dtMascota.nombre;	
	this->genero = dtMascota.genero;
    this->peso = dtMascota.peso;
 	this->racionDiaria = dtMascota.racionDiaria;
}
	
string DtMascota::getNombre () {
	return this->nombre;
}

Genero DtMascota::getgenero () {
	return this->genero;  
}
float DtMascota::getPeso () {
	return this->peso;
}
/*float DtMascota::getracionDiaria () {
	return this->racionDiaria;
}*/

DtMascota::~DtMascota(){}
