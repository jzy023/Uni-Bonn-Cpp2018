#include <iostream>
#include <vector>
#include <math.h>
#include "image.H"
#include "io_tools.H"

int& igg::Image::at(int row, int col)
{
	return data_[row*cols_ + col];
}

bool igg::Image::FillFromPgm
(
	const std::string& file_name
) 
{
	igg::io_tools::ImageData sample = 
		igg::io_tools::ReadFromPgm(file_name);

	if(sample.data.empty()){
		return false;
	}

	rows_ = sample.rows;
	cols_ = sample.cols;
	data_ = sample.data;
	return true;
}

void igg::Image::WriteToPgm
(
	const std::string& file_name
)
const
{
	igg::io_tools::ImageData sample {rows_,cols_,max_val_,data_};
	igg::io_tools::WriteToPgm(sample, file_name);
}

std::vector<float> igg::Image::ComputeHistogram(int bins)
{
	std::vector<float> v (bins);
	// v.reserve(bins);

	for (int i = 0; i < rows_*cols_; ++i)
	{
		v[data_[i]*bins/max_val_] += 1.0/(rows_*cols_);
	}

	return v;
}

void igg::Image::DownScale(int scale)
{
	// if the original size is divisible by the scaling factor
	if(rows_%scale == 0){
		int newRows = rows_/scale;
		int newCols = cols_/scale;
		std::vector<int> newData (newRows*newCols, 0);
		for (int i = 0; i < rows_*cols_; ++i)
		{
			// load original coordinates from data_
			int origialRow = i/cols_;
			int origialCol = i%cols_;
			// calculate new coordinates from originals
			int newRow = origialRow/scale;
			int newCol = origialCol/scale;

			newData[newRow*newRows + newCol] += data_[i]/(scale*scale); 
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

void igg::Image::UpScale(int scale)
{	
	std::cout << "scaling original image..." << std::endl;
	std::vector<int> newData (scale*scale*rows_*cols_);
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
				newData[newRow*scale*rows_ + newCol] = 
					data_[origialRow*cols_ + origialCol];
			}
		}
	}
	// write newly generated data to original
	data_.resize(scale*scale*rows_*cols_);
	rows_ = rows_*scale;
	cols_ = cols_*scale;
	data_ = newData;
}