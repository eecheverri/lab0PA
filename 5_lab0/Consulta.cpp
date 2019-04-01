#include "Consulta.h"

//constructor por defecto
Consulta::Consulta()
{
  fechaConsulta = "";//ver tema fecha
  motivo = "";
}
//constructor comun
Consulta:Consulta(DtFecha pfechaConsulta, string pmotivo)
{
  fechaConsulta = pfechaConsulta;
  motivo = pmotivo;
}

//propiedades
void setFechaConsulta(DtFecha pfechaConsulta)
{
  fechaConsulta = pfechaConsulta;
}

DtFecha getFechaConsulta()
{
  return fechaConsulta;
}

void setMotivo(string pmotivo)
{
  motivo = pmotivo;
}

string getMotivo()
{
  return motivo;
}

//Destructor
Consulta::~Consulta(){}
