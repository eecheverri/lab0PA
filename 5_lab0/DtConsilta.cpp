#include "DtConsulta.h"

DtConsulta::DtConsulta () {
	fechaConsulta = DtFecha();
	motivo = "motivo";
}

DtConsulta::DtConsulta (DtFecha fechaConsulta,string motivo) {
	this->fechaConsulta = fechaConsulta;
	this->motivo = motivo;
}

DtConsulta::~DtConsulta(){}


