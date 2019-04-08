#include "Consulta.h"
#include "DtFecha.h"

//constructor por defecto
Consulta::Consulta()
{
  fechaConsulta = DtFecha();
  motivo = "";
}
//constructor comun
Consulta::Consulta(DtFecha pfechaConsulta, string pmotivo)
{
  fechaConsulta = pfechaConsulta;
  motivo = pmotivo;
}

//propiedades
void Consulta::setFechaConsulta(DtFecha pfechaConsulta)
{
  fechaConsulta = pfechaConsulta;
}

DtFecha Consulta::getFechaConsulta()
{
  return fechaConsulta;
}

void Consulta::setMotivo(string pmotivo)
{
  motivo = pmotivo;
}

string Consulta::getMotivo()
{
  return motivo;
}

//Destructor
Consulta::~Consulta(){}
