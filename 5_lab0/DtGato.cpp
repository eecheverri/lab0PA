#include <cstdlib>
#include <iostream>
#include "TipoPelo.h"
#include "DtGato.h"

using namespace std;

DtGato::DtGato () {
	this->tipoPelo = Corto;
}

DtGato::DtGato (string nombre,Genero genero,float peso,float racionDiaria,TipoPelo tipoPelo):DtMascota(nombre,genero,peso,racionDiaria){
	this->tipoPelo = tipoPelo;
}
