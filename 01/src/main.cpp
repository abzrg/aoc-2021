// Advent of Code: Day 1
// Ali Bozorgzadeh
#include <cstdint>
#include <exception>
#include <iostream>

#include "utils/parser.h"
#include "utils/timer.h"

static uint32_t problem1(const std::string &file);
static uint32_t problem2(const std::string &file);

int main() {
    auto timer = utils::Timer();

    // Problem 1
    std::cout << "Problem 1: Answer: \x1B[1m\x1B[32m" << problem1("input.txt")
              << "\033[0m.\n";

    // Problem 2
    std::cout << "Problem 2: Answer: \x1B[1m\x1B[32m" << problem2("input.txt")
              << "\033[0m.\n";

    return 0;
}

// Problem 1
static uint32_t problem1(const std::string& file) {
    // Read input file and buffer it
    std::vector<uint32_t> depths;
    try {
        depths = utils::parseOnePerLine<uint32_t>(file);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        return 2;
    }

    size_t nDepthIncrease = 0;
    // No previous measurement to first one
    for (size_t idx = 1, nMeasurements = depths.size(); idx < nMeasurements;
         ++idx) {
        uint32_t curr = depths[idx];
        uint32_t prev = depths[idx - 1];

        if (curr > prev) nDepthIncrease++;
    }

    return nDepthIncrease;
}

// Problem 2
#define WINDOW_LENGTH 3ULL
static uint32_t problem2(const std::string& file) {
    // Read input file and buffer it
    std::vector<uint32_t> depths;
    try {
        depths = utils::parseOnePerLine<uint32_t>(file);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        return 0;
    }

    // Store sum of each three data into an element within a new vector
    std::vector<uint32_t> windowSum;
    for (size_t idx = WINDOW_LENGTH - 1, nMeasurements = depths.size();
         idx < nMeasurements; ++idx)
        windowSum.emplace_back(depths[idx] + depths[idx - 1] + depths[idx - 2]);

    // Check for the number of increase in sum
    uint32_t nDepthIncrease = 0;
    for (size_t idx = 1, nWindows = windowSum.size(); idx < nWindows; ++idx)
        nDepthIncrease += windowSum[idx] > windowSum[idx - 1] ? 1 : 0;

    return nDepthIncrease;
}
