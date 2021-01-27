#include <iostream>
#include <string>
#include <array>
#include <vector>


int main(int argc, char const *argv[])
{
	std::cout << "Hello World" << std::endl;
	std::string myWord;
	std::cout << myWord.empty() << "\n" << "\n";

// Data Structure
	// Array
	std::array<int,3> arr = {11, 12, 13};
	std::cout << "First element of array is " << arr.front() << "\n";
	std::cout << "Last element of array is " << arr[arr.size()-1] << "\n"; 
	std::cout << "The size of array is " << arr.size() << "\n\n";
	// Vector
	std::vector<int> v = {21, 22, 23}; // dynamic table, size initialization not needed
	std::cout << "First element of vector is " << v[0] << "\n";
	std::cout << "The size of vector is " << v.size() << "\n";
	v.emplace_back(24);
	std::cout << "Newly added element to v is " << v[v.size()-1] << "\n";
	std::cout << "The size of vector is " << v.size() << "\n";
	const int kIterNum = 10;
	std::vector<int> v1;
	v1.reserve(kIterNum); // initialize vector with memory space to hold n items
	std::cout << "New vector is {"; 
	for (int i = 0; i < kIterNum; ++i)
	{
		// "v1[i] = i" modifies directly on memory address reserved for supposively 
		// i-th element, instead of changing i-th element itself, thus not changing 
		// the actual size of the vector
		v1.emplace_back(i+11);
		std::cout << v1[i] << " ";
	}
	std::cout << "}\n\n";

// Reference of Variables
	// reference is like an alias of a variable
	// avoid copying data and save memory
	int myVal = 1;
	int& refMyVal = myVal;
	std::cout << "Value of myVal is " << myVal << "\n";
	std::cout << "Value of reference is " << refMyVal << "\n";
	refMyVal = 10;
	std::cout << "Value of variable and ref after change: " << myVal << "\n\n";
	// const reference
	const int& kNewRef = myVal;
	myVal = 1; // kNewRef = 1;
	// now change ref would not work
	std::cout << "myVal: " << myVal << "; "
	<< "const Ref: " << kNewRef << "\n\n";

// switch Statement
	switch(myVal){
		case 1:
			std::cout << "myVal at origianl value" << "\n\n";
			break;
		case 10:
			std::cout << "myVal at new value" << "\n\n";
			break;
		default:
			std::cout << "condition not defined" << "\n\n";
	}

// Loops
	// while loop
	// for loop
	std::cout << "Range for-loop" << "\n";
	int num = 1;
	for (const auto& val: v1)
	{ // iterate over the size of vector
	  // equivalent to:
	  //   for (i=0; i < v1.size(); i++)
		std::cout << val << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	// Exit loops
	// use "continue" to skip loop
}