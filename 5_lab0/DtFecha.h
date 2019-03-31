#ifndef DtFecha_H
#define DtFecha_H

using namespace std;

class DtFecha{
	

private : 
	int  dia;
   	int  mes;
   	int  anio;

public :
	DtFecha();
	DtFecha(int,int,int);	
	int getDia();
	int getMes();
	int getAnio();
};
#endif

