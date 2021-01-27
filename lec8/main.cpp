#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "usestd.h"
#include "enums.h"

struct A {
	A(int num){ 
		a = num; 
		cout << "constructing A" << endl;
	}
	A(){ cout << "constructing A" << endl; }
	~A(){ cout << "destroying A" << endl; }
	int a = 0;
};


struct Shape
{
	virtual void print() const = 0;
};
struct square: public Shape
{
	void print() const override { cout << "Square\n"; }
};
struct triangle: public Shape
{
	void print() const override { cout << "Triangle\n"; }	
};


int main(int argc, char const *argv[])
{
	// Unique Pointer
	// cannot be copied
	// default constructor for type/class from C++14 on
	// 	auto p = std::make_unique<Type>(parameter)
	auto a_ptr = make_unique<A>(42);
	cout << "ptr->a: " << a_ptr->a << endl;
	cout << "a pointer: " << a_ptr.get() << endl;
	// with move() the old pointer a_ptr is moved to variable b_ptr
	// and the original variable no longer stores the memory address
	cout << "\nnow move(a_ptr)" << endl;
	auto b_ptr = move(a_ptr);
	cout << "a pointer: " << a_ptr.get() << endl;
	cout << "b pointer: " << b_ptr.get() << endl;

	// Shared Pointer
	auto a1_ptr = make_shared<A>(14);
	cout << "\nshared pointer use count: "<< a1_ptr.use_count() << endl;
	if(true){
		cout << ">> entering scope" << endl;
		auto b1_ptr = a1_ptr;
		cout << "shared pointer use count: "<< a1_ptr.use_count() << endl;
		cout << ">> exiting scope" << endl;	
	}
	cout << "shared pointer use count: "<< a1_ptr.use_count() << endl;


	// A vector of unique pointer 
	cout << endl;
	vector<unique_ptr<Shape>> shapes;
	shapes.emplace_back(new square);
	shapes.emplace_back(new triangle);
	// auto& is used instead of auto*
	// because auto* is a raw pointer type whereas
	// the vector stores unique(smart) pointer 
	for (const auto& shape : shapes){
		shape->print();
	}
	cout << endl;


	// Map
	map<int,std::string> m = {
		{2,"number 2"},
		{0,"initial"},
		{1,"number 1"}
	};
	m.emplace(3,"number 3");
	cout << "map size: " << m.size() << endl;
	for(const auto& kv : m){
		cout << "key: " << kv.first 
			 << " , value: " << kv.second << endl;
	}


	// Type Casting
	//


	// Enumeration Class
	cout << endl;
	enum class EnumType {
		OPTION_1, // 0
		OPTION_2, // 1
		OPTION_3, // 2
	};
	print(Channel::STDOUT, "hello");
	print(Channel::STDERR, "world");

	return 0;
}
