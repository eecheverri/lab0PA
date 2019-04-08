#include <iostream>
#include <cstdlib>
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

int main() {
	int a = 4;
	int b = 3;
	int c = 2;
	A* objA = new A();
	B* objB = new B();
	C* objC = new C();
	
	objA->setA(a);
	objA->nombreClase(); 
	cout << "El atributo es: "<< objA->getA(a)<< endl;
	objB->setB(b);
	objB->nombreClase();
	cout << "El atributo es: "<< objB->getB(b)<<endl;
	objC->setC(c);
	objC->nombreClase();
	cout << "El atributo es: "<< objC->getC(b)<<endl;
	return 0;
}

