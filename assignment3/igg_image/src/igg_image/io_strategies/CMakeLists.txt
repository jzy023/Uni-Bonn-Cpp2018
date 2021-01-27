find_package(PNG REQUIRED)
#include_directories(${PNG_INCLUDE_DIRS})

add_library(strategies
			ppm_strategy.cpp
            png_strategy.cpp)
            
# TODO: link strategies against needed libraries.
target_link_libraries(strategies ${PNG_LIBRARY})
