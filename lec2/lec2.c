#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

#include "lec2.h"

/* compile with the following command lines:
	> c++ -std=c++11 -c func.cpp -o func.o
*/

// Function Definitions
int fSum(int a, int b){
	return a + b;
}
vector<int> fUnitVec(int size){
	vector<int> v1(size);
	for (int i = 0; i < size; ++i) { v1[i] = 1; }
	return v1;
}
void fPrintVec(vector<int> v){
	int iter = v.size();
	cout << "{";
	for (int i = 0; i < iter-1; ++i)
	{
		cout << v[i] << ", ";
	}
	cout << v[iter-1] << "}" << endl; 
}
// pass by reference
string fConStr(const string& s1, const string& s2){
	// use reference to avoid copying large variable
	// use "const" to avoid accidentally change value
	return s1 + " " + s2;
}
// function overloads
// be careful with non-obviouse overloads like int/float
string fType(int num){ return "int";}
string fType(const string& str){ return "string";}