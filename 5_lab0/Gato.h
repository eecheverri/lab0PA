#ifndef Gato_H
#define Gato_H

#include "TipoPelo.h"
#include "Genero.h"
#include "Mascota.h"

using namespace std;

class Gato: public Mascota
{
  private: TipoPelo tipoPelo;
  
  public:
          //constructor por defecto
          Gato();
          //constructor comun
          Gato(string, Genero, float, TipoPelo);
          
          //propiedades
          void setTipoPelo(TipoPelo);
          TipoPelo getTipoPelo();
                    
          //operaciones
          float obtenerRacionDiaria();
          
          //Destructor
           ~Gato();
          
};

#endif

