#include <vector>
#include <string>
#include "image.h"

namespace igg {

Image::Pixel Image::at(int row, int col)
{
    return data_[row*cols_ + col];
}

const Image::Pixel Image::at(int row, int col) const
{
    return data_[row*cols_ + col];
}

void Image::DownScale(int scale)
{
	// if the original size is divisible by the scaling factor
	if(rows_%scale == 0){
		int newRows = rows_/scale;
		int newCols = cols_/scale;
		std::vector<Image::Pixel> newData (newRows*newCols);
		for (int i = 0; i < rows_*cols_; ++i)
		{
			// load original coordinates from data_
			int origialRow = i/cols_;
			int origialCol = i%cols_;
			// calculate new coordinates from originals
			int newRow = origialRow/scale;
			int newCol = origialCol/scale;

			newData[newRow*newRows + newCol].red += data_[i].red/(scale*scale);
			newData[newRow*newRows + newCol].green += data_[i].green/(scale*scale);
			newData[newRow*newRows + newCol].blue += data_[i].blue/(scale*scale);
		}
		std::cout << "scaling original image..." << std::endl;
		rows_ = newRows;
		cols_ = newCols;
		data_.resize(rows_*cols_);
		data_ = newData;
	}
	else{
		std::cout << "scaling factor is non-divisible" << std::endl;
	}
	// needs other solution for when non-divisible scaling
}


void Image::UpScale(int scale)
{
	std::cout << "scaling original image..." << std::endl;
	std::vector<Image::Pixel> newData (scale*scale*rows_*cols_);
	for (int i = 0; i < rows_*cols_; ++i)
	{
		// load original coordinates from data_
		int origialRow = i/cols_;
		int origialCol = i%cols_;
		// calculate new coordinates from originals
		for (int n = 0; n < scale; ++n)
		{
			for (int m = 0; m < scale; ++m)
			{
				int newRow = origialRow*scale + n;
				int newCol = origialCol*scale + m;
				newData[newRow*scale*rows_ + newCol].red = 
					data_[origialRow*cols_ + origialCol].red;
				newData[newRow*scale*rows_ + newCol].green = 
					data_[origialRow*cols_ + origialCol].green;
				newData[newRow*scale*rows_ + newCol].blue = 
					data_[origialRow*cols_ + origialCol].blue;
			}
		}
	}
	// write newly generated data to original
	data_.resize(scale*scale*rows_*cols_);
	rows_ = rows_*scale;
	cols_ = cols_*scale;
	data_ = newData;
}

void Image::ReadFromDisk(const std::string& file_name)
{
	igg::ImageData sample = io_strategy_.Read(file_name);
	rows_ = sample.rows;
	cols_ = sample.cols;
	max_val_ = sample.max_val;
	data_.reserve(rows_*cols_);
	for (int i = 0; i < rows_*cols_; ++i)
	{
		data_[i].red = sample.data[0][i];
		data_[i].green = sample.data[1][i];
		data_[i].blue = sample.data[2][i];
	}
}

void Image::WriteToDisk(const std::string& file_name)
{
	igg::ImageData sample;
	sample.rows = rows_;
	sample.cols = cols_;
	sample.max_val = max_val_;
	sample.data.resize(3);
	sample.data[0].reserve(rows_*cols_);
	sample.data[1].reserve(rows_*cols_);
	sample.data[2].reserve(rows_*cols_);
	for (int i = 0; i < rows_*cols_; ++i)
	{
		sample.data[0][i] = data_[i].red;
		sample.data[1][i] = data_[i].green;
		sample.data[2][i] = data_[i].blue;
	}

	if(io_strategy_.Write(file_name,sample)){
		std::cout << "file written successfully." << std::endl;
	}
	else{
		std::cout << "file written FAILED." << std::endl;
	};
}

}
