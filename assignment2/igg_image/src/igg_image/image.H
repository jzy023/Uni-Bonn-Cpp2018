#include <vector>
#include <string>

namespace igg {

class Image {
 public:
////////////////////////// Create the public interface here ///////////////////////
 	// Constructors
 	Image() {
 		data_.reserve(0);
 	};

 	Image
 	(
 		int rows,
 		int cols
 	):
 	rows_(rows),
 	cols_(cols)
 	{
 		data_.reserve( rows_*cols_ );
 	};

 	// Member Functions
 	int size() { 
 		return data_.size(); 
 	}

 	const int& rows() /*const*/ { 
 		return rows_; 
 	}

 	const int& cols() /*const*/ { 
 		return cols_; 
 	}

 	int& at(int row, int col);

 	bool FillFromPgm(const std::string& file_name);

 	void WriteToPgm(const std::string& file_name) const;

 	std::vector<float> ComputeHistogram(int bins);

 	void DownScale(int scale);

 	void UpScale(int scale);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg




