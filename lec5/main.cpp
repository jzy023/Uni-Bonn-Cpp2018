#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "rectangle.h"

int main()
{

	rectangle myRect(10,20);
	square mySqua(20);
	myRect.print();
	mySqua.print();

	// with out 'virtual' and 'override' keywords
	// in class inferitance, when parent class type
	// referrence is assigned, the code is not able 
	// call the function in derived class, and will 
	// instead call the origianl function in parent
	// class
	rectangle& myRect_ref = mySqua;
	myRect_ref.print();
	return 0;
}