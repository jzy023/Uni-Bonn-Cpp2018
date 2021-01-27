#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

#include "obj.h"


void printStudentInfo(const Student& student) {
	student.printInfo();
}


int main()
{
	Student myStudent
	(
		150035,
		2020,
		"Dave"		
	);
	nameID student1 = {150035, "John", "Ericsson"};

	// cout << myStudent.name();
	myStudent.printInfo();

	std::vector<int> v = {2,4,6,8};
	std::cout << "\n" << v.size() << std::endl;
	int val = 10;
	std::cout << val/3 << " " << val%3;
	return 0;
}


