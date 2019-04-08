#include <cstdlib>
#include <iostream>
#include "C.h"

using namespace std;

C::C(){
	c=0;
}
C::C(int c){
	this->c=c;
}
int C::getC(int c){
	return this->c;	
}
void C::setC(int c){
	this->c=c;
}
void C::nombreClase(){
	cout<<"clase C - ";
}

