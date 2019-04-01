#ifndef Socio
#define Socio

#include <map>
#include <string>

class Socio
{
  private:
    //Atributos
    string ci;
    string nombre;
    DtFecha fechaingreso;
    //map<Mascota, int> * mapMascotas;
    //map<Consulta, int> * mapConsultas;
  public:
  //Constructores
  //Constructor por defecto
  Socio();
  
  //Constructor comun
  Socio(string pci, string, pnombre, DtFecha pfechaingreso, map<Mascota, int> pmapMascotas, map<Consulta, int> * pmapConsultas);
  
  //Propiedades
  void setCi(string pci);
  string getCi();
  
  void setNombre(string pnombre);
  string getNombre();
  
  void setFechaIngreso(DtFecha pfechaingreso);
  DtFecha getFechaIngreso();
  
  /*
  void setMapMascotas(map<Mascota, int> pmapMascotas);
  map<Mascota, int> getMapMascotas();
  
  void setMapConsultas(map<Consulta, int> pmapConsultas);
  map<Consulta, int> getMapConsultas();*/
  
  
  
  //Destructor
  ~Socio();
  
}

#endef
