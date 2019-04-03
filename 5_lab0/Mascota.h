#ifndef Mascota_H
#define Mascota_H

#include <string>
#include "Genero.h"

using namespace std;

class Mascota 
	{
	private:
	  //Atributos
	  string nombre;
	  Genero genero;
	  float peso;
	  
	public:
	  
	  //Constructores
	  
	  //Constructor por defecto
	  Mascota();
	  
	  //Constructor comun
	  Mascota(string, Genero, float);
	  
	  //Propiedades
	  
	  void setNombre(string);
	  string getNombre();
	  
	  void setGenero(Genero);
	  Genero getGenero();
	  
	  void setPeso(float);
	  float getPeso();
	  
	  //Operaciones
	  
	  virtual float obtenerRacionDiaria() = 0;
	  
	  //Destructor
	  virtual ~Mascota();
	  
};//Fin mascota
	
#endif
	  
	  
  
  
