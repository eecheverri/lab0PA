#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "DtMascota.h"
#include "Genero.h"
#include "RazaPerro.h"
#include "TipoPelo.h"
#include "DtFecha.h"
#include "DtGato.h"
#include "DtConsulta.h"
#include "DtPerro.h"
#include "Socio.h"
#include "Gato.h"
#include "Perro.h"
#include "RazaPerro.h"

#define MAX_SOCIOS 100

using namespace std;


Socio** socios = new Socio* [MAX_SOCIOS];
int cantSocios = 0;

void registrarSocio(string ci, string nombre,const DtMascota& dtMascota) /* Registra un socio con su mascota. El valor el atributo racionDiaria sedebe setear en 0.*/
{
	Mascota* mascota;
	//DtMascota dtmasc = DtMascota(dtMascota);
	//Mascota* mascota = new Mascota()
	try{
		
		DtGato dtGato = dynamic_cast<const DtGato&>(dtMascota);
		//DtGato dtGato = dynamic_cast<DtGato>(const_cast<DtMascota&>(dtMascota));
		
		
		mascota = new Gato(dtGato.getNombre(),dtGato.getgenero(),dtGato.getPeso(),dtGato.getTipoPelo());									
		
		
		}catch(std::bad_cast){
			try{
			
				//DtPerro dtPerro = dynamic_cast<DtPerro&>(dtMascota);
				DtPerro dtPerro = dynamic_cast<const DtPerro&>(dtMascota);
				mascota = new Perro(dtPerro.getNombre(),dtPerro.getgenero(),dtPerro.getPeso(),dtPerro.getRazaPerro(),dtPerro.getVacunaCachorro());
		  	}catch(std::bad_cast){
	        	cout << "Error\n";
	      }
	}
	
	Socio* socio = new Socio(ci,nombre,DtFecha());
	
	socio->agregarMascota(mascota);
	socios[cantSocios] = socio;
	cantSocios++;
}

void agregarMascota(string ci, const DtMascota& dtMascota) /*Agrega una nueva mascota a un socio ya registrado. Si no existe un socio registrado con esa cédula, 
se levanta una excepción std::invalid_argument.*/
{
}

void ingresarConsulta(string motivo, string ci)/* Crea una consulta con un motivo para un socio. Si no existe un socio registrado con esa cédula, 
se levanta una excepción std::invalid_argument*/
{
}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& Fecha,string ciSocio, int& cantConsultas) /*que devuelve las consultas antes de cierta fecha. Para poder implementar esta operación se deberá sobrecargar el operador < (menor que) para el DataType Fecha. El largo del arreglo está dado por el parámetro cantConsultas.*/
{
}

void eliminarSocio(string ci) /*que elimina al socio, sus consultas y sus mascotas. Si no existe un socio registrado con esa cédula, se levanta una excepción std::invalid_argument.*/
{
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas)/*devuelve un arreglo con las mascotas del socio. El largo del arreglo está dado por el
parámetro cantMascotas. Si no existe un socio registrado con esa cédula, se levanta
una excepción std::invalid_argument.*/
{
}




int main() {
	cout << "Bienvenido. Elija la opción" << endl; 
	while(true)
	{	
		/*cout << salida1 << " " << numero << ". " << salida2 << endl;*/		
		cout << "1) Registrar socio " << endl; 
		cout << "2) Agregar mascota " << endl; 
		cout << "3) Ingresar consulta " << endl; 
		cout << "4) Ver consultas antes de fecha " << endl; 
		cout << "5) Eliminar socio " << endl; 
		cout << "6) Obtener mascotas  " << endl; 
		cout << "0) Salir  " << endl; 
		
	    cout << "Opcion: " << endl; 
		int comando;
		cin >> comando;			

		if (comando == 1){	
			string ci,nombreSocio,nombreMascota,tipoMascota;
			int tipoPeloIndice,generoIndice,razaPerroIndice;
			float  peso;
			bool vacunaCachorro;
			char tieneVacunaCachorro;			                   
			//DtMascota dtMascota;
			
		 	cout << "Ingrese cedula: " << endl; 
			cin >> ci;	
		 	cout << "Ingrese nombre socio: " << endl; 
			cin >> nombreSocio;				
			cout << "Ingrese nombre mascota: " << endl; 
			cin >> nombreMascota;	
			cout << "Ingrese genero mascota: Macho 1, Hembra 2" << endl; 
			cin >> generoIndice;
			/*Genero genero;
			if (generoIndice == "M")
				genero = Macho;
			else
				genero = Hembra;*/
				
			cout << "Ingrese peso: " << endl; 
			cin >> peso;			
			cout << "¿Es gato o perro? G/P: " << endl; 
			cin >> tipoMascota;
			if (tipoMascota == "G"){
				cout << "Ingrese tipo de pelo Corto 1, Mediano 2, Largo 3: " << endl;
				cin >> tipoPeloIndice;
				/*TipoPelo tipoPelo;
				if (tipoPeloIndice == "C")
					tipoPelo = Corto;
				else if (tipoPeloIndice == "M") 
					tipoPelo = Mediano;
				else
					tipoPelo = Largo;*/
				 DtGato dtPerro = DtGato(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<TipoPelo>(tipoPeloIndice));
	registrarSocio(ci, nombreSocio,dtPerro) ;
			}else{
				cout << "Ingrese raza del perro: " << endl;
				cin >> razaPerroIndice;
				//if 
				cout << "¿Tiene vacuna cachorro? S/N: " << endl;
				cin >> tieneVacunaCachorro;
				//vacunaCachorro = (tieneVacunaCachorro == 'S');							
				DtPerro dtPerro = DtPerro(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<RazaPerro>(razaPerroIndice),(tieneVacunaCachorro == 'S'));
					registrarSocio(ci, nombreSocio,dtPerro) ;				
					
			}

		
			
		
			
		}

		else if (comando == 2){
			int i;
		cin >> i;
		
				Socio* socio = new Socio("123","nom",DtFecha());
				Mascota* mascota = new Gato("nombre",Hembra,200,Corto);
				socio->agregarMascota(mascota);
				//DtMascota dtm = DtGato(mascota->getNombre(),mascota->getGenero(),mascota->getPeso(),200,static_cast<TipoPelo>(i));
				DtGato dtm = DtGato(mascota->getNombre(),mascota->getGenero(),mascota->getPeso(),200,static_cast<TipoPelo>(i));
				//DtMascota** coso = new DtMascota*[10];
				//coso[1] =dynamic_cast<DtMascota&>(dtm) ;
				//DtGato gato = dynamic_cast<DtGato&>(dtm);
				//cout << mascota->getNombre() << endl; 
				 // cout << dynamic_cast<DtGato&>(dtm) << endl; 
				  //cout << dynamic_cast<DtGato&>(coso[1]) << endl; 
				 
				//DtMascota** mascotas = new DtMascota*;
				//DtMascota& dtMascota2 = DtGato(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<TipoPelo>(tipoPeloIndice));				 
				 //DtMascota& dtMascota2 = DtGato(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<TipoPelo>(tipoPeloIndice));
				  //dynamic_cast<DtGato&>(dtMascota);
				//cout << dynamic_cast<DtGato&>(dtMascota2) << endl; 

		}		
		else if (comando == 3)
				cout << "1) Registrar socio " << endl; 
		else if (comando == 4)
				cout << "1) Registrar socio " << endl; 
		else if (comando == 5)
				cout << "1) Registrar socio " << endl; 
		else if (comando == 6)
				cout << "1) Registrar socio " << endl; 
		else if (comando ==0 )
			return(0);
				
		
		//system("pause");		
	}
}

	
