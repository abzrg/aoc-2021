#include <cstdint>
#include <iostream>
#include <stdexcept>

#include "utils.h"

struct Position {
    uint32_t x;  // horizontal position       (→ +)
    uint32_t y;  // vertical position / depth (↓ +)
};

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: dive1 INPUTFILE\n";
        return 1;
    }

    // Parse the planned course into a vector of pairs
    // - each pair holds an instruction
    // - each instruction is comprised of:
    //   - a direction, and
    //   - a magnitude
    std::vector<std::pair<std::string, uint32_t>> course;
    try {
        course = parseTwoPerLine<std::string, uint32_t>(argv[1]);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    // Initial position
    Position pos{0, 0};
    // Navigate
    for (const auto &instruction : course) {
        const auto &direction = instruction.first;
        const auto &magnitude = instruction.second;

        if (direction == "up") {
            pos.y -= magnitude;
        } else if (direction == "down") {
            pos.y += magnitude;
        } else if (direction == "forward") {
            pos.x += magnitude;
        }
    }

    // Print the result
    std::cout << "Final Position: (" << pos.x << ", " << pos.y << ")\n";
    std::cout << "Final Answer: x * y = " << pos.x * pos.y << '\n';

    return 0;
}
