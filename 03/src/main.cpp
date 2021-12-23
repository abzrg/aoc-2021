// Advent of Code: Day 03
// Ali Bozorgzadeh
#include <bitset>     // std::bitset
#include <cstdint>    // uint32_t
#include <cstdlib>    // std::exit()
#include <iostream>   // std::cerr, std::cout
#include <stdexcept>  // std::runtime_error
#include <string>     // std::string
#include <vector>     // std::vector

#include "utils/parser.h"
#include "utils/timer.h"

template <size_t N>
static uint32_t problem1(const std::string &input);

template <size_t N>
static uint64_t problem2(const std::string &input);

// If you want most common pass true as second argument, otherwise false
template <size_t N>
bool computeCommonBitAtPos(std::vector<std::bitset<N>> &vec, size_t pos,
                           bool is_most);

#define BITWIDTH 12

int main() {
    auto timer = utils::Timer();

    std::cout << "Problem 1: answer: " << problem1<BITWIDTH>("input.txt")
              << '\n';
    std::cout << "Problem 2: answer: " << problem2<BITWIDTH>("input.txt")
              << '\n';

    return 0;
}

// N: width of the bits
// > for std::bitset<N>, N must be known at compile time, otherwise
//   std::vector<bool> or boost::dynamic_bitset may be used
template <size_t N>
static uint32_t problem1(const std::string &input) {
    // Read the file and buffer it
    std::vector<std::bitset<N>> data;
    try {
        data = utils::parseOnePerLine<std::bitset<N>>(input);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        std::exit(1);
    }

    // Bits are initialized to zero
    std::bitset<N> gamma;

    // For each bit position
    // > Here we counting in the reverse order, from the least significant bit
    //   to the most
    for (size_t bitPos = 0; bitPos < N; ++bitPos) {
        uint32_t nOnes = 0;
        uint32_t nZeros = 0;

        // Look up index bitPos of bits in each line
        for (const auto bits : data) bits[bitPos] == 0 ? ++nZeros : ++nOnes;

        // Compute the most common bit
        nZeros > nOnes ? gamma[bitPos] = 0 : gamma[bitPos] = 1;
    }

    // epsilon is exactly flipped version of gamma (Note the overloaded ~
    // operator)
    std::bitset<N> epsilon = ~gamma;

    // Answer
    uint32_t powerConsumption =
        static_cast<uint32_t>(gamma.to_ulong() * epsilon.to_ulong());

    return powerConsumption;
}

template <size_t N>
bool computeCommonBitAtPos(std::vector<std::bitset<N>> &vec, size_t pos,
                           bool is_most) {
    size_t nZeros = 0;
    size_t nOnes = 0;

    for (const auto bits : vec) {
        bits[pos] == 0 ? ++nZeros : ++nOnes;
    }

    if (is_most) return nZeros > nOnes ? false : true;
    return nZeros > nOnes ? true : false;
}

template <size_t N>
static uint64_t problem2(const std::string &input) {
    (void)input;

    std::vector<std::bitset<N>> data =
        utils::parseOnePerLine<std::bitset<N>>(input);

    // Use these to do the calculation on a reduced set of binary numbers
    std::vector<std::bitset<N>> data_curr_pos = data;
    std::vector<std::bitset<N>> data_next_pos;

    // O2 Generator rating
    uint64_t O2_rating = 0;
    for (size_t bitPos = N - 1; bitPos >= 0; --bitPos) {
        bool mostCommonBit =
            computeCommonBitAtPos<N>(data_curr_pos, bitPos, true);

        // Clear its content before pushing new binary numbers in it
        data_next_pos.clear();

        // Create new vector
        for (const auto bits : data_curr_pos) {
            if (static_cast<bool>(bits[bitPos]) == mostCommonBit) {
                data_next_pos.push_back(bits);
            }
        }

        // Check if we left with one binary number
        if (data_next_pos.size() == 1) {
            O2_rating = data_next_pos[0].to_ulong();
            break;
        }

        // Swap them, so no copy
        data_curr_pos.swap(data_next_pos);
    }

    // CO2 Scrubber Rating
    uint64_t CO2_rating = 0;
    data_curr_pos = data;
    data_next_pos.clear();
    for (size_t bitPos = N - 1; bitPos >= 0; --bitPos) {
        // Calculate the least common bit
        bool leastCommonBit =
            computeCommonBitAtPos<N>(data_curr_pos, bitPos, false);

        // Clear its content before pushing new binary numbers in it
        data_next_pos.clear();

        // Create new vector
        for (const auto bits : data_curr_pos) {
            if (static_cast<bool>(bits[bitPos]) == leastCommonBit) {
                data_next_pos.push_back(bits);
            }
        }

        // Check if we left with one binary number
        if (data_next_pos.size() == 1) {
            CO2_rating = data_next_pos[0].to_ulong();
            break;
        }

        // Swap them, so no copy
        data_curr_pos.swap(data_next_pos);
    }

    return O2_rating * CO2_rating;
}
