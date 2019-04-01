#include "Gato.h"

//constructor por defecto
Gato::Gato()
{
  tipoPelo = "Mediano";
}

//constructor comun
Gato:Gato(TipoPelo ptipoPelo):base(pnombre, pgenero, ppeso)
{
  tipoPelo = ptipoPelo;
}

//propiedades
void setTipoPelo(TipoPelo ptipoPelo)
{
  tipoPelo = ptipoPelo;
}

TipoPelo getTipoPelo()
{
  return tipoPelo;
}

//Operaciones
float Gato::obtenerRacionDiaria()
{
  return base.peso * 0.015;
}

  
//Destructor
Gato::~Gato(){}
