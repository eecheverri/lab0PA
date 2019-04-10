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
#include "Consulta.h"
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

	try{
		
		DtGato dtGato = dynamic_cast<const DtGato&>(dtMascota);
				
		mascota = new Gato(dtGato.getNombre(),dtGato.getgenero(),dtGato.getPeso(),dtGato.getTipoPelo());											
		//cout << "-------------------------- agrego GATO en registrar socio " << mascota->getNombre()  <<"\n";	
		}catch(std::bad_cast){
			try{

				DtPerro dtPerro = dynamic_cast<const DtPerro&>(dtMascota);
				mascota = new Perro(dtPerro.getNombre(),dtPerro.getgenero(),dtPerro.getPeso(),dtPerro.getRazaPerro(),dtPerro.getVacunaCachorro());
				//cout << "-------------------------- agrego perro en registrar socio " << mascota->getNombre()  <<"\n";	
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

	int i=0;
	bool encontro = false;
	while (not encontro && i< cantSocios){
		if (socios[i]->getCi() == ci)
			encontro = true;
		else
			i++;	
	}
	
	try{		
		DtGato dtGato = dynamic_cast<const DtGato&>(dtMascota);		
		
		mascota = new Gato(dtGato.getNombre(),dtGato.getgenero(),dtGato.getPeso(),dtGato.getTipoPelo());
		//cout << "-------------------------- agrego gato " << mascota->getNombre()  <<"\n";	

	}catch(std::bad_cast){
		try{				
			DtPerro dtPerro = dynamic_cast<const DtPerro&>(dtMascota);
			mascota = new Perro(dtPerro.getNombre(),dtPerro.getgenero(),dtPerro.getPeso(),dtPerro.getRazaPerro(),dtPerro.getVacunaCachorro());
			//cout << "-------------------------- agrego perro " << mascota->getNombre()  <<"\n";	

		}catch(std::bad_cast){
			cout << "Error\n";
		}
	}
	
	if (encontro)		
		socios[i]->agregarMascota(mascota);
	else
		throw std::invalid_argument( "No se encontro el socio." );

}

void ingresarConsulta(string motivo, string ci)/* Crea una consulta con un motivo para un socio. Si no existe un socio registrado con esa cédula, 
se levanta una excepción std::invalid_argument*/
{
	int i=0;
	bool encontro = false;
	while (not encontro && i< cantSocios){
		if (socios[i]->getCi() == ci)
			encontro = true;
		else
			i++;	
	}
	if (encontro){	
		Consulta* consulta = new Consulta(DtFecha(),motivo);
		socios[i]->agregarConsulta(consulta);
	}
	else
		throw std::invalid_argument( "No se encontro el socio." );
	
}

DtConsulta** verConsultasAntesDeFecha(const DtFecha& Fecha,string ciSocio, int& cantConsultas) /*que devuelve las consultas antes de cierta fecha. Para poder implementar esta operación se deberá sobrecargar el operador < (menor que) para el DataType Fecha. El largo del arreglo está dado por el parámetro cantConsultas.*/
{
	DtConsulta** dtConsultas;
	int i=0;
	bool encontro = false;
	while (not encontro && i< cantSocios){
		if (socios[i]->getCi() == ciSocio)
			encontro = true;
		else
			i++;	
	}
	if (encontro){
		
		Consulta** consultas = socios[i]->verConsultasAntesDeFecha(Fecha,cantConsultas);					
		dtConsultas = new DtConsulta*[cantConsultas];
	
		for( int i = 0; i < cantConsultas; i++ ) {
			dtConsultas[i] = new DtConsulta(consultas[i]);				
		}
	}else
		throw std::invalid_argument( "No se encontro el socio." );
	return dtConsultas;
}

void eliminarSocio(string ci) /*que elimina al socio, sus consultas y sus mascotas. Si no existe un socio registrado con esa cédula, se levanta una excepción std::invalid_argument.*/
{
	int i=0;
	bool encontro = false;
	while (not encontro && i< cantSocios){
		if (socios[i]->getCi() == ci)
			encontro = true;
		else
			i++;	
	}

	if (encontro){		
		delete socios[i];
		cantSocios--;
		socios[i] = socios[cantSocios];
	}else
		throw std::invalid_argument( "No se encontro el socio." );
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas)/*devuelve un arreglo con las mascotas del socio. El largo del arreglo está dado por el
parámetro cantMascotas. Si no existe un socio registrado con esa cédula, se levanta
una excepción std::invalid_argument.*/
{	
	int i=0;
	bool encontro = false;
	while (not encontro && i< cantSocios){
		if (socios[i]->getCi() == ci)
			encontro = true;
		else
			i++;	
	}
	
	if (encontro){
		Mascota** mascotas;
		mascotas = socios[i]->obtenerMascotas(cantMascotas);
		DtMascota* dtMascota;
		DtMascota** dtMascotas = new DtMascota*[cantMascotas];
	
		for( int i = 0; i < cantMascotas; i++ ) {
			
			Mascota* mascota = mascotas[i];			
			
			/* CODIGO MAS CORRECTO PERO SIN PROBAR
			Gato* gato = dynamic_cast<Gato*>(mascota);
			if (Gato* <> nullptr){
				Gato* gato = dynamic_cast<Gato*>(mascota);					
				DtGato* dtGato = new DtGato(gato);							
				dtMascota = dynamic_cast<DtMascota*>(dtGato);
				
			}Else{
				Perro* perro = dynamic_cast<Perro*>(mascota);					
				DtPerro* dtPerro = new DtPerro(perro);							
				dtMascota = dynamic_cast<DtPerro*>(dtPerro);				
			}
			*/

			try{	
				if (mascota->SoyUn() == "P")	
					throw std::bad_cast();	
				Gato* gato = dynamic_cast<Gato*>(mascota);				
				DtGato* dtGato = new DtGato(gato);							
				dtMascota = dynamic_cast<DtMascota*>(dtGato); ;			
			}catch(std::bad_cast){
				try{				
					Perro* perro = dynamic_cast<Perro*>(mascota);					
					DtPerro* dtPerro = new DtPerro(perro);							
					dtMascota = dynamic_cast<DtPerro*>(dtPerro);	

			  	}catch(std::bad_cast){
		        	cout << "Error\n";
				}	
					
		    }					
			
		 	dtMascotas[i] = dtMascota;
		}
		
		return dtMascotas;
		
	}else
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
				cout << "Ingrese raza del perro labrador = 1, ovejero = 2, bulldog = 3, pitbull = 4, collie = 5, pekines = 6, otro = 7: " << endl;
				cin >> razaPerroIndice;
				cout << "¿Tiene vacuna cachorro? S/N: " << endl;
				cin >> tieneVacunaCachorro;							
				DtPerro dtPerro = DtPerro(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<RazaPerro>(razaPerroIndice),(tieneVacunaCachorro == 'S'));
				registrarSocio(ci, nombreSocio,dtPerro) ;			
					
			}
			
		}else if (comando == 2){ //agregarMascota
			
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
				//cout << "GATOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << endl; 
			}else{
				cout << "Ingrese raza del perro labrador = 1, ovejero = 2, bulldog = 3, pitbull = 4, collie = 5, pekines = 6, otro = 7: " << endl;
				cin >> razaPerroIndice;
				cout << "¿Tiene vacuna cachorro? S/N: " << endl;
				cin >> tieneVacunaCachorro;							
				DtPerro dtPerro = DtPerro(nombreMascota,static_cast<Genero>(generoIndice),peso,0,static_cast<RazaPerro>(razaPerroIndice),(tieneVacunaCachorro == 'S'));
				agregarMascota(ci,dtPerro);	
				//cout << "PERROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO " << endl; 			
					
			}

		}else if (comando == 3){//ingresarConsulta
			string ci,motivo;
			cout << "Ingrese ci: " << endl; 
			cin >> ci;	
			cout << "Ingrese motivo: " << endl; 
			cin >> motivo;
			
			ingresarConsulta(motivo,ci);
			
		}else if (comando == 4){//verConsultasAntesDeFecha

			string ci;	
			int dia,mes,anio,cantConsultas;
			cout << "Ingrese ci: " << endl; 
			cin >> ci;
			cout << "Ingrese dia: " << endl; 
			cin >> dia;
			cout << "Ingrese mes: " << endl; 
			cin >> mes;
			cout << "Ingrese anio: " << endl; 
			cin >> anio;
			DtConsulta** dtConsultas = verConsultasAntesDeFecha(DtFecha(dia,mes,anio),ci,cantConsultas);
			
			for( int i = 0; i < cantConsultas; i++ ) {
				cout << *dtConsultas[i];
			}
			
		}else if (comando == 5){//eliminarSocio
			string ci;			
			cout << "Ingrese ci: " << endl; 
			cin >> ci;
			eliminarSocio(ci);
			
		}else if (comando == 6){
			string ci;
			int cantMascotas = 0;
			cout << "Ingrese ci: " << endl; 
			cin >> ci;
			DtMascota** mascotas = obtenerMascotas(ci,cantMascotas);
			
			for( int i = 0; i < cantMascotas; i++ ) {
				try{
					
					
					cout << dynamic_cast<DtGato&>(*mascotas[i]) << endl; 

				}catch(std::bad_cast){
					try{				
						cout << dynamic_cast<DtPerro&>(*mascotas[i]) << endl; 
			  		}catch(std::bad_cast){
		        		cout << "Error\n";
					
					}
				}
			
			}
				
		}else if (comando ==0 )
			return(0);
					
	}
}

	
