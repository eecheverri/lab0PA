#ifndef B_H
#define B_H

#include "A.h"
#include "C.h"

class B{
	private:
		int b;
		A* conA;
		C* conC;
	public:
		B();
		B(int a);
		int getB(int);
		void setB(int);
		void nombreClase();
};

#endif

