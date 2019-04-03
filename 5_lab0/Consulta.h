#ifndef Consulta_H
#define Consulta_H

#include <string>
#include "DtFecha.h"
class Consulta 
{
  private:
    //Atributos
    DtFecha fechaConsulta;
    string motivo;
  public:
  //Constructores
  //Constructor por defecto
  Consulta();
  //Constructor comun
  Consulta(DtFecha , string);
  
  //Propiedades
  void setFechaConsulta(DtFecha pfechaConsulta);
  DtFecha getFechaConsulta();
  
  void setMotivo(string pmotivo);
  string getMotivo();

  //Destructor
  ~Consulta();
  
};//Fin Consulta

#endif
  
