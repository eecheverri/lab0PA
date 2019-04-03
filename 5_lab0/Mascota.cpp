#include "Mascota.h"

//constructor por defecto
Mascota::Mascota()
{
  nombre = "nombre";
  genero = Genero();
  peso = 0;
}
//constructor comun
Mascota::Mascota(string nombre, Genero genero, float peso)
{
  this->nombre = nombre;
  this->genero = genero;
  this->peso = peso;
}

//propiedades
void Mascota::setNombre(string nombre)
{
  this->nombre = nombre;
}

string Mascota::getNombre()
{
  return this->nombre;
}

void Mascota::setGenero(Genero genero)
{
  this->genero = genero;
}

Genero Mascota::getGenero()
{
  return this->genero;
}

void Mascota::setPeso(float peso)
{
  this->peso = peso;
}

float Mascota::getPeso()
{
  return this->peso;
}
  
//Destructor
Mascota::~Mascota(){}
  
