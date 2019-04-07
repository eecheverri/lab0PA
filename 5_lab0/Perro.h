#ifndef Perro_H
#define Perro_H

#include "RazaPerro.h"
#include "Mascota.h"
#include "Genero.h"

class Perro: public Mascota{
  private: 
  		RazaPerro raza;
        bool vacunaCachorro;           
  public:
          //constructor por defecto
          Perro();
          //constructor comun
          Perro(string, Genero, float, RazaPerro, bool);
          
          //propiedades
          void setRazaPerro(RazaPerro);
          RazaPerro getRazaPerro();
          
          void setVacunaCachorro(bool);
          bool getVacunaCachorro();
          
          //operaciones
          float obtenerRacionDiaria();
          
          //Destructor
          ~Perro();
          
};

#endif
