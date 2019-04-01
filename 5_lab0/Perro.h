#ifndef Perro
#define Perro

class Perro: public Mascota
{
  private: RazaPerro raza;
           bool vacunaCachorro;
           
  public:
          //constructor por defecto
          Perro();
          //constructor comun
          Perro(RazaPerro praza, bool pvacunaCachorro):base(pnombre,pgenero,ppeso);
          
          //propiedades
          void setRazaPerro();
          RazaPerro getRazaPerro();
          
          void setVacunaCachorro();
          bool vacunaCachorro();
          
          //operaciones
          float obtenerRacionDiaria();
          
          //Destructor
          Perro::~Perro(){}
          
}
