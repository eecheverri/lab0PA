#include <cstdlib>
#include <iostream>
#include "DtMascota.h"
#include "Genero.h"
#include "RazaPerro.h"
#include "TipoPelo.h"
#include "DtFecha.h"
#include "DtConsulta.h"

using namespace std;


void registrarSocio(string ci, string nombre, const DtMascota& dtMascota) /* Registra un socio con su mascota. El valor el atributo racionDiaria sedebe setear en 0.*/
{
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
//void registrarSocio(string ci, string nombre, const DtMascota& dtMascota) 
		if (comando == 1){	
			string ci,nombreSocio,nombreMascota,generoNombre,tipoPeloNombre,razaPerro,tipoMascota;
			float  peso;
			bool vacunaCachorro;
			char tieneVacunaCachorro;			                   
			
		 	cout << "Ingrese cedula: " << endl; 
			cin >> ci;	
		 	cout << "Ingrese nombre socio: " << endl; 
			cin >> nombreSocio;				
			cout << "Ingrese nombre mascota: " << endl; 
			cin >> nombreMascota;	
			cout << "Ingrese genero mascota: M/H" << endl; 
			cin >> generoNombre;
			cout << "Ingrese peso: " << endl; 
			cin >> peso;			
			cout << "¿Es gato o perro? G/P: " << endl; 
			cin >> tipoMascota;
			if (tipoMascota == "G"){
				cout << "Ingrese tipo de pelo: " << endl;
				cin >> tipoPeloNombre;
			}else{
				cout << "Ingrese raza del perro: " << endl;
				cin >> razaPerro;
				cout << "¿Tiene vacuna cachorro? S/N: " << endl;
				cin >> tieneVacunaCachorro;
				vacunaCachorro = (tieneVacunaCachorro == 'S');							
			}
			
		}

		else if (comando == 2)
				cout << "1) Registrar socio " << endl; 
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

	
