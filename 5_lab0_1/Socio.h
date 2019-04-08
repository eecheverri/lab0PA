#ifndef Socio_H
#define Socio_H

#include "DtFecha.h"
#include "Mascota.h"
#include "Consulta.h"

#define MAX_MASCOTAS 10
#define MAX_CONSULTAS 20

using namespace std;

/*struct mascotas{
	Mascota* mascotas[MAX_MASCOTAS];
	int tope;
} ;*/


class Socio
{
  private:
    //Atributos
    string ci;
    string nombre;
    DtFecha fechaIngreso;
	Mascota* mascotas[MAX_MASCOTAS];
	Consulta* consultas[MAX_CONSULTAS];
	int topeM,topeC;
	
  public:
  //Constructores
  //Constructor por defecto
  Socio();
  
  //Constructor comun
  Socio(string, string, DtFecha);
  
  //Propiedades
  void setCi(string);
  string getCi();
  
  void setNombre(string);
  string getNombre();
  
  void setFechaIngreso(DtFecha);
  DtFecha getFechaIngreso();
  
  void agregarMascota(Mascota*); 
  
  Mascota** obtenerMascotas(int&);
  
  void agregarConsulta(Consulta*); 
  
  Consulta** verConsultasAntesDeFecha(DtFecha,int&);
  
  //Destructor
  ~Socio();
  
};

#endif
