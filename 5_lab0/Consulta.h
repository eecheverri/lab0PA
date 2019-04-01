#ifndef Consulta
#define Consulta

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
  Consulta(DtFecha pfechaConsulta, string pmotivo);
  
  //Propiedades
  void setFechaConsulta(DtFecha pfechaConsulta);
  DtFecha getFechaConsulta();
  
  void setMotivo(string pmotivo);
  string getMotivo();

  //Destructor
  ~Consulta();
  
}//Fin Consulta

#endef
  
