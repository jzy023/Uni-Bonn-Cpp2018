#include <iostream>
#include <vector>

using std::cout; using std::endl;


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
	// vector storing pointer of type Shape
	std::vector<Shape*> shapes;
	// create 2 sub-types of Shape
	square s;
	triangle t;
	// move the address of 2 objects to vector
	shapes.emplace_back(&s);
	shapes.emplace_back(&t);
	// test print
	for (const auto* shape : shapes)
	{
		shape->print();
	}
	return 0;
}