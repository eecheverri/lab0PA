#ifndef DtMascota_H
#define DtMascota_H
#include "Genero.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class DtMascota{

protected : 
		string  nombre;
        Genero  genero;
        float   peso;
        float   racionDiaria;

public :
	DtMascota();
	DtMascota(string ,Genero ,float ,float );
	DtMascota(const DtMascota&);
	string getNombre();
	Genero getgenero();
	float getPeso();
	virtual float getracionDiaria() = 0;
	virtual~DtMascota();

};
#endif
