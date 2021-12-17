#include <exception>
#include <fstream>
#include <vector>

template <typename T>
std::vector<T> parseOnePerLine(const std::string &path) {
    // Open file for read
    std::ifstream ifs(path);
    if (!ifs) throw std::runtime_error("Could not open file\n");

    // Store data into a raw vector
    std::vector<T> raw;
    T buffer;
    while (ifs >> buffer) raw.emplace_back(buffer);

    // Close the file
    ifs.close();

    return raw;
}
