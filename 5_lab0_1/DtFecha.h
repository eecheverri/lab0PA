#ifndef DtFecha_H
#define DtFecha_H
#include <cstdlib>
#include <iostream>

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
	friend ostream& operator << (ostream&, const DtFecha&);
	friend bool operator < (const DtFecha&,const DtFecha&);
	friend bool operator <= (const DtFecha&,const DtFecha&);
};
#endif

