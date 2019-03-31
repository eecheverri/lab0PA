#ifndef DtPerro_H
#define DtPerro_H
#include "RazaPerro.h"
#include "DtMascota.h"

using namespace std;

class DtPerro : public DtMascota{

private : 
	RazaPerro raza;
	bool vacunaCachorro;

public :
	DtPerro();
	DtPerro(string,Genero,float,float,RazaPerro,bool);

};
#endif
