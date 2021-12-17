#include <fstream>    // std::ifstream
#include <stdexcept>  // std::runtime_error
#include <utility>    // std::pair
#include <vector>     // std::vector

// Used in day: 1
template <typename T>
std::vector<T> parseOnePerLine(const std::string &path) {
    // Open file for read
    std::ifstream ifs(path);
    if (!ifs) throw std::runtime_error("Could not open file '" + path + "'.\n");

    // Store data into a raw vector
    std::vector<T> raw;
    T buffer;
    while (ifs >> buffer) raw.emplace_back(buffer);

    // Close the file
    ifs.close();

    return raw;
}

// Used in day: 2
template <typename T, typename U>
std::vector<std::pair<T, U>> parseTwoPerLine(const std::string &path) {
    // Open file for read
    std::ifstream ifs(path);
    if (!ifs) throw std::runtime_error("Could not open file '" + path + "'.\n");

    // Store data into a raw vector of pairs of type T and U
    std::vector<std::pair<T, U>> raw;
    T tBuffer;
    U uBuffer;
    while (ifs >> tBuffer >> uBuffer) {
        raw.emplace_back(std::pair<T, U>(tBuffer, uBuffer));
    }

    // Close the file
    ifs.close();

    return raw;
}
