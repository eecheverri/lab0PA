#include "Gato.h"

//constructor por defecto
Gato::Gato()
{
  tipoPelo = Mediano;
}

//constructor comun
Gato::Gato(string nombre, Genero genero, float peso, TipoPelo tipoPelo):Mascota(nombre, genero, peso)
{
  this->tipoPelo = tipoPelo;
}

//propiedades
void Gato::setTipoPelo(TipoPelo tipoPelo)
{
  this->tipoPelo = tipoPelo;
}

TipoPelo Gato::getTipoPelo()
{
  return this->tipoPelo;
}

//Operaciones
float Gato::obtenerRacionDiaria()
{
  return this->getPeso() * 0.015f;//base->peso * 0.015;
}

string Gato::SoyUn(){
	return "G";
}

//Destructor
Gato::~Gato(){}
