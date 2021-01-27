#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class Image {
public:
	// constructor
	Image(const string& file_name); 
	// functions
	void fDraw();
	// destructor
	~Image();
private:
	int rows_ = 0;
	int cols_ = 0;
};


class Student 
{
public:

	// constructors
	Student(){};

	Student
	(
		int ID,
		int classYear,
		string Name
	): 
	ID_(ID),
	classYear_(classYear),
	Name_(Name)
	{}

	// member funcions (methods)
	void printInfo() const
	{
		cout << "Student Name: " << Name_
		     << "\nStudent ID: " << ID_
		     << "\nYear Class: " << classYear_;
	}

	void printName() const;

	// destructor
	~Student(){};

private:
	int ID_;
	int classYear_;
	string Name_;
};

// Student::Student() {}
// void Student::printName() const
// {
// 	cout << name();
// };


// use struct to pack data (functions now return 
// a struct which contains multiple values)
struct nameID {
	int ID; 
	string firstName;
	string lastName;
};



