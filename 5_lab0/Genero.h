#ifndef GENERO_H
#define GENERO_H

using namespace std;

enum genero{Macho,Hembra};

class Genero{
	

private : 
		genero  nombre;

public :
	Genero();
	Genero(genero);	
	genero getGenero();
};
#endif
