#ifndef DtMascota_H
#define DtMascota_H
#include "Genero.h"

using namespace std;

class DtMascota{

private : 
		string  nombre;
        Genero  genero;
        float   peso;
        float   racionDiaria;

public :
	DtMascota();
	DtMascota(string ,Genero ,float  ,float );

};
#endif
