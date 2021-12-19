#include <cstdint>
#include <iostream>
#include <stdexcept>

#include "utils/parser.h"
#include "utils/timer.h"

static uint64_t problem1(const std::string &file);
static uint64_t problem2(const std::string &file);

int main() {
    auto timer = utils::Timer();

    // Problem 1
    std::cout << "Problem 1: answer = \x1B[1m\x1B[32m" << problem1("input.txt")
              << "\033[0m.\n";

    // Problem 2
    std::cout << "Problem 2: answer = \x1B[1m\x1B[32m" << problem2("input.txt")
              << "\033[0m.\n";

    return 0;
}

static uint64_t problem1(const std::string &file) {
    // Read data and buffer it
    std::vector<std::pair<std::string, uint64_t>> course;
    try {
        course = utils::parseTwoPerLine<std::string, uint64_t>(file);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    // Initial position
    struct Position {
        uint64_t x;  // horizontal position       (right +)
        uint64_t y;  // vertical position / depth (down +)
    } pos{0, 0};

    // Navigate
    for (const auto &instruction : course) {
        // Read instruction into direction and magnitude
        const auto &direction = instruction.first;
        const auto &magnitude = instruction.second;

        if (direction[0] == 'u') {
            pos.y -= magnitude;
        } else if (direction[0] == 'd') {
            pos.y += magnitude;
        } else if (direction[0] == 'f') {
            pos.x += magnitude;
        }
    }

    // Answer
    return pos.x * pos.y;
}

static uint64_t problem2(const std::string &file) {
    // Read data and buffer it
    std::vector<std::pair<std::string, uint64_t>> course;
    try {
        course = utils::parseTwoPerLine<std::string, uint64_t>(file);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    // Initial position
    struct Position {
        uint64_t x;  // horizontal position       (right +)
        uint64_t y;  // vertical position / depth (down +)
    } pos{0, 0};
    uint64_t aim = 0;

    // Navigate
    for (const auto &instruction : course) {
        // Read instruction into direction and magnitude
        const auto &direction = instruction.first;
        const auto &magnitude = instruction.second;

        if (direction[0] == 'u') {
            aim -= magnitude;
        } else if (direction[0] == 'd') {
            aim += magnitude;
        } else if (direction[0] == 'f') {
            pos.x += magnitude;
            pos.y += magnitude * aim;
        }
    }

    // Answer
    return pos.x * pos.y;
}
