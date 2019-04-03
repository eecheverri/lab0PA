#ifndef Socio_H
#define Socio_H

#include "DtFecha.h"
#include "Mascota.h"
#include "Consulta.h"

using namespace std;

class Socio
{
  private:
    //Atributos
    string ci;
    string nombre;
    DtFecha fechaIngreso;
	
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
  
  //void agregarMascota(Mascota*);  
  
  //void agregarConsulta(Consulta*); 
  
  //Consulta** verConsultasAntesDeFecha(DtFecha);
  
  //Destructor
  ~Socio();
  
};

#endif
