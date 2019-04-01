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
    //map<Mascota, int> * listaMascotas;
    //map<Consulta, int> * listaConsultas;
  public:
  //Constructores
  //Constructor por defecto
  Socio();
  
  //Constructor comun
  Socio(string pci, string, pnombre, DtFecha pfechaingreso, map<Mascota, int> plistaMascotas, map<Consulta, int> * plistaConsultas);
  
  //Propiedades
  void setCi(string pci);
  string getCi();
  
  void setNombre(string pnombre);
  string getNombre();
  
  void setFechaIngreso(DtFecha pfechaingreso);
  DtFecha getFechaIngreso();
  
  /*
  void setListaMascotas(map<Mascota, int> plistaMascotas);
  map<Mascota, int> getListaMascotas();
  
  void setListaConsultas(map<Consulta, int> plistaConsultas);
  map<Consulta, int> getListaConsultas();*/
  
  
  
  //Destructor
  ~Socio();
  
}

#endef
