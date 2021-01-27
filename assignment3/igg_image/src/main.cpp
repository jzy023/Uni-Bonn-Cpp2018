#include <iostream>
#include <vector>
#include <string>

#include "igg_image/image.h"

int main()
{
	std::string filePPM = 
		"/home/noreff/CppCourse/assignment3/igg_image/data/pbmlib.ascii.ppm";
	std::string filePNG = 
		"/home/noreff/CppCourse/assignment3/igg_image/data/pngSample.png";

	igg::PngIoStrategy test;
	igg::Image myImage(test);
	myImage.ReadFromDisk(filePNG);
	myImage.DownScale(2);
	std::string toPNG = 
		"/home/noreff/CppCourse/assignment3/igg_image/data/pngScaled.png";
	myImage.WriteToDisk(toPNG);

	igg::PpmIoStrategy test2;
	igg::Image myImage2(test2);
	myImage2.ReadFromDisk(filePPM);
	std::cout << "----------" << std::endl;
	std::cout << myImage2.at(0,0).red << std::endl;
	std::cout << myImage2.at(0,0).green << std::endl;
	std::cout << myImage2.at(0,0).blue << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << myImage2.at(0,1).red << std::endl;
	std::cout << myImage2.at(0,1).green << std::endl;
	std::cout << myImage2.at(0,1).blue << std::endl;
	return 0;
}