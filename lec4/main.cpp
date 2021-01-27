#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "value.h"
#include "vehicle.h"
#include "geometry.h"

int main()
{
	std::string str = "!";
	// str is a lvalue
	value::Print(str);
	// "?" is a rvalue
	value::Print("?");
	// make str a rvalue
	value::Print(move(str));

	// move() move the ownership of str the variable to owner[1],
	// after which calling str no longer makes sense
	std::vector<std::string> owner;
	owner.emplace_back(str);
	owner.emplace_back(move(str));
	std::cout << owner[0] << " " << owner[1] << std::endl; 
	std::cout << "str after move(): " << str << std::endl; 

	// rvalues are marked as temporary, when it is assigned to another 
	// variable, the compiler, instead copying its value to a new variale 
	// with a new memory address, it simply 'moves' it to save memory and 
	// computational power

	// lvalues can be on the right side of =
	// rvalues cannot be on the left side of =

	vehicle myCar(1800,500,200,6,4);
	rectangular myRec(10,20);
	square mySq(10);
	std::cout << "size of rectangular: " << myRec.size() << std::endl;
	std::cout << "size of square: " << mySq.size() << std::endl;


	return 0;
}