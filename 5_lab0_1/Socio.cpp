#include "Socio.h"
#include <iostream>

Socio::Socio() {
	this->ci = "ci";
	this->nombre = "nombre";
	this->fechaIngreso = DtFecha();
	this->topeM = 0;
}

Socio::Socio(string ci,string nombre,DtFecha fechaIngreso){
	this->ci = ci;
	this->nombre = nombre;
	this->fechaIngreso = fechaIngreso;
	this->topeM = 0;
}

string Socio::getCi(){
	return this->ci;
}

void Socio::setCi(string ci){
	this->ci = ci;
}

string Socio::getNombre(){
	return this->nombre;
}

void Socio::setNombre(string nombre){
	this->nombre = nombre;
}

void Socio::setFechaIngreso(DtFecha fechaIngreso){
	this->fechaIngreso = fechaIngreso;		
}

DtFecha Socio::getFechaIngreso(){
	return this->fechaIngreso;	
}

void Socio::agregarMascota(Mascota* mascota) {		
	//cout << "this->mascotas[i]" << mascota->getNombre();	
	this->mascotas[topeM] = mascota;	
	//cout << "this--------------------------->mascotas[i]" << this->mascotas[this->topeM]->getNombre();	
	this->topeM++;	
}

Mascota** Socio::obtenerMascotas(int& cantMascotas) {
	cantMascotas = this->topeM;
	Mascota** mascotasArr = new Mascota*[this->topeM];
	//cout << "mascotasArr[i] "<<mascotasArr[1]->getNombre() :
	//cout << "this->mascotas[i]" << this->mascotas[1]->getNombre();
	for( int i = 0; i < this->topeM; i++ ) {		
	  mascotasArr[i] = this->mascotas[i];	  
	}
	return mascotasArr;
}

void Socio::agregarConsulta(Consulta* consulta){	
	this->consultas[topeC] = consulta;	
	this->topeC++;
}

Consulta** Socio::verConsultasAntesDeFecha(DtFecha dtFecha,int& cantConsultas){		
	Consulta** consultasArr = new Consulta*[this->topeC];
	cantConsultas = 0;
	for( int i = 0; i < this->topeC; i++ ) {	
	//cout << "------------------" << consultas[i]->getFechaConsulta() << "\n";
		if (this->consultas[i]->getFechaConsulta() < dtFecha ) {
	  		consultasArr[i] = this->consultas[i];	  
	  		cantConsultas++;	  		
	  	}
	}	
	return consultasArr;
	
	
}
  
Socio::~Socio() {
	for( int i = 0; i < this->topeM; i++ ) {		
	  delete this->mascotas[i];	  
	}
	
	for( int i = 0; i <= this->topeC; i++ ) {
	  delete this->consultas[i];
	}
}


