#ifndef DtPerro_H
#define DtPerro_H
#include "RazaPerro.h"
#include "DtMascota.h"
#include "Perro.h"

using namespace std;

class DtPerro : public DtMascota{

private : 
	RazaPerro raza;
	bool vacunaCachorro;

public :
	DtPerro();
	DtPerro(string,Genero,float,float,RazaPerro,bool);	
	DtPerro(const DtPerro&);
	DtPerro(Perro*);
	friend ostream& operator << (ostream&, const DtPerro&);
	RazaPerro getRazaPerro();
	bool getVacunaCachorro();
	float getracionDiaria();
	~DtPerro();
};
#endif
