#include "TipoPelo.h"
#include "DtGato.h"

using namespace std;

DtGato::DtGato () {
	this->tipoPelo = Corto;
}

DtGato::DtGato (string nombre,Genero genero,float peso,float racionDiaria,TipoPelo tipoPelo):DtMascota(nombre,genero,peso,racionDiaria){
	this->tipoPelo = tipoPelo;
	//prueba git
}

DtGato::DtGato (const DtGato& dtGato){	
	this->nombre = dtGato.nombre;	
	this->genero = dtGato.genero;
    this->peso = dtGato.peso;
 	this->racionDiaria = dtGato.racionDiaria;
 	this->tipoPelo = dtGato.tipoPelo;
}

DtGato::DtGato (Gato* gato){	
	this->nombre = gato->getNombre();	
	this->genero = gato->getGenero();
    this->peso = gato->getPeso();
 	this->racionDiaria = gato->obtenerRacionDiaria();
 	this->tipoPelo = gato->getTipoPelo();
}
	
ostream& operator <<(ostream& salida, const DtGato& dtg) {
	cout << "Nombre: " << dtg.nombre << "\nGenero: ";
	if (dtg.genero == Macho)
		cout << "Macho ";	
	else
		cout << "Hembra ";
			
	cout << "\nPeso: " << dtg.peso<< " kg " << "\nRacion Diaria: " << dtg.racionDiaria << "\nTipo de pelo "  ;	
	if (dtg.tipoPelo == Corto) 
		cout << "Corto ";	
	else if (dtg.tipoPelo == Mediano)
		cout << "Mediano ";	
	else if (dtg.tipoPelo == Largo)
		cout << "Largo ";	
	cout << "\n ";		

	return salida;
}

TipoPelo DtGato::getTipoPelo() {
	return 	this->tipoPelo;
}

float DtGato::getracionDiaria() {
	return this->racionDiaria;
}


DtGato::~DtGato(){}
