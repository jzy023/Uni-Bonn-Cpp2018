#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
// #include <opencv2/opencv.hpp>

#include "template.h"

using namespace std;
int main()
{
	// template classes
	myClass<int> someObj(1,2);
	myClass<std::string> otherObj("hello","world");
	someObj.get();
	otherObj.get();
	cout << "\n";

	// Iterators
	cout << "vector iterator:\n";
	vector<double> v = {{1, 2, 3}};
	for (auto iter = v.begin(); iter != v.end(); ++iter)
	{
		// iterators are pointer types, so * is needed to dereference
		cout << *iter << endl;
	}
	cout << "map iterator:\n";
	map<int, string> m = {{1,"one"},{2,"two"},{3,"three"}};
	for (map<int, string>::iterator mIter = m.find(1); 
		 mIter != m.end(); ++mIter)
	{
		cout << mIter->first << ": " << mIter->second << endl;
	}


	// 



	return 0;
}