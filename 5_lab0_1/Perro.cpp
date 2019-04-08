#include "Perro.h"


//constructor por defecto
Perro::Perro()
{
  raza = otro;
  vacunaCachorro = false;
}

//constructor comun
Perro::Perro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro):Mascota(nombre, genero, peso)
{
  this->raza = raza;
  this->vacunaCachorro = vacunaCachorro;
}

//propiedades
void Perro::setRazaPerro(RazaPerro praza)
{
  raza = praza;
}

RazaPerro Perro::getRazaPerro()
{
  return this->raza;
}

void Perro::setVacunaCachorro(bool pvacunaCachorro)
{
  vacunaCachorro = pvacunaCachorro;
}

bool Perro::getVacunaCachorro()
{
  return this->vacunaCachorro;
}

//Operaciones
float Perro::obtenerRacionDiaria()
{
  return getPeso() * 0.025f;
}

string Perro::SoyUn(){
	return "P";
}
//Destructor
Perro::~Perro(){}
