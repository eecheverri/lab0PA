#ifndef DtConsulta_H
#define DtConsulta_H

#include <cstdlib>
#include <iostream>
#include "DtFecha.h"

using namespace std;

class DtConsulta{

private : 
		DtFecha  fechaConsulta;
        string  motivo;

public :
	DtConsulta();
	DtConsulta(DtFecha ,string);
	
	~DtConsulta();

};
#endif
