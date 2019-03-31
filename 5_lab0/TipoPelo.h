#ifndef TipoPelo_H
#define TipoPelo_H

using namespace std;

enum tipoPelo{Corto,Mediano,Largo};

class TipoPelo{

private : 
	tipoPelo  nombre;

public :
	TipoPelo();
	TipoPelo(tipoPelo);
	tipoPelo getTipoPelo();
};
#endif

