#include <cstdlib>
#include <iostream>
#include "DtFecha.h"
#include <ctime>

using namespace std;

//DataType Fecha
DtFecha::DtFecha () {
	time_t fecha = time(0);
	
	tm *ltm = localtime(&fecha);
   
	dia = ltm->tm_mday;
	mes =  1 + ltm->tm_mon;
	anio = 1970 + ltm->tm_year;
}
DtFecha::DtFecha (int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int DtFecha::getDia(){
	return this->dia;	
}

int DtFecha::getMes(){
	return this->mes;	
}

int DtFecha::getAnio(){
	return this->anio;	
}


