#ifndef Gato
#define Gato

class Gato: public Mascota
{
  private: TipoPelo tipoPelo;
  
  public:
          //constructor por defecto
          Gato();
          //constructor comun
          Gato(TipoPelo ptipoPelo):base(pnombre,pgenero,ppeso);
          
          //propiedades
          void setTipoPelo();
          TipoPelo getTipoPelo();
                    
          //operaciones
          float obtenerRacionDiaria();
          
          //Destructor
          Gato::~Gato(){}
          
}
