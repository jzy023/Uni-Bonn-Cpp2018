template <class dataType> 
class myClass{
public:
	myClass(
		const dataType& data1,
		const dataType& data2
	):
	data1_(data1),
	data2_(data2)
	{}

	void get() const;

private:
	dataType data1_;
	dataType data2_;
};

#include "template.hpp"