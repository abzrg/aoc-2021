// Source:
// https://github.com/lento234/advent2021/blob/main/include/utils/timer.h

#pragma once

#include <chrono>
#include <iostream>
#include <string>

namespace utils {
template <typename T = std::chrono::microseconds>
class Timer {
    using time_t = T;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::string unit = "μs";

public:
    Timer() {
        // Start clock
        start = std::chrono::high_resolution_clock::now();

        // Determine the unit
        if (std::is_same<T, std::chrono::microseconds>::value)
            unit = "μs";
        else if (std::is_same<T, std::chrono::milliseconds>::value)
            unit = "ms";
        else if (std::is_same<T, std::chrono::seconds>::value)
            unit = "s";
        else if (std::is_same<T, std::chrono::minutes>::value)
            unit = "min";
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        std::cout << "\n[Summary Total elapsed = "
                  << std::chrono::duration_cast<time_t>(end - start).count()
                  << unit << "]\n\n";
    }
};

}  // namespace utils
