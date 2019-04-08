#include <cstdlib>
#include <iostream>
#include "B.h"

using namespace std;

B::B(){
	b=0;
}
B::B(int b){
	this->b=b;
}
int B::getB(int b){
	return this->b;	
}
void B::setB(int b){
	this->b=b;
}
void B::nombreClase(){
	cout<<"Clase B - ";
}

