#include <iostream>

using namespace std;

#include "lec2.h"

/* compile with the following command lines:
	> ar rcs libfunc.a func.o
	> c++ -std=c++11 main.cpp -L . -lfunc -o main
*/

int main(int argc, char const *argv[])
{
	// pass by copy
	int x1 = 2;
	int x2 = 3;
	cout << fSum(x1, x2) << endl; 
	vector<int> v = fUnitVec(3);
	fPrintVec(v);
	// pass by reference
	string s1 = "John";
	string s2 = "Wick";
	cout << fConStr(s1,s2) << endl;
	// function overloads
	cout << "the type of x1 is " << fType(x1) << endl;	
	cout << "the type of s1 is " << fType(s1) << endl;
	// std built-in algorithms
	vector<int> v2 = {1,54,8,2,23,1,64,21};
	sort(v2.begin(), v2.end());
	fPrintVec(v2);

	return 0;
}


