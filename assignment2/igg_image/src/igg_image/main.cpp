#include <iostream>
#include <vector>
#include "image.H"
#include "io_tools.H"
#include <sys/stat.h>

bool IsPathExist(const std::string &s)
{
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}

int main()
{
	igg::Image imageCat(128,128);
	std::cout << imageCat.rows() << std::endl;
	// imageCat.rows() = 1; is legal and will change 'private' 
	// variables if method 'rows()' was passed by reference
	// without setting to const 
	std::cout << imageCat.rows() << std::endl;


	std::cout << "------------" << std::endl;
	igg::Image test(512,512);
	std::cout << "Data at pixel (128,256) is " 
	          << test.at(128,256) << std::endl;
	std::string fileName = 
		"/home/noreff/CppCourse/assignment2/igg_image/data/lena.ascii.pgm";
	std::cout << "If read .pgm file to Image: "
			  << test.FillFromPgm(fileName) << std::endl;
	std::cout << "Data at pixel (128,256) is NOW "
			  << test.at(128,256) << std::endl;

	std::cout << "------------" << std::endl;
	test.DownScale(4);
	std::string outputFileName = 
		"/home/noreff/CppCourse/assignment2/igg_image/data/new.ascii.pgm";
	test.WriteToPgm(outputFileName);

	std::cout << "------------" << std::endl;
	int histogramSize = 4;
	std::vector<float> v = test.ComputeHistogram(histogramSize);
	std::cout << "The weight of each bar of histogram: " << std::endl;
	// std::cout << "The weight of bar #3 is " << v[2] << std::endl;
	for (int i = 0; i < histogramSize; ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}
