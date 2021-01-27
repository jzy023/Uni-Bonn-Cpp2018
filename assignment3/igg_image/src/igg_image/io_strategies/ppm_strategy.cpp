#include "igg_image/io_strategies/ppm_strategy.h"

#include <string>
#include <vector>


namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name,
                          const ImageData& data) const {
    std::cout << "Write" << std::endl;
    return false;
}

ImageData PpmIoStrategy::Read(const std::string& file_name) const {
    std::cout << "Reading..." << std::endl;
    ImageData sample;
    // read file header
    std::ifstream file(file_name, std::ios_base::in);
    int fileLine = 0;
    std::string line;
    while(std::getline(file, line)){
        if (line[0] == 'P'){ 
            fileLine++;
            continue;
        }
        else if(line[0] == '#'){ 
            continue;
        }
        else if(fileLine == 1){
            std::cout << "l " << fileLine << ", read rows and cols" << std::endl;
            std::stringstream ss(line);
            ss >> sample.rows >> sample.cols;
            fileLine++;
        }
        else if(fileLine == 2){
            std::cout << "l " << fileLine << ", read max_val" << std::endl;
            std::stringstream ss(line);
            ss >> sample.max_val;
            fileLine++;
            break;
        }
    }
    // read file header
    int pixelData;
    int idxPixelData = 0;
    int idxSampleData = 0;
    sample.data.resize(3);
    sample.data[0].reserve(sample.rows*sample.cols);
    sample.data[1].reserve(sample.rows*sample.cols);
    sample.data[2].reserve(sample.rows*sample.cols);
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::cout << "l " << fileLine << ", content: "
                  << line << std::endl;
        while (ss >> pixelData){
            idxSampleData = idxPixelData/3;
            sample.data[idxPixelData%3][idxSampleData] = pixelData;
            // if(idxPixelData%3 == 0){
            //     sample.data[0][idxSampleData] = pixelData;
            // }
            // else if(idxPixelData%3 == 1)
            // {
            //     sample.data[1][idxSampleData] = pixelData;
            // }
            // else{
            //     sample.data[2][idxSampleData] = pixelData;
            // }
            idxPixelData++;

        }
        if(fileLine == 15)
        {
            break;
        }
        fileLine++;
    }

    return sample;
}




}  // namespace igg
