#include <cstdint>
#include <exception>
#include <iostream>

#include "utils.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: sonarsweep INPUTFILE\n";
        return 1;
    }

    // Read data into a vector of type fixed 32 bit size unsigned integer
    std::string inputData = argv[1];
    std::vector<uint32_t> depths;
    try {
        depths = parseOnePerLine<uint32_t>(inputData);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 2;
    }

    // Calculate the number of increase in the measured depth
    size_t nDepthIncrease = 0;
    // Indexing starts at 1 because there is no previous measurement for the
    // first measured depth
    size_t nMeasurement = depths.size();
    for (size_t i = 1; i < nMeasurement; ++i) {
        uint32_t currMeasurement = depths[i];
        uint32_t prevMeasurement = depths[i - 1];
        if (currMeasurement > prevMeasurement) nDepthIncrease++;
    }

    // Print the result
    std::cout << nDepthIncrease << '\n';

    return 0;
}
