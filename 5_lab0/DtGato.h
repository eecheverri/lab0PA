#ifndef DtPerro_H
#define DtPerro_H
#include "TipoPelo.h"
#include "DtMascota.h"

using namespace std;

class DtGato : public DtMascota{

private : 
	TipoPelo tipoPelo;

public :
	DtGato();
	DtGato(string,Genero,float,float,TipoPelo);
};
#endif
