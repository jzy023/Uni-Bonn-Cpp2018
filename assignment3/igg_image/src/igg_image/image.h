// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"

namespace igg {

class Image {
 public:
    // constructor
    Image(const IoStrategy& io_strategy
    ):
    io_strategy_(io_strategy)
    {};

    Image(
        int rows,
        int cols,
        const IoStrategy& io_strategy
    ):
        rows_(rows),
        cols_(cols),
        io_strategy_(io_strategy)
    {};
    
    // A struct within class Image that defines a pixel.
    struct Pixel {
        int red;
        int green;
        int blue;
    };

    // TODO: fill public interface.
    int row() const {return rows_;}
    int col() const {return cols_;}
    int dataSize() const {return data_.size();}
    void ini(){
        for (int i = 0; i < rows_*cols_; ++i)
        {
            Pixel pixIni{0,0,0};
            data_.emplace_back(pixIni);
        }
    }

    Pixel at(int row, int col);
    const Pixel at(int row, int col) const;
    
    void DownScale(int scale);
    void UpScale(int scale);
    void ReadFromDisk(const std::string& file_name);
    void WriteToDisk(const std::string& file_name);

 private:
    int rows_ = 0;
    int cols_ = 0;
    int max_val_ = 255;
    std::vector<Pixel> data_;
    // IoStrategy is an abstract type, 
    // meaning it cannot be instantiated
    const IoStrategy& io_strategy_;
};

}  // namespace igg
