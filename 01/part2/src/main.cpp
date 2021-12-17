#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

#define WIDTH_OF_SLIDE 3ULL

int main(int argc, char **argv) {
    // Check for user input
    if (argc != 2) {
        std::cerr << "Usage: sonarsweep2 INPUTFILE\n";
        return 1;
    }

    // Parse the input into a vector of unsigned fixed size integers
    std::string inputData = argv[1];
    std::vector<uint32_t> depths;
    try {
        depths = parseOnePerLine<uint32_t>(inputData);
    } catch(const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 0;
    }

    // Store sum of each three data into an element within a new vector
    std::vector<uint32_t> groupMeasurementSum;
    size_t nMeasurements = depths.size();
    for (size_t i = WIDTH_OF_SLIDE - 1; i < nMeasurements; ++i)
        groupMeasurementSum.emplace_back(depths[i] + depths[i - 1] +
                                         depths[i - 2]);

    // Check for the number of increase in sum
    uint32_t nIncreaseInDepth = 0;
    size_t nGroups = groupMeasurementSum.size();
    for (size_t i = 1; i < nGroups; ++i)
        nIncreaseInDepth +=
            groupMeasurementSum[i] > groupMeasurementSum[i - 1] ? 1 : 0;

    // Print the result
    std::cout << nIncreaseInDepth << '\n';

    return 0;
}
