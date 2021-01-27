#include <iostream>
#include <vector>
#include <array>
#include <math.h>

int main()
{
	int step = 1;
	const int sizeStep = 100000/sizeof(int);
	std::cerr << "current memory allocated on stack:\n";
	while(true){
		int size = step*sizeStep;
		int arr[size] = {1};
		step++;
		arr[0]++;
		std::cerr << "> "  
				  << sizeof(arr)/1000 << "KB" << std::endl;
	}
	return 0;
}