#include "Mascota.h"

//constructor por defecto
Mascota::Mascota()
{
  nombre = "";
  genero = null;
  peso = 0;
}
//constructor comun
Mascota:Mascota(string pnombre, Genero pgenero, float ppeso)
{
  nombre = pnombre;
  genero = pgenero;
  peso = ppeso;
}

//propiedades
void setNombre(string pnombre)
{
  nombre = pnombre;
}

string getNombre()
{
  return nombre;
}

void setGenero(Genero pgenero)
{
  genero = pgenero;
}

Genero getGenero()
{
  return genero;
}

void setPeso(float ppeso)
{
  peso = ppeso;
}

float getPeso()
{
  return peso;
}

//Operaciones
  
public:virtual float obtenerRacionDiaria(){}//Duda de sintaxis
  
//Destructor
Mascota::~Mascota(){}
  
