#include <cstdlib>
#include <iostream>
#include "A.h"

using namespace std;

A::A(){
	a=0;
}
A::A(int a){
	this->a=a;
}
int A::getA(int a){
	return this->a;	
}
void A::setA(int a){
	this->a=a;
}
void A::nombreClase(){
	cout <<"Clase A - ";
}

