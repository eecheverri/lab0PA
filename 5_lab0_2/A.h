#ifndef A_H
#define A_H

class B;//forward declaration
class C;//forward declaration

class A{
	private:
		int a;
		B* conB;
		C* conC;
	public:
		A();
		A(int a);
		int getA(int);
		void setA(int);
		void nombreClase();
};

#include "B.h"
#include "C.h"

#endif

