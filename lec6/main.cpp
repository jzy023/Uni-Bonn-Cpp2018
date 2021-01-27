#include <iostream>
#include <math.h>

#include "point.h"

int main(int argc, char const *argv[])
{
	point a(1,1);
	point b(2,2);
	std::cout << point::distance(a,b) << std::endl;

	return 0;
}
