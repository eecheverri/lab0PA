#include "Socio.h"

Socio::Socio() {
	this->ci = "ci";
	this->nombre = "nombre";
	this->fechaIngreso = DtFecha();
	this->tope = 0;
}

Socio::Socio(string ci,string nombre,DtFecha fechaIngreso){
	this->ci = ci;
	this->nombre = nombre;
	this->fechaIngreso = fechaIngreso;
	this->tope = 0;
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
	
	this->tope++;
	this->mascotas[tope] = mascota;
	
}

Mascota** Socio::obtenerMascotas(int& cantMascotas) {
	cantMascotas = this->tope;
	Mascota** mascotasArr = new Mascota*[this->tope];
	for( int i = 0; i <= this->tope; i++ ) {
	  mascotasArr[i] = this->mascotas[i];
	}
	return mascotasArr;
}
Socio::~Socio() {

}


