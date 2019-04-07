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

ostream& operator <<(ostream& salida, const DtPerro& dtp) {
	cout << "Nombre: " << dtp.nombre << "\nGenero: " << dtp.genero << "\nPeso: " << dtp.peso<< " kg " << "\nRacion Diaria: " << dtp.racionDiaria << "\nTiene vacuna del Cachorro: " ;	
	if (dtp.vacunaCachorro)
			cout << "Si" ;
	else
		cout << "No"; 
	
	return salida;
}


RazaPerro DtPerro::getRazaPerro(){
	return 	this->raza; 
}

bool DtPerro::getVacunaCachorro(){
	return 	this->vacunaCachorro; 
}

DtPerro::~DtPerro(){}
