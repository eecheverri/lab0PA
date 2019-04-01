#ifndef Mascota
#define Mascota

class Mascota {
private:
  //Atributos
  string nombre;
  Genero genero;
  float peso;
public:
  
  //Constructores
  
  //Constructor por defecto
  Mascota();
  
  //Constructor comun
  Mascota(string pnombre, Genero, pgenero, float ppeso);
  
  //Propiedades
  
  void setNombre(string pnombre);
  string getNombre();
  
  void setGenero(Genero pgenero);
  Genero getGenero();
  
  void setPeso(float ppeso);
  float getPeso();
  
  //Destructor
  ~Mascota();
  
}//Fin mascota

#endef
  
  
  
  
