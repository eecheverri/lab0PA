#include "Perro.h"

//constructor por defecto
Perro::Perro()
{
  raza = "otro";
  vacunaCachorro = false;
}

//constructor comun
Perro:Perro(RazaPerro praza, bool pvacunaCachorro):base(pnombre, pgenero, ppeso)
{
  raza = praza;
  vacunaCachorro = pvacunaCachorro;
}

//propiedades
void setRaza(RazaPerro praza)
{
  raza = praza;
}

RazaPerro getRaza()
{
  return raza;
}

void setVacunaCachorro(bool pvacunaCachorro)
{
  vacunaCachorro = pvacunaCachorro;
}

bool getVacunaCachorro()
{
  return vacunaCachorro;
}

//Operaciones
float Perro::obtenerRacionDiaria()
{
  return base.peso * 0.025;
}

  
//Destructor
Perro::~Perro(){}
