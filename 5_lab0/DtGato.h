#ifndef DtGato_H
#define DtGato_H
#include "TipoPelo.h"
#include "DtMascota.h"
#include "Gato.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class DtGato : public DtMascota{

private : 
	TipoPelo tipoPelo;

public :
	DtGato();
	DtGato(string,Genero,float,float,TipoPelo);
	DtGato(const DtGato&);
	DtGato(Gato*);
	friend ostream& operator << (ostream&, const DtGato&);	
	TipoPelo getTipoPelo();
	float getracionDiaria();
	~DtGato();

};
#endif
