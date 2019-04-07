#ifndef DtGato_H
#define DtGato_H
#include "TipoPelo.h"
#include "DtMascota.h"

using namespace std;

class DtGato : public DtMascota{

private : 
	TipoPelo tipoPelo;

public :
	DtGato();
	DtGato(string,Genero,float,float,TipoPelo);
	friend ostream& operator << (ostream&, const DtGato&);
	TipoPelo getTipoPelo();
	~DtGato();
};
#endif
