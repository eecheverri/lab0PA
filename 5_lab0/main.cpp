#include <cstdlib>
#include <iostream>
#include <stdexcept>
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
#include "Mascota.h"

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
	        	cout << "Error al registrar socio.\n";
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
	Mascota* mascota;

	try{
		
		DtGato dtGato = dynamic_cast<const DtGato&>(dtMascota);		
		
		mascota = new Gato(dtGato.getNombre(),dtGato.getgenero(),dtGato.getPeso(),dtGato.getTipoPelo());
		
		}catch(std::bad_cast){
			try{
			
				DtPerro dtPerro = dynamic_cast<const DtPerro&>(dtMascota);
				mascota = new Perro(dtPerro.getNombre(),dtPerro.getgenero(),dtPerro.getPeso(),dtPerro.getRazaPerro(),dtPerro.getVacunaCachorro());
		  	}catch(std::bad_cast){
	        	cout << "Error\n";
	      }
	}
	int i=0;
	bool encontro = false;
	while (not encontro && i<= cantSocios){
		if (socios[i]->getCi() != ci)
			encontro = true;
		else
			i++;	
	}
	if (encontro)
		socios[i]->agregarMascota(mascota);
	else
		throw std::invalid_argument( "No se encontro el socio." );
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
	int i=0;
	bool encontro = false;
	while (not encontro && i<= cantSocios){
		if (socios[i]->getCi() != ci)
			encontro = true;
		else
			i++;	
	}
	if (encontro){	
		Mascota** mascotas;
		mascotas = socios[i]->obtenerMascotas(cantMascotas);
		DtMascota* dtMascota;
		DtMascota** dtMascotas = new DtMascota*[cantMascotas];
		for( int i = 0; i <= cantMascotas; i++ ) {
			//DtMascota* dtMascota = new DtMascota(mascotas[i]->getNombre(),mascotas[i]->getGenero(),mascotas[i]->getPeso(),mascotas[i]->obtenerRacionDiaria());
			//DtMascota* dtMascota = new DtMascota(mascotas[i]->getNombre(),mascotas[i]->getGenero(),mascotas[i]->getPeso(),mascotas[i]->obtenerRacionDiaria());
			Mascota* mascota = mascotas[i];		
			try{			

				Gato* gato = dynamic_cast<Gato*>(mascota);		
				DtGato dtGato = DtGato(gato);							
				/*DtMascota**/ dtMascota = dynamic_cast<DtMascota*>(gato); ;			
			}catch(std::bad_cast){
				try{				
					Perro* perro = dynamic_cast<Perro*>(mascota);		
					DtPerro dtPerro = DtPerro(perro);							
					/*DtMascota**/ dtMascota = dynamic_cast<DtPerro*>(perro); ;	

			  	}catch(std::bad_cast){
		        	cout << "Error\n";
		    }
	}						
			
		 	dtMascotas[i] = dtMascota;
		}		
	}
	else
		throw std::invalid_argument( "No se encontro el socio." );	
	
}


int main() {

	cout << "Bienvenido. Elija la opcion" << endl; 
	while(true)
	{		
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

		if (comando == 1){	//registrarSocio
		
			string ci,nombreSocio,nombreMascota,tipoMascota;
			int tipoPeloIndice,generoIndice,razaPerroIndice;
			float  peso;
			bool vacunaCachorro;
			char tieneVacunaCachorro;
			
		 	cout << "Ingrese cedula: " << endl; 
			cin >> ci;	
		 	cout << "Ingrese nombre socio: " << endl; 
			cin >> nombreSocio;				
			cout << "Ingrese nombre mascota: " << endl; 
			cin >> nombreMascota;	
			cout << "Ingrese genero mascota: Macho 1, Hembra 2" << endl; 
			cin >> generoIndice;
			cout << "Ingrese peso: " << endl; 
			cin >> peso;			
			cout << "¿Es gato o perro? G/P: " << endl; 
			cin >> tipoMascota;
			if (tipoMascota == "G"){
				cout << "Ingrese tipo de pelo Corto 1, Mediano 2, Largo 3: " << endl;
				cin >> tipoPeloIndice;
				DtGato dtGato = DtGato(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<TipoPelo>(tipoPeloIndice));
				registrarSocio(ci, nombreSocio,dtGato) ;
			}else{
				cout << "Ingrese raza del perro: " << endl;
				cin >> razaPerroIndice;
				cout << "¿Tiene vacuna cachorro? S/N: " << endl;
				cin >> tieneVacunaCachorro;							
				DtPerro dtPerro = DtPerro(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<RazaPerro>(razaPerroIndice),(tieneVacunaCachorro == 'S'));
				registrarSocio(ci, nombreSocio,dtPerro) ;			
					
			}	
		}
		
		else if (comando == 2){ //agregarMascota
			
			string ci,nombreMascota,tipoMascota;
			int tipoPeloIndice,generoIndice,razaPerroIndice;
			float  peso;
			bool vacunaCachorro;
			char tieneVacunaCachorro;	
					
		 	cout << "Ingrese cedula: " << endl; 
			cin >> ci;
			cout << "Ingrese nombre mascota: " << endl; 
			cin >> nombreMascota;	
			cout << "Ingrese genero mascota: Macho 1, Hembra 2" << endl; 
			cin >> generoIndice;
			cout << "Ingrese peso: " << endl; 
			cin >> peso;			
			cout << "¿Es gato o perro? G/P: " << endl; 
			cin >> tipoMascota;
			
			if (tipoMascota == "G"){
				cout << "Ingrese tipo de pelo Corto 1, Mediano 2, Largo 3: " << endl;
				cin >> tipoPeloIndice;
				DtGato dtGato = DtGato(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<TipoPelo>(tipoPeloIndice));
				agregarMascota(ci,dtGato);
			}else{
				cout << "Ingrese raza del perro: " << endl;
				cin >> razaPerroIndice;
				cout << "¿Tiene vacuna cachorro? S/N: " << endl;
				cin >> tieneVacunaCachorro;							
				DtPerro dtPerro = DtPerro(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<RazaPerro>(razaPerroIndice),(tieneVacunaCachorro == 'S'));
				agregarMascota(ci,dtPerro);				
					
			}

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

	
