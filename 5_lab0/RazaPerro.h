#ifndef RazaPerro_H
#define RazaPerro_H

using namespace std;

enum razaPerro{labrador, ovejero, bulldog, pitbull, collie, pekines, otro};

class RazaPerro{

private : 
	razaPerro  nombre;

public :
	RazaPerro();
	RazaPerro(razaPerro);
	razaPerro getRazaPerro();
};
#endif
