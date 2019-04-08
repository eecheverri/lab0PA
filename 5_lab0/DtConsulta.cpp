#include "DtConsulta.h"

DtConsulta::DtConsulta () {
	fechaConsulta = DtFecha();
	motivo = "motivo";
}

DtConsulta::DtConsulta (DtFecha fechaConsulta,string motivo) {
	this->fechaConsulta = fechaConsulta;
	this->motivo = motivo;
}

DtConsulta::DtConsulta (Consulta* consulta){	
	this->fechaConsulta = consulta->getFechaConsulta();
	this->motivo = consulta->getMotivo();
}

DtConsulta::~DtConsulta(){}

DtFecha DtConsulta::getFecha(){ 
	return this->fechaConsulta;
}

string DtConsulta::getMotivo(){
	return this->motivo;
}

ostream& operator <<(ostream& salida, const DtConsulta& dtConsulta) {
	cout << dtConsulta.fechaConsulta << " - " << dtConsulta.motivo << "\n";
	return salida;
}


